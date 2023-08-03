#ifndef STRINGFUNCTIONS_H_INCLUDED
#define STRINGFUNCTIONS_H_INCLUDED

int get_frequency(const char* restrict str, const char character, int LenOfString);
int removeCharacterInString(char *str, const char character);
int strcount(const char *str);

/*
source - source string
start - starting index from where you want to get substring
numOfCharacters - number of characters to be copied in substring
target - target string in which you want to store targe string
return type - int : 0 on success
*/
int substring(char *source, int start, int numOfCharacters, char *target);

/*
source – string to copy from
destination – second string to copy to
return type - int : 0 on success
*/
int strCopy(char *source, char *destination);

/*
str1 – string to concatenate to (resulting string)
str2 – second string to concatenate from
return type - int : 0 on success
*/
int strConcat(char *str1, char *str2);
#endif // STRINGFUNCTIONS_H_INCLUDED
