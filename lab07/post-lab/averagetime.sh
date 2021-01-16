#!/bin/bash

declare -i RUN_NUM=5
declare -i AVG_TIME=0
declare -i TOTAL_TIME=0

while [[ true ]] ; do
    echo "enter the exponent for counter.cpp:"
    read exp

    if [[ $exp == "quit" ]] ; then
      exit 0
    fi

    for (( i=1; i<$RUN_NUM+1; i++ )) ; do
	echo "Running iteration $i..."
	msCount=`./a.out $exp`
	TOTAL_TIME=$(($msCount + $TOTAL_TIME))
	echo "time taken: ${msCount} ms"
    done

    AVG_TIME=$(($TOTAL_TIME/$RUN_NUM))
    echo "$RUN_NUM iterations took $TOTAL_TIME ms"
    echo "Average time was $AVG_TIME ms"
    exit 0
done
