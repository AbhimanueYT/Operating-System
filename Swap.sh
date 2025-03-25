#!/bin/bash
read -p "A = " a
read -p "B = " b
t=$a
a=$b
b=$t
echo "Swap"
echo "A = "$a
echo "B = "$b
