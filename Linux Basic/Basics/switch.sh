#!/bin/bash

add(){
	
	read -p "Enter two numbers = " num1 num2
	num=$((num1 + num2))
	echo "Addition = " $num
}

sub(){
	
	read -p "Enter two numbers = " num1 num2
	num=$((num1 - num2))
	echo "Subtraction = " $num
}

mult(){
	
	read -p "Enter two numbers = " num1 num2
	num=$((num1 * num2))
	echo "Multiplication = " $num
}

div(){
	
	read -p "Enter two numbers = " num1 num2
	num=$((num1 / num2))
	echo "Division = " $num
}

echo "1.Add two numbers"
echo "2.Subtract two numbers"
echo "3.Multiply two numbers"
echo "4.Divide two numbers"
 
read -p "Enter you choice = " ch

case $ch in
	1)echo
		add;;
	2)echo
		sub;;
	3)echo
		mult;;
	4)echo
		div;;
	*)echo "Invalid input"
esac
