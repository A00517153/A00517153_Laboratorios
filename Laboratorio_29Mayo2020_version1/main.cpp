/*----------------------------------
 *
 * Laboratorio: Apuntadores en C++
 * Fecha: 29-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/
#include <iostream>
#include <string>
#include <sstream>

#include "BigInteger.h"

using namespace std;

const bool comas=true; // Manage if there will be comas displayed when the text is printed.

void run(){
  BigInteger *A,*B;
  string num;
  stringstream num2;
  cout<<"\nEnter the value of the first Big Integer: ";
  cin>>num;
  int n=0;
  for (int i=0;i<num.size();i++){if(num[i]=='0'&&num.size()>2&&n==i){n++;}}
  for(int i=n;i<num.size();i++){num2<<num[i];}
  A=new BigInteger(num2.str());

  cout<<"\nEnter the value of the first Big Integer: ";
  num=string();
  cin>>num;
  num2=stringstream();
  n=0;
  for (int i=0;i<num.size();i++){if(num[i]=='0'&&num.size()>2&&n==i){n++;}}
  for(int i=n;i<num.size();i++){num2<<num[i];}
  B=new BigInteger(num2.str());

  cout<<"\nA: "<<A->toString(comas)<<endl;
  cout<<"B: "<<B->toString(comas)<<endl;

  A->add(*B);

  cout<<"\nA + B = "<<A->toString(comas)<<endl;
  delete A;
  delete B;
}

int main(){
  run();  
  return 0;
}