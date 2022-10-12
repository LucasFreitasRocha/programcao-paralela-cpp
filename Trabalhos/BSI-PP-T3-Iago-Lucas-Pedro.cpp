// Autores:  Iago Dias, Lucas Rocha e  Pedro Ferreira
// Maquina utilizada: Ubuntu 20.04
// Comando Utilizado para compilar: g++ T3-PP.cpp -o executavel-T3 -pthread -std=c++11
// Comando para executar depois de compilar: ./executavel-T3

#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

sem_t semSo, semSu, semMu, semDi; //cria os semafaro (componentes/recurso)

void soma( int a, int b, int n, int tempo ) {
 
  int soma = a + b;
  cout << "\nEu sou a Thread SOMA (" << soma << ") e vou dormir por " << tempo << " segundos!\n"; 
  while(n > 0) {
    sem_wait(&semSo); // fica esperando o semafaro(recurso) semSO ser liberado
    this_thread::sleep_for (chrono::seconds(tempo));
    cout << "\n\n\n";
    cout << "SOMA (" << soma << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    n--;
    sem_post(&semSu); // libera o semafaro(recurso) semSu
  }
}

void subtracao( int a, int b, int n, int tempo ) {
    int subtracao = a - b;
   cout << "Eu sou a Thread SUBTRAÇÃO (" << subtracao << ") e vou dormir por " << tempo << " segundos!\n";

  while(n > 0) { 
    sem_wait(&semSu); // fica esperando o semafaro(recurso) semSO ser liberado
    this_thread::sleep_for (chrono::seconds(tempo));;
    cout << "SUBTRAÇÃO (" << subtracao << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    sem_post(&semMu); // libera o semafaro(recurso) semMu
    n--;
  }
}

void multiplicacao( int a, int b, int n, int tempo ) {
  int multiplicacao = a * b;
  cout << "Eu sou a Thread MULTIPLICAÇÃO (" << multiplicacao << ") e vou dormir por " << tempo << " segundos!\n";
  while(n > 0) {
    sem_wait(&semMu);   // fica esperando o semafaro(recurso) semSu ser liberado
    this_thread::sleep_for (chrono::seconds(tempo));;
    cout << "MULTIPLICAÇÃO (" << multiplicacao << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    sem_post(&semDi); // libera o semafaro(recurso) semDi
    n--;
  }
}

void divisao( int a, int b, int n, int tempo ) {
  int divisao = a / b;
   cout << "Eu sou a Thread DIVISÃO (" << divisao << ") e vou dormir por " << tempo << " segundos!\n";
  while(n > 0) {
    sem_wait(&semDi); // fica esperando o semafaro(recurso) semSu ser liberado
    this_thread::sleep_for (chrono::seconds(tempo));;
    cout << "DIVISÃO (" << divisao << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    sem_post(&semSo); // libera o semafaro(recurso) semSo
    n--;
  }
}

int main() {
  cout << "\n";
  int a, b, n;
  

  cout << "Informe um valor  para o A: ";
  cin >> a;

 do
   {
     cout << "Informe um valor inteiro para B (diferente de zero): ";
     cin >> b;
     cout << "\n";
   } while (b == 0);
 
  do
   {
     
    cout << "Informe a quantidade de vezes para o  loop maior que zero: ";
    cin >> n;
     cout << "\n";
   } while (n < 1);


  /* sem_init serve para iniciar o semaforo:
    parametros:
    1º o proprio parametro
    2º Especifica se o semáforo é compartilhado ou não (entre processos e threads). 
    Valor 0 significa que é compartilhado entre threads, e diferente de 0 é compartilhado entre processos;
    3º 0 significa que o semáforo vai começar em 0  e 1 significa que vai começar em verde
  */
  sem_init(&semSo,0,1);
  sem_init(&semSu,0,0);
  sem_init(&semMu,0,0);
  sem_init(&semDi,0,0);


  thread So(soma, a , b, n,  (1 + rand() % 10)), 
         Su(subtracao, a, b, n,  (1 + rand() % 10)),
         Mu(multiplicacao, a, b, n,  (1 + rand() % 10)), 
         Di(divisao, a, b, n,  (1 + rand() % 10));
  
  So.join();
  Su.join();
  Mu.join();
  Di.join();

  return 0;
}
