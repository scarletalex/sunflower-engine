#include "twoAxis.h"

TWO_AXIS::TWO_AXIS(){}

TWO_AXIS::TWO_AXIS(int PinServoAxisX, int PinServoAxisY){
    _ServoAxisX.attach(PinServoAxisX);
    _ServoAxisY.attach(PinServoAxisY);
}

void TWO_AXIS::limiteAxisX(int Mov, int Med){
    _limiteMaxAxisX = Med + Mov;
    _limiteMinAxisX = Med - Mov;
    _angleNormalAxisX = Med;
}

void TWO_AXIS::limiteAxisY(int Mov, int Med){
      _limiteMaxAxisY = Med + Mov;
      _limiteMinAxisY = Med - Mov;
      _angleNormalAxisY = Med;
}


void TWO_AXIS::moveAxisX(int Angle){
  
  if(_limiteMaxAxisX != 0 and (Angle > _limiteMaxAxisX)) Angle = _limiteMaxAxisX;
  if(_limiteMinAxisX != 0 and (Angle < _limiteMinAxisX)) Angle = _limiteMinAxisX;

  _ServoAxisX.write(Angle);
}

void TWO_AXIS::moveAxisY(int Angle){
  if(_limiteMaxAxisY != 0 and (Angle > _limiteMaxAxisY)) Angle = _limiteMaxAxisY;
  if(_limiteMinAxisX != 0 and (Angle < _limiteMinAxisY)) Angle = _limiteMinAxisY;

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
