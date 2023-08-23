<<COMMENT
for ((i=0; i<=10; i++));
	do
		echo "Number = $i"
	done
	
# Infinite Loop	
while :
	do
		*code*
	done
COMMENT

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
	
while :
	do
		echo "1.Add two numbers"
		echo "2.Subtract two numbers"
		echo "3.Multiply two numbers"
		echo "4.Divide two numbers"
		 
		read -p "Enter you choice = " ch

		case $ch in
			1)add;;
			2)sub;;
			3)mult;;
			4)div;;
			*)echo "Invalid input"
esac		
		echo
	done
