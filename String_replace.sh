#!/bin/bash
read -p "String " a
read -p "Sub string " b
read -p "Replace " c
m=""
x=${#b}
for ((i=0;i<=${#a};i++));do
	if [ "${a:i:x}" = "$b" ];then
		m=$m$c
		i=$((i+x-1))
	else
		m=$m${a:i:1}
	fi
done
echo "String = "$m
