#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "tests.h"

// Using the function my_strchr, write a function that computes and returns an array with all the positions of the occurrences of a character in a string.
 const char* my_strchr(const char* s, char character){
    // TODO your code here
    while (*s != '\0') {
        if (*s == character) {
            return s;
        }
        s++; 
    }
    return NULL;
}


void find_all( const char * str, char character, int*  positions, unsigned int cap, unsigned int * l){
    memset(positions, -1, cap * sizeof(int));
    const char* p= str;
    int i = 0;
    while ((p = my_strchr(p, character)) != NULL && i < cap) {
        positions[i++] = p - str;
        p++;
    }
    *l = i;
 }



int main()
{
#if  ENABLE_TESTS > 0
    run_tests(true);
#endif 

    return 0;
}
