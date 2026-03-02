#!/bin/bash
# Stage, commit per problem number, and push
# Usage: ./push.sh

ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"

git add -A

if git diff --cached --quiet; then
    echo "Nothing to commit"
    exit 0
fi

# Get changed problem numbers and other files separately
PROBLEMS=$(git diff --cached --name-only | grep -oP '^\d+' | sort -u)
OTHERS=$(git diff --cached --name-only | grep -vP '^\d+/')

# Commit each problem directory separately
for PROB in $PROBLEMS; do
    git reset HEAD -- . > /dev/null 2>&1
    git add "$PROB/"
    echo "Committing: solve $PROB"
    git commit -m "solve $PROB"
done

# Commit remaining non-problem files if any
if [ -n "$OTHERS" ]; then
    git reset HEAD -- . > /dev/null 2>&1
    echo "$OTHERS" | xargs git add
    echo "Committing: update"
    git commit -m "update"
fi

git push
