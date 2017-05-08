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

slist* init_dictionary(int length) {
    int i;
    slist *dictionary;

    dictionary = (slist*) malloc(length * sizeof (slist));
    ERRORMEMORY((dictionary == NULL), (COLOR_RED STR_ERR_MEMORY COLOR_RESET));

    for (i = 0; i < length; i++) {
        dictionary[i].element = NULL;
        dictionary[i].size = ZERO;
    }

    return dictionary;
}

void dump_line(FILE * fp) {
    int ch;

    while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

void dump_line_error(FILE * fp) {
    printf(COLOR_RED STR_ERR_INPUT COLOR_RESET);
    dump_line(fp);
}

int numberOfDigits(int number) {
    int cont = 1;
    while (number / TEN > 0) {
        number = number / TEN;
        cont++;
    }
    return cont;
}

snode* new_node() {
    snode *node;
    node = (snode *) malloc(sizeof (snode));
    ERRORMEMORY((node == NULL), (COLOR_RED STR_ERR_MEMORY COLOR_RESET));

    printf(STR_OPENING);
    printf(STR_DNI);
    while (!scanf("%d", &node->DNI)) dump_line_error(stdin);
    dump_line(stdin);
    printf(STR_NAME);
    while (!scanf("%s", node->Info.name)) dump_line_error(stdin);
    dump_line(stdin);
    printf(STR_SURNAME);
    while (!scanf("%s", node->Info.surname)) dump_line_error(stdin);
    dump_line(stdin);
    printf(STR_SEX);
    while (!scanf("%c", &node->Info.sex) || node->Info.sex != 'M' && node->Info.sex != 'F') dump_line_error(stdin);
    dump_line(stdin);
    printf(STR_BIRTH_DATE);
    while (!scanf("%d %d %d", &node->Info.dateBirth.day,
            &node->Info.dateBirth.month, &node->Info.dateBirth.year)
            || numberOfDigits(node->Info.dateBirth.day) != LENGTH_2 &&
            numberOfDigits(node->Info.dateBirth.day) != LENGTH_1 ||
            numberOfDigits(node->Info.dateBirth.month) != LENGTH_2 ||
            numberOfDigits(node->Info.dateBirth.year) != LENGTH_4 ||
            node->Info.dateBirth.year > YEARNUMBER || node->Info.dateBirth.day > NUMB_DAYS ||
            node->Info.dateBirth.month > NUMB_MONTH) dump_line_error(stdin);
    dump_line(stdin);
    node->next = NULL;
    node->prev = NULL;

    return node;
}

int add_node(snode *node, slist *dictionary, int length) {
    snode *aux;
    int pos, end = 0;

    pos = hash(node->DNI, length);

    if (dictionary[pos].element == NULL) {
        dictionary[pos].element = node;
        dictionary[pos].size++;
    } else {
        aux = dictionary[pos].element;
        while (end != 1) {
            if (aux->DNI == node->DNI) {
                free(node);
                return FALSE;
            }
            if (aux->next == NULL) {
                end = 1;
                aux->next = node;
                node->prev = aux;
                dictionary[pos].size++;
            }
            aux = aux->next;
        }
    }
    return TRUE;
}

int delete_node(slist *dictionary, int key, int length) {
    snode *aux, *prev, *next;
    int pos;
    pos = hash(key, length);
    aux = seek_node(dictionary, key, length);

    if (aux != NULL) {
        if ((aux->prev == NULL)&&(aux->next != NULL)) {
            aux->next->prev = NULL;
            dictionary[pos].element = aux->next;
            aux->next = NULL;
            free(aux);
            dictionary[pos].size--;
            return TRUE;

        } else if ((aux->prev != NULL)&&(aux->next == NULL)) {
            aux->prev->next = NULL;
            aux->prev = NULL;
            free(aux);
            dictionary[pos].size--;
            return TRUE;

        } else if ((aux->prev == NULL)&&(aux->next == NULL)) {
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
            printf("Found!!!");
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
    int i, a, cont = 0;
    snode *aux;
    a = size_dictionary(dictionary, length);

    if (a == 0) {
        printf("Print fail: Llista buida\n");
    } else {

        for (i = 0; i < length; i++) {
            aux = dictionary[i].element;
            while (aux != NULL) {
                cont++;
                printf("User %d: \n", cont);
                print_node(aux);
                aux = aux->next;
            }
        }
    }
}

int hash(int key, int length) {
    return key % length;
}

void print_node(snode *node) {
    if (node != NULL) {
        printf(STR_NODE_DNI, node->DNI);
        printf(STR_NODE_NAM_SUR, node->Info.name, node->Info.surname);
        printf(STR_NODE_SEX, node->Info.sex);
        printf(STR_NODE_BIRTHDATE, node->Info.dateBirth.day, node->Info.dateBirth.month, node->Info.dateBirth.year);
    } else {
        printf(STR_ERR_NEXTS);
    }
}

slist* add_conjunct(slist *dictionary, int numElem, int length) {
    int i, result;
    slist *aux;
    snode *nodeAux;

    aux = (slist*) malloc(numElem * sizeof (slist));
    ERRORMEMORY((aux == NULL), (COLOR_RED STR_ERR_MEMORY COLOR_RESET));

    for (i == 0; i < numElem; i++) {
        nodeAux = new_node();
        aux[i].element = nodeAux;
        aux[i].size++;
    }

    for (i == 0; i < numElem; i++) {
        result = add_node(aux[i].element, dictionary, length);
        if (result == FALSE) {
            printf("Error adding user with DNI: %d, already exist", aux[i].element->DNI);
        } else {
            printf("Adding correct of user with DNI: %d", aux[i].element->DNI);
        }
    }

    free(aux);
}

void modify_node(snode *node) {

    if (node != NULL) {
        char name[MAX_LENGTH10];
        char surname[MAX_LENGTH10];
        char sex;
        sdateBirth dateBirth;

        printf(STR_MOD_INF1);
        printf(STR_NAME);
        while (!scanf("%s", name)) dump_line_error(stdin);
        dump_line(stdin);

        printf(STR_MOD_INF1);
        printf(STR_SURNAME);
        while (!scanf("%s", surname)) dump_line_error(stdin);
        dump_line(stdin);

        printf(STR_MOD_INF2);
        printf(STR_SEX);
        while (!scanf("%c", &sex) || sex != 'M' && sex != 'F' && sex != 'N') dump_line_error(stdin);
        dump_line(stdin);

        printf(STR_MOD_INF2);
        printf(STR_BIRTH_DATE);
        while (!scanf("%d %d %d", &dateBirth.day,
                &dateBirth.month, &dateBirth.year)
                || numberOfDigits(dateBirth.day) != LENGTH_2 &&
                numberOfDigits(dateBirth.day) != LENGTH_1 ||
                numberOfDigits(dateBirth.month) != LENGTH_2 ||
                numberOfDigits(dateBirth.year) != LENGTH_4 ||
                dateBirth.year > YEARNUMBER || dateBirth.day > NUMB_DAYS ||
                dateBirth.month > NUMB_MONTH) dump_line_error(stdin);
        dump_line(stdin);

        if (name != STR_NULL) {
            node->Info.name = name;
        }
        if (surname != STR_NULL) {
            node->Info.surname = surname;
        }
        if (sex != CHAR_N) {
            node->Info.sex = sex;
        }
        if (dateBirth.day != INT_2_0) {
            node->Info.dateBirth.day = dateBirth.day;
        }
        if (dateBirth.month != INT_2_0) {
            node->Info.dateBirth.month = dateBirth.month;
        }
        if (dateBirth.year != INT_4_0) {
            node->Info.dateBirth.year = dateBirth.year;
        }

        printf(STR_MOD_END);
    } else {
        printf(STR_ERR_NEXTS);
    }

}