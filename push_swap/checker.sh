#!/usr/bin/env bash


# Color codes
BLUE="\033[34m"
YELLOW="\033[93m"
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

CHECKER="./checker_linux"
TEST_SIZES=(3 5)
THRESHOLDS=(2 11)
NUM_TESTS=25

MIN_VAL=-999
MAX_VAL=999

function test_stack_size() {
    local PUSH_SWAP="$1"
    local SIZE="$2"
    local THRESHOLD="$3"

    local total_instructions=0
    local correct_count=0

    echo "  -> Stack size: $SIZE  | Threshold: $THRESHOLD"

    for ((i=1; i<=NUM_TESTS; i++)); do
        # Generate a random list of unique integers of length $SIZE
        ARG=$(seq $MIN_VAL $MAX_VAL | shuf -n $SIZE | xargs)

        # Count instructions
        INSTR_COUNT=$(./$PUSH_SWAP $ARG | wc -l)

        # Check with checker_linux => OK or KO
        RESULT=$(./$PUSH_SWAP $ARG | $CHECKER $ARG)

        # Summation for average
        total_instructions=$((total_instructions + INSTR_COUNT))

        # Tally correctness
        if [ "$RESULT" == "OK" ]; then
            correct_count=$((correct_count + 1))
        fi
    done

    # Compute average instructions
    local avg_instructions=$((total_instructions / NUM_TESTS))

    # Print results
    echo "     Tests run: $NUM_TESTS"
    echo "     Sorted OK: $correct_count/$NUM_TESTS"
    echo "     Avg instructions: $avg_instructions"

    # Compare average instructions to threshold
    if [ "$avg_instructions" -le "$THRESHOLD" ] & [ $correct_count == $NUM_TESTS ] ; then
    echo -e "     ${GREEN}Performance: PASS (<= $THRESHOLD)${RESET}"
    else
    echo -e "     ${RED}Performance: FAIL (> $THRESHOLD)${RESET}"
    fi
    echo
}

PUSH_SWAP="push_swap"

if [ ! -f "$PUSH_SWAP" ]; then
    echo "  Error: $PUSH_SWAP not found! Did compilation fail?"
    continue
fi

for idx in "${!TEST_SIZES[@]}"; do


        size="${TEST_SIZES[$idx]}"
        threshold="${THRESHOLDS[$idx]}"

        test_stack_size "$PUSH_SWAP" "$size" "$threshold"
    done

echo -e "\nAll tests checker completed!"