#include <stdio.h>
#include <string.h>

int front = -1;
int rear = -1;
int size;
void ENQUEUE (int arr[]){
    int data;
    printf ("\nEnter the value to be ENQUEUED");
    scanf  ("%d", &data);
    if (((front == 0) && (rear = size))||(front = rear + 1)){
        printf ("\n The Queue is full."); 
    }

    else{
        if (rear == -1){
            rear++;
            front++;
            arr[rear] = data;
        }
        else if (rear == size) {
            rear = 0;
            arr[rear] = data;
        }
        else {
            rear = rear + 1;
            arr[rear] = data;
        }
    }
}

void DEQUEUE (int arr []){
    if (front == -1){
        printf ("\nThe Queue is empty");
    }
    else {
        printf ("\nThe deleted element is: %d", arr[front]);
        if (front == rear){
            front = -1;
            rear = -1;
        }

        else if (front == size){
            front = 0;
        }

        else {
            front++;
        }

    }
}

void DISPLAY(int arr[]){
    int n = front;
    if (front == -1){
        printf ("\nThe queue is empty")
    }
    else{
        while (n != rear){
            printf ("\n%d", arr[n]);
            if (n == size){
                n = 0;
            }
            else {
                n++;
            }
        }
    }
    

}
//Main function
void main(){
    /*Taking user input on Queue requirements*/
    printf("Please enter the size of the Queue required: ");
    scanf("%d", &size);
    size = size -1;
    int array [size];
    /*Usage instruction for user*/
    printf("\nTo ENQUEUE type '1'");
    printf("\nTo DEQUEUE type '2'");
    printf("\nTo display queue '3'");
	printf("\nTo END the program type '4'");
    int checker = 0;
    int choice;
    while (checker == 0){
        printf ("\nPlease enter the operation to be performed on the Queue:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ENQUEUE(array);
            break;

        case 2:
            DEQUEUE(array);
            break;

        case 3:
            DISPLAY(array);
            break;
        
        case 4:
            checker = 1;
            break;
        
        default:
            printf ("\nIncorrect Choice entered.");
            break;
        }
    }
