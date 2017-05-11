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

int *merge(int *A, int *B) {
    int k1 = 1, k2 = 1;
    int N = sizeof (A);
    int M = sizeof (B);
    int *RES = (int*) malloc((N + M) * sizeof (int));
    int k = 1;
    while (k1 <= N || k2 <= M) {
        if (A[k1] <= B[k2]) {
            RES[k] = A[k1];
            k1++;
            k++;
        } else {
            RES[k] = B[k2];
            k2++;
            k++;
        }
    }
    while (k1 <= N) {
        RES[k] = A[k1];
        k1++;
        k++;
    }
    while (k2 <= M) {
        RES[k] = B[k2];
        k2++;
        k++;
    }
    return RES;
}

int * merge_sort(int *DNI) {
    int k;
    int N = sizeof (DNI);

    if (N == 1) {
        return DNI;
    } else {
        k = N / 2;
        int *A1 = (int*) malloc(k * sizeof (int));
        A1 = merge_sort(&DNI[0]);
        int *A2 = (int*) malloc((N - k) * sizeof (int));
        A2 = merge_sort(&DNI[k + 1]);
        return merge(A1, A2);
    }
}

snode binary_search(slist *dictionary, int key, int hash) {

}

