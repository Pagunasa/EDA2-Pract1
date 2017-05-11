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

int *fill_list(slist *dictionary, int length) {
    int i, pos = 0;
    snode *aux;
    int *DNI = (int*) malloc(size_dictionary(dictionary, length) * sizeof (int));
    for (i = 0; i < length; i++) {
        aux = dictionary[i].element;
        while (aux != NULL) {
            DNI[pos] = aux->DNI;
            pos++;
            aux = aux->next;
        }
    }
    return DNI;
}

int* buble(int *a, int length) {// buble sort
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