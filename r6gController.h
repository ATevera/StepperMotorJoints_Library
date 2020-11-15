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
    float _Relation, _Min, _Max, _Old;
    bool _Positive;

  public:
    Joint();
    void SetPines(int PDir, int PStep) { _PDir = PDir; _PStep = PStep;}
    void SetRelation(float Relation) { _Relation = Relation; }
    void SetSpeedRotation(int Speed) { _Speed = Speed; }
    void SetPositiveTurn(bool Positive) { _Positive = Positive; }
    void SetSoftwareLimits(float Min, float Max) { _Min = Min; _Max = Max; }
    void SetInitialAngle(float InitialAngle) { _Old = InitialAngle; }

    int DegreesToSteps(float New);
    bool CheckSafetyMove(float J);
    bool AngularMove(float New, int steps, int count);
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
    //void SetEndEffector(int EndEffector) { _EndEffector = EndEffector; }

    int MaxDegrees(int Pulsos[6]);
    void InitEndEffector(int EndEffector);
    void ToggleEndEffectorState(int State);
};
#endif