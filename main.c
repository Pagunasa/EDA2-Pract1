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

/*
 * 
 */
int main(int argc, char** argv) {
    
    int globalSize;
    slist *list;
    
    globalSize = init_dictionary(&list);
        
    return (EXIT_SUCCESS);
}

