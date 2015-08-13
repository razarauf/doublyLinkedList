//
//  main.c
//  test
//
//  Created by Raza Rauf on 1/19/2014.
//  Copyright (c) 2014 Raza Rauf. All rights reserved.
//
#include"LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct node input;
    
    char entermore = '\0';
    //getchar();
    
    char delete_input = '\0';
    
    while (entermore!='k') {
        
        printf ( "\n*******************************************************\n" );
        printf ("i: Insert (Insert an element and keep the list ordered)\n");
        printf ("d: Delete (Delete a node with the given value)\n");
        printf ("p: Print  (Print the content of the current list)\n");
        printf ("q: Print Backward (Print the content of the current list - backwards)\n");
        printf ("k: Quit   (Quit the program)\n");
        printf ( "*******************************************************");
        printf ("\n   Please enter your choice here:");
        
        scanf( "%s",  &entermore);
        getchar();
        
        switch(entermore)
        {
            case 'i':
                printf( "Enter artist's name [100]: " );
                input.artist = (char *) malloc(100);
                fgets(input.artist, 100, stdin);
                
                printf( "Enter album's name [50]: " );
                input.album = (char *) malloc(100);
                fgets(input.album, 100, stdin);
                
                printf( "Enter song's name [200]: " );
                input.song = (char *) malloc(200);
                fgets(input.song, 200, stdin);
                
                printf( "Enter date: " );
                scanf( "%d", &input.date );
                
                //get the first runtime
                printf( "Enter runtime: " );
                scanf( "%d", &input.runtime );
                
                insertItem(input);
                break;

            case 'd':
                printf( "Enter artist's name to delete: " );
                fgets(&delete_input, 100, stdin);
                deleteItem(&delete_input);
                break;

            case 'p':
                print();
                break;
                
            case 'q':
                rev_print();
                break;
                
            case 'k':
                break;

            default:
                printf ("\n Invalid choice. Please try again.\n");
                break;
            
            getchar();
        }
    }
    return 0;
}

