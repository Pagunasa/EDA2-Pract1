/* 
 * File:   strings.h
 * Author: u140172
 *
 * Created on 3 de mayo de 2017, 11:09
 */

#ifndef STRINGS_H
#define	STRINGS_H

//Boleans
#define TRUE 1
#define FALSE 0
#define EMPTY -1
#define ZERO 0

//Numbers
#define MAX_LENGTH10 10
#define MAX_LENGTH20 20

//Colors
#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"

//Strings
#define STR_DICT_LENGTH "Define dictionary length "
#define STR_INPT_KEY "Input the user DNI: "

//ADD strings
#define ERROR_ADD "Error adding this DNI exist\n"
#define OK_ADD "Adding completed\n"

//Menu Strings
#define STR_MEN_WELCOME "Welcome to this program please choose an option: \n"
#define STR_MEN_OPT_ADD "1- Add a new user \n"
#define STR_MEN_OPT_DEL "2- Delete a user \n"
#define STR_MEN_OPT_SEK "3- Search a user \n"
#define STR_MEN_OPT_MDF "4- Modify information for one person \n"
#define STR_MEN_OPT_PNT "5- Print all the inputs \n"
#define STR_MEN_OPT_EXT "0- Close the program \n"
#define STR_NOTVALID_OPT "Not valid option\n"
#define STR_THANKS "Thank you for use the program "

//Print Node Strings
#define STR_NODE_DNI "DNI: %i\n"
#define STR_NODE_NAM_SUR "Full name: %s %s\n"
#define STR_NODE_SEX "Sex: %c \n"
#define STR_NODE_BIRTHDATE "BirthDate: %i/%i/%i"


//Menu numbers
#define INT_MEN_OPT_ADD 1
#define INT_MEN_OPT_DEL 2
#define INT_MEN_OPT_SEK 3
#define INT_MEN_OPT_MDF 4
#define INT_MEN_OPT_PNT 5
#define INT_MEN_OPT_EXT 0

//Errors
#define STR_ERR_MEMORY "SYSTEM ERROR(Not enough memory)"
#define STR_ERR_INPUT "ERROR: not valid input, please re-enter input:"

#endif	/* STRINGS_H */

