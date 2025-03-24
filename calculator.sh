#!/bin/bash
while true
do
  echo "1)Add
  2)Sub
  3)Mul
  4)Div
  5)Exit"
  read x
  if [ $x -eq 5 ];then
    echo "Exiting..."
    break
  fi
  echo "Enter first number:"
  read a
  echo "Enter second number:"
  read b
  case $x in
    1) r=$(($a+$b))
      echo "Result: "$r
      ;;
    2) r=$(($a-$b))
      echo "Result: "$r
      ;;
    3) r=$(($a*$b))
      echo "Result: "$r
      ;;
    4)
      if [ $b -eq 0 ];then
        echo "Not possible"
      else
        r=$(($a/$b))
        echo "Result: "$r
      fi
      ;;
    *) echo "Invalid"
    ;;
  esac
done
