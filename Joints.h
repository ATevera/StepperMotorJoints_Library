/*
  Joints.h - Control de articulaciones en robots con motores a paso.
  Autor: Alejandro Tevera Ruiz
  Contacto: atevera.rz@gmail.com
  Lanzada para dominio público en 2020. 
*/

#ifndef Morse_h
#define Morse_h
 
#include "Arduino.h"
 
class Joint
{
  public:
    Joint(int PDir, int PStep, int Speed, int Relation);
    void dot();
    void dash();
  private:
    int _PDir;
    int _PStep;
    int _Speed;
    int _Relation;
};
 
#endif


// dir, step, delay, steps, giro, rm