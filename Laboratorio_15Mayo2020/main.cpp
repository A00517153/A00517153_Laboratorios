/*----------------------------------
 *
 * Laboratorio: POO y C++
 * Fecha: 15-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/

#include <iostream>
#include "tr_iso.h"
using namespace std;

int main(){
  system("clear");
  cout<<"Triangulo1 (Introduccion de datos posterior a la generacion.):"<<endl;
  Tr_Iso tr1;

  cout<<"Triangulo2 (Introduccion previa de los datos.):"<<endl;
  float temp1,temp2;
  cout<<"Datos Tr_Iso 2:"<<endl;
  cout<<"Valor de los lados iguales: ";
  cin>>temp1;
  cout<<"Valor del lado diferente: ";
  cin>>temp2;
  Tr_Iso tr2(temp1,temp2);

  cout<<"Triangulo3 (copia del Triangulo 2.):"<<endl;
  Tr_Iso tr3(tr2);
  return 0;
}