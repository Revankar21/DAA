#include <stdio.h>
#include <string.h>
#define MAX 256
int t[MAX];
int count = 0;
void shifttable(char pat[])
{
    int m = strlen(pat);
    for (int i = 0; i < MAX; i++)
        t[i] = m;
    for (int j = 0; j < m - 1; j++)
        t[pat[j]] = m - 1 - j;
}
int horspool(char src[], char pat[])
{
    int n = strlen(src);
    int m = strlen(pat);
    int i = m - 1;
    while (i < n)
    {
        int k = 0;
        while ((k < m) && (pat[m - 1 - k] == src[i - k]))
            k++;
            
        if (k == m)
            return (i - m + 1);
        else
        {
            i = i + t[src[i]];
            count = count + 1;
        }
    }
    return -1;
}
int main()
{
    char src[100], pat[10];
    int pos;
    printf("\nEnter the main source string:\n");
    scanf("%s", src);
    printf("\nEnter the pattern to be searched\n");
    scanf("%s", pat);
    shifttable(pat);

    pos = horspool(src, pat);
    if (pos >= 0)
    {
        printf("\n Found at %d position ", pos + 1);
        printf("\n Number of shifts are %d", count);
    }
    else
        printf("\n String match failed");
    return 0;
}



