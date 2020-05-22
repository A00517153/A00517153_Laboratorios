/*----------------------------------
 *
 * Laboratorio: Herencia en C++
 * Fecha: 22-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class package{
  protected:
    float weight,cost_per_kg;
    string sender_info,recipient_info,info;
  public:
    package(){};
    package(string r, string d, float w, float cpk){
      sender_info=r;
      recipient_info=d;
      weight=w;
      cost_per_kg=cpk;
    };
    double calc_cost() const{return double(weight*cost_per_kg);};

    void set_info(){
      stringstream aux;
      aux<<sender_info<<endl<<recipient_info<<endl<<"Weight: "<<weight<<" kg\t"<<"Charge: $";
      info=aux.str();
    };

    string display_info() {
      set_info();
      stringstream aux;
      aux<<info<<calc_cost();
      return aux.str();
    };
    

};

#endif