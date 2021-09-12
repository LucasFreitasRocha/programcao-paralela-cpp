#include <iostream>
#include <thread>
using namespace std;

bool ehcomposto(int numero, int divisor, int contador)
{
  if (divisor >= numero)
  {
    if (contador >= 3)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    if (numero % divisor == 0)
    {
      contador++;
    }
    divisor++;
    ehcomposto(numero, divisor, contador);
  }
}
void preenhecer(int *vetor)
{
  srand(time(NULL));
  int numeroCompsotos = 0, numeroNaoCompostos = 0, i = 0, aux = 0;
  while (i < 20)
  {
    cout << "Digite um numero: " << endl;
    cin >> aux ;
    
    if (ehcomposto(aux, 1, 0) && numeroCompsotos < 10)
    {
      i++;
      numeroCompsotos++;
      vetor[i] = aux;
    }
    if (!ehcomposto(aux, 1, 0) && numeroNaoCompostos < 10)
    {
      i++;
      numeroNaoCompostos++;
      vetor[i] = aux;
    }
    cout << "tem " << numeroCompsotos << " numeros compostos, precisamos de 10" << endl;
    cout << "tem " << numeroNaoCompostos << " numeros não compostos, precisamos de 10" << endl;
  }

  for (int j = 0; j < 20; j++)
  {
    cout << vetor[j] << " ";
  }
  cout << endl;
}
void organizar(int *vetor, int contador, int total)
{
  int aux = 0;
  if (!(contador >= 10))
  {
    if (ehcomposto(vetor[contador], 1, 0))
    {
      contador++;
      organizar(vetor, contador, total);
    }

    if (ehcomposto(vetor[total], 1, 0) && !ehcomposto(vetor[contador], 1, 0))
    {
      aux = vetor[total];
      vetor[total] = vetor[contador];
      vetor[contador] = aux;
      contador++;
      total--;
      organizar(vetor, contador, total);
    }
    if (ehcomposto(vetor[total], 1, 0) && ehcomposto(vetor[contador], 1, 0))
    {
      total--;
      organizar(vetor, contador, total);
    }
  }
}

int main(int argc, char **argv)
{
  int vetor[20];
  cout << "Vetor Antes de organizar: " << endl;
  preenhecer(vetor);
  organizar(vetor, 0, 20);
  cout << "Depois de organizar: " << endl;
  for(int i = 0 ; i< 20 ; i++){
   cout << vetor[i] << " ";
  }
  cout << endl;
  return 0;
}