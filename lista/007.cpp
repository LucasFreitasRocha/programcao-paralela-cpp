// Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void preencher(int *vetor)
{
  	srand(time(NULL));
  
	for (int i = 0; i < 50; i++)
	{
	vetor[i] = (rand() % 100) + 1;
	cout << vetor[i] << " ";
	}
	cout << endl;
}

int getMaior(int *vetor, int contador, int maior)	//contador vai andando a posiçao no vetor;
{

	if (contador == 50)		//verificar se chegou no último elemento, para já entregar o maior
	{
	return maior;
	}
	
	if (maior < vetor[contador])	//se o atual maior é menor que o elemento atual sendo verificado, maior é substituido pelo elemento atual
	{
	maior = vetor[contador];
	}
  
  	contador++;

	return getMaior(vetor, contador, maior); //enviar a proxima posição e o maior atual
}

int main(int argc, char **argv)
{
	int vetor[50];
	cout << "Vetor: ";
	preencher(vetor);
	
	int maior = getMaior(vetor, 0, 0); 
	cout << "\nMaior do vetor: "  << maior << endl;
	
	return 0;
}
