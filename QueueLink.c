#include <stdio.h>
#include <stdlib.h>

typedef struct node{//typedef to create a user defined data type
    int data;
    struct node * link;
}node;

node * head  = NULL; //Initializing the value of head to NUll

//ENQUEUE
node * ENQUEUE(int value){
    node * temp;//stores data for new node
    node * traverse;//acts as pointer for traversal
    temp = (node *) malloc (sizeof(struct node));
    temp -> data = value;
    if (head == NULL){ // For an empty list
            temp ->link = head;
            return temp;
        }
    else{//For an existing list
        traverse = head;
        while (traverse ->link != NULL){
            traverse = traverse ->link;
        }
        traverse ->link = temp;
        temp -> link = NULL;
        return head;
    }
}

//DEQUEUE
int DEQUEUE(){
    if (head == NULL){
        printf ("The list is empty");
        return 0;
    }
    else{
        node * p = head;
        printf ("\nThe removed element is: %d", p->data);
        head = p ->link;
        free (p);
    }
}

//Display
void DISPLAY(){//Function to display
    node* p = head;
    while (p != NULL){
        printf ("%d ->", p->data);
        p = p->link;
    }
    
}

//Main function
void main(){
    int x = 0;
    while (x == 0){
        int choice, info;
        printf("\nEnter the operation code to perform: ");
        printf("\n1: ENQUEUE");
        printf("\n2: DEQUEUE");
        printf("\n3: DISPLAY");
        printf("\n4: END\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf ("\nEnter the data to be pushed: ");
                scanf ("%d", &info);
                head = ENQUEUE(info);
                break;

            case 2:
                DEQUEUE();
                break;

            case 3:
                DISPLAY();
                break;

            case 4:
                x =1;
                break;

            default:
                printf ("\nENTER a valid CHOICE");
                break;
        }

    }
}