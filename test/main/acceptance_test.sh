#!/bin/bash

# Acceptance test for push swap program

# Set initial error value
error="0"

# Check for push_swap executable
if [[ ! -f "push_swap" ]]; then
	echo "Can't find push_swap executable."
	exit 1
fi

# These should give an error.
if [[ $(./push_swap 1 2 3 "") != "Error" ]]; then
	error=$(($error + 1))
fi

if [[ $(./push_swap 1 2 3 " ") != "Error" ]]; then
	error=$(($error + 1))
fi

if [[ $(./push_swap 1 2 "  " 3) != "Error" ]]; then
	error=$(($error + 1))
fi

if [[ $(./push_swap 1 2 a 3) != "Error" ]]; then									# wrong character
	error=$(($error + 1))
fi

if [[ $(./push_swap 1 2 1 3) != "Error" ]]; then									# duplicate
	error=$(($error + 1))
fi

if [[ $(./push_swap 1 2 1 3000000000000000000000000000000) != "Error" ]]; then		# int overflow
	error=$(($error + 1))
fi

if [[ $(./push_swap) != "Error" ]]; then											# no input
	error=$(($error + 1))
fi

if [[ $(./push_swap 1) != "" ]]; then												# one number, don't need sorting
	error=$(($error + 1))
fi

if [[ $(./push_swap 1 2 3 4 5) != "" ]]; then										# one number, don't need sorting
	error=$(($error + 1))
fi

# Test conclusion
if [[ "$error" -eq "0" ]]; then
	echo "Acceptance test was a succes!"
	exit 0
else
	echo "Acceptance test failed: $error tests failed!"
	exit 1
fi