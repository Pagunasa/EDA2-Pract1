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

slist* init_dictionary(int length);// inicialitza diccionari
int add_node(snode *node, slist *dictionary, int length);// afegeix node
snode* new_node();// crea node i omple informació
int delete_node(slist *dictionary, int key,int length);// borra node
snode *seek_node(slist *dictionary, int key, int length);// busca node en el diccionari
int size_dictionary(slist *dictionary,int length);// numero de persones en el diccionari
int hash(int key, int length);// calcula la clau 
void print_dictionary(slist *dictionary,int length);// imprimeix tots els nodes del diccionari
void dump_line(FILE * fp);// evita error d'entrada de dades per teclat
void dump_line_error(FILE * fp);
void print_node(snode *node);// imprimeix informació d'un node
int numberOfDigits(int number);//numero maxim de digits a entrar per teclat
slist* add_conjunct(slist *dictionary, int numElem, int length);//afegeix nodes a partir d'un array
void modify_node(snode *node);// modifica node ja existent
void print_list_ordered(int *a, int arraylength, slist *dictionary, int length);// imprimeix tots els nodes de forma ordenada

#endif	/* DICTIONARY_H */

