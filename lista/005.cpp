// Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira

#include <iostream>
#include <cstdlib>
using namespace std;

int calcular(int a, int b)
{
  
  if(b == 0)	//tratativa do expoente ser 0
  {
    return 1;
  }
  else if(b == 1)	//tratativa do expoente ser 1
  {
    return a;
  }
  else
  {
    return (a*(calcular(a, b-1)));	//A vai multiplicando por A ate B ser igual 1
  }
}

int main(int argc , char** argv)
{
  bool correto = true;
  int a,b;
  
  while(correto)
  {
    cout << "Escrevar um numero diferente de zero para A: \n";
    cin >> a;
    
    if(a == 0 )
	{
      cout << "Voce digitou o numero zero \n";
    }
	else
	{
      correto = false;  //recebe false para sair do loop
    }
  }
  
  correto = true;  //recebe true para entrar no novo loop para escolha de B
  
  while (correto)
  {
    cout << "Escrevar um numero positivo para B: \n";
    cin >> b;
    
    if(b < 0)
	{
      cout << "Voce digitou um numero negativo. \n";
    }
	else
	{
      correto = false;
    }
  }
  
  int resultado = calcular(a,b);
  cout << "A elevado B (A^B) =  " << resultado << endl;
  
  return 0;
}
