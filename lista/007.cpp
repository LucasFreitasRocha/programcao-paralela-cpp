#include <iostream>
#include <thread>
using namespace std;
void preenhecer(int *vetor)
{
  srand(clock());
  for (int i = 0; i < 50; i++)
  {
    vetor[i] = (rand() % 100) + 1;
    cout << vetor[i] << " ";
  }
  cout << endl;
}

int getMaior(int *vetor, int contador, int maior)
{
  cout << "Contador: " << contador  << endl;
  cout << "Maior: " << maior << endl;
  if (contador == 50)
  {
    return maior;
  }

  if (maior < vetor[contador])
  {
    maior = vetor[contador];
  }
  contador++;

  getMaior(vetor, contador, maior);
}
int main(int argc, char **argv)
{
  int vetor[50];
  cout << "Vetor: " << endl;
  preenhecer(vetor);
  int maior = getMaior(vetor, 0, 0);
  cout << "Maior do vetor: "  << maior << endl;
  return 0;
}