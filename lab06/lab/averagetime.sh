#!/bin/bash
declare -i AVG_MILLI=0


echo "Input a dictionary file"
read dict

echo "Input a grid file"
read grid

RUNNING_TIME_ONE=`./a.out $dict $grid| tail -1`
RUNNING_TIME_TWO=`./a.out $dict $grid| tail -1`
RUNNING_TIME_THREE=`./a.out $dict $grid| tail -1`
RUNNING_TIME_FOUR=`./a.out $dict $grid| tail -1`
RUNNING_TIME_FIVE=`./a.out $dict $grid| tail -1`



AVG_MILLI=$(((RUNNING_TIME_ONE+RUNNING_TIME_TWO+RUNNING_TIME_THREE+RUNNING_TIME_FOUR+RUNNING_TIME_FIVE)/5))

echo "Average run time is $AVG_MILLI milliseconds"
