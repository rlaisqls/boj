#!/bin/bash
# Stage and commit a problem directory
# Usage: ./commit.sh <problem_number>
#        ./commit.sh all
#
# Examples:
#   ./commit.sh 25304          # commit all files in 25304/
#   ./commit.sh all            # commit all changed problem directories

BASE="$(dirname "$0")"

commit_one() {
    local PROB="$1"
    local DIR="$BASE/$PROB"

    if [ ! -d "$DIR" ]; then
        echo "Error: directory $PROB not found"
        return 1
    fi

    git add "$DIR"

    if git diff --cached --quiet -- "$DIR"; then
        echo "No changes to commit for $PROB"
        return 0
    fi

    git commit -m "solve $PROB"
    echo "Committed $PROB"
}

if [ "$1" = "all" ]; then
    dirs=$(git status --porcelain | awk '{print $NF}' | cut -d'/' -f1 | sort -un | grep -E '^[0-9]+$')
    for dir in $dirs; do
        commit_one "$dir"
    done
else
    PROB="${1:-$BOJ}"
    if [ -z "$PROB" ]; then
        echo "Usage: ./commit.sh <problem_number|all> (or set \$BOJ)"
        exit 1
    fi
    commit_one "$PROB"
fi
