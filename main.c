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
#include "struct.h"
#include "dictionary.h"

/*
 *
 */
int main(int argc, char** argv) {

    int length, i;
    slist *list;

    printf(STR_DICT_LENGTH);
    scanf("%d", & length);
    list = init_dictionary(list, length);

    
    add_node(list, length);
    add_node(list, length);
    add_node(list, length);
    
   i=delete_node(list, 1, length);
    printf("%d si o no\n", i );
    
    
     
    print_dictionary(list, length);

    return (EXIT_SUCCESS);
}

