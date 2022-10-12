#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

/*void PreencherMat (int MatL[][tam], int B[tam])
{
	int i,j;
	srand(time(NULL));
		
	for(i=0;i<tam;i++)
	{
		for (j=0;j<tam;j++)
		{
			if(j>i){
				MatL[i][j]=0;
			}else{
			MatL[i][j]=rand()%10+1;
			B[i]=rand()%10+1;
			}
		}
	}
}
*/



int main()
{
	
	int MatL[3][3] = {3, 1, 0, 0, 2, -1, 0, 0, 3};
	int B[3]= {4, 2, 0};
	int X[3];
	
	
	
	void CalcularX (int MatL[][3], int X[3], int B[3])
{
	int s=0;
	int i, j, n = 3;
	for(i = 0; i < n; i++)
	{
		X[i]=0;
		for (j = 0; j <= i - 1; j++)
		{
			s=s+MatL[i][j]*X[j];	
		}
		X[i]=(B[i]-s)/MatL[i][i];
		s=0;
		printf("\nX%d = %d\n",i,X[i]);
	}
}

void Imprimir (int MatL[][3],int B[3])
{
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			printf("|%d|\t",MatL[i][j]);
		}
		printf(" = %d\t",B[i]);
		printf("\n");
	}	
}
	
	Imprimir(MatL,B);
	CalcularX (MatL, X, B);
	
}
	
