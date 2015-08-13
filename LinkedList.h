//
//  LinkedList.h
//  test
//
//  Created by Raza Rauf on 1/19/2014.
//  Copyright (c) 2014 Raza Rauf. All rights reserved.
//

#ifndef test_LinkedList_h
#define test_LinkedList_h

struct node {
    struct node *prev;
    
    char *artist;
    char *album;
    char *song;
    int date;
    int runtime;
    
    struct node *next;
};

void init(struct node);
void print ();
void rev_print ();
void insertItem(struct node);
void deleteItem(char *);

#endif
