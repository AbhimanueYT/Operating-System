#!/bin/bash
read -p "String = " a
rev=""
for ((i=${#a};i>=0;i--));do
	rev=$rev${a:i:1}
done
if [ $rev = $a ];then
	echo "Palindrome"
else
	echo "Nope"
fi
