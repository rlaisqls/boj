#!/bin/bash
# Create a new problem directory with a template solution file
# Usage: ./new.sh <problem_number>

PROB="${1:-$BOJ}"

if [ -z "$PROB" ]; then
    echo "Usage: ./new.sh <problem_number> (or set \$BOJ)"
    exit 1
fi
DIR="$(dirname "$0")/$PROB"

if [ -d "$DIR" ]; then
    echo "Directory $PROB already exists"
    exit 1
fi

mkdir -p "$DIR"

cat > "$DIR/main.cpp" << 'EOF'
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
EOF

echo "Created $PROB/main.cpp"
