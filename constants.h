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
#define TEN 10
#define YEARNUMBER 2017
#define NUMB_DAYS 31
#define NUMB_MONTH 12
#define LENGTH_1 1
#define LENGTH_2 2
#define LENGTH_4 4
#define INT_2_0 00
#define INT_4_0 0000

//Chars
#define CHAR_N 'N'

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
#define STR_ADD_CONJ "How many users you want to input? "
#define STR_NULL "NULL"
#define STR_ADD_CRRT "Adding correct of user with DNI: %d"

//ADD strings
#define ERROR_ADD "Error adding this DNI exist\n"
#define OK_ADD "Adding completed \n\n"

//DELETE strings
#define ERROR_DEL "Error deleting, this DNI not exist\n"
#define OK_DEL "Deletion completed \n\n"

//Menu Strings
#define STR_MEN_WELCOME "Welcome to this program \n"
#define STR_MEN_OPT_ADD "1- Add a new user \n"
#define STR_MEN_OPT_DEL "2- Delete a user \n"
#define STR_MEN_OPT_SEK "3- Search a user \n"
#define STR_MEN_OPT_MDF "4- Modify information for one person \n"
#define STR_MEN_OPT_PNT "5- Print all the inputs \n"
#define STR_MEN_OPT_AD2 "6- Add a conjunt of users \n"
#define STR_MEN_OPT_EXT "0- Close the program \n"
#define STR_MEN_CHOOSE  "Please choose an option: "
#define STR_NOTVALID_OPT "Not valid option\n"
#define STR_THANKS "Thank you for use the program "
#define STR_FOUND "Found!!! \n\n"
#define STR_JUMP "\n\n"

//Print Node Strings
#define STR_NODE_NUSER "User %d: \n"
#define STR_NODE_DNI "DNI: %i\n"
#define STR_NODE_NAM_SUR "Full name: %s %s\n"
#define STR_NODE_SEX "Sex: %c \n"
#define STR_NODE_BIRTHDATE "BirthDate: %i/%i/%i\n"

//Node Strings
#define STR_OPENING "Input user information: \n"
#define STR_DNI "DNI: "
#define STR_NAME "Name: "
#define STR_SURNAME "Surname: "
#define STR_SEX "Sex: "
#define STR_BIRTH_DATE "Birth date: "
#define STR_MOD_INF1 "Write NULL if you don't want to modify this information \n"
#define STR_MOD_INF2 "Write N if you don't want to modify this information \n"
#define STR_MOD_INF3 "Write 00 in day or month or 0000 in year if you don't want to modify this field \n"
#define STR_MOD_END "Modification completed \n\n"

//Menu numbers
#define INT_MEN_OPT_ADD 1
#define INT_MEN_OPT_DEL 2
#define INT_MEN_OPT_SEK 3
#define INT_MEN_OPT_MDF 4
#define INT_MEN_OPT_PNT 5
#define INT_MEN_OPT_AD2 6
#define INT_MEN_OPT_EXT 0

//Errors
#define STR_ERR_MEMORY "SYSTEM ERROR(Not enough memory) \n"
#define STR_ERR_INPUT "ERROR: not valid input, please re-enter input: "
#define STR_ERR_NEXTS "Error printing the person, not exists \n"
#define STR_ERR_EMPTY "Print fail: Llista buida \n"
#define STR_ERR_ADD "Error adding user with DNI: %d, already exist \n"

#endif	/* STRINGS_H */

