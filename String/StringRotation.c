#include <stdio.h>

/**
 *Method one£ºDirect Shift
 * 
 *1.Define a function that moves the first place of the string to the end.
 *2.Calling the function n times £¬then can move the n characters at the 
 *  beginning of the string to the end. 
*/
void LeftShift(char* s, int n)
{
    int i; 
    char temp = s[0];
    for (i = 1; i < n; i++)
    {
        s[i - 1] = s[i];
    } 
    s[n - 1] = temp;
}

void LeftRotateString(char* s, int n, int m)
{
    while (m--)
    {
        LeftShift(s, n);
    }
}


int main()
{
    char s[] = "abcd";
    LeftRotateString(s, 4, 2);
    printf(s);
    return 0;
}
