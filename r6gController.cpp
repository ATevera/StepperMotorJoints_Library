/*
  Joints.cpp - Control de articulaciones en robots con motores a paso.
  Autor: Alejandro Tevera Ruiz
  Contacto: atevera.rz@gmail.com
  Lanzada para dominio público en 2020. 
*/

#include <Arduino.h>
#include "r6gController.h"

Joint::Joint() {}

int Joint::DegreesToSteps(float New)
{
  int pulses = 0;
  pulses = (abs(New - _Old)*_Relation)/1.8;
  return pulses; 
}

bool Joint::CheckSafetyMove(float J)
{
  return J >= _Min && J <= _Max;
}

bool Joint::AngularMove(float New, int steps, int count)
{
  if (CheckSafetyMove(New))
  {
    if (New > _Old) digitalWrite(_PDir, _Positive);
    else digitalWrite(_PDir, not _Positive);

    if (count <= steps)
    {
      digitalWrite(_PStep, HIGH);
      delay(_Speed);
      digitalWrite(_PStep, LOW);
    }
    else _Old = New;

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

int Robot::MaxDegrees(int Pulsos[6])
{  
  int max1, max2, max3, max4;
  max1 = max(Pulsos[0],Pulsos[1]);
  max2 = max(Pulsos[2],Pulsos[3]);
  max3 = max(Pulsos[4],Pulsos[5]);
  max4 = max(max1,max2);
  return max(max3,max4);
}

void Robot::InitEndEffector(int EndEffector)
{
  _EndEffector = EndEffector;
  pinMode(_EndEffector, OUTPUT);
  digitalWrite(_EndEffector, LOW);
}

void Robot::ToggleEndEffectorState(int State)
{
  /*Toma el parámetro State para cambiar el estado del efector final. */
  if (State != _EFState)
  {
    EF_State = State;
    digitalWrite(_EndEffector, _EFState);
  }
}