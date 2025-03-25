#!/bin/bash
read -p "Path = " p
if [ ! -f $p ];then
	echo "Nope"
else
	read -p "word = " w
	echo -n "Number of times is "
	grep -ow $w $p | wc -l
fi
