/*----------------------------------
 *
 * Laboratorio: Apuntadores en C++
 * Fecha: 05-Junio-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/
#include <iostream>

#include "grader.h"

using namespace std;

int main(){
  char guide[]="112341423114322314231442314231223422";
  grader i(guide);
  char id[]="A00517153";
  char ans[]="11 3 1133 22322314231432211231 34 2";
  cout<<i.grade(id,ans)<<endl;
  return 0;
}