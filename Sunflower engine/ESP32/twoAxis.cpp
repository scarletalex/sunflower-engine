#include "twoAxis.h"

TWO_AXIS::TWO_AXIS(){}

TWO_AXIS::TWO_AXIS(int PinServoAxisX, int PinServoAxisY){
    _PinServoAxisX = PinServoAxisX;
    _PinServoAxisY = PinServoAxisY;
    _ServoAxisX.setPeriodHertz(50); // standard 50 hz servo
    _ServoAxisY.setPeriodHertz(50); // standard 50 hz servo
    _ServoAxisX.attach(PinServoAxisX, 1000, 2000); // Attach the servo after it has been detatched
    _ServoAxisY.attach(PinServoAxisY, 1000, 2000); // Attach the servo after it has been detatched
}

void TWO_AXIS::limiteAxisX(int Mov, int Med){
  if(_PinServoAxisX != 0){
      _limiteMaxAxisX = Med + Mov;
      _limiteMinAxisX = Med - Mov;
      _angleNormalAxisX = Med;
  }
}

void TWO_AXIS::limiteAxisY(int Mov, int Med){
  if(_PinServoAxisY != 0){
    _limiteMaxAxisY = Med + Mov;
    _limiteMinAxisY = Med - Mov;
    _angleNormalAxisY = Med;
  }
}


void TWO_AXIS::moveAxisX(int Angle){
  _ServoAxisX.write(Angle);
}

void TWO_AXIS::moveAxisY(int Angle){
  _ServoAxisY.write(Angle);
}

void TWO_AXIS::setSpeeds(int foto, int demo, int crono){
  _speedF = foto;
  _speedD = demo;
  _speedC = crono;
}

int TWO_AXIS::getFotoV(){
  return _speedF;
}

int TWO_AXIS::getDemoV(){
  return _speedD;
}

int TWO_AXIS::getCronoV(){
  return _speedC;
}

int TWO_AXIS::getNormalAxisX(){
    return _angleNormalAxisX;
}
int TWO_AXIS::getNormalAxisY(){
    return _angleNormalAxisY;
}

int TWO_AXIS::getMaxAxisX(){
    return _limiteMaxAxisX;
}
int TWO_AXIS::getMaxAxisY(){
    return _limiteMaxAxisY;
}

int TWO_AXIS::getMinAxisX(){
    return _limiteMinAxisX;
}

int TWO_AXIS::getMinAxisY(){
    return _limiteMinAxisY;
}
