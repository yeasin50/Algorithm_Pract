#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    bool ignoreLine = false;

    FILE *fp1, *fp2;
    fp1 = fopen("codeWithComment.txt", "r");
    fp2 = fopen("output2.txt", "w");

    char c;
    int a = 0;
    char prev;

    while ((c = fgetc(fp1)) != EOF)
    {

        //TODO: setup invisible here
        if (prev == '/' && c == '/')
        {
            ignoreLine = true;
        }

        if (c == '\n')
        {
            ignoreLine = false;
        }

        //TODO:  invisible char
        if (ignoreLine)
            continue;

        //TODO: set Visible
        if (c != '/')
        {
            // printf("%c", c);
            fputc(c, fp2);
        };

        prev = c;
    }

    fclose(fp1);
    fclose(fp2);
}
