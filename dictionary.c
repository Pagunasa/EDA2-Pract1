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

int init_dictionary(slist *dictionary){
    int size, i;
    
    printf(STR_DICT_LENGTH);
    scanf("%d", &size);
    
    dictionary = (slist *)malloc(size * sizeof(slist));
    ERRORMEMORY((dictionary == NULL), (COLOR_RED STR_ERR_MEMORY COLOR_RESET));
    
    for(i = 0; i < size; i++){
        dictionary[i].element = NULL;
        dictionary[i].size = ZERO;
    }
    
    return size;
}

int add_node(slist *dictionary, snode data){
    
}

int delete_node(slist *dictionary, int key){
    
}

int seek_node(slist *dictionary, int key){
    
}

int size_dictionary(slist *dictionary){
    
}

int hash(int key, int size){
    return key % size;
}
