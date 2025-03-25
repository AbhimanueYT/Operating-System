#!/bin/bash
read -p "Enter 1st number " a
read -p "Enter 2nd number " b
read -p "Enter 3rd number " c
if [ $a -gt $b ] && [ $a -gt $c ];then
	echo "Largest number is "$a
elif [ $b -gt $a ] && [ $b -gt $c ];then
	echo "Largest number is "$b
else
	echo "Largest number is "$c
fi
