#include<stdio.h>
int main()
{
    int a[5][5];
    int i,j ;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            a[i][j] = 0;
        }
    }
    
    int x,y,z;
    for(i=0;i<=3;i++){
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] = z;
        a[y][x] = z;
        printf("Got out\n ");
    }
    printf("Got out suzz");
    int arr[5], req[5];
    int dist = 0, k;
    int min;
    for(i=0;i<5;i++){
        arr[0] = i;
        int pos =1;
        while(pos!=6){
            for(j=0;j<5;j++){
                if(a[i][j])
                {
                    arr[pos++] = j;
                    dist+= a[i][j];
                    i = j;
                    break;
                }
            }
        }
        if(dist<min)
        {
            min = dist;
            for(k=0;k<5;k++)
            {
                req[k] = arr[k];
            }
        } 
    }
    for(i=0;i<5;i++)
    {
        printf("%d ", req[i]);
    }
    printf("\n %d", min);

}