#ifndef STRINGFUNCTIONS_H_INCLUDED
#define STRINGFUNCTIONS_H_INCLUDED

int get_frequency(const char* restrict str, const char character, int LenOfString);
int removeCharacterInString(char *str, int LenOfString, const char character);
int strcount(const char *str);

/*
source - source string
from - starting index from where you want to get substring
n - number of characters to be copied in substring
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
#endif // STRINGFUNCTIONS_H_INCLUDED
