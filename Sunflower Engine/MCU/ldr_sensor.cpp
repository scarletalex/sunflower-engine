#include "ldr_sensor.h"

LDR_SENSOR::LDR_SENSOR(){}

LDR_SENSOR::LDR_SENSOR(int LDR_1, int LDR_2, int LDR_3, int LDR_4){

    _ldr1Pin = LDR_1;
    _ldr2Pin = LDR_2;
    _ldr3Pin = LDR_3;
    _ldr4Pin = LDR_4;
}

void LDR_SENSOR::sensibilidade(byte sense){
    _ldrSense = sense;
}

void LDR_SENSOR::leitura(){
    _sd  = analogRead(_ldr1Pin);
    _se  = analogRead(_ldr2Pin);
    _ie  = analogRead(_ldr3Pin);
    _id  = analogRead(_ldr4Pin);

    _m_superior = (_sd + _se) / 2;
    _m_inferior = (_id + _ie) / 2;
    _m_direita  = (_sd + _id) / 2; 
    _m_esquerda = (_se + _ie) / 2;

    _delta_v  = _m_superior - _m_inferior; 
    _delta_h  = _m_esquerda - _m_direita; 
}

int LDR_SENSOR::getMediaSuperior(){
    return _m_superior;
}

int LDR_SENSOR::getMediaInferior(){
    return _m_inferior;
}

int LDR_SENSOR::getMediaEsquerda(){
    return _m_esquerda;
}

int LDR_SENSOR::getMediaDireita(){
    return _m_direita;
}

int LDR_SENSOR::getDeltaAxisX(){
    return _delta_h;
}

int LDR_SENSOR::getDeltaAxisY(){
    return _delta_v;
}

byte LDR_SENSOR::getLdrSense(){
    return _ldrSense;
}
int LDR_SENSOR::getIE(){
  return _ie;
}
int LDR_SENSOR::getID(){
  return _id;
}
int LDR_SENSOR::getSE(){
  return _se;
}
int LDR_SENSOR::getSD(){
  return _sd;
}
