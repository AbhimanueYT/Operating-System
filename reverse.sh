#!/bin/bash
read -p "String = " a
rev=""
for ((i=${#a};i>=0;i--));do
	rev=$rev${a:i:1}
done
echo "Reverse "$rev
