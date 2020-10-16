#include <stdio.h>
#include <stdlib.h>

char prev = NULL;

int main()
{

    FILE *fp1, *fp2;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    char c;
    while ((c = fgetc(fp1)) != EOF)
    {
        if (prev == NULL)
        {
            // printf("%c", c);
            fputc(c,fp2);
            prev = c;
            continue;
        }
        else if (prev == ' ' && c == ' ')
        {
            continue;
        }
        else
        {
            // printf("%c", c);
            fputc(c,fp2);
            prev = c;
        }
    }
    fclose(fp1);
    fclose(fp2);
}
