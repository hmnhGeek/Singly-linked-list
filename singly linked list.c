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

void interchange( int index1, int index2 ){
    /* First check is list is empty or it contains only one element. */
    if( head == NULL || head -> next == NULL ){
        printf("Cna't exchange elements.\n");
    }
    else{
        /* If one of the index is zero. */
        if( index1 == 0 || index2 == 0 ){
            /* Now traverse the list. */
            
            int stmt1 = ( index1 == 0 );
            int stmt2 = ( index2 == 0 );
            
            if( stmt1 == 0 ){
                linked *temp = head;
                int pos = 0;
                while( temp != NULL ){
                    if( pos == index1 ){
                        int temp1 = temp -> data;
                        temp -> data = head -> data;
                        head -> data = temp1;
                        break;
                    }
                    else{
                        pos += 1;
                        temp = temp -> next;
                    }
                }
                if( temp == NULL ){
                    printf("You are out of bounds.\n");
                }
            }
            if( stmt2 == 0 ){
                linked *temp = head;
                int pos = 0;
                while( temp != NULL ){
                    if( pos == index2 ){
                        int temp1 = temp -> data;
                        temp -> data = head -> data;
                        head -> data = temp1;
                        break;
                    }
                    else{
                        pos += 1;
                        temp = temp -> next;
                    }
                }
                if( temp == NULL ){
                    printf("You are out of bounds.\n");
                }
            }
        }
        else{
            /* If the 0th index is not involved. */
            linked *temp1 = head;
            linked *temp2 = head;
            int pos1 = 0;
            int pos2 = 0;
            
            while( temp1 != NULL ){
                if( pos1 == index1 ){
                    break;
                }
                else{
                    pos1 += 1;
                    temp1 = temp1 -> next;
                }
            }
            while( temp2 != NULL ){
                if( pos2 == index2 ){
                    break;
                }
                else{
                    pos2 += 1;
                    temp2 = temp2 -> next;
                }
            }
            int temporary = temp1 -> data;
            temp1 -> data = temp2 -> data;
            temp2 -> data = temporary;
        }
    }
} // End of interchange() function. //

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

void insertmid( int item, int index ){
    // Check if index is >= 0. //
    if( index >= 0 ){
        // Check if head is null, cause if it is then simple insert() function will suffice. //
        if( head == NULL ){
            insert( item );
        }
        else{
            int pos = 0;
            // Now traverse the list untill pos == index. //
            linked *temp = head;
            linked *prev;
            while( temp != NULL ){
                if( pos == index ){
                    /* Here there are two cases. i) if index = 0, i.e. temp == head.
                    ii) or any other index. */
                    if( temp == head ){
                        // Store the item in a new random node. //
                        linked *var = ( linked * )malloc( sizeof( linked ) );
                        var -> data = item;
                        var -> next = head;
                        head = var;
                        // Inserted at position 0. //
                        break;
                    }
                    else{
                        // Take the new element at a random node. //
                        linked *var = ( linked * )malloc( sizeof( linked ) );
                        var -> data = item;
                        prev -> next = var;
                        var -> next = temp;
                        // Element inserted at any general position. //
                        break;
                    }
                }
                else{
                    pos += 1;
                    prev = temp;
                    temp = temp -> next;
                }
            }
            /* Now if temp has become null, that means user has entered
            an index which is out of range. So in this case just append the element
            to the last of the list. */
            if( temp == NULL ){
                insert( item );
            }
        }
    }
}

void delete_from_pos( int index ){
    // First check empty list condition. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        /* Now if the user wants to delete from position 0. */
        if( index == 0 ){
            // Take value of head in a temp pointer, so as to free it later. //
            linked *temp = head;
            // Update head with the next node. //
            head = temp -> next;
            // free temp now. //
            free( temp );
            // Item at position zero deleted. //
        }
        else{
            int pos = 0;
            /* Now traverse the whole list unitill pos becomes equal to 
            the index provided by the user. For this initialise pointer temp. */
            linked *temp = head;
            linked *prev;
            while( temp != NULL ){
                if( pos == index ){
                    prev -> next = temp -> next;
                    free( temp );
                    break;
                }
                else{
                    pos += 1;
                    prev = temp;
                    temp = temp -> next;
                }
            }
            /* Now if temp becomes NULL, that means the user is out of index range. */
            if( temp == NULL ){
                printf("You are out of range, can't delete element.\n");
            }
        }
    }
}

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
        printf("Enter 6 to insert at a position.\n");
        printf("Enter 7 to delete at a position.\n");
        printf("Enter 8 to swap at a indexes.\n");

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
        else if( x == 6 ){
            // Take item and position from the user. //
            int item, pos;
            printf("Enter item: ");
            scanf("%d", &item);
            printf("Enter position: ");
            scanf("%d", &pos);
            // Now make a call to the insertmid() function. //
            insertmid( item, pos );
        }
        else if( x == 7 ){
            // Take the index to be deleted. //
            int pos;
            printf("Enter the index to be deleted at: ");
            scanf("%d", &pos);
            // Make a call to delete_from_pos() function. //
            delete_from_pos( pos );
        }
        else if( x == 8 ){
            // Take the indexes to be swapped. //
            int pos1, pos2;
            printf("Enter the index1: ");
            scanf("%d", &pos1);
            printf("Enter the index2: ");
            scanf("%d", &pos2);
            // Make a call to delete_from_pos() function. //
            interchange( pos1, pos2 );
        }
        else{
            printf("Invalid choice. \n");
        }
    }
} // End of main() function. //
