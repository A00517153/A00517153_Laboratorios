/*----------------------------------
 *
 * Laboratorio: Herencia en C++
 * Fecha: 22-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/

#ifndef OVERNIGHT_PACKAGE_H
#define OVERNIGHT_PACKAGE_H

#include <iostream>
#include <string>
#include <sstream>
#include "package.h"

class overnight_package:public package{
  protected:
    float rate_per_kg;
  public:
    overnight_package():package(){};
    overnight_package(string r, string d, float w, float cpk,float rpk) :package(r,d,w,cpk){
      rate_per_kg=rpk;
    };

    double calc_cost() const{
      return double( (rate_per_kg * weight) + package::calc_cost() );
    };
    string display_info() {
      set_info();
      stringstream aux;
      aux<<info<<calc_cost();
      return aux.str();
    };
};

#endif 