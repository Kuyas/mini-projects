#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int e,m;
	scanf("%d %d",&e,&m);
	int row = 100;
	int col = e/m;
	int a[row][col];

	int i,j;
	//MAX E cond
	for(i=0;i<m;i++)
	{
		if(i==(m-1)){
			a[0][i] = e;
		}
		else{
			a[0][i] = 0;
		}
	}
	int e1=e;
	int m1=m;

	// MIN E CONDITION
	for(i=0;i<m;i++)
	{
		a[1][i]=e/m;
		e1=e1-e/m;

	}
	if(e1!=0){
		a[1][i-1]+=e1;
	}
	e1=e;
	m1=m;
	i=1;

	int k=2;
	//OTHER CONDITIONS
	for(k=2;k;k++){
		for(j=0;j<m;j++){
			while(i<e/m){
				e1=e1-i;
				if(i<2&&i>0){
					continue;
				}
				else{
					
				}

			}
		}
	}



	return 0;
}