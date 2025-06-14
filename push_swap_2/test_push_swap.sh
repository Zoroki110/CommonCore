#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=== PUSH_SWAP TESTER ===${NC}"

# Compile the project
echo -e "\n${YELLOW}Compiling...${NC}"
make re
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation successful!${NC}"

# Test basic functionality
echo -e "\n${YELLOW}=== Basic Tests ===${NC}"

# Test with no arguments
echo -e "\nTesting with no arguments:"
./push_swap
echo "Exit code: $?"

# Test with invalid arguments
echo -e "\nTesting with invalid arguments:"
./push_swap 0 one 2 3 2>/dev/null
echo "Exit code: $?"

# Test with duplicates
echo -e "\nTesting with duplicates:"
./push_swap 1 2 3 2 2>/dev/null
echo "Exit code: $?"

# Test with already sorted array
echo -e "\nTesting with sorted array:"
./push_swap 1 2 3 4 5
echo "Exit code: $?"

# Test simple cases
echo -e "\n${YELLOW}=== Simple Cases ===${NC}"

echo -e "\nTesting 2 numbers (reverse):"
./push_swap 2 1

echo -e "\nTesting 3 numbers:"
./push_swap 3 2 1

echo -e "\nTesting 5 numbers:"
./push_swap 5 4 3 2 1

# Performance tests
echo -e "\n${YELLOW}=== Performance Tests ===${NC}"

# Function to generate random numbers
generate_random() {
    local count=$1
    local numbers=""
    for i in $(seq 1 $count); do
        numbers="$numbers $i"
    done
    echo $numbers | tr ' ' '\n' | shuf | tr '\n' ' '
}

# Test 100 numbers
echo -e "\nTesting 100 random numbers:"
ARG=$(generate_random 100)
OPERATIONS=$(./push_swap $ARG | wc -l)
echo "Operations: $OPERATIONS"
if [ $OPERATIONS -lt 700 ]; then
    echo -e "${GREEN}✓ Under 700 operations${NC}"
else
    echo -e "${RED}✗ Over 700 operations${NC}"
fi

# Test 500 numbers
echo -e "\nTesting 500 random numbers:"
ARG=$(generate_random 500)
OPERATIONS=$(./push_swap $ARG | wc -l)
echo "Operations: $OPERATIONS"
if [ $OPERATIONS -lt 5500 ]; then
    echo -e "${GREEN}✓ Under 5500 operations${NC}"
else
    echo -e "${RED}✗ Over 5500 operations${NC}"
fi

# Compile bonus if available
echo -e "\n${YELLOW}=== Bonus Tests ===${NC}"
make bonus 2>/dev/null
if [ $? -eq 0 ] && [ -f "./checker" ]; then
    echo -e "${GREEN}Checker compiled successfully!${NC}"
    
    # Test checker with valid sequence
    echo -e "\nTesting checker with valid sequence:"
    echo -e "sa\npb\npb\npb\nsa\npa\npa\npa" | ./checker 2 1 3 6 5 8
    
    # Test checker with invalid sequence
    echo -e "\nTesting checker with invalid sequence:"
    echo -e "sa\nrra\npb" | ./checker 3 2 1 0
    
    # Test checker with push_swap output
    echo -e "\nTesting checker with push_swap output:"
    ARG="4 67 3 87 23"
    RESULT=$(./push_swap $ARG | ./checker $ARG)
    echo "Result: $RESULT"
    if [ "$RESULT" = "OK" ]; then
        echo -e "${GREEN}✓ Push_swap output is valid${NC}"
    else
        echo -e "${RED}✗ Push_swap output is invalid${NC}"
    fi
else
    echo -e "${YELLOW}Bonus not available or compilation failed${NC}"
fi

echo -e "\n${YELLOW}=== Test Complete ===${NC}"