#include <dlfcn.h>
#include <stdio.h>

//char *dll_path = "C:\Users\Stanley.Ezeh\Documents\Advanced C Programming\Dynamic Link Libraries\Challenge17_121\bin\libstringfunctions.dll";
char *dll_path2 = "C:/Users/Stanley.Ezeh/Documents/Advanced C Programming/Dynamic Link Libraries/Challenge17_121/bin/libstringfunctions.dll";

int main(void)
{
    //dlopen(dll_path, RTLD_LAZY);
    // Handle for the dlopen api
    void *handle = NULL;

    // function pointers
    int (*get_frequency)(const char* restrict, const char, int)=NULL;
    int (*removeCharacterInString)(char*, const char)=NULL;
    int (*substring)(char*, int, int, char*)=NULL;
    int (*strCopy)(char*, char*)=NULL;
    int (*strConcat)(char*, char*)=NULL;
    int (*strcount)(const char *str) = NULL;

    // error 
    char *err = NULL;

    if((handle = dlopen(dll_path2, RTLD_LAZY)) == NULL){
        fputs(dlerror(),stderr);
        return (1);
    }

    // clear all error conditions
    dlerror();

    // Resolve all required symbols
    get_frequency = dlsym(handle,"get_frequency");
    substring = dlsym(handle,"substring");
    strCopy = dlsym(handle,"strCopy");
    strConcat =dlsym(handle,"strConcat");
    strcount =dlsym(handle, "strcount");

    // Check again for errors
    err = dlerror();
    if(err){
        fputs(err, stderr);
        return (1);
    }

    /**
     * 
     * @brief Run the tests here
     * @author Stanley Ezeh
     * ---------------------------------------------------------
     */

    char *c = "Hi i want to remove all the letters i in this string";

    // string count
    printf("\nNumber of characters is %d",strcount(c));
    char d [strcount(c)];

    // string copy test
    (*strCopy)(c, d);
    printf("\n%s \n",d);

    // Substring test
    int numberOfCharcters = 9;
    char subString[numberOfCharcters];
    (*substring)(c, -6, numberOfCharcters, subString);
    printf("%s\n", subString);

    // stringconcat test
    char left[100] = "I want to concatenate this";
    char *right = "with this second string";
    (*strConcat)(left, right);
    printf("%s\n", left);

    /**End of tests -----------------------------------------*/

    // close the handle
    dlclose(handle);


}