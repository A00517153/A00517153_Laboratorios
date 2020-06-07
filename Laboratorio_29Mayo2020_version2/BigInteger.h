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
    s_int size; 
    s_int *number=new s_int[0];

  public:
    BigInteger(string);
    BigInteger(BigInteger const &BI);
    ~BigInteger();
    void add(BigInteger &b);
    string toString(bool);
    string toString();
};

BigInteger::BigInteger(string n){
  delete []number; number=NULL;
  size=0;
  for(s_int i=0;i<n.size();i++){( n[i]=='0' && (size-0)==i && n.size()>1)? size++:size;}
  size=n.size()-size+1;
  number=new s_int[size];
  for(s_int i=0;i<size-1;i++){
    number[i]=n[n.size()-1-i]-48;
  }
}

BigInteger::BigInteger(BigInteger const &BI){
  delete [] number; number=NULL;
  size=(BI.number[0]=0)? BI.size:BI.size+1;
  number=new s_int[size];
  for (s_int i=0;i<BI.size;i++){
    number[i]=BI.number[i];
  }
}

BigInteger::~BigInteger(){
  delete [] number; number=NULL;
}

void BigInteger::add(BigInteger &b){
  s_int carry=0,temp=0;
  s_int s_size=(size<b.size)? size:b.size;
  s_int b_size=(size==s_size)? b.size:size;
  
  s_int *temp_number=number;
  number=NULL;
  size=b_size;
  number=new s_int[size];
  for(s_int i=0;i<s_size;i++){
    number[i]=temp_number[i];
  }
  delete [] temp_number;
  temp_number=NULL;

  for (s_int i=0;i<s_size;i++){
    temp=(number[i]+b.number[i]+carry);
    number[i]=temp%10;
    carry=(temp-number[i])/10;
  }
  for (s_int i=s_size;i<b_size;i++){
    if (size==b_size){
      temp=(b.number[i]+carry);
      number[i]=temp%10;
      carry=(temp-number[i])/10;
    }else{
      temp=(number[i]+carry);
      number[i]=temp%10;
      carry=(temp-number[i])/10;
    }
  }
  if(number[size-1]!=0){
    s_int *temp_number=number;
    number=NULL;
    size=size+1;
    number=new s_int[size];
    for(s_int i=1;i<size;i++){
      number[i-1]=temp_number[i-1];
    }
    delete [] temp_number;
    temp_number=NULL;
  }
}

string BigInteger::toString(bool comas){
  stringstream aux;
  for(s_int i=1;i<=size;i++){
    if (!(i==1 && number[size-1]==0)){
      if(comas){if((i-1-size%3)%3==0&&i!=2){aux<<",";}} 
      aux<<(s_int)(number[size-i]);
    }
  }
  return aux.str();
}

string BigInteger::toString(){
  stringstream aux;
  for(s_int i=1;i<=size;i++){
    if (!(i==0 && number[size-1]==0)){ 
      aux<<(s_int)(number[size-i]);
    }
  }
  return aux.str();
}
#endif