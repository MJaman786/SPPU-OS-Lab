#!/bin/sh

create(){
	read -p "Enter name of the book : " ab
	res=$(ls | grep $ab | wc -w)
	if [ $res -gt 0 ]; then
		echo "Book already exixt"
	else
		touch $ab.txt
		echo "Book name '$ab' created"
	fi	
}

insert(){
	echo ""
	read -p "Enter the name of book : " ab
	res=$(ls | grep $ab | wc -w)
	if [ $res -gt 0 ]; then
		echo " Book have found "
		read -p "-> Enter name    = " name
		read -p "-> Enter gmail   = " gmail
		read -p "-> Enter address = " address
		echo "" >> $ab
		echo "[Name = '$name' | Gmail = '$gmail' | Address = '$address']" >> $ab
		echo "Contact has added in book..."
	else
		echo "Book not found"
	fi
	
}

modify(){
	read -p "Enter name of book : " ab;
	res=$(ls | grep $ab | wc -w)
	if [ $res -gt 0 ]; then
		echo "Book found"
	
		read -p "Enter gmail for modification : " gmail
		res1=$(cat $ab | grep $gmail | wc -w)
		if [ $res1 -gt 0 ]; then
			echo "Enter new information"
			read -p "1. Enter name : " new_name
			read -p "2. Gmail      : " new_gmail
			read -p "3. Address    : " new_address
			
			sed -i "/$gmail/c [Name = '$new_name' | gmail = '$new_gmail' | address = '$new_address']" $ab
		else
			echo "profile not found"
		fi
	else
		echo "Book not found"
	fi
}

delete(){

	echo ""
	read -p "Enter name of the book : " ab
	res=$(ls | grep $ab | wc -w)
	if [ $res -gt 0 ]; then
		echo "Book found"
		read -p "Enter gmail for deleting contac : " dgmail
		res2=$(cat $ab | grep $dgmail | wc -w)
		if [ $res2 -gt 0 ]; then
			echo ""
			sed -i "/$dgmail/d" "$ab"
			echo "Contac is deleted"
		else
			echo "Contac not found"
		fi		
	else
		echo "Book not found"
	fi
}

display(){
	echo ""
	read -p "Enter name of the book : " ab
	res=$(ls | grep $ab | wc -w) 
	if [ $res -gt 0 ]; then
		echo "Book found"
		echo "Content in file : "
		cat $ab
	else
		echo "Book Not found"
	fi
}

while [ true ]
do
	echo ""
	echo "----------- MENU ------------"
	echo "1. Create"
	echo "2. Insert"
	echo "3. Modify"
	echo "4. Delete"
	echo "5. Display"
	echo "6. Exit"
	echo " "
	read -p "Enter your choice : " choice
	
	case $choice in
		1) create ;;
		2) insert ;; 
		3) modify ;;
		4) delete ;;
		5) display ;;
		6) exit ;;
		
		*) echo "Enter valid option";;
		
	esac
		
done
	 
<<COMMENTS
aman@aman-Latitude-E5470:~$ ./aman.sh

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 1
Enter name of the book : ABCD
Book name 'ABCD' created

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 2

Enter the name of book : ABCD
 Book have found 
-> Enter name    = aman
-> Enter gmail   = aman@gmail.com
-> Enter address = pune
Contact has added in book...

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 2

Enter the name of book : aditya
Book not found

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 2

Enter the name of book : ABCD
 Book have found 
-> Enter name    = aditya
-> Enter gmail   = aditya@gmail.com
-> Enter address = pimpri
Contact has added in book...

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 5

Enter name of the book : ABCD
Book found
Content in file : 

[Name = 'aman' | Gmail = 'aman@gmail.com' | Address = 'pune']

[Name = 'aditya' | Gmail = 'aditya@gmail.com' | Address = 'pimpri']

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 3
Enter name of book : ABCD
Book found
Enter gmail for modification : aman@gmail.com
Enter new information
1. Enter name : ayan
2. Gmail      : ayan@gmail.com
3. Address    : pune

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 5

Enter name of the book : ABCD
Book found
Content in file : 

[Name = 'ayan' | gmail = 'ayan@gmail.com' | address = 'pune']

[Name = 'aditya' | Gmail = 'aditya@gmail.com' | Address = 'pimpri']

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 4

Enter name of the book : ABCD
Book found
Enter gmail for deleting contac : ayan@gmail.com

Contac is deleted

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 5

Enter name of the book : ANCD
Book Not found

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice : 5

Enter name of the book : ABCD
Book found
Content in file : 


[Name = 'aditya' | Gmail = 'aditya@gmail.com' | Address = 'pimpri']

----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Delete
5. Display
6. Exit
 
Enter your choice :   


COMMENTS
