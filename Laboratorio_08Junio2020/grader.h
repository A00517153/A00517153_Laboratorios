/*----------------------------------
  *
 * Laboratorio: Apuntadores en C++
 * Fecha: 05-Junio-2020
 * Autor: A00517153 Johann Palomino
 *
 *----------------------------------*/
#ifndef GRADER_H
#define GRADER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std; 

class grader{
  private:
    short n_questions;
    char *guide=new char[0];

  public:
    grader(char*);
    grader(string);
    ~grader();

    string grade(char* ,char*);
};

grader::grader(char* guide_){
  stringstream aux;
  aux<<guide_;
  string guide__=aux.str();
  n_questions=guide__.size();
  delete guide;guide=NULL;
  guide=new char[n_questions];

  for (int i=0;i<n_questions;i++){    
    guide[i]=(((short)(guide__[i]))==32)?'0':guide__[i];
  }
}

grader::grader(string guide_){
  n_questions=guide_.size();
  delete guide;guide=NULL;
  guide=new char[n_questions];

  for (int i=0;i<n_questions;i++){    
    guide[i]=(((short)(guide_[i]))==32)?'0':guide_[i];
  }
}

grader::~grader(){
  delete guide;guide=NULL;
}

string grader::grade(char* student_id, char* student_answer){
  int correct_ans=0;
  for(int i=0;i<n_questions;i++){
    if (student_answer[i]==32){
      //do nothing
    }else{
      if (student_answer[i]==guide[i]){
        correct_ans+=2;
      }else{
        correct_ans--;
      }
    }
  }
  float grade_value=100*correct_ans/n_questions;
  grade_value=(grade_value>100)?100:grade_value;
  string grade_letter;
  if (grade_value>90){
    grade_letter="A";
  }else{
    if (grade_value>80){
      grade_letter="B";
    }else{
      if (grade_value>70){
        grade_letter="C";
      }else{
        if (grade_value>60){
          grade_letter="D";
        }else{
          grade_letter="F";
        }
      }
    }
  }
  stringstream aux;
  aux<<student_id<<":\t"<<grade_value<<"%, "<<grade_letter;
  return aux.str();
}

#endif