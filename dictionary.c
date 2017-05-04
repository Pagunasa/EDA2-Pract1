/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Pagunasa
 *
 * Created on 23 de abril de 2017, 11:27
 */

#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include "constants.h"

int init_dictionary(slist *dictionary) {
    int size, i;

    printf(STR_DICT_LENGTH);
    scanf("%d", &size);

    dictionary = (slist *) malloc(size * sizeof (slist));
    ERRORMEMORY((dictionary == NULL), (COLOR_RED STR_ERR_MEMORY COLOR_RESET));

    for (i = 0; i < size; i++) {
        dictionary[i].element = NULL;
        dictionary[i].size = ZERO;
    }

    return size;
}

void dump_line(FILE * fp) {
    int ch;

    while ((ch = fgetc(fp)) != EOF && ch != '\n')
        /* null body */;
}

snode* new_node() {
    snode *node;
    node = (snode *) malloc(sizeof (snode));
    ERRORMEMORY((node == NULL), (COLOR_RED STR_ERR_MEMORY COLOR_RESET));

    printf("Input user information: \n");
    printf("DNI: ");
    while (!scanf("%d", node->DNI)) dump_line(stdin); //En todos !!!!!!!
    printf("Name: ");
    scanf("%s", node->Info.name);
    printf("Surname: ");
    scanf("%s", node->Info.surname);
    printf("Sex: ");
    scanf("%c", node->Info.sex);
    printf("Birth date: ");
    scanf("%d %d %d", node->Info.dateBirth.day, node->Info.dateBirth.month, node->Info.dateBirth.year);

    node->next = NULL;
    node->prev = NULL;

    return node;
}

int add_node(slist *dictionary, int size) {
    snode *node, *aux;
    int pos;

    node = new_node();
    pos = hash(node->DNI, size);

    if (dictionary[pos].element == NULL) {
        dictionary[pos].element == node;
    } else {
        aux = dictionary[pos].element;
        while (aux->next != NULL) {
            if (aux->DNI == node->DNI) {
                return FALSE;
            }
            aux = dictionary[pos].element->next;
        }
        aux->next = node;
        node->prev = aux;
        dictionary[pos].size++;
    }

    return TRUE;
}

int delete_node(slist *dictionary, int key, int size) {
    snode *aux, *prev, *next;
    aux = seek_node(dictionary, key, size);

    if (aux != NULL) {
        prev = aux->prev;
        next = aux->next;
        prev->next = next;
        next->prev = prev;
        free(aux);
        return TRUE;
    }
    return FALSE;

}

snode *seek_node(slist *dictionary, int key, int size) {
    int pos;
    snode *aux;

    pos = hash(key, size);
    aux = dictionary[pos].element;

    while (aux != NULL) {
        if (aux->DNI == key) {
            //Printf del contenido
            return aux;
        }
        aux = dictionary[pos].element->next;
    }
    return NULL;
}

int size_dictionary(slist *dictionary) {

}

int hash(int key, int size) {
    return key % size;
}
