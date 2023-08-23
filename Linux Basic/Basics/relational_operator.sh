
# -eq 	= 	equal to
# -ne 	= 	not equal to
# -gt 	= 	greater than
# -lt	= 	less than
# -ge	=   greater than  or equal to
# -le 	=   less than  or equal to

#!/bin/bash

read -p "Enter number : " num1
if [ $num1 -gt 10 ];
then 
	echo "Number $num1 >= 10"
	
elif [ $num1 -eq 10 ];
then
	echo "Number $num1 == 10"

else
	echo "Number $num1 < 10"

fi
