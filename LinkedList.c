//
//  LinkedList.c
//  test
//
//  Created by Raza Rauf on 1/19/2014.
//  Copyright (c) 2014 Raza Rauf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"


struct node *head;
struct node *tail;
struct node *lastNode;

void init(struct node struc_node){
    head = (struct node *) malloc( sizeof(struct node) );
    
    //make head point to beginning of linked list
    struct node *currPtr = head;

    currPtr->prev = 0;
    tail = currPtr;
    currPtr->next=0;
    
    currPtr->artist = struc_node.artist;
    currPtr->album = struc_node.album;
    currPtr->song = struc_node.song;
    currPtr->date = struc_node.date;
    currPtr->runtime = struc_node.runtime;
}

void print (){
    if(head==NULL){
        printf("\n***There doesn't seem to be anything here...***\n");
    }
    else{
        printf("\n***Printing in order:***\n");
        struct node *newCurr;
        newCurr = head;
        
        while (newCurr!=0) {
            printf("Artist: %s", newCurr->artist);
            printf("Album: %s", newCurr->album);
            printf("Song Title: %s", newCurr->song);
            printf("Date: %d\n", newCurr->date);
            printf("Runtime: %d\n\n", newCurr->runtime);
    //        printf("Runtime: %d\n", newCurr->runtime);
            newCurr=newCurr->next;
        }
    }

}
void rev_print (){
    if(head==NULL){
        printf("\n***...here anything be to seem doesn't There***\n");
    }
    else{
        printf("\n***Printing in backward order:***\n");
        struct node *reCurr;
        reCurr = tail;
        while (reCurr!=0) {
            printf("Artist: %s", reCurr->artist);
            printf("Album: %s", reCurr->album);
            printf("Song Title: %s", reCurr->song);
            printf("Date: %d\n", reCurr->date);
            printf("Runtime: %d\n\n", reCurr->runtime);
            reCurr=reCurr->prev;
        }
    }
}

void insertItem(struct node struc_node){
    
    if(head==NULL){
        init(struc_node);
        return;
    }
    
    struct node *currPtr = head;
    struct node *prevPtr = 0;
    
    int input = struc_node.runtime;
    
    while (currPtr!=NULL && input > currPtr->runtime) {
//        if(){
            prevPtr = currPtr;
            currPtr=currPtr->next;
//        }
    }
    if (prevPtr==0) {
        //meaning inserting at head
        struct node *oldNodePtr = currPtr; //save pointer to old node
        currPtr = (struct node *) malloc( sizeof(struct node) );
        
        currPtr->artist = struc_node.artist;
        currPtr->album = struc_node.album;
        currPtr->song = struc_node.song;
        currPtr->date = struc_node.date;
        currPtr->runtime = struc_node.runtime;
        
        currPtr->next = oldNodePtr;
        currPtr->prev = 0;
        
        head = currPtr;
        oldNodePtr->prev = currPtr;
    }
    else if (currPtr==0) {
        //meaning inserting at end
        struct node *currPtr = (struct node *) malloc( sizeof(struct node) );
        
        currPtr->artist = struc_node.artist;
        currPtr->album = struc_node.album;
        currPtr->song = struc_node.song;
        currPtr->date = struc_node.date;
        currPtr->runtime = struc_node.runtime;
//        currPtr->runtime = input;
        currPtr->prev = prevPtr;
        currPtr->next = 0;
        
        tail = currPtr;
        prevPtr->next = currPtr;
    }
    else{
        //inserting in the middle somewhere...
        struct node *oldNodePtr = currPtr; //save pointer to old node
        currPtr = (struct node *) malloc( sizeof(struct node) );
        
        currPtr->artist = struc_node.artist;
        currPtr->album = struc_node.album;
        currPtr->song = struc_node.song;
        currPtr->date = struc_node.date;
        currPtr->runtime = struc_node.runtime;
        
//        currPtr->runtime = input;
        currPtr->next = oldNodePtr;
        currPtr->prev = prevPtr;
        
        prevPtr->next = currPtr;
        oldNodePtr->prev = currPtr;
    }
}

void deleteItem(char *delete_art){
    
    //int strcmp ( const char *s1, const char *s2 );
    //Negative if s1 is less than s2.
    //Zero if s1 and s2 are equal.
    //Positive if s1 is greater than s2.
    
    struct node *currPtr = head;
    struct node *prevPtr = 0;
    
    int input;
    
    while (currPtr!=NULL) {
        
        input = strcmp ( delete_art, currPtr->artist );
        
//        if(input==currPtr->runtime)
        if(input==0)
        {
            if (prevPtr==0 && currPtr->next==0)
            {
                head=0;
                tail=0;
                free(currPtr);
                currPtr=0;
                printf("Cannot delete last node!!! No more time left to fix this:(\n");
                return;
            }else if (prevPtr==0)
            {
                //meaning deleting at the head .. problem here...
                struct node *nextPtr = currPtr->next; //save pointer to old node
                head = nextPtr;
                nextPtr->prev = 0;
//                currPtr=nextPtr;
                currPtr=head;
                prevPtr=0;
            }else if (currPtr->next==0)
            {
                //meaning deleting at end
                prevPtr->next=0;
                currPtr->prev=0;
                currPtr=0;
                tail = prevPtr;
                return;
            }else
            {
                //deleting in the middle somewhere...
                struct node *nextPtr = currPtr->next;
                prevPtr->next = nextPtr;
                nextPtr->prev = prevPtr;
                currPtr->prev = 0;
                currPtr->next = 0;
//                currPtr = nextPtr;
                currPtr=head;
                prevPtr=0;
            }
        
        }
        else{
            prevPtr = currPtr;
            currPtr=currPtr->next;
        }
    }
}