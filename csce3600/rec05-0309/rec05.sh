# Kelly Zhou, ksz0009

#! /bin/bash

curve () {
  incr=$1
  shift
  grades=("$@")
  index=0

  for i in "${grades[@]}"
  do
    let "grades[$index]=$(($i+$incr))"
    index=$((index+1))
  done
}

if [ $# != 1 ]
then
  echo "usage: ./rec05.sh <curve amount>"
  exit 0
else
  for i in 1 2 3 4 5
  do
  	read -p "Enter QUIZ #$i: " grades[$i-1]
  done
fi

curve $1 "${grades[@]}"

echo "Curved Grades:"
for (( i=0 ; $i<${#grades[*]} ; i=$i+1 ))
do
	echo "grades[$i] = ${grades[$i]}"
done
