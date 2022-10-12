// Autores:  Iago Dias, Lucas Rocha e  Pedro Ferreira
// Maquina utilizada: Ubuntu 20.04
// Comando Utilizado para compilar: g++ T2-PP.cpp -o executavel-T2 -pthread -std=c++11
// Comando para executar depois de compilar: ./executavel-T2

#include <iostream>
#include <thread>

using namespace std;

void soma( int a, int b , int tempo) {
  

  int soma = a + b;
  cout << "Eu sou a Thread SOMA (" << soma << ") e vou dormir por " << tempo << " segundos!\n"; 
  
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread SOMA (" << soma << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

void subtracao( int a, int b, int tempo) {
 

  int subtracao = a - b;
  cout << "Eu sou a Thread SUBTRAÇÃO (" << subtracao << ") e vou dormir por " << tempo << " segundos!\n";
  
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread SUBTRAÇÃO (" << subtracao << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

void multiplicacao( int a, int b, int tempo) {
  

  int multiplicacao = a * b;
  cout << "Eu sou a Thread MULTIPLICAÇÃO (" << multiplicacao << ") e vou dormir por " << tempo << " segundos!\n";
 
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread MULTIPLICAÇÃO (" << multiplicacao << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

void divisao( int a, int b, int tempo) {
  

  int divisao = a / b;
  cout << "Eu sou a Thread DIVISÃO (" << divisao << ") e vou dormir por " << tempo << " segundos!\n";
  
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread DIVISÃO (" << divisao << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

int main() {
  cout << "\n";
  int a, b;
  srand(time(NULL));

   cout << "Informe um valor inteiro para A: ";
   cin >> a;

   do
   {
     cout << "Informe um valor inteiro para B (diferente de zero): ";
     cin >> b;
     cout << "\n";
   } while (b == 0);

  thread So(soma, a, b, (1 + rand() % 20)), 
         Su(subtracao, a, b, (1 + rand() % 20)), 
         Mu(multiplicacao, a, b, (1 + rand() % 20)), 
         Di(divisao, a, b, (1 + rand() % 20));
  
  So.join();
  Su.join();
  Mu.join();
  Di.join();

  cout << "\n";

  return 0;
}