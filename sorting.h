/* 
 * File:   sorting.h
 * Author: u140172
 *
 * Created on 3 de mayo de 2017, 11:12
 */

#ifndef SORTING_H
#define	SORTING_H

#include "struct.h"

void sort(slist *list,snode *new);
int* buble(int *a, int length);// bubble sort
snode binary_search(slist *dictionary,int key,int hash);
int *fill_list(slist *dictionary, int length);// omple array amb els DNIs dels nodes 

#endif	/* SORTING_H */

