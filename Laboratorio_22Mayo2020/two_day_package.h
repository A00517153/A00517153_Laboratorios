/*----------------------------------
 *
 * Laboratorio: Herencia en C++
 * Fecha: 22-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/

#ifndef TWO_DAY_PACKAGE_H
#define TWO_DAY_PACKAGE_H

#include <iostream>
#include <string>
#include <sstream>
#include "package.h"

class two_day_package:public package{
  protected:
    float fixed_fare;
  public:
    two_day_package():package(){};
    two_day_package(string r, string d, float w, float cpk,float fr) :package(r,d,w,cpk){
      fixed_fare=fr;
    };

    double calc_cost() const{
      return double(fixed_fare + package::calc_cost());
    };
    string display_info() {
      set_info();
      stringstream aux;
      aux<<info<<calc_cost();
      return aux.str();
    };
};

#endif 