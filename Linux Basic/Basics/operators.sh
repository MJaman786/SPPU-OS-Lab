#############################################
#		Add					>> 		+		#
#		Substraction		>> 		-		#
#		Multiplication		>>		*		#
#		Division			>>		/		#
#		Modulus				>>		%		#
#		Exponent			>>		**		#
#############################################

#!/bin/bash

read -p "Enter two numbers = " num1 num2
add=$(($num1 + $num2))
echo "Addition of two numbers = " $add
echo
read -p "Enter two numbers = " num1 num2
sub=$(($num1 - $num2))
echo "Subtraction of two numbers = " $sub
echo
read -p "Enter two numbers = " num1 num2
mul=$(($num1 * $num2))
echo "Multiplication of two numbers = " $mul
echo
read -p "Enter two numbers = " num1 num2
div=$(($num1 / $num2))
echo "Division of two numbers = " $div
echo
read -p "Enter two numbers = " num1 num2
mod=$(($num1 % $num2))
echo "Modulus of two numbers = " $mod
echo
read -p "Enter two numbers = " num1 num2
mod=$(($num1 ** $num2))
echo "Exponent of two numbers = " $mod

