#include <iostream>
#include <thread>
using namespace std;

void preenhecer(int matriz[][5])
{
	srand(clock());
	cout << " Matriz \n";
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

	cout << "Somas: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
				auxSoma += abs( matriz[j][i]);
		}
		cout << auxSoma <<  " ";
		if(somaMenor == 0){
			somaMenor = auxSoma;
		}else if(somaMenor > auxSoma){
			somaMenor = auxSoma;
		}
		auxSoma = 0;
	}
	cout << endl << " Multiplicacoes:  " << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			auxMult *= matriz[i][j];
		}
		cout << auxMult <<  " ";
		if(multMaior < auxMult){
			multMaior = auxMult;
		}
		auxMult = 1;
	}
	cout << endl;
	if(somaMenor <= multMaior){
		return true;
	}else{
		return false;
	}
}

int main(int argc, char **argv)
{

	int matriz[4][5];
	preenhecer(matriz);

	if(verificacao(matriz)){
		cout << "Condicao Satisfeita" << endl;
	}else{
			cout << "Condicao Insatisfeita" << endl;
	}
	return 0;
}
