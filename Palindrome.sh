#!/bin/bash
read -p "Enter the value " n
og=$n
rev=0
while [ $n -gt 0 ];do
	rev=$((rev*10+$((n % 10))))
	n=$((n/10))
done
if [ $rev -eq $og ];then
	echo "Palindrome"
else
	echo "Nope"
fi
