# Version: v 1.0.0
# Problem Statement: Array Spliting from user
# Developed by: Sharvil Dandekar

x = True

while x:

    # Creation of Array
    try:
        size = int(input("Enter the size of the array: "))

    except ValueError:
        print("The value submitted as the size of the array is not an integer")
        break

    array = [None] * size
    for i in range (0, size, 1):
        if ((i+1) % 10 == 1) and ((i+1) % 100 != 11):
            ordinal = "st"

        elif ((i+1) % 10 == 2) and ((i+1) % 100 != 12):
            ordinal = "nd"

        elif ((i+1) % 10 == 3) and ((i+1) % 100 != 13):
            ordinal = "rd"

        else:
            ordinal = "th"

        try:
            array[i] = int(input(f"Enter the {i+1}{ordinal} element: "))

        except ValueError:
            print("The value of element submitted is not an integer. Please re-format the array")
            break

    # Array Split
    try:
        split = int(input("Enter the splitting of the array: "))
        if split >= len(array):
            print("The value of integer is out of index")
            break

    except ValueError:
        print("The value submitted as the size of the array is not an integer")
        break

    array1 = array[:split]
    array2 = array[split:]
    print(array1)
    print(array2)

    # Menu
    try:
        choice = int(input("Choose:\n1: To Continue with a new array\n2: To Exit\n"))
        if choice == 1:
            x = True

        elif choice == 2:
            x = False

        else:
            print("Invalid type use an integer value.")

    except ValueError:
        print("Invalid type use an integer value.")
        break