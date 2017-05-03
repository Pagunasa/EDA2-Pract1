/* 
 * File:   dictionary.h
 * Author: u137557
 *
 * Created on 3 de mayo de 2017, 11:40
 */

#ifndef DICTIONARY_H
#define	DICTIONARY_H

void init_dictionary(slist **dictionary);
int add_node(slist **dictionary, snode data);
int delete_node(slist **dictionary, int key);
int seek_node(slist **dictionary, int key);
int size_dictionary(slist **dictionary);
int hash(int key);

#endif	/* DICTIONARY_H */

