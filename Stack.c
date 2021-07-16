#include <stdio.h>
#include <string.h>
//All function formal declaration
int push(int arr[], int head, int info);
int pop(int arr[], int head);
int peep(int arr[], int head);
int change(int arr[], int head);
int display(int arr[], int head);

//Main function
void main(){
    int size = 0, top = -1, data;
	
    /*Taking user input on stack requirements*/
    printf("Please enter the size of the stack required: ");
    scanf("%d", &size);
    int array [size];
    
    /*Usage instruction for user*/
    printf("\nTo PUSH type '1'");
    printf("\nTo POP type '2'");
    printf("\nTo PEEP type '3'");
    printf("\nTo CHANGE type '4'");
	printf("\nTo DISPLAY the entire array type '5'");
	printf("\nTo END the program type '6'");
    int checker = 0;
    int choice;
    /*While loop is used to run the operations over and over again without restarting 
    the program*/
    while (checker == 0){
        printf ("\nPlease enter the operation to be performed on the stack:");
        scanf("%d", &choice);
		
		//Function call for PUSH
		if(choice == 1){
			
			//Overflow condition result
			if (top >= size){
				printf("\nThe stack is FULL, OVERFLOW condition attained.");
			}

			//Normal PUSH condition result
			else {
				printf ("\nPlease enter the DATA to be PUSHED onto the STACK: ");
				scanf("%d", &data);
				top = push(array, top, data);
			}
			checker = 0;
		}
		
		//Function call for POP
		else if(choice == 2){
			
			//UNDERFLOW condition result
			if (top < 0){
				printf("\nThe stack is EMPTY, UNDERFLOW condition attained.");
			}
			
			//Normal POP condition result
			else {
				top = pop(array, top);
			}
			checker = 0;
		}
		
		//Function call for PEEP
		else if(choice == 3){
			//UNDERFLOW condition result
			if (top < 0){
				printf("\nThe stack is EMPTY, UNDERFLOW condition attained.");
			}
			
			//Normal PEEP condition result
			else{
				peep (array, top);
			}
		}
		
		//Function call for CHANGE
		else if(choice == 4){
			//UNDERFLOW condition result
			if (top < 0){
				printf("\nThe stack is EMPTY, UNDERFLOW condition attained.");
			}
			
			//Normal CHANGE condition result
			else{
				change(array, top);
			}
		}
		
		//Function call to DISPLAY
		else if(choice == 5){
			if (top == -1){
			    printf("\nThe stack is EMPTY, UNDERFLOW condition attained.");
			}
			else{
				display(array, top);
			}
		}
		
		//Case to end the program and exit the loop
		else if(choice == 6){
			printf("\nThankyou, BYE BYE HOOMAN");
			checker = 1;
		}
		
		//Default error message
		else{
			printf("\nYour input was INVALID please try a VALID input.");
		}
	}    
}


//PUSH function
int push(int arr[], int head, int info){
	//The top pointer goes to point the next empty block
	head++;
	
	//Info is stored in the next block
	arr[head] = info;
	
	//The new top value is returned
	return head;
}

//POP function
 int pop(int arr[], int head){
	//The top pointer goes to the previos filled block
	printf ("\nThe popped element has value: %d", arr[head]);
	
	//The top pointer goes to the previos filled block
	head--;
	
	//The new top value is returned
	return head; 
}

//PEEP function
int peep(int arr[], int head){
	//Position integer declaration
	int pos, data;
	
	//Taking user input for the position to peek
	printf("\nPlease enter the position from the top of the stack [Top = %d] at which you want to peek:  ", head + 1);
	scanf("%d", &pos);
	
	//Default error statement
	if ((pos > head)||(pos < 0)){
		printf("\nPlease enter valid value for the position to access");
	}
	
	//Printing out the value to peek
	else{
		pos = head - pos + 1;
		data = arr[pos];
		printf ("\nThe value you intend to peep is: %d", data);
	}
	return 0;
}

//CHANGE function
int change(int arr[], int head){
	//Position integer declaration.
	int pos, data;
	
	//Taking user input for the position to change
	printf ("\nPlease Enter the position from the top of the stack [Top = %d] at which you want to edit:  ", head +1);
	scanf ("%d", &pos);
	
	//Default error statement
	if ((pos > head)||(pos < 0)){
		printf("\nPlease enter valid value for the position to access");
	}
	
	//Changing the desired value
	else{
	    pos = head - pos + 1;
		printf("\nPlease enter the data that must be changed: ");
		scanf ("%d", &data);
		arr[pos] = data;
	}
	return 0;
}

//DISPLAY function
int display(int arr[], int head){
	int x = head;
	printf("The stack is in the following condition: ");
	while (x >= 0){
		printf("\n%d", arr[x]);
		x--;
	}
	return 0;
}		