/* 
 * File:   sorting.h
 * Author: u140172
 *
 * Created on 3 de mayo de 2017, 11:12
 */

#ifndef STRUCTS_H
#define	STRUCTS_H

#include "constants.h"

typedef struct{
    int day;
    int month;
    int year;
}sdateBirth;

typedef struct{
    char name[MAX_LENGTH10];
    char surname[MAX_LENGTH10];
    char sex;
    sdateBirth dateBirth;
}sdata;

typedef struct node{
    int DNI;
    sdata Info;
    struct node *next;
}snode;

typedef struct {
    snode* element;
    int size;
}slist;

#endif	/* STRUCTS_H */
