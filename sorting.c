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

void merge(slist *dictionary) {

}

snode binary_search(slist *dictionary, int key, int hash) {

}

