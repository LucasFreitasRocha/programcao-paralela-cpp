// Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void preenhecer(int matriz[][5])
{
	srand(time(NULL));
	
	cout << " Matriz A: \n";
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matriz[i][j] = (rand() % 20) + 1;
			cout << matriz[i][j] << " ";
		}
		
		cout << endl;
	}
}

bool verificacao(int matriz[][5])
{
	int auxSoma = 0, somaMenor = 0, auxMult = 1, multMaior = 0;

	cout << "\nSomas: " << endl; //realiza a somas das colunas
	
	for (int i = 0; i < 5; i++)		//inverte linha com coluna, para fixar a coluna e ir pulando e somando em cada linha na coluna fixada
	{
		for (int j = 0; j < 4; j++)
		{
			auxSoma += abs(matriz[j][i]);
		}
		
		cout << auxSoma <<  " | ";  //mostra a soma de cada coluna
		
		if(somaMenor == 0)	//verifica qual soma é menor. se for zero, é a primeira iteração ainda
		{
			somaMenor = auxSoma;
		}
		else if(somaMenor > auxSoma)
		{
			somaMenor = auxSoma;
		}
		
		auxSoma = 0;
	}
	
	cout << endl << " \nMultiplicacoes:  " << endl;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			auxMult *= matriz[i][j];	//multiplica as linhas
		}
		
		cout << auxMult <<  " | ";	//mostra o produto de cada linha
			
		if(multMaior < auxMult)		//verifica o maior produto
		{
			multMaior = auxMult;
		}
		
		auxMult = 1;	//1 pq multiplcação por zero não daria certo
	}
	
	cout << endl;
	
	if(somaMenor <= multMaior) //verifica a condição
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char **argv)
{

	int matriz[4][5];
	preenhecer(matriz);

	if(verificacao(matriz))
	{
		cout << "\nCondicao Satisfeita" << endl;
	}
	else
	{
			cout << "\nCondicao Insatisfeita" << endl;
	}
	
	return 0;
}
