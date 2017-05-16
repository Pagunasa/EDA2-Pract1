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
#include "sorting.h"
#include "dictionary.h"

void sort(slist *list, snode *new) {
    snode *aux;
    aux = list->element;
    if (new->DNI < aux->DNI) {
        new->next = aux;
        aux->prev = new;
        list->element = new;
        return;
    }
    while (aux->next != NULL) {
        if (aux->DNI < new->DNI && aux->next->DNI > new->DNI) {
            new->next = aux->next;
            aux->next->prev = new;
            aux->next = new;
            new->prev = aux;
            return;
        }
        aux = aux->next;
    }
    if (new->DNI > aux->DNI) {
        aux->next = new;
        new->prev = aux;
        return;
    }
}

int *fill_list(slist *dictionary, int length) {// omple un array amb les claus 
    int i, pos = 0;
    snode *aux;
    int *DNI = (int*) malloc(size_dictionary(dictionary, length) * sizeof (int));// crea array
    for (i = 0; i < length; i++) {// omple array amb les claus dels nodes del diccionari
        aux = dictionary[i].element;
        while (aux != NULL) {
            DNI[pos] = aux->DNI;
            pos++;
            aux = aux->next;
        }
    }
    return DNI;// retorna l'array
}

int* buble(int *a, int length) {// bubble sort
    // ordena l'array de DNIs del programa anterior 
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

        }
    }
    return a;
}