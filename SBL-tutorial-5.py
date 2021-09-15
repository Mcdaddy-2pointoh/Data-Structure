# Version: v 1.0.0
# Problem Statement: Binary Search
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
    for i in range(0, size, 1):
        if ((i + 1) % 10 == 1) and ((i + 1) % 100 != 11):
            ordinal = "st"

        elif ((i + 1) % 10 == 2) and ((i + 1) % 100 != 12):
            ordinal = "nd"

        elif ((i + 1) % 10 == 3) and ((i + 1) % 100 != 13):
            ordinal = "rd"

        else:
            ordinal = "th"

        try:
            array[i] = int(input(f"Enter the {i + 1}{ordinal} element: "))

        except ValueError:
            print("The value of element submitted is not an integer. Please re-format the array")
            break

    # Select a number to find
    try:
        number = int(input("Enter the number to find: "))

    except ValueError:
        print("The value submitted as the size of the array is not an integer")
        break

    for i in range(0, len(array), 1):
        a = i
        b = -(i+1)
        if array[a] == number:
            print(f'The number {number} was found on index {a} in the array')
            number = False
            x = False
            break

        elif array[b] == number:
            print(f'The number {number} was found on index {len(array) + b} in the array')
            number = False
            x = False
            break

    if (number):
        print('Number not found')

