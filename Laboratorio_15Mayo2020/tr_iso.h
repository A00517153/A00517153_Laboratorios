/*----------------------------------
 *
 * Laboratorio: POO y C++
 * Fecha: 15-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/

#include <iostream>
#include <math.h>
using namespace std;

class Tr_Iso {
  protected:
    float lado_a,lado_b,perimetro;
    double area;
  public:
    Tr_Iso();
    Tr_Iso(float a,float b);
    Tr_Iso(const Tr_Iso &obj);
    double get_area();
    float get_perimetro();
    void print_data();
    void set_data(float a,float b);
    void calc_data();
};

Tr_Iso::Tr_Iso(){
  lado_a=0;
  lado_b=0;
  set_data(lado_a,lado_b);
}

Tr_Iso::Tr_Iso(float a,float b){
  set_data(a,b); 
}

Tr_Iso::Tr_Iso(const Tr_Iso &obj){
  set_data(obj.lado_a,obj.lado_b);
}

void Tr_Iso::set_data(float a,float b){
  
  bool test;
  test=true;
  while (test){
    if (a+b>a && a+a>b && a!=b){
      lado_a=a; lado_b=b;
      test=false;
      calc_data();
      print_data();
    }else {
      cout<<"Favor de insertar Valores validos"<<endl;
      cout<<"Valor de los lados iguales: ";
      cin>>a;
      cout<<"Valor del lado desigual: ";
      cin>>b;
      //system("clear");
    }
  }
  
}

void Tr_Iso::print_data(){
  cout<<"\n\nValor de los lados iguales: "<<lado_a<<" unidades"<<endl;
  cout<<"Valor del lado diferente: "<<lado_b<<" unidades"<<endl;
  cout<<"Valor del perimetro : "<<get_perimetro()<<" unidades"<< endl;
  cout<<"Valor del area : "<<get_area()<<" unidades cuadradas\n\n"<< endl;
}

float Tr_Iso::get_perimetro(){
  return perimetro;
}

double Tr_Iso::get_area(){
  return area;
}

void Tr_Iso::calc_data(){
  perimetro=2*lado_a+lado_b;
  area=(double)(sqrt(pow(lado_a*lado_b/2,2)-pow(lado_b/2,4)));
}
