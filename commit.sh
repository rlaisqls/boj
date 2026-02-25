#!/bin/bash
# Stage and commit a problem directory
# Usage: ./commit.sh <problem_number>
#
# Examples:
#   ./commit.sh 25304          # commit all files in 25304/

PROB="${1:-$BOJ}"

if [ -z "$PROB" ]; then
    echo "Usage: ./commit.sh <problem_number> (or set \$BOJ)"
    exit 1
fi
DIR="$(dirname "$0")/$PROB"

if [ ! -d "$DIR" ]; then
    echo "Error: directory $PROB not found"
    exit 1
fi

git add "$DIR"

# Check if there are staged changes
if git diff --cached --quiet -- "$DIR"; then
    echo "No changes to commit for $PROB"
    exit 0
fi

git commit -m "solve $PROB"
echo "Committed $PROB"
