#!/bin/bash

# Acceptance test for push swap program

# These should give an error.
# ./push_swap 1 2 3 ""

./push_swap 1 2 3 " "

./push_swap 1 2 "  " 3
