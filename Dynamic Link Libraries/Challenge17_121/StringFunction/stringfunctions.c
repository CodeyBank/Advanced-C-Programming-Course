/**
  ******************************************************************************
  * @file    main.c
  * @author  Stanley Ezeh
  * @brief   String functions created as a challenge for Advanced C programming
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019-2021 StanleyCorp.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include <stdio.h>

int strcount(const char *str) {
    int count=0;
    while(*(str++) != '\0') {
        count++;
    }
    return count;
}


int get_frequency(const char* restrict str, const char character, int LenOfString) {
    int frequency = 0;
    for(int i=0; i<LenOfString; i++) {
        if(str[i] == character) {
            frequency++;
        }
    }

    return frequency;
}

int removeCharacterInString(char *str, const char character) {
    int numOfCharactersRemoved = 0;
    // int i=1, j=0;
    // for (i =0; str[i]!='\0'; i++){
    //     for(j=i; str[j]!='\0'; j++){
    //         if(str[j] == character){
    //            str[j] = str[j+1];
    //            break;
    //         }
    //     }
    // }
//    while(*str != '\0'){
//        if(*str == character){
//            *str = *(str+1);
//            numOfCharactersRemoved++;
//            i++;
//            continue;
//        }
//        str++;
//    }
//
//    *str = '\0';
    return numOfCharactersRemoved;
}

int substring(char *source, int start, int numOfCharacters, char *target) {
    int len=0;
    //get the length of the string
    for(len=0; source[len]!='\0'; len++);

    // check the start
    if(start > len) {
        return 1;
    }

    if(start < 0) {
        start += len;
    }

    if((start+numOfCharacters)> len||(numOfCharacters == -1)) {
        numOfCharacters = len - start;
    }

    for(int j=start; j<(start+numOfCharacters); j++) {
        *target = source[j];
        target++;
    }

    *target = '\0';
    return 0;
}


int strCopy(char *source, char *destination) {

    // exit if invalid string is sent
    if ((source==NULL) || (sizeof(source[0]) != sizeof(char))) {
        return 1;
    }

    int i=0;
    for (i=0; source[i]!='\0'; i++) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return 0;
}

int strConcat(char *str1, char *str2) {

    while(*str1!= '\0') str1++;

    while(*str2 != '\0'){
        *str1 = *str2;
        str2++;
        str1++;
    };
   *str1 = '\0';

    return 0;
}
