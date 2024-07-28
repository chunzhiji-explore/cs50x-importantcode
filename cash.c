#include <cs50.h>
#include <stdio.h>

int main(void)
{
     int n;
    do
    {
         n = get_int(" change owned:");
    }
    while (n<0);

    int a = n/25;
    int i = n-25*a;
    int b = i/10;
    int j = i-10*b;
    int c = j/5;
    int k = j-5*c;
    printf ("%i\n",a+b+c+k);

}
