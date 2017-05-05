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
#include "main.h"
#include "dictionary.h"

/*
 *
 */
int main(int argc, char** argv) {

    int length, i;
    slist *list;

    printf(STR_DICT_LENGTH);
    while (!scanf("%d", &length)) dump_line_error(stdin);


    list = init_dictionary(length);

    print_dictionary(list, length);

    menu(list, length);

    add_node(list, length);
    add_node(list, length);
    add_node(list, length);

    i = delete_node(list, 1, length);
    printf("%d si o no\n", i);

    print_dictionary(list, length);

    return (EXIT_SUCCESS);
}

void menu(slist *list, int length) {
    int option = 0, trueOrFalse, key;
    snode *result;

    do {
        printf(STR_MEN_WELCOME);
        printf(STR_MEN_OPT_ADD);
        printf(STR_MEN_OPT_DEL);
        printf(STR_MEN_OPT_SEK);
        printf(STR_MEN_OPT_MDF);
        printf(STR_MEN_OPT_PNT);
        printf(STR_MEN_OPT_EXT);
        while (!scanf("%d", &option)) dump_line_error(stdin);

        switch (option) {
            case INT_MEN_OPT_ADD: //add a new person
                trueOrFalse = add_node(list, length);
                if(trueOrFalse == FALSE){
                    printf(COLOR_RED ERROR_ADD COLOR_RESET);
                }else{
                    printf(OK_ADD);
                }
                break;
            case INT_MEN_OPT_DEL:
                printf(STR_INPT_KEY);
                while (!scanf("%d", &key)) dump_line_error(stdin);
                trueOrFalse = delete_node(list, 1, length);
                break;
            case INT_MEN_OPT_SEK:
                printf(STR_INPT_KEY);
                while (!scanf("%d", &key)) dump_line_error(stdin);
                result = seek_node(list, key, length);
                print_node(result);
                break;
            case INT_MEN_OPT_MDF:
                break;
            case INT_MEN_OPT_PNT:
                break;
            case INT_MEN_OPT_EXT:
                printf(STR_THANKS);
                break;
            default:
                printf(STR_NOTVALID_OPT);
        }

    } while (option != 0);


}