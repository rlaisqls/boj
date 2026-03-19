import sys
input=sys.stdin.readline
T=int(input())
for _ in range(T):
    x1,y1,x2,y2=map(int,input().split())
    n=int(input())
    ans=0
    for _ in range(n):
        cx,cy,r=map(int,input().split())
        d1=(x1-cx)**2+(y1-cy)**2
        d2=(x2-cx)**2+(y2-cy)**2
        r2=r*r
        if (d1<r2)!=(d2<r2):
            ans+=1
    print(ans)
