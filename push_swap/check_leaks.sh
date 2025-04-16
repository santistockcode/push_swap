#!/usr/bin/env bash

# Color codes
BLUE="\033[34m"
YELLOW="\033[93m"
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

CHECKER="./checker_linux"
TEST_SIZES=(3 5 10)
THRESHOLDS=(2 12 1)
NUM_TESTS=10

MIN_VAL=-999
MAX_VAL=999

function test_stack_size() {
    local PUSH_SWAP="$1"
    local SIZE="$2"
    local THRESHOLD="$3"

    local total_tests=0
    local leak_free_count=0

    echo "  -> Stack size: $SIZE  | Threshold: $THRESHOLD"

    local LOG_DIR="tests/random/$SIZE"
    mkdir -p "$LOG_DIR"

    for ((i=1; i<=NUM_TESTS; i++)); do
        total_tests=$((total_tests + 1))
        ARG=$(seq $MIN_VAL $MAX_VAL | shuf -n $SIZE | xargs)

        LOG_FILE="$LOG_DIR/checker_$i.log"

        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
          --log-file="$LOG_FILE" ./$PUSH_SWAP $ARG > /dev/null 2>&1

        if grep -q "All heap blocks were freed -- no leaks are possible" "$LOG_FILE" &&
           grep -q "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" "$LOG_FILE"; then
            leak_free_count=$((leak_free_count + 1))
        else
            echo -e "${RED}Memory leak detected!${RESET}"
            echo -e "${YELLOW}Failing ARG:${RESET} $ARG"
            echo "See: $LOG_FILE"
            exit 1
        fi
    done

    echo -e "${GREEN}Leak check passed: $leak_free_count/$total_tests${RESET}"
}

PUSH_SWAP="push_swap"

if [ ! -f "$PUSH_SWAP" ]; then
    echo "  Error: $PUSH_SWAP not found! Did compilation fail?"
    exit 1
fi

for idx in "${!TEST_SIZES[@]}"; do
    size="${TEST_SIZES[$idx]}"
    threshold="${THRESHOLDS[$idx]}"
    test_stack_size "$PUSH_SWAP" "$size" "$threshold"
done

echo -e "\nAll tests checker completed!"
