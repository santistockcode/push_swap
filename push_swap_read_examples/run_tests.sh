#!/usr/bin/env bash


# Color codes
BLUE="\033[34m"
YELLOW="\033[93m"
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"


# ------------------------------------------------------------------------------
# 1. Configuration
# ------------------------------------------------------------------------------
# List all sub-projects (folder names) under examples/
PROJECTS=("ayogun" "hu8813" "suspectedoceano" "mcombeau" "beatrizdile" "sisittu99" "madebypixel02" "raulmarcano" "gjmacias" "42YerevanProjects")

# Where checker_linux is located
CHECKER="./checker_linux"

# Test scenarios: (array of stack sizes)
TEST_SIZES=(3 5 100)

# Thresholds to compare average instructions. They must match the order above.
# if x=3   => n <= 3
# if x=5   => n <= 12
# if x=100 => n < 700  (42 subject requirement)
# if x=500 => n < 11500
#
# Feel free to swap in 1500 for the 100 case if you prefer that threshold.
THRESHOLDS=(3 12 700)

# Number of random tests to run for each scenario
NUM_TESTS=3

# Range of numbers to pick from (for generating random lists)
# For small stack sizes (3,5), it doesn't matter if the range is big,
# since we only pick a few unique numbers anyway.
MIN_VAL=-999
MAX_VAL=999

# ------------------------------------------------------------------------------
# 2. Ensure projects are compiled (creates ./push_swap in each project folder)
# ------------------------------------------------------------------------------
echo "Compiling all projects..."
make all

# ------------------------------------------------------------------------------
# 3. Test function: given a project path and a stack size, runs multiple tests
#    to compute average instruction count & check correctness.
# ------------------------------------------------------------------------------
function test_stack_size() {
    local PUSH_SWAP="$1"
    local SIZE="$2"
    local THRESHOLD="$3"

    # We'll run $NUM_TESTS random tests, track total instructions and correct count.
    local total_instructions=0
    local correct_count=0

    echo "  -> Stack size: $SIZE  | Threshold: $THRESHOLD"

    for ((i=1; i<=NUM_TESTS; i++)); do
        # Generate a random list of unique integers of length $SIZE
        ARG=$(seq $MIN_VAL $MAX_VAL | shuf -n $SIZE | xargs)

        # Count instructions
        INSTR_COUNT=$($PUSH_SWAP $ARG | wc -l)

        # Check with checker_linux => OK or KO
        RESULT=$($PUSH_SWAP $ARG | $CHECKER $ARG)

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
    if [ "$avg_instructions" -le "$THRESHOLD" ]; then
    echo -e "     ${GREEN}Performance: PASS (<= $THRESHOLD)${RESET}"
    else
    echo -e "     ${RED}Performance: FAIL (> $THRESHOLD)${RESET}"
    fi
    echo
}

# ------------------------------------------------------------------------------
# 4. Main loop over each project and each test size
# ------------------------------------------------------------------------------
echo
echo "============================================================="
echo "Running tests for each project..."
echo "============================================================="

for prj in "${PROJECTS[@]}"; do
    echo -e "\n${YELLOW}=== Testing Project: $prj ===${RESET}"
    PROJECT_PATH="examples/$prj"
    PUSH_SWAP="$PROJECT_PATH/push_swap"

    if [ ! -f "$PUSH_SWAP" ]; then
        echo "  Error: $PUSH_SWAP not found! Did compilation fail?"
        continue
    fi

    # Test each scenario (size + threshold)
    for idx in "${!TEST_SIZES[@]}"; do
        size="${TEST_SIZES[$idx]}"
        threshold="${THRESHOLDS[$idx]}"

        test_stack_size "$PUSH_SWAP" "$size" "$threshold"
    done
done

echo -e "\nAll tests completed!"
