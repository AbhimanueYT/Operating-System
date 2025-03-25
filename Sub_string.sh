#!/bin/bash
read -p "String = " a
read -p "Substring = " b
a_size=${#a}
b_size=${#b}
f=0
for ((i=0;i<=a_size-b_size;i++));do
	if [ ${a:i:b_size} = $b ];then
		f=1
	fi
done
if [ $f -gt 0 ];then
	echo "Found"
else
	echo "Nope"
fi
