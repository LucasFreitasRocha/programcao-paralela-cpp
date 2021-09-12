#include <iostream>
#include <thread>
using namespace std;
int calcular(int a, int multiplicacao, int b){
  
  if(b == 0){
    return 1;
  }else if(b == 1){
    return multiplicacao;
  }else{
    calcular(a, a*multiplicacao, b-1);
  }
}

int main(int argc , char** argv){
  bool correto = true;
  int a,b;
  
  while(correto){
    cout << "Escrevar um numero diferente de zero para a: \n";
    cin >> a;
    if(a == 0 ){
      cout << "Você escreveu o numero zero \n";
    }else{
      correto = false;
    }
  }
  correto = true;
  while (correto)
  {
    cout << "Escrevar um numero positivo para b: \n";
    cin >> b;
    if(b < 0){
      cout << "Você digitou um numero negativo. \n";
    }else{
      correto = false;
    }
  }
  int resultado = calcular(a,a,b);
  cout << "o resultado é: " << resultado << endl;
  return 0;
}