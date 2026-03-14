section .bss
    grid resb 10201      ; 101*101 byte array
    buf  resb 32         ; I/O buffer

section .text
    global main

; ---- read one integer from stdin -> eax ----
read_int:
    xor esi, esi         ; result = 0
.skip:
    mov eax, 3
    mov ebx, 0
    mov ecx, buf
    mov edx, 1
    int 0x80
    cmp eax, 0
    jle .done
    movzx eax, byte [buf]
    cmp eax, ' '
    jle .skip
    jmp .digit
.loop:
    mov eax, 3
    mov ebx, 0
    mov ecx, buf
    mov edx, 1
    int 0x80
    cmp eax, 0
    jle .done
    movzx eax, byte [buf]
    cmp eax, '0'
    jl .done
    cmp eax, '9'
    jg .done
.digit:
    sub eax, '0'
    imul esi, esi, 10
    add esi, eax
    jmp .loop
.done:
    mov eax, esi
    ret

; ---- write integer in eax to stdout ----
write_int:
    mov edi, buf+31      ; end of buffer
    mov byte [edi], 10   ; newline
    test eax, eax
    jnz .conv
    dec edi
    mov byte [edi], '0'
    jmp .print
.conv:
    mov ebx, 10
.loop2:
    test eax, eax
    jz .print
    xor edx, edx
    div ebx
    add dl, '0'
    dec edi
    mov [edi], dl
    jmp .loop2
.print:
    ; edx = length = (buf+32) - edi
    mov edx, buf+32
    sub edx, edi
    mov eax, 4
    mov ebx, 1
    mov ecx, edi
    int 0x80
    ret

main:
    ; save callee-saved registers
    push ebp
    push ebx
    push esi
    push edi

    ; read n
    call read_int
    mov ebp, eax         ; ebp = n

.read_loop:
    test ebp, ebp
    jz .count

    call read_int
    push eax             ; save a
    call read_int
    mov ebx, eax         ; ebx = b
    pop eax              ; eax = a

    ; mark grid[a+i][b+j] = 1 for i=0..9, j=0..9
    mov ecx, 0           ; i
.row:
    cmp ecx, 10
    jge .next_rect
    mov edx, 0           ; j
.col:
    cmp edx, 10
    jge .next_row
    ; offset = (a+i)*101 + (b+j)
    push eax
    push ecx
    push edx
    add ecx, eax         ; a+i
    add edx, ebx         ; b+j
    imul ecx, ecx, 101
    add ecx, edx
    mov byte [grid+ecx], 1
    pop edx
    pop ecx
    pop eax
    inc edx
    jmp .col
.next_row:
    inc ecx
    jmp .row
.next_rect:
    dec ebp
    jmp .read_loop

.count:
    ; count all 1s in grid
    xor eax, eax         ; sum
    xor ecx, ecx         ; index
.count_loop:
    cmp ecx, 10201
    jge .output
    cmp byte [grid+ecx], 1
    jne .count_next
    inc eax
.count_next:
    inc ecx
    jmp .count_loop

.output:
    call write_int

    ; restore callee-saved registers and return 0
    pop edi
    pop esi
    pop ebx
    pop ebp
    xor eax, eax
    ret
