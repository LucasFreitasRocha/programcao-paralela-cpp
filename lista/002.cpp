// Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Verifica se o produto da matriz pela sua transposta � igual a matriz identidade
bool verificar(int matrizMultiplicada[][4])
{
	int matrizI[4][4];	//matriz identidade
	bool ortogonal = true;	//variavel para armazenar se � ortogonal ou n�o
  
	cout << "\nMatriz identidade: \n\n";
  	//criando a matriz identidade
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
		    	matrizI[i][j] = 1;	//diagonal preenchida com 1
			}
		  	else
			{
		    	matrizI[i][j] = 0;	//resto da matriz preenchida com 0
		  	}
		  	
		  	cout << matrizI[i][j] << "\t ";	//mostra a matriz na tela organizada com um espa�amento de tab entre os n�meros
		 
		  	if (matrizMultiplicada[i][j] != matrizI[i][j])	//compara cada elemtento das matrizes para saber se o produto � a matriz identidade
			{
		    	ortogonal = false;
		  	}
		}
		
	cout << endl;	//pula linha na tela
	
	}
	
	return ortogonal;
}

//multiplica a matriz M pela sua transposta
void multiplicarMatriz(int matriz[][4], int matrizT[][4], int matrizMultiplicada[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrizMultiplicada[i][j] = 0;	//come�a com zero pois logo em seguida vai ser somada com o produto de cada linha com cada coluna, matriz vazia n�o � poss�vel fazer opera��es
			
			for (int k = 0; k < 4; k++)
			{
				matrizMultiplicada[i][j] += matriz[i][k] * matrizT[k][j];	//fixa uma linha de cada vez para ir multiplicando e somando com cada coluna da outra matriz
			}
		}
	}
	
	cout << endl;
	
	cout << "\nMatriz M x Mtransposta: \n\n";
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matrizMultiplicada[i][j] << "\t ";
		}
		
	cout << endl;
	
	}		
}

//cria a matriz transposta de M
void matrizTransposta(int matriz[][4], int matrizT[][4], int matrizMultiplicada[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
      		matrizT[i][j] = matriz[j][i];	//matriz transposta = linha vira coluna e coluna vira linha
		}
	}
	
	cout << "\nMatriz Mtransposta: \n\n";
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matrizT[i][j] << "\t ";
		}
		
	cout << endl;
	
	}	
  	
	multiplicarMatriz(matriz, matrizT, matrizMultiplicada);		//ap�s criar a transposta, j� chama a fun��o de multiplica��o
}

//cria a matriz M com n�meros inteiros aleat�rios de 0 a 29
void preencher(int matriz[][4], int matrizT[][4], int matrizMultiplicada[][4])
{
  	srand(time(NULL));	//sincroniza com o clocl do computador para n�o gerar a mesma sequ�ncia de n�meros aleat�rios

	for (int i = 0; i < 4; i++)
	{
    	for (int j = 0; j < 4; j++)
		{
     		matriz[i][j] = rand() % 29;
		}
	}
	
	cout << "Matriz M: \n\n";
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matriz[i][j] << "\t ";
		}
		
	cout << endl;
	
	}			
	
	matrizTransposta(matriz, matrizT, matrizMultiplicada);	//ap�s criar a matriz M, j� chama a fun��o para criar a transposta
}

int main(int argc, char **argv)
{
	int matriz[4][4];
	int matrizT[4][4];
	int matrizMultiplicada[4][4];
  
  	preencher(matriz, matrizT, matrizMultiplicada);
 
 	if(verificar(matrizMultiplicada))		//verifica se � ortogonal, olhando o resultado da variavel ortogonal
	{
		cout << "\nMatriz M e ortogonal \n";
	}
	else
	{
		cout << " \nMatriz M nao e ortogonal\n";
	}
	
  return 0;
}
