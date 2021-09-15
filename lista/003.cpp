//Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void organizar(int *vetor)
{
	int aux2;	//vari�vel para armazenar temporariamente o elemento do vetor que quero mudar de posi��o
	
  	for (int i = 0; i < 20; i++)
	{
    	for (int j = i + 1; i < 19; j++)	//pega sempre o pr�ximo elemento. Para no 18, pq o proximo vai ser 19, assim n�o foge do range do vetor
		{
			if (i % 2 == 0 && vetor[i] % 2 != 0)	//verifica se a posi�ao do vetor � par e o elemento dele � �mpar, caso verdadeiro, parte pra pr�xima itera��o
			{
       			break;
			}
			else if (i % 2 != 0 && vetor[i] % 2 == 0)	//verifica se a posi�ao do vetor � �mpar e o elemento dele � par, caso verdadeiro, parte pra pr�xima itera��o
			{
				break;
			}
			else
			{
				if (j % 2 == 0 && vetor[j] % 2 == 0)	//caso contrario, verifica se os dois s�o pares, caso positivo, � realizado a troca do atual com o pr�ximo
				{
			        aux2 = vetor[i];
			        vetor[i] = vetor[j];
			        vetor[j] = aux2;
				}
       			if (j % 2 != 0 && vetor[j] % 2 != 0)	////caso contrario, verifica se os dois s�o �mpares, caso positivo, � realizado a troca do atual com o pr�ximo
				{
			        aux2 = vetor[i];
			        vetor[i] = vetor[j];
			        vetor[j] = aux2;
        		}
      		}
    	}
	}

	cout << "\nDepois de organizar: \n";
	
	for (int i = 0; i < 20; i++)
	{
    	cout << vetor[i] << " ";
  	}
  	
  	cout << endl;
}


void preenhecer(int *vetor)
{

	int numerosImparesNoVetor = 0;	//contador de numeros impares
	int numerosParesNoVetor = 0;	//contador de numeros impares
	int aux, i = 0;		//contador da delimita��o de pares e impares
	srand(time(NULL));
  
  	cout << "Preenchendo vetor...\n "  << endl;
  
	while (i < 20)	
	{
	    aux = rand() % 50;

	    if (numerosParesNoVetor < 10  && aux % 2 == 0)	//delimita a quantidade de numeros pares no vetor
		{
      		vetor[i] = aux;
     		i++;
     		numerosParesNoVetor++;
	    }
	    
	    if (numerosImparesNoVetor < 10 && aux % 2 != 0)		//delimita a quantidade de numeros impares no vetor
		{
	      vetor[i] = aux;
	      numerosImparesNoVetor++;
	      i++;
		}
		
		cout << "Numeros impares no vetor: " << numerosImparesNoVetor  << endl;
	    cout << "Numeros pares no vetor: " << numerosParesNoVetor  << endl;
	}
	
	cout << "\nAntes de organizar: \n";
	
	for (int i = 0; i < 20; i++)
	{
		cout << vetor[i] << " ";
	}
	
	cout << endl;
}

int main(int argc, char **argv)
{
	int vetor[20];
	preenhecer(vetor);
	organizar(vetor);
	
	return 0;
}
