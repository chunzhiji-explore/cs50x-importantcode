#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    //为新字符串提供内存
    char *t = malloc(strlen(s) + 1);
    if （t == NULL）
    {
        return 1;
    }

    //等效于 strcpy（t, s);
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    // 释放malloc所调用的内存
    free(t);
    return 0;

}
