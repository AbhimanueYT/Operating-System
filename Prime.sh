#!/bin/bash
read -p "Enter the value " n
f=0
for ((i=1;i<=n/2;i++)) {
	if [ $((n%i)) -eq 0 ];then
		f=$((f+1))
	fi
}
if [ $f -gt 1 ];then
	echo "Nope"
else
	echo "Prime"
fi
