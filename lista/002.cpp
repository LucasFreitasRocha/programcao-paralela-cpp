#include <iostream>
#include <thread>
using namespace std;

bool verificar(int matrizMultiplicada[][4])
{
  int matrizI[4][4];
  bool ortogonal = true;
  cout << "Matriz identidade: \n";
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (i == j)
      {
        matrizI[i][j] = 1;
      }
      else
      {
        matrizI[i][j] = 0;
      }
      cout << matrizI[i][j] << " ";
      if (matrizMultiplicada[i][j] != matrizI[i][j])
      {
        ortogonal = false;
      }
    }
    cout << endl;
  }
  return ortogonal;
}

void multiplicarMatriz(int matriz[][4], int matrizT[][4], int matrizMultiplicada[][4])
{
  cout << "Matriz Multiplicada: \n";
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      matrizMultiplicada[i][j] = matrizT[i][j] * matriz[i][j];
      cout << matrizMultiplicada[i][j] << " ";
    }
     cout << endl;
  }
}
void matrizTransporta(int matriz[][4], int matrizT[][4], int matrizMultiplicada[][4])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      matrizT[i][j] = matriz[j][i];
    }
  }
  multiplicarMatriz(matriz, matrizT, matrizMultiplicada);

}

void preenhecer(int matriz[][4], int matrizT[][4], int matrizMultiplicada[][4])
{
  srand(clock());

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      matriz[i][j] = rand() % 29;
    }
  }
  matrizTransporta(matriz, matrizT, matrizMultiplicada);
}

int main(int argc, char **argv)
{

  int matriz[4][4];
  int matrizT[4][4];
  int matrizMultiplicada[4][4];
  preenhecer(matriz, matrizT, matrizMultiplicada);
 

  cout << "matriz: \n ";
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Matriz Transporta \n";
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << matrizT[i][j] << " ";
    }
    cout << endl;
  }
  if( verificar(matrizMultiplicada)){
    cout << "\n Condicao Satisfeita \n";
  }else {
    cout << " \n Condicao Nao Satisfeita \n";
  }
  return 0;
}
