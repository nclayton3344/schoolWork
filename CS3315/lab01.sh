#!/bin/bash

# File: lab01.sh
# Calculate sum of the first n non-negative integers
# and display the result
# Programmer: Nathan Clayton, Professor Haiduk
# Date: 02/22/2019

function sumint(){
    #NOTE: one argument expected for this function
    #      it will be located in $1
    declare -i sum=0
    declare -i i=1
    declare -i n=${1:=0}  #use value of $1 if it exists; otherwise 0

    while (( i <= n )); do
        (( sum += i ))
        (( i += 1 ))
    done
    printf "%d" $sum
}

declare -i ok=0
# do not declare n so that we can validate it
#until [[ $ok -eq 1 ]]; do
until (( ok )); do
    read -p "Input a non-negative integer: " n

    # if n was an integer with possible leading + or -; then
    #    if n < 0; then
    #         display that input was an integer but negative -- try again
    #    else
    #         set ok appropriately
    #    fi
    # else
    #    display that input was not an integer -- try again
    # fi
    if [[  $n =~ ^[-+]?[0-9]+$ ]]; then
    	if (( n < 0 )); then 
		printf "Input was an integer but negative -- try again.\n"
    	else
		ok=1
	fi
    else
	printf "The input was not an integer -- try again.\n"
    fi
done

# Modify the print and the function call so that values entered with
# leading 0s are not interpreted as octal numbers for both output and
# for passing to the function
printf "Sum of the first %d non-negative integers is %d\n" $((10#$n)) $(sumint $((10#$n)))
