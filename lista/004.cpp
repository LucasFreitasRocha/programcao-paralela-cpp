// Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void preenhecer(int *vetor)
{
	srand(time(NULL));
	
	for (int i = 0; i < 30; i++)
	{
    	vetor[i] = (rand() % 30) + 1;  //zero não entra, somente de 1 a 30 (incluidos)
	}
}


void imprimir(int *vetor)
{
	for (int i = 0; i < 30; i++)
	{
		cout << vetor[i] << " ";
	}
}


void ordenar(int *vetor)
{
	int aux;
	
	for (int i = 0; i < 30; i++)
	{
    	for (int j = 0; j < 29; j++)	//para no 28, pra poder comparar com o proximo que é o último - 29 (posição no vetor)
		{
      		if (vetor[j] < vetor[j + 1])	//compara o atual com o próximo, caso for menor, faz a troca
			  {
		        aux = vetor[j];
		        vetor[j] = vetor[j + 1];
		        vetor[j + 1] = aux;
      		}
    	}
  	}
}

int main(int argc, char **argv)
{
	int vetor[30];
	preenhecer(vetor);
	
	cout << " \n Antes de ordenar! \n";
	imprimir(vetor);
	ordenar(vetor);
	
	cout << " \n Depois de ordenar! \n";
	imprimir(vetor);
	cout << endl;
	
	return 0;
}
