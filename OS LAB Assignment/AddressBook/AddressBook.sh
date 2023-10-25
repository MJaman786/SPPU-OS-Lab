#!/bin/sh

create() {
    echo ""
    read -p "-> Enter name for address book : " abname
    result=$(ls | grep "$abname" | wc -w)
    if [ $result -gt 0 ]; then
        echo "-> Book already exists"
    else
        touch "$abname"
        echo "-> Book created with the name '$abname'"
    fi
}

insert() {
    echo ""
    read -p "Enter name of the book : " abname
    result=$(ls | grep "$abname" | wc -w)
    if [ $result -gt 0 ]; then
        echo "-> Book found"
        read -p "Enter phone number : " phone
        res=$(cat "$abname" | grep "$phone" | wc -w)
        if [ $res -gt 0 ]; then
            echo "-> ERROR: Record already exists"
        else
            echo "Enter information : "
            read -p "1. Enter full name : " name
            read -p "2. Enter email : " email
            read -p "3. Enter phone number : " number
            echo "Full Name: $name | Email: $email | Phone Number: $number" >> "$abname"
        fi
    else
        echo "-> Book not found"
    fi
}

modify() {
    echo ""
    read -p "Enter name of the book: " abname
    result=$(ls | grep "$abname" | wc -w)
    
    if [ $result -gt 0 ]; then
        echo "-> Book found"
        read -p "Enter the phone number of the contact you want to modify: " phone
        res=$(cat "$abname" | grep "$phone" | wc -w)
        
        if [ $res -gt 0 ]; then
            echo "Enter new information for the contact:"
            read -p "1. Enter full name: " new_name
            read -p "2. Enter email: " new_email
            read -p "3. Enter phone number: " new_number
            
            # Use sed to modify the contact information in the address book
            sed -i "/$phone/c $new_name | $new_email | $new_number" "$abname"
            echo "Contact modified successfully."
        else
            echo "-> ERROR: Contact not found in the address book"
        fi
    else
        echo "-> Book not found"
    fi
}

display() {
    echo ""
    read -p "Enter the book name : " abname
    result=$(ls | grep "$abname" | wc -w)
    if [ $result -gt 0 ]; then
        echo "-> Book found"
        cat "$abname"
    else
        echo "-> Book not found"
    fi
}

while true; do
    echo "----------- MENU ------------"
    echo "1. Create"
    echo "2. Insert"
    echo "3. Modify"
    echo "4. Display"
    echo "5. Exit"
    echo ""
    read -p "Enter your choice : " choice

    case $choice in
        1) create ;;
        2) insert ;;
        3) modify ;;
        4) display ;;
        5) exit ;;
        *) echo "Invalid option" ;;
    esac
done

<<COMMENT
	#output:
	
aman@aman-Latitude-E5470:~$ ./a.sh
----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Display
5. Exit

Enter your choice : 1

-> Enter name for address book : ABCD
-> Book created with the name 'ABCD'
----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Display
5. Exit

Enter your choice : 2

Enter name of the book : ABCD
-> Book found
Enter phone number : 123
Enter information : 
1. Enter full name : Aman Munir Mujawar
2. Enter email : aman@gmail.com
3. Enter phone number : 123456
----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Display
5. Exit

Enter your choice : 4

Enter the book name : ABCD
-> Book found
Full Name: Aman Munir Mujawar | Email: aman@gmail.com | Phone Number: 123456
----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Display
5. Exit

Enter your choice : 3

Enter name of the book: ABCD
-> Book found
Enter the phone number of the contact you want to modify: 123456
Enter new information for the contact:
1. Enter full name: Ayan Munir Mujawar
2. Enter email: ayan@gmail.com
3. Enter phone number: 123123
Contact modified successfully.
----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Display
5. Exit

Enter your choice : 4

Enter the book name : ABCD
-> Book found
Ayan Munir Mujawar | ayan@gmail.com | 123123
----------- MENU ------------
1. Create
2. Insert
3. Modify
4. Display
5. Exit

Enter your choice : 5
aman@aman-Latitude-E5470:~$ 

COMMENT
