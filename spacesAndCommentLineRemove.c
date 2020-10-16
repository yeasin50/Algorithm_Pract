#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool ignoreLine = false;

    FILE *fp1, *fp2;
    fp1 = fopen("globalInput.txt", "r");
    fp2 = fopen("globalOutput.txt", "w");

    char c;
    int a = 0;
    char prevChar;

    while ((c = fgetc(fp1)) != EOF)
    {

        //TODO: setup invisible here
        if (prevChar == '/' && c == '/')
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

        //TODO:: pass extra space
        if (prevChar == ' ' && c == ' ')
        {
            continue;
        }

        //TODO: set Visible
        if (c != '/')
        {
            // printf("%c", c);
            fputc(c, fp2);
        };

        prevChar = c;
    }

    fclose(fp1);
    fclose(fp2);
}
