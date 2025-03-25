#!/bin/bash
read -p "Enter the values " -a arr
for ((i=0;i<${#arr[@]}-1;i++));do
	for ((j=0;j<${#arr[@]}-i-1;j++));do
		if [ ${arr[j]} -gt ${arr[j+1]} ];then
			t=${arr[j]}
			arr[j]=${arr[j+1]}
			arr[j+1]=$t
		fi
	done
done
echo "Sorted "${arr[@]}
