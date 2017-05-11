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
#include "sorting.h"

/*
 *
 */
int main(int argc, char** argv) {

    int length;
    slist *list;

    printf(STR_DICT_LENGTH);
    while (!scanf("%d", &length)) dump_line_error(stdin);



    list = init_dictionary(length);

    // print_dictionary(list, length);

    menu(list, length);

    //    add_node(list, length);
    //    add_node(list, length);
    //    add_node(list, length);
    //
    //    i = delete_node(list, 1, length);
    //    printf("%d si o no\n", i);
    //
    //    print_dictionary(list, length);

    return (EXIT_SUCCESS);
}

void menu(slist *list, int length) {
    int option = 0, trueOrFalse, key, i, aux;
    int *DNI;
    snode *result;

    printf(STR_MEN_WELCOME);
    do {
        printf(STR_MEN_OPT_ADD);
        printf(STR_MEN_OPT_DEL);
        printf(STR_MEN_OPT_SEK);
        printf(STR_MEN_OPT_MDF);
        printf(STR_MEN_OPT_PNT);
        printf(STR_MEN_OPT_AD2);
        printf(STR_MEN_OPT_EXT);
        printf(STR_MEN_CHOOSE);
        while (!scanf("%d", &option)) dump_line_error(stdin);

        switch (option) {
            case INT_MEN_OPT_ADD: //add a new person
                result = new_node();
                trueOrFalse = add_node(result, list, length);
                if (trueOrFalse == FALSE) {
                    printf(COLOR_RED ERROR_ADD COLOR_RESET);
                } else {
                    printf(COLOR_GREEN OK_ADD COLOR_RESET);
                }
                break;
            case INT_MEN_OPT_DEL: //delete a person
                printf(STR_INPT_KEY);
                while (!scanf("%d", &key)) dump_line_error(stdin);
                trueOrFalse = delete_node(list, key, length);
                if (trueOrFalse == FALSE) {
                    printf(COLOR_RED ERROR_DEL COLOR_RESET);
                } else {
                    printf(COLOR_GREEN OK_DEL COLOR_RESET);
                }
                break;
            case INT_MEN_OPT_SEK: //search a person
                printf(STR_INPT_KEY);
                while (!scanf("%d", &key)) dump_line_error(stdin);
                result = seek_node(list, key, length);
                print_node(result);
                break;
            case INT_MEN_OPT_MDF: //Modify one element
                printf(STR_INPT_KEY);
                while (!scanf("%d", &key)) dump_line_error(stdin);
                result = seek_node(list, key, length);
                modify_node(result);
                break;
            case INT_MEN_OPT_PNT: //Print all the elements os the list
                aux=size_dictionary(list, length);
                DNI=fill_list(list, length);
                DNI=buble(DNI, aux);
                print_list_ordered(DNI, aux, list, length);
               
                break;
            case INT_MEN_OPT_AD2:
                printf(STR_ADD_CONJ); //Aqui la key quiere decir numero usuarios
                while (!scanf("%d", &key)) dump_line_error(stdin);
                add_conjunct(list, key, length);
                break;
            case INT_MEN_OPT_EXT: //Exit
                printf(STR_THANKS);
                clear_all(list, length);
                break;
            default:
                printf(STR_NOTVALID_OPT);
        }

    } while (option != 0);


}