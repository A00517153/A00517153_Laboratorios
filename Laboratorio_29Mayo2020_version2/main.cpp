/*----------------------------------
 *
 * Laboratorio: Apuntadores en C++
 * Fecha: 29-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/
#include <iostream>

#include "BigInteger.h"

using namespace std;

const bool comas=true; //change the output number to display it with comas.

void insert_lines(s_int lines){
  for(s_int i=0;i<lines;i++){cout<<"\n";}
}

int main() {
  string entry;
  cout<<"Please Enter Value for A: ";
  cin>>entry;
  BigInteger A(entry);
  cout<<"Please Enter Value for B: ";
  cin>>entry;
  BigInteger B(entry);
  
  insert_lines(5);
  cout<<"The Value for A is \t\t=\t"<<A.toString(comas)<<endl;
  cout<<"The Value for B is \t\t=\t"<<B.toString(comas)<<endl;
  A.add(B);
  cout<<"The Sum of A and B is \t=\t"<<A.toString(comas)<<endl;

  return 0;
}