/*----------------------------------
 *
 * Laboratorio: Herencia en C++
 * Fecha: 22-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include "package.h"
#include "two_day_package.h"
#include "overnight_package.h"

using namespace std;

int main(){
  system("clear");

  float weight=0,cost_per_kg=0,fare=0;
  /*weight=20.2;cost_per_kg=9.5;fare=1.2;*/
  while (weight<=0){
    cout<<"Please enter a positive weight value: ";
    cin>>weight;
    system("clear");
  };
  while (cost_per_kg<=0){
    cout<<"Please enter a positive cost per kg value: ";
    cin>>cost_per_kg;
    system("clear");
  };
  while (fare<=0){
    cout<<"Please enter a positive fare value: ";
    cin>>fare;
    system("clear");
  };
  
  string temp;
  cout<<"";cin;
  system("clear");
  stringstream rem_inf,des_inf;
  string FN,A,CP,S,C;
  cout<<"SENDER INFO: \n";getline(cin,FN);
  cout<<"Please enter sender's full name: ";getline(cin,FN);
  cout<<"Please enter sender's address: ";getline(cin,A);
  cout<<"Please enter sender's postal code: ";getline(cin,CP);
  cout<<"Please enter sender's state: ";getline(cin,S);
  cout<<"Please enter sender's country: ";getline(cin,C);
  
  rem_inf<<"SENDER: \nFull Name: "<< FN <<"\nAddress: "<< A <<"\nCP: "<<CP<<"\tState: "<<S<<"\tCountry: "<<C;

  cout<<"\nRECIPIENT INFO: \n";
  cout<<"Please enter recipient's full name: ";getline(cin,FN);
  cout<<"Please enter recipient's address: ";getline(cin,A);
  cout<<"Please enter recipient's postal code: ";getline(cin,CP);
  cout<<"Please enter recipient's state: ";getline(cin,S);
  cout<<"Please enter recipient's country: ";getline(cin,C);
  
  des_inf<<"RECIPIENT: \nFull Name: "<< FN <<"\nAddress: "<< A <<"\nCP: "<<CP<<"\tState: "<<S<<"\tCountry: "<<C;
  
  

  package p1(rem_inf.str(),des_inf.str(),weight,cost_per_kg);
  two_day_package p2(rem_inf.str(),des_inf.str(),weight,cost_per_kg,fare);
  overnight_package p3(rem_inf.str(),des_inf.str(),weight,cost_per_kg,fare);

  cout<<"\n\nPACKAGE: \n"<<p1.display_info()<<endl;
  cout<<"\n\nTWO DAY PACKAGE: \n"<<p2.display_info()<<endl;
  cout<<"\n\nOVERNIGHT PACKAGE: \n"<<p3.display_info()<<endl;

  cout<<"\n\tProcess Terminated\n";
}
