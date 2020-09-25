/*
  Joints.cpp - Control de articulaciones en robots con motores a paso.
  Autor: Alejandro Tevera Ruiz
  Contacto: atevera.rz@gmail.com
  Lanzada para dominio público en 2020. 
*/

#include "Arduino.h"
#include "Joints.h"
 
Joint::Joint(int PDir, int PStep, int Speed, int Relation)
{
  pinMode(PDir, OUTPUT);
  pinMode(PStep, OUTPUT);
  int _PDir = PDir;
  int _PStep = PStep;
  int _Speed = Speed;
  int _Relation = Relation;
}
 
void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}