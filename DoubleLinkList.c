#include <stdio.h>
#include <stdlib.h>

typedef struct node{//typedef to create a user defined data type
    int data;
    struct node * next;
    struct node * previous;
}node;

node * head  = NULL; //Initializing the value of head to NUll

node* ADD(int info){
    int choice;
    node * new;
    node * check = head;
    new = (node *)malloc(sizeof(struct node));
    printf ("\nSELECT the type of entry:");
    printf ("\n1: Entry at front.");
    printf ("\n2: Entry at rear.\n");
    scanf ("\n%d", &choice);
    new -> data = info;
    
    //Adding at front
    if (choice == 1){
        new -> next = head;
        new -> previous = NULL;
        head = new;

    //Adding at rear
    }
    else if (choice == 2){
        if (head == NULL){
            new -> next = head;
            new -> previous = NULL;
            head = new;
        }

        else {
            while (check -> next != NULL){
                check = check -> next;
            }
            new -> previous = check;
            new -> next = NULL;
            check -> next = new;
            head = head;
        }
    }

    //Default
    else {
        printf ("Please enter a valid choice.");
    }
    return head;
}

void DELETE(){
    if (head == NULL){
        printf ("The list is empty.");
        return;
    }

    else{
        int choice, info;
        node * check = head;
        node * mark;
        printf ("\nSELECT the type of deletion: ");
        printf ("\n1 : Deletion at front.");
        printf ("\n2 : Deletion at rear");
        printf ("\n3 : Deletion by element.\n");
        scanf ("%d", &choice);
        if (choice == 1){// Deletion at front
            head = check ->next;
            head -> previous = NULL;
            info = check ->data;
            free(check);
        }

        else if (choice == 2){//Deletion at rear
            while (check -> next != NULL)
            {
                check = check ->next;            
            }
            (check -> previous) -> next = NULL;
            info = check -> data;
            free(check); 
        }
        
        else if (choice == 3){//Deletion by element
            printf ("\nEnter the element to delete: ");
            scanf ("%d", &info);
            if (head->data == info){
                check = head;
                head = head -> next;
                info = check ->data;
                printf ("\n%d is deleted from the list.", info);
                free(check);
                return;
            }
        
            else
            {
                while (check -> next != NULL){
                    if (check -> data == info){
                        mark = check -> previous;
                        mark -> next = check -> next;
                        mark = check ->next;
                        mark -> previous = check -> previous;
                        info = check -> data;
                        printf ("\n%d is deleted from the list.", info);
                        free (check);
                        return;
                    }
                    check = check -> next;
                }
                printf ("The element does not exist");
                return;
            }
        }
    }   
}

void DISPLAY(){
    node * check = head;
    do{
        printf ("%d ->", check->data);
        check = check->next;
    }while (check != NULL );
}


void  main(){
    int x = 0;
    int val;
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
                val = DELETE(); //calling the function to delete
                break;

            case 3:
                DISPLAY();//calling the function to display
                break;
            
            default:
                printf ("Incorrect choice please enter valid choice.");//default code
        }
    }
}
