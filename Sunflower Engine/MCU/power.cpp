#include "power.h"

POWER::POWER(){}

POWER::POWER(int pinVolt, int pinAmper, int shuntValor){
    _pinVolt = pinVolt;
    _pinAmper = pinAmper;
    _shuntValor = shuntValor;
}

void POWER::velocidadeLeitura(int milisecond){
    _velocidadeLeitura = milisecond;
}

void POWER::leitura(){
  if((millis() - tempLeitura) >= _velocidadeLeitura){
      tempLeitura = millis(); 

        _volt = analogRead(_pinVolt);       // <-- instantaneos voltage
        _amper  = (analogRead(_pinAmper) / _shuntValor);    // <-- instantaneos current 

        _power = _volt * _amper;       // <-- instantaneos power of system 
        _energy += _volt * _amper;    // <-- sum of energy converted                                
    }
}

double POWER::getPower(){
    return _power;
}
double POWER::getAmper(){
    return _amper;
}
double POWER::getVolt(){
  return _volt;
}
double POWER::getEnergy(){
     return _energy/(3600000/_velocidadeLeitura);
}
