#!/bin/bash
read -p "String = " a
read -p "Character = " b
f=0
for ((i=0;i<${#a};i++));do
	if [ $b = ${a:i:1} ];then
		f=$((f+1))
	fi
done
echo $f" times"
