#include <stdio.h>

void swap(int *a, int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int main()
{
    int n,s,i,j;
    scanf("%d",&n);
    int h1[n],m1[n],h2[n],m2[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&h1[i],&m1[i],&h2[i],&m2[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            //Swap Variables
            if(h1[j]<h1[i])
            {
            swap(&h1[j],&h1[i]);
            swap(&h2[j],&h2[i]);
            swap(&m1[j],&m1[i]);
            swap(&m2[j],&m2[i]);
            }

        }
    }
    //Count no of cabs
    int c = 1;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n-1;j++)
        {
            if(h1[j]<h2[i])
            {
                c++;

            }
            else if((h1[j]==h2[i])&&(m1[j]<m2[i]))
            {
                c++;
            }
            else
            {
                i++;j++;
            }

        }
    }

    printf("%d\n",c);

    for(i=0;i<n;i++)
    {
        printf("%d.%d\t%d.%d\n",h1[i],m1[i],h2[i],m2[i]);
    }
    return 0;
}



