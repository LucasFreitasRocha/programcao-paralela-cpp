// Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira
#include <iostream>
#include <thread>
using namespace std;

bool ehcomposto(int numero, int divisor, int contador) // o divisor tem que > 0;
{
  if (divisor >= numero) // essa funcao é recursiva, é chamada até o divisor ser igual ao numero
  {
    if (contador >= 3) // se o contador for maior 3 significa que o numero é composto;
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
    if (numero % divisor == 0) // verifica se o numero divido pelo divisor tem resto 0
    {
      contador++; 
    }
    divisor++;
    ehcomposto(numero, divisor, contador); 
  }
}
void preenhecer(int *vetor)
{
  int numeroCompsotos = 0, numeroNaoCompostos = 0, i = 0, aux = 0;
  // faz um while para preencher com numeros compostos ou não.
  while (i < 20)
  {
    cout << "Digite um numero: " << endl;
    cin >> aux ;
    
    if (ehcomposto(aux, 1, 0) && numeroCompsotos < 10) // verifica se já tem 10 numeros compostos;
    {
      i++;
      numeroCompsotos++;
      vetor[i] = aux; // add o numero não compostos caso não tenha 10 numeros  compostos
    }
    if (!ehcomposto(aux, 1, 0) && numeroNaoCompostos < 10) // verifica se já tem 10 numeros não compostos;
    {
      i++;
      numeroNaoCompostos++;
      vetor[i] = aux; // add o numero não compostos caso não tenha 10 numeros não compostos
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
// total comeca com 20 
// contador comeca com 0
{
  int aux = 0;
  if (!(contador >= 10))
  {
    if (ehcomposto(vetor[contador], 1, 0)) // se o numero na posicao contador for composto não faz a troca, apenas avança
    {
      contador++;
      organizar(vetor, contador, total);
    }

    if (ehcomposto(vetor[total], 1, 0) && !ehcomposto(vetor[contador], 1, 0)) // se o numero na  posicao total
    //  for composto e o numero na posicao contador não for , faz a troca
    {
      aux = vetor[total];
      vetor[total] = vetor[contador];
      vetor[contador] = aux;
      contador++;
      total--;
      organizar(vetor, contador, total);
    }
    if (ehcomposto(vetor[total], 1, 0) && ehcomposto(vetor[contador], 1, 0))
    // se o numero na posicao total for composto e o numero na posicao contador for composto
    // diminiu total e chama a funcao novamente
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