#include<stdio.h>
int main()
{
     int N,K,X,i,no,f;
    scanf(" %d %d %d",&N,&K,&X);
    int a[N];
    int flag;
    int count = 0;
    int c = X%K;
     int cnt = 0;
    for(i=0;i<N;i++)
    {
        a[i]=1;
    }

    while(count<N){

            i=X-1;
            c=X%K;
            if(c==0)
                i++;
            while(c!=0)
            {
                i++;
                if(i==N)
                    i=0;
                if(a[i]==0)
                    c++;
                a[i]=0;
                c--;
            }
            flag=0;
            for(;i<N;i++)
            {
                if(a[i]==1&&flag==0)
                {
                    X=i+1;
                    flag=1;
                }
            }
            count++;
    }

    //Print no of person alive
    for(i=0;i<N;i++)
    {
        if(a[i]==1)
            printf("%d",i+1);
    }
}
