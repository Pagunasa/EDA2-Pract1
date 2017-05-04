/*
 * File:   dictionary.h
 * Author: u137557
 *
 * Created on 3 de mayo de 2017, 11:40
 */

#ifndef DICTIONARY_H
#define	DICTIONARY_H
#include "struct.h"

#define ERRORMEMORY(condition, msg) if condition {printf msg; exit(0);}

int init_dictionary(slist *dictionary);
int add_node(slist *dictionary, int size);
snode* new_node();
int delete_node(slist *dictionary, int key);
snode *seek_node(slist *dictionary, int key, int size);
int size_dictionary(slist *dictionary);
int hash(int key, int size);

#endif	/* DICTIONARY_H */

