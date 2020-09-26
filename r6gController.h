/*
  Joints.h - Control de articulaciones en robots con motores a paso.
  Autor: Alejandro Tevera Ruiz
  Contacto: atevera.rz@gmail.com
  Lanzada para dominio público en 2020. 
*/

#ifndef r6gController_h
#define r6gController_h
 
#include <Arduino.h>
 
class Joint
{
  private:
    int _PDir, _PStep, _Speed;
    float _Relation, _Min, _Max;
    bool _Positive;

  public:
    Joint();
    void SetPines(int PDir, int PStep) { _PDir = PDir; _PStep = PStep;}
    void SetRelation(float Relation) { _Relation = Relation; }
    void SetSpeedRotation(int Speed) { _Speed = Speed; }
    void SetPositiveTurn(bool Positive) { _Positive = Positive; }
    void SetSoftwareLimits(float Min, float Max) { _Min = Min; _Max = Max; }

    int DegreesToSteps(float Old, float New);
    bool CheckSafetyMove (float J);
    bool AngularMove(float Old, float New, int steps, int count);
    void Shutdown();
};

class Robot
{
  private:
    String _RobotName; 
    int _EndEffector;
  public:
    Robot();
    String SetRobotName(String Name) { _RobotName = Name; }
    String GetRobotName() {return _RobotName;}
    void SetEndEffector(int EndEffector) { _EndEffector = EndEffector; }

    float MaxDegrees(float p1, float p2, float p3, float p4, float p5, float p6);
    void InitEndEffector();
};
#endif

// dir, step, delay, steps, giro, rm