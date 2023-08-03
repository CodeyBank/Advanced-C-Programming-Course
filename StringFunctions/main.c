/**
  ******************************************************************************
  * @file    stm32wbxx_it.c
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
  #include <strings.h>
  #include "StringFunctions.h"


int strcount(const char *str){
    int count=0;
    while(*(str++) != '\0'){
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

int removeCharacterInString(char *str, int LenOfString, const char character){
    int numOfCharactersRemoved = 0, len=0;
    char newString[LenOfString];

    for (char *start=str; *start != '\0'; start++) {
        if (*start== character){
            numOfCharactersRemoved++;
            continue;
        }
        newString[len] = *start;
        len++;
    }
    newString[len+1] = '\0';
    printf("Length of new string is %d", (int)strlen(newString));

    //copy the newstring back to the old string
    for(char *s=newString; *s != '\0'; s++){
        *str = *s;
    }
    *str = '\0';

    //*str = dst-(LenOfString-numOfCharactersRemoved);


    return numOfCharactersRemoved;

}

int substring(char *source, int start, int numOfCharacters, char *target){
    int len=0, j;
    //get the length of the string
    for(len=0; source[len]!='\0'; len++);

    // check the start
    if(start > len){
        return 1;
    }
    if((start+numOfCharacters)> len||(numOfCharacters == -1)){
        numOfCharacters = len - start;
    }

    for(j=start; j<(start+numOfCharacters); j++ ){
        target[j] = source[j];
    }

    target[j] = '\0';
    return 0;
}


int strCopy(char *source, char *destination){

    // exit if invalid string is sent
    if ((source==NULL) || (sizeof(source[0]) != sizeof(char))){
        return 1;
    }
//    while(*(source++) != '\0'){
//        *source = *destination;
//        destination++;
//    }
    int i=0;
    for (i=0; source[i]!='\0'; i++){
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return 0;
}

