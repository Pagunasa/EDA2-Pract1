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

slist* init_dictionary(int length);
int add_node(slist *dictionary, int length);
snode* new_node();
int delete_node(slist *dictionary, int key,int length);
snode *seek_node(slist *dictionary, int key, int length);
int size_dictionary(slist *dictionary,int length);
int hash(int key, int length);
void print_dictionary(slist *dictionary,int length);
void dump_line(FILE * fp);
void dump_line_error(FILE * fp);
void print_node(snode *node);
int numberOfDigits(int number);

#endif	/* DICTIONARY_H */

