#!/bin/bash
echo "Enter the elements"
read -a arr
sort_arr=($(printf "%s\n" "${arr[@]}"| sort -n))
echo "Sorted array:${sort_arr[@]}"
