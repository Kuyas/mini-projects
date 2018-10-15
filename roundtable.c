#include<stdio.h>

int main()
{
    int N,K,X,i;
    scanf(" %d %d %d",&N,&K,&X);
    int a[N];
    int c = X%K;
    int count = 0;
    while(count<N)
    {
        for(i=(X+1); i<(X+c);i++)
        {
            a[i] = 0;
            count++;
        } 
    }
    for(i=0;i<N;i++)
    {
        if(a[i]==1)
            printf(a[i]);
    }
    return 0;
}

