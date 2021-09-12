#include <iostream>
#include <thread>
using namespace std;

void preenhecer(int *vetor)
{
  srand(clock());

  for (int i = 0; i < 30; i++)
  {
    vetor[i] = (rand() % 30) + 1;
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
    for (int j = 0; j < 29; j++)
    {
      if (vetor[j] < vetor[j + 1])
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
