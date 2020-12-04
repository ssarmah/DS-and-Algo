#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool palindrom(char s[],int first, int last)
{

    if (first == last)
    return true;


    if (s[first] != s[last])
    return false;


    if (first < last + 1)
    return palindrom(s, first + 1, last - 1);

    return true;
}

bool Pal(char s[])
{
int length = strlen(s);


if (length == 0)
    return true;

return palindrom(s, 0, length - 1);
}


int main()
{
    char s[50];
    printf("\n **************PALINDROM***************");
    printf("\n enter a string");
    scanf("%s",s);
    if (Pal(s))
    printf("\n The string is palindrom");
    else
    printf("\n The string is not palindrom");

    return 0;
}
