#Kelly Zhou, ksz0009
#CSCE 3600.002
#March 2, 2023
#This bash script tracks the users that log in and out of the CSE Linux machine that it is run in.

#!/bin/bash
currDate=$(date) #currDate contains the current date
printf "%s initial users logged in\n" "$currDate"
who > initial.txt #writes all of the current logged in users to initial.txt
awk ' /^[a-z]{,3}[0-9]{4}/ && !seen[$0] {print} ' initial.txt > initialFixed.txt #makes sure that the user is a student/teacher (not cengadmin) and removes duplicates. modified list is stored in initialFixed.txt
awk -v host="$(hostname)" '{
  print "> " $1 " logged in to " host
}' initialFixed.txt
rel=1 #rel is used to represent the relationship between the length of initialFixed.txt and afterFixed.txt. Default value is 1
      #0 = the length of initialFixed.txt is less than the length of afterFixed.txt
      #1 = the length of initialFixed.txt is equal to the length of afterFixed.txt
      #2 = the length of initialFixed.txt is greater than the length of afterFixed.txt

sigint_handler() { #custom signal handler to trap ^C
    echo "(SIGINT) ignored. Enter ^C one more time to terminate program."
    trap SIGINT
}
trap 'sigint_handler' SIGINT

while true #loop that tracks which users log in and log out. repeats until the program is terminated
do
  who > after.txt #writes all of the logged in users to after.txt after the 10 second wait
  awk ' /^[a-z]{,3}[0-9]{4}/{print} ' after.txt > afterFixed.txt
  grep -Fxvf initialFixed.txt afterFixed.txt > diff.txt #finds the different lines/users between initialFixed.txt and afterFixed.txt and stores the values in diff.txt
  grep -Fxvf afterFixed.txt initialFixed.txt >> diff.txt

  initialLength=$(wc -l < initialFixed.txt) #initalLength contains the number of lines/users in initialFixed.txt
  afterLength=$(wc -l < afterFixed.txt) #afterLength contains the number of lines/users in afterFixed.txt

  if [ $initialLength -lt $afterLength ] #if/else statements to find the new relationship between the lengths of initialFixed.txt and afterFixed.txt
  then
    newRel=0
  elif [ $initialLength -eq $afterLength ]
  then
    newRel=1
  else
    newRel=2
  fi

  if [ $rel -lt $newRel ] #if/else statements with commands for what happens based on the new relationship between the lengths of initialFixed.txt and afterFixed.txt
  then
    awk -v host="$(hostname)" '{ print "> " $1 " logged out of " host }' diff.txt
    who > initial.txt
    awk ' /^[a-z]{,3}[0-9]{4}/{print} ' initial.txt > initialFixed.txt
  elif [ $rel -gt $newRel ]
  then
    awk -v host="$(hostname)" '{ print "> " $1 " logged in to " host }' diff.txt
    who > initial.txt
    awk ' /^[a-z]{,3}[0-9]{4}/{print} ' initial.txt > initialFixed.txt
  fi

  numUsers=0 #numUsers stores the number of users that are currently logged in to the server
  while read users #while loop that counts the number of lines/users in afterFixed.txt
  do
    numUsers=$((numUsers+1))
  done < afterFixed.txt
  echo "$(date) # of users: " $numUsers
  sleep 10 #waits 10 seconds to repeat the loop
done
