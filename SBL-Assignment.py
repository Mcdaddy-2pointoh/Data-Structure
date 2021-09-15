# Version: v 1.0.0
# Problem Statement: Use Multidimensional arrays as database. Add as much functionality of database as possible.
# Developed by: Sharvil Dandekar


data = []

x = True

while x:
    print("1. Create")
    print("2. Update")
    print("3. Read")
    print("4. Delete")
    print("5. Exit")
    option = int(input("Enter your operation: "))
    if option == 1:
        name = input("Enter your Name: ")
        section = input("Enter your Section: ")
        CGPA = input("Enter your CGPA: ")
        data.append([name, section, CGPA])

    elif option == 2:
        index = int(input("Enter the Roll Number to update: "))
        if index < len(data):
            name = input("Enter your Name: ")
            section = input("Enter your Section: ")
            CGPA = input("Enter your CGPA: ")
            data[index-1] = [name, section, CGPA]

        else:
            print("Invalid Index")

    elif option == 3:
        index = int(input("Enter the index to read: "))
        print(data[index-1])

    elif option == 4:
        index = int(input("Enter the index to delete: "))
        del data[index-1]

    elif option == 5:
        x = False