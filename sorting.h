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
void merge(slist *dictionary);
snode binary_search(slist *dictionary,int key,int hash);

#endif	/* SORTING_H */

