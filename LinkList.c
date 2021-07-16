
#include <stdio.h>
#include <stdlib.h>

typedef struct node{//typedef to create a user defined data type
    int data;
    struct node * link;
}node;

node * head  = NULL; //Initializing the value of head to NUll

node * ADD(int value){
    int choice;
    int info;
    node * temp;//stores data for new node
    node * traverse;//acts as pointer for traversal
    printf ("\nSELECT the type of entry:");
    printf ("\n1: Entry at front.");
    printf ("\n2: Entry at rear.");
    printf ("\n3: Entry after an element.\n");
    temp = (node *) malloc (sizeof(struct node));
    temp -> data = value;
    scanf ("\n%d", &choice);
    if (choice == 1){//For an existing list at front
        temp ->link = head;
        return temp;
    }
    
    else if (choice == 2){//For a list at rear
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
    
    
    else if (choice == 3){
        traverse = head;
        if(traverse == NULL){
                temp ->link = head;
                head = temp;
                return head;
        }
        else{
            printf ("\nEnter the data element to be added after: \n");
            scanf ("%d", &info);
            traverse = head;
            while (traverse != NULL){
                if (traverse -> data == info){
                    temp -> link = traverse ->link;
                    traverse -> link = temp;
                    return head;
                }
                traverse = traverse->link;
            }
            printf ("The given element does not exist in the list.");
            return head;
        }
    }
    else {//DEFAULT output
        printf ("\n Wrong code input. PLEASE TRY AGAIN.");
    }
}

node* DELETE(){
    
    if (head == NULL){
        printf ("The list is empty");
        return NULL;
    }
    else{
        int choice, info, del;
        node * p = head;
        node * q;
        printf ("\nSELECT the type of deletion: ");
        printf ("\n1 : Deletion at front.");
        printf ("\n2 : Deletion at rear");
        printf ("\n3 : Deletion by element.\n");
        scanf ("%d", &choice);
        
        if (choice == 1){
            printf ("\nThe removed element is: %d", p->data);
            head = p ->link;
            free (p);
            return head;
        }

        else if (choice == 2){
            while (p -> link != NULL){
                    if ((p -> link) -> link == NULL){
                        q = p;
                    }
                    p = p -> link;
                }
            printf ("\nThe removed element is: %d", p->data);
            q -> link = NULL;
            free (p);
            return head;
        }
        else if (choice == 3){
            printf ("\nEnter the data element to be deleted: \n");
            scanf ("%d", &del);
            p = head;
            while (p -> link != NULL){
                if ((p->link)->data == del){
                    p -> link = (p ->link)-> link;
                    p = p -> link;
                    printf ("\nThe removed element is: %d", p->data);
                    free (p);
                    return head;
                }
                p = p-> link;        
            }
            printf ("\nThis element does not exist in the list.");
            return head;
        }

        else{
            printf ("\nENTER a valid choice");
            return head;
        }

    }    
}

void DISPLAY(){//Function to display
    node* p = head;
    while (p != NULL){
        printf ("%d ->", p->data);
        p = p->link;
    }
    
}

void  main(){
    int x = 0;
    //The menu driven list
    while (x == 0){
        int choice, data;
        printf ("\nEnter the operation to PERFORM");
        printf ("\n1: INSERT");
        printf ("\n2: DELETE");
        printf ("\n3: DISPLAY\n");
        scanf ("%d", &choice);
        switch (choice){
            case 1:
                printf ("\nEnter the data to be input: ");
                scanf ("%d", &data);
                head = ADD(data); //calling the function to add
                break;

            case 2:
                DELETE(); //calling the function to delete
                break;

            case 3:
                DISPLAY();//calling the function to display
                break;
            
            default:
                printf ("Incorrect choice please enter valid choice.");//default code
                break;
        }
    }
}