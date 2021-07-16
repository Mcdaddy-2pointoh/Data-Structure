#include <stdio.h>
#include <stdlib.h>
typedef struct node{//typedef to create a user defined data type
    int data;
    struct node * link;
}node;

node * head  = NULL;

//Function to push

node * PUSH(int value){
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

//Function to POP

int POP(){
    if (head == NULL){
        printf ("The list is empty.");
        return 0;
    }

    else{
        node * p = head;
        node * q;
        while (p -> link != NULL){
                    if ((p -> link) -> link == NULL){
                        q = p;
                    }
                    p = p -> link;
                }
            printf ("\nThe removed element is: %d", p->data);
            q -> link = NULL;
            free (p);
    }
}

//Function to VIEW

void DISPLAY(){
    node* p = head;
    while (p != NULL){
        printf ("%d ->", p->data);
        p = p->link;
    }
    
}


void main(){
    int x = 0;
    while (x == 0){
        int choice, info;
        printf("\nEnter the operation code to perform: ");
        printf("\n1: PUSH");
        printf("\n2: POP");
        printf("\n3: DISPLAY");
        printf("\n4: END\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf ("\nEnter the data to be pushed: ");
                scanf ("%d", &info);
                head = PUSH(info);
                break;

            case 2:
                POP();
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