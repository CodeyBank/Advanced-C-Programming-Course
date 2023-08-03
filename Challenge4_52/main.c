#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef enum{
    false = 0,
    true = !false
} bool;

bool hasCharacter(const char *line, const char ch){
    while(*line){
        if (ch == *line)
            return true;
        line++;
    }
    return false;
}

int main(int argc, char *argv[])
{

    // check that we have exactly three command line args
    if (argc != 3){
        char msg [50];
        strcpy(msg, "invalid Number of arguments");
        puts(msg);
        exit(1);
    }

    //Test purpose. remove when not in use.
//    for (int arg=0; arg < argc; arg++){
//        puts(argv[arg]);
//    }

    // try to open the file given
    FILE *file_ptr = NULL;

    file_ptr = fopen(argv[2], "r");

    // check if file was successfully opened
    if (file_ptr == NULL){
        char msg [50];
        strcpy(msg, "File failed to open");
        puts(msg);
        exit(1);
    }

    // read line by line
    char buffer [256] = {'\0'};
    char ch = argv[1][0];

    while(fgets(buffer,sizeof(buffer), file_ptr) != NULL){
        //check the buffer if the first character is same as the one give
        if(hasCharacter(buffer, ch)){
            puts(buffer);
        }
    }

    // close the file before terminating the application
    fclose(file_ptr);
    return 0;
}
