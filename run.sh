#!/bin/bash
# Compile and run a solution, optionally testing against input files
# Usage: ./run.sh <problem_number> [input_file]
#
# Examples:
#   ./run.sh 1000            # compile and run with stdin
#   ./run.sh 1000 1.in       # compile and run with 1.in as input
#   ./run.sh 1000 all        # run against all *.in files, compare with *.out

if [ -z "$1" ]; then
    echo "Usage: ./run.sh <problem_number> [input_file|all]"
    exit 1
fi

PROB="$1"
DIR="$(dirname "$0")/$PROB"
SRC="$DIR/main.cpp"
BIN="$DIR/sol"

if [ ! -f "$SRC" ]; then
    echo "Error: $SRC not found"
    exit 1
fi

# Compile
echo "Compiling..."
g++ -std=c++17 -O2 -Wall -Wextra -o "$BIN" "$SRC"
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi
echo "Compiled OK"

# Run
if [ -z "$2" ]; then
    # Interactive: read from stdin
    "$BIN"
elif [ "$2" = "all" ]; then
    # Test all *.in files
    PASS=0
    FAIL=0
    TOTAL=0
    for INF in "$DIR"/*.in; do
        [ -f "$INF" ] || continue
        TOTAL=$((TOTAL + 1))
        BASE=$(basename "$INF" .in)
        OUTF="$DIR/$BASE.out"
        ACTUAL=$("$BIN" < "$INF" 2>/dev/null)

        if [ -f "$OUTF" ]; then
            EXPECTED=$(cat "$OUTF")
            if [ "$ACTUAL" = "$EXPECTED" ]; then
                echo "[PASS] $BASE"
                PASS=$((PASS + 1))
            else
                echo "[FAIL] $BASE"
                echo "  Expected:"
                echo "$EXPECTED" | sed 's/^/    /'
                echo "  Got:"
                echo "$ACTUAL" | sed 's/^/    /'
                FAIL=$((FAIL + 1))
            fi
        else
            echo "[RUN]  $BASE"
            echo "$ACTUAL" | sed 's/^/    /'
            PASS=$((PASS + 1))
        fi
    done
    if [ $TOTAL -eq 0 ]; then
        echo "No .in files found in $DIR"
        exit 1
    fi
    echo "---"
    echo "Result: $PASS passed, $FAIL failed / $TOTAL total"
    [ $FAIL -ne 0 ] && exit 1
else
    # Single input file
    INF="$DIR/$2"
    if [ ! -f "$INF" ]; then
        echo "Error: $INF not found"
        exit 1
    fi
    "$BIN" < "$INF"
fi
