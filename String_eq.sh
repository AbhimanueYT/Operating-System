#!/bin/bash
read -p "String 1 = " a
read -p "String 2 = " b
if [ $a = $b ];then
	echo "Same"
else
	echo "Nope"
fi
