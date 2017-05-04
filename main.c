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

    int globalSize, i;
    slist *list;

    globalSize = init_dictionary(&list);

    for (i = 0; i < globalSize; i++) {
        printf("%d", list[i].size);
    }

    add_node(&list, globalSize);

    printf("%d", list[1].element->DNI);
    //print_dictionary(list, globalSize);

    return (EXIT_SUCCESS);
}

