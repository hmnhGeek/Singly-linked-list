#include<stdio.h>
#include<stdlib.h>

// define a structure for singly linked list. //
typedef struct node{
    int data;
    struct node *next;
}linked;

// Initialise head pointer as an instance. //
linked *head = NULL;

void insert( int item ){
    /* First check if head is NULL, because if it is then you have
    to first initialise head. */
    if( head == NULL ){
        head = ( linked * )malloc( sizeof( linked ) );
        head -> data = item;
        head -> next = NULL;
    }
    else{
        /* Now if head is not null, then there is a totally different strategy
        to insert an element. For this initialise a pointer temp to traverse the
        whole list. */
        linked *temp;
        temp = head;
        linked *prev; // pointer to store the previous temp value after temp is updated. //

        // Initialise the while loop. //
        while( temp != NULL ){
            prev = temp;
            temp = temp -> next;
        }

        // Now prev has the address of last node. //
        /* We now must create a new random node containing our item.
        Then we must link this node to prev's next. */

        linked *var;
        var = ( linked * )malloc( sizeof( linked ) );
        var -> data = item;
        var -> next = NULL;
        prev -> next = var;

        // Now the element is inserted. //
    }
    printf("Element is inserted.\n");
} // End of insert() function. //

void delete( int item ){
    /* This function will become complicated, so be with the flow.
    First we will check if the list is empty or not. */
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        /* Now we must check if the element going to be deleted is the
        very first node. But before that we must initialise pointer temp
        to type linked. */
        linked *temp;
        temp = head;

        // Also initialise pointer prev to hold address of previous node. //
        linked *prev;

        // Now start the while() loop. //
        while( temp != NULL ){
            if( temp -> data == item ){
                // Now check if this founded element is at very first position. //
                if( temp == head ){
                    head = head -> next;
                    linked *temp1 = temp;
                    temp = head;
                    free( temp1 );
                    // This process will go on till the temp reaches NULL, i.e. the last element. //
                    // We must use continue to stop program to go to temp = temp -> next.
                }
                else{
                    // Now previous node's next must contain temp -> next, since temp is going to be//
                    // freed. //
                    prev -> next = temp -> next;
                    // Again initialise temp with head. //
                    linked *temp1 = temp;
                    temp = head;
                    free( temp1 );
                }
            }
            else{
                prev = temp;
                temp = temp -> next;
            }
        }
        printf("Elemeents deleted.\n");
    }
} // End of delete() function. //

void display(){
    // This is a very simple function. //
    // Initialise a temp pointer to traverse the whole list. //
    linked *temp;
    temp = head;

    // Check if head is NULL. //
    if( head == NULL ){
        printf("The linked list is empty.\n");
    }
    else{
        while( temp != NULL ){
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
    }
} // End of display() function. //

void search( int item ){
    /* First check if the list is empty or not. */
    if( head == NULL ){
        printf("List is empty.\n");
    }
    else{
        // Initialise a temp pointer to traverse the whole list. //
        linked *temp;
        temp = head;

        // Also initialise index variable to print indexes. //
        int index = -1;

        while( temp != NULL ){
            index += 1;
            if( temp -> data == item ){
                printf("Item found at %d.\n", index);
            }
            temp = temp -> next;
        }
        if( index == -1 ){
            printf("Element not found. \n");
        }
    }
} // End of search() function. //

void main(){
    /* To make a menu driven program, initialise
    an integer variable ch = 1. */
    int ch = 1;

    while( ch == 1 ){
        printf("Enter 1 to insert.\n");
        printf("Enter 2 to delete.\n");
        printf("Enter 3 to display.\n");
        printf("Enter 4 to search an element.\n");
        printf("Enter 5 to exit.\n");

        // initialise a choice variable. //
        int x;
        printf("Enter your choice: ");
        scanf("%d", &x);

        if( x == 1 ){
            // Take the item from the user. //
            int item;
            printf("Enter the item: ");
            scanf("%d", &item);

            // Now make a call to insert() function. //
            insert( item );
        }
        else if( x == 2 ){
            // Take the item to be deleted from the user. //
            int item;
            printf("Enter the item to be deleted: ");
            scanf("%d", &item);

            // Now make a call to delete() function. //
            delete( item );
        }
        else if( x == 3 ){
            // Here simply make a call to display() function. //
            display();
        }
        else if( x == 4 ){
            // Take the element from the user to search. //
            int item;
            printf("Enter the item to be searched: ");
            scanf("%d", &item);

            // Now make a call to search() function. //
            search( item );
        }
        else if( x == 5 ){
            // Change ch = 0 to halt the while loop. //
            ch = 0;
        }
        else{
            printf("Invalid choice. \n");
        }
    }
} // End of main() function. //
