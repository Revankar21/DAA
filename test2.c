
#include <stdio.h>
#include <stdlib.h>
int i,j,k=0,pop[10],v[10];
void dfs(int source,int a[10][10],int n)
{
    int stack[10],top=-1;
    v[source]=1;
    stack[++top]=source+1;
    while(top!=-1)
    {
        for(j=0;j<n;j++)
        {
            if( a[source][j]==1 && v[j]==1)
            {
                for(i=top;i>=0;i--)
                if(stack[i] == j+1)
                {
                    printf("\n Topological order not possible");
                    exit(0);
                }
            }
            else
            {
                if( a[source][j] == 1 && v[j] == 0)
                {
                    v[j]=1;
                    stack[++top]=j+1;
                    source=j;
                    j=0;
                }
            }
        }
        pop[k++]=source+1;
        top--;
        source=stack[top]-1;
    }
}
void topo(int a[10][10], int n)
{
for(i=0;i<n;i++)
v[i]=0;
for(i=0;i<n;i++)
if(v[i]==0)
dfs(i,a,n);
}
int main()
{
    int n,a[10][10];
    printf("Enter the no. of vertices:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    topo(a,n);
    printf("The topological ordering is:\n");
    for(i=n-1;i>=0;i--)
    printf("%d\t",pop[i]);
}





