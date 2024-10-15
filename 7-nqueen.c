#include <stdio.h>
#include <stdlib.h>
void nqueens(int n);
int can_place(int c[10],int r);
void display(int c[10],int r);
int count = 0;
int main()
{
 int n;
 printf("Enter n(no. of queens):");
 scanf("%d",&n);
 if(n==2||n==3)
 printf("Solution does not exist.");
 else
 {
     nqueens(n);
     printf("Total no. of solutions: %d\n",count);
 }
 return 0;
}
void nqueens(int n)
{
    int c[10],i,r=0;
    c[r]=-1;
    while(r>=0)
    {
        c[r]++;
        while(c[r]<n && !can_place(c,r))
        c[r]++;
        if(c[r]<n)
        {
            if(r==n-1)
            {
                printf("Solution %d:",++count);
                for(i=0;i<n;i++)
                printf("%4d",c[i]+1);
                display(c,n);
            }
            else
            {
                r++;
                c[r]=-1;
            }
        }
        else
        r--;
    }
}
int can_place(int c[10],int r)
{
    int i;
    for(i=0;i<r;i++)
    {
        if((c[i]==c[r])||(abs(i-r)==abs(c[i]-c[r])))
        return 0;
    }
    return 1;
}
void display(int c[10],int n)
{
    char cb[10][10];
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cb[i][j]='-';
    for(i=0;i<n;i++)
    cb[i][c[i]]='Q';
    printf("\n\nChessboard: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%4c",cb[i][j]);
        printf("\n\n");
    }
}