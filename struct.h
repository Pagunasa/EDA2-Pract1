/* 
 * File:   sorting.h
 * Author: u140172
 *
 * Created on 3 de mayo de 2017, 11:12
 */

#ifndef STRUCTS_H
#define	STRUCTS_H

#include "constants.h"

typedef struct{// data de naixament d'una persona
    int day;// dia neixament
    int month;// mes de naixament
    int year;// any de naixament
}sdateBirth;

typedef struct{//dades a emmagatzemar d'una persona
    char name[MAX_LENGTH10];
    char surname[MAX_LENGTH10];
    char sex;
    sdateBirth dateBirth;// data naixament
}sdata;

typedef struct node{// node de la llista enllaçada
    int DNI;//clau 
    sdata Info;// informació de la persona
    struct node *next;// punter al següent node
    struct node *prev;//punter al node previ
}snode;

typedef struct {// estructura de la llista enllaçada
    snode* element;// punter al primer node de la llista
    int size;//nombre de nodes que té la llista
}slist;

#endif	/* STRUCTS_H */
