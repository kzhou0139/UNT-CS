#!/bin/bash
randNum=$(( $RANDOM%10 + 1 ))
while true
do
    read -p "Enter a number between 1 and 10: " guess
    if [ $guess != $randNum ]
      then
        echo "Sorry, you are not correct. Try again!"
    else
      echo "Congratulations, the number is $randNum."
      exit -1
    fi
done
