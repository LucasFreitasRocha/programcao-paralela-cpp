// Alunos: Iago Dias, Lucas Freitas e Pedro Ferreira
// Sistema operacional usado: Ubuntu 20.04 LTS - GNU/LINUX 4.4.0-19041
// Compilador: g++ -pthread t1.cpp -o t1

#include <iostream>
#include <thread>

using namespace std;

void disciplineName(){
  cout << "Programacao Paralela\n";
}

void collegeName(){
  cout << "IFF\n";
}


int main(){
  thread t1(collegeName);
  thread t2(disciplineName);
  
  t1.join();
  t2.join();
  
  return 0;
}
