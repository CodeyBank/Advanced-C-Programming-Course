#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


#define SPECIFIER '#'
void printLN(const char* str, ...);

int sum(int count, ...);

/*
    chose a data type
*/

/*
    This function requires the first and second parameters to be passed at the very least
    in order to compute the average. You must pass a sentinel value of -1.0 to indicate
    the end of the list.

*/
double average_with_sentinel(double first, double second, ...);

/* Should return an array of indices for each occurrence of a character*/
int *get_index(const char * str, const char ch);


/* Returns the number of times a character occurs in an array */
int get_number_of_occurences(const char *str, const char ch);

int main()
{
    char test[] = "This is a test # to count how # many # are in this string #";

    int res =0;
    char ch = '#';
    res = get_number_of_occurences(test, SPECIFIER);
    int *arrresult;

    arrresult = get_index(test, ch);

    // print it out
    for (int i=0; i< res; i++)
        printf("index: %d\n", arrresult[i]);


    // free the allocated memory
    free(arrresult);
    return 0;
}


void printLN(const char* str, ...){

    /*
        1. search through the string for the format specifiers #
        2. Count how many they are so that we can use them to loop through the va_list
        2. Get the index of the format specifier and use that to get the format type.
        4. Using the format type, replace the variable with the format specifier at the right index
        5. Use puts to print to console.
        6  TODO Implement error handling routines
    */

    int numOfOccurrences=0; // be used to extract the number of parameters from the va_list
    int *indices;

    numOfOccurences = get_number_of_occurences(str, SPECIFIER);
    if (numOfOccurrences < 1){
        /*Prepare error conditions. use Jump to label to handle errors like this*/
    }

    indices = get_index(str, SPECIFIER); // to be used for replacements

    //get the array of datatypes. for now we support three types, f d and c
    char datatypes[numOfOccurences]


    // begin varable argument definitions
    va_list arg_ptr;
    va_start(arg_ptr, str);

    // loop through the argument list to extract the variables. ?? do we need to convert before inserting
    for(int i =0; i<numberOfOccurences; i++){
        if (str[])
    }

}

int *get_index(const char * str, const char ch){
    /*
        * For the first run, count how many times the character occurred
        * use this value to create an array dynamically on the heap
        * run through the character array again but this time recording
            the location of the character
    */

    int sizeofarray = get_number_of_occurences(str, ch);

    // create the array on the heap
    int *indices=NULL;
    indices = (int*)malloc(sizeof(int)*sizeofarray);

    // return if unable to dynamically create array
    if(indices == NULL) exit(EXIT_FAILURE);

    int index=0;
    // run through the array collect the locations.
    for (int i=0; i< strlen(str); ++i){
        if(str[i]==ch){
            indices[index++]=i;
        }
    }

    return indices;
}

int get_number_of_occurences(const char *str, const char ch){
    /*
        Iterate through the character array and count how many times string occured
    */
    int num_of_occurences=0;

    for (int i=0; i<strlen(str); i++){
        if (str[i]==ch){
            num_of_occurences++;
        }
    }

    return num_of_occurences;
}
