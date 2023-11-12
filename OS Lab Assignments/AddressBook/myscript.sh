create(){
	read -p "Enter book name : " ab
	if [ -f "$ab.txt" ]; then
		echo "Book already exist..."
	else
		touch "$ab.txt"
		echo "Book created..."
	fi
}

insert(){
	read -p "Enter book name : " ab
	if [ -f "$ab.txt" ]; then
		read -p "-> Enter phonenumber : " phone
			if grep -q "$phone" "$ab.txt"; then
				echo "Contac already exist"
			else
				read -p "-> Enter name : " name
				read -p "-> Enter address :" address
				echo " ">> "$ab.txt"
				echo "[Name : $name | Phone : $phone | Address : $address]" >> "$ab.txt"
			fi
	else
		echo "Book not found"
	fi
}

modify(){
    read -p "Enter book name: " ab
    if [ -f "$ab.txt" ]; then
        read -p "Enter phone number : " old_phone
        if grep -q "$old_phone" "$ab.txt"; then
            read -p "-> Enter new name : " new_name
            read -p "-> Enter new phone : " new_phone
            read -p "-> Enter new address : " new_address
            sed -i "/$old_phone/c [Name : $new_name | Phone : $new_phone | Address : $new_address]" "$ab.txt"
        else
            echo "Contact not found."
        fi
    else
        echo "Book not found."
    fi
}


delete(){
	read -p "Enter book name : " ab
		if [ -f "$ab.txt" ];then
			read -p "Enter phonenumber : " phone
				if grep -q "$phone" "$ab.txt";then
					sed -i "/$phone/d" "$ab.txt"
				else
					echo "Contac not found"
				fi
		else 
			echo "Book not found"
		fi
}

display(){
	read -p "Enter book name : " ab
	if [ -f "$ab.txt" ]; then
		cat "$ab.txt"
	else
		echo "Book not found"
	fi
}


while [ 1 ];
do
	echo "-------- Menu ----------"
	echo "1.CREATE"
	echo "2.INSERT"
	echo "3.MODIFY"
	echo "4.DELETE"
	echo "5.DISPLAY"
	echo "6.Exit"
	echo " "
	read -p "Enter your choice : " choice
	case $choice in
		1)create ;;
		2)insert ;;
		3)modify ;;
		4)delete ;;
		5)display ;;
		6)exit ;;
		*)echo "Enter valid option"
	esac
done 

<<

------------ output --------------

aman@aman-Latitude-E5470:~$ ./myscript.sh
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 1
Enter book name : addressbook
Book created...
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 2
Enter book name : addressbook
-> Enter phonenumber : 10001
-> Enter name : AMAN
-> Enter address :PUNE
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 5
Enter book name : addressbook
 
[Name : AMAN | Phone : 10001 | Address : PUNE]
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 3
Enter book name: addressbook
Enter phone number : 10001
-> Enter new name : AYAN
-> Enter new phone : 10002
-> Enter new address : PUNE
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 5
Enter book name : addressbook
 
[Name : AYAN | Phone : 10002 | Address : PUNE]
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 4
Enter book name : addressbook
Enter phonenumber : 10002
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 5
Enter book name : addressbook
 
-------- Menu ----------
1.CREATE
2.INSERT
3.MODIFY
4.DELETE
5.DISPLAY
6.Exit
 
Enter your choice : 6
aman@aman-Latitude-E5470:~$ 
>>
