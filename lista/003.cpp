#include <iostream>
#include <thread>
using namespace std;

void organizar(int *vetor)
{
  int aux2;
  for (int i = 0; i < 20; i++)
  {
    for (int j = i + 1; i < 19; j++)
    {

      if (i % 2 == 0 && vetor[i] % 2 != 0)
      {
        break; 
      }
      else if (i % 2 != 0 && vetor[i] % 2 == 0)
      {
       break;
      }
      else
      {
        if (j % 2 == 0 && vetor[j] % 2 == 0)
        {
          aux2 = vetor[i];
          vetor[i] = vetor[j];
          vetor[j] = aux2;
        }
        if (j % 2 != 0 && vetor[j] % 2 != 0)
        {
          aux2 = vetor[i];
          vetor[i] = vetor[j];
          vetor[j] = aux2;
        }
      }
    }
  }

  cout << "Depois de organizar: \n";
  for (int i = 0; i < 20; i++)
  {
    cout << vetor[i] << " ";
  }
  cout << endl;
}
void preenhecer(int *vetor)
{

  int numerosImparesNoVetor = 0;
  int numerosParesNoVetor = 0;
  int aux, i = 0;
  srand(clock());
  while (i < 20)
  {

    aux = rand() % 50;
    cout << "Numeros impares no vetor: " << numerosImparesNoVetor  << endl;
     cout << "Numeros pares no vetor: " << numerosParesNoVetor  << endl;
    if (numerosParesNoVetor < 10  && aux % 2 == 0 )
    {
      vetor[i] = aux;
      i++;
      numerosParesNoVetor++;
    }
    if ( numerosImparesNoVetor < 10 && aux % 2 != 0 )
    {
      vetor[i] = aux;
      numerosImparesNoVetor++;
      i++;
    }
  }
  cout << "Antes de organizar: \n";
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
