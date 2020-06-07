/*----------------------------------
  *
 * Laboratorio: Apuntadores en C++
 * Fecha: 29-Mayo-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/
#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef short int s_int;
class BigInteger{
  private:
    int size; 
    s_int *number;

  public:
    BigInteger(string num){
      if (num[0]=='0'&&num.size()>1){
        size=num.size()-1;
        number=new s_int[size];
        for (int i=1;i<=size;i++){
          number[i-1]=(num[size+1-i]-48);
        }
      }else{
        size=num.size();
        number=new s_int[size];
        for (int i=1;i<=size;i++){
          number[i-1]=(num[size-i]-48);
        }
      }
    }

    ~BigInteger(){
      delete [] number;
      number=NULL;
    }

    void add(BigInteger &b){
      stringstream aux;
      int s_size=(b.size<size)? b.size:size;
      int b_size=(s_size==size)? b.size:size;
      s_int temp=0;
      for (int i=0;i<s_size;i++){
        aux<<(((s_int)(b.number[i]+number[i]))+temp)%10;
        temp=s_int(((s_int)(b.number[i]+number[i])+temp)/10);
      }
      if(b_size>size){
        for(int i=s_size;i<b_size;i++){
          aux<<(((s_int)(b.number[i]))+temp)%10;
          temp=s_int(((s_int)(b.number[i])+temp)/10);
        }
      }else{
        for(int i=s_size;i<b_size;i++){
          aux<<(((s_int)(number[i]))+temp)%10;
          temp=s_int(((s_int)(number[i])+temp)/10);
        }
      }
      aux<<(s_int)(temp);
      string aux2=aux.str();
      aux=stringstream();
      for (int i=1;i<=aux2.size();i++){aux<<aux2[aux2.size()-i];}
      if (aux.str()[0]=='0'){
        size=aux2.size()-1;
        number=new s_int[size];
        for (int i=0;i<size;i++){
          number[i]=(aux.str()[size-i]-48);
        }
      }else{
        size=aux2.size();
        number=new s_int[size];
        for (int i=1;i<=size;i++){
          number[i-1]=(aux.str()[size-i]-48);
        }
      }
    }

    string toString(bool comas)const{
      stringstream aux;
      for(int i=1; i<=size;i++){
        if(comas){if((i-1-size%3)%3==0&&i!=1){aux<<",";}}
        aux<<number[size-i];
      }
      return aux.str();
    }


};

#endif