#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void foo(char * str);

void foo(char * str)
{
    struct sample
    {
        int length;
        char *str;
    };

    // struct sample *s = malloc(sizeof(struct sample));
    // s->length = 10;
    // s->str = malloc(s->length + 1);

    // strcpy(s->str,"abcdefghij");

    // // s->str[s->length] = '\0';
    // // s->str[s->length] = 'k';
    // printf("%s\n",s->str);
    // printf("%c\n",s->str[s->length]);

    /*-------------------------------------------------*/

    struct sample *s = malloc(sizeof(struct sample));
    s->length = 10;

    // s->str = str;
    // strcpy(s->str, str);
    // s->str[s->length] = '\0';
    char *t = str;
    char *temp = t;
    while (*temp)
    {
        temp++;
    }
    *temp = 'k';
    temp++;
    *temp = 'l';
    temp++;
    *temp = '\0';
    // s->str[s->length] = 'k';
    // s->str[s->length + 1] = '\0';
    printf("%s\n", s->str);
    printf("%c\n", s->str[s->length]);
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    char str[] = "abcdefghij";
    foo(str);
    system("pause");
    return 0;
}
