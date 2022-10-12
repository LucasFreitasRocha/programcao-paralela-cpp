// Autores:  Iago Dias, Lucas Rocha e  Pedro Ferreira
// Maquina utilizada: Ubuntu 20.04
// Comando Utilizado para compilar: g++ T4-PP.cpp -o executavel-T4 -pthread -std=c++11
// Comando para executar depois de compilar: ./executavel-T4

#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

sem_t semSoma, semCalculo;
int i, j, n = 3;
int A[3][3] = {1, 1, 1, 0, 1, 1, 0, 0, 1};
int B[3]= {3, 2, 2};
int X[3], soma;
void somatorio() {  //somat�rio das multiplica��es dos elementos da matriz pela coluna(vetor) de X
  for (i = n-1; i > -1; i--) {
    sem_wait(&semSoma);   
    
    soma = 0;
    for (j = n-1; j > i-1; j--) {
      soma += A[i][j] * X[j];
    }
    
    sem_post(&semCalculo);
  }
}

void calculo() { //Calculo para descobrir os elementos do vetor X
  for (int i = n-1; i > -1; i--) {
    sem_wait(&semCalculo);
    
    X[i] = ( (B[i] - soma) / A[i][i] );

    sem_post(&semSoma);
  }
}

int main() {
  sem_init(&semSoma,0,1);
  sem_init(&semCalculo,0,0);

  thread t_Soma(somatorio), 
         t_Calculo(calculo);

  t_Soma.join();
  t_Calculo.join();

  cout << "\nResutado dos valores de X:\n";
	for(i = 0 ; i < n ; i++ ) {
		printf("X[%d]: %d\n", i+1, X[i]);
	}
  cout << "\n";

  return 0;
}
