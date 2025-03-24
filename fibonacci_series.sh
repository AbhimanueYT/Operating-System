#!/bin/bash
echo "Enter the number"
read n
echo "Fibonacci series"
a=0
b=1
echo $a
r=$(($a+$b))
echo $r
for((i=0;i<n;i++)){
	a=$r
	echo $a
	r=$(($a+$b))
	b=$a
}
