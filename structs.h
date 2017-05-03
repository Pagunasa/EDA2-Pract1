

#ifndef STRUCTS_H
#define	STRUCTS_H

typedef struct{
    char name[MAX_LENGTH10];
    char surname[MAX_LENGTH10];
    char sex;
    int day;
    int month;
    int year;
}sdata;

typedef struct node{
    int DNI;
    sdata Info;
    node *next;
}snode;

typedef struct {
    snode *first;
    int size;
}slist;

#endif	/* STRUCTS_H */

