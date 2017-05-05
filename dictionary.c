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

int* init_dictionary(slist *dictionary, int length) {
    int i;

    dictionary = (int*) malloc(length * sizeof (slist));

    for (i = 0; i < length; i++) {
        dictionary[i].element = NULL;
        dictionary[i].size = ZERO;
    }

    return dictionary;
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
    while (!scanf("%d", &node->DNI)) dump_line(stdin);
    dump_line(stdin);
    printf("Name: ");
    while (!scanf("%s", node->Info.name)) dump_line(stdin);
    dump_line(stdin);
    printf("Surname: ");
    while (!scanf("%s", node->Info.surname)) dump_line(stdin);
    dump_line(stdin);
    printf("Sex: ");
    while (!scanf("%c", &node->Info.sex)) dump_line(stdin);
    dump_line(stdin);
    printf("Birth date: ");
    while (!scanf("%d %d %d", &node->Info.dateBirth.day, &node->Info.dateBirth.month, &node->Info.dateBirth.year)) dump_line(stdin);
    dump_line(stdin);
    node->next = NULL;
    node->prev = NULL;

    return node;
}

int add_node(slist *dictionary, int length) {
    snode *node, *aux;
    int pos;

    node = new_node();
    pos = hash(node->DNI, length);

    if (dictionary[pos].element == NULL) {
        dictionary[pos].element = node;
        dictionary[pos].size++;
    } else {
        aux = dictionary[pos].element;
        while (aux->next != NULL) {
            if (aux->DNI == node->DNI) {
                return FALSE;
            }
            aux = aux->next;
        }
        aux->next = node;
        node->prev = aux;
        dictionary[pos].size++;
    }

    return TRUE;
}

int delete_node(slist *dictionary, int key, int length) {
    snode *aux, *prev, *next;
    int pos;
    pos = hash(key, length);
    aux = seek_node(dictionary, key, length);

    if (aux != NULL) {
        if ( (aux->prev == NULL)&&(aux->next!=NULL) ) {
            aux->next->prev = NULL;
            dictionary[pos].element = aux->next;
            aux->next = NULL;
            free(aux);
            dictionary[pos].size--;
            return TRUE;

        } else if ((aux->next == NULL)&&(aux->prev!=NULL)) {
            aux->prev->next = NULL;
            aux->prev = NULL;
            free(aux);
            dictionary[pos].size--;
            return TRUE;

        } else if ((aux->next == NULL)&&(aux->prev == NULL)) {
            dictionary[pos].element = NULL;
            free(aux);
            dictionary[pos].size--;
            return TRUE;

        } else {
            prev = aux->prev;
            next = aux->next;
            prev->next = next;
            next->prev = prev;
            free(aux);

            dictionary[pos].size--;
            return TRUE;
        }
    } else {
        return FALSE;
    }
}

snode *seek_node(slist *dictionary, int key, int length) {
    int pos;
    snode *aux;

    pos = hash(key, length);
    aux = dictionary[pos].element;

    while (aux != NULL) {
        if (aux->DNI == key) {
            //Printf del contenido
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

int size_dictionary(slist *dictionary, int length) {
    int i, cnt = 0;
    for (i = 0; i < length; i++) {
        cnt += dictionary[i].size;
    }
    return cnt;
}

void print_dictionary(slist *dictionary, int length) {
    int i, a;
    snode *aux;
    a = size_dictionary(dictionary, length);

    if (a==0) {
        printf("Llista buida\n");
    } else {

        for (i = 0; i < length; i++) {
            aux = dictionary[i].element;
            while (aux != NULL) {
                printf("%d \n", aux->DNI);
                aux = aux->next;
            }
        }
    }
}

int hash(int key, int length) {
    return key % length;
}

