#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rotate (char c, int n);
int main(int argc, string argv[])
{
     if (argc != 2 )
     {
        printf("Usage: ./caesar key\n");
        return 1;
     }
     for(int k=0; k<strlen(argv[1]);k++)
     if (!isdigit(argv[1][k]))
     {
        printf("Usage: ./caesar key\n");
        return 1;
     }
     else
     {
        int i = atoi (argv[1]);
        string plaintext= get_string("plaintext: ");
        for(int j=0 ; j < strlen(plaintext) ; j++)
        plaintext[j] = rotate (plaintext[j], i );
        printf("ciphertext: %s\n", plaintext);
     }
}
char rotate (char c, int n)
{
    if(c>='a' && c<='z')
 {
    return 'a'+ (c - 'a' + n) % 26;
 }
    else if (c>='A' && c<='Z')
 {
     return 'A'+ (c - 'A' + n) %26;
 }
    else
 {
     return c;
 }
}
