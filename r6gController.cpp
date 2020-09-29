/*
  Joints.cpp - Control de articulaciones en robots con motores a paso.
  Autor: Alejandro Tevera Ruiz
  Contacto: atevera.rz@gmail.com
  Lanzada para dominio público en 2020. 
*/

#include <Arduino.h>
#include "r6gController.h"
Joint::Joint() {}

int Joint::DegreesToSteps(float Old, float New)
{
  int pulses = 0;
  pulses = (abs(New-Old)*_Relation)/1.8;
  return pulses; 
}

bool Joint::CheckSafetyMove(float J)
{
  return J >= _Min && J <= _Max;
}

bool Joint::AngularMove(float Old, float New, int steps, int count)
{
  if (CheckSafetyMove(New))
  {
    if (New > Old) digitalWrite(_PDir, _Positive);
    else digitalWrite(_PDir, not _Positive);

    if (count <= steps && New != Old)
    {
      digitalWrite(_PStep, HIGH);
      delay(_Speed);
      digitalWrite(_PStep, LOW);
      delay(_Speed);
    }
    return true;
  }
  return false;
}

void Joint::Shutdown()
{
  pinMode(_PDir,OUTPUT);
  pinMode(_PStep,OUTPUT);
  digitalWrite(_PStep,LOW);
  digitalWrite(_PDir, LOW);
}

Robot::Robot() {}

float Robot::MaxDegrees(float p1, float p2, float p3, float p4, float p5, float p6)
{  
  float max1, max2, max3, max4;
  max1=max(p1,p2);
  max2=max(p3,p4);
  max3=max(p5,p6);
  max4=max(max1,max2);
  return max(max3,max4);
}

void Robot::InitEndEffector()
{
  pinMode(_EndEffector, OUTPUT);
  digitalWrite(_EndEffector, LOW);
}