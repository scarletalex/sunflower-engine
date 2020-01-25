#include "power.h"

POWER::POWER(){}

POWER::POWER(int pinVolt, int pinAmper){
    _pinVolt = pinVolt;
    _pinAmper = pinAmper;
}

void POWER::velocidadeLeitura(int milisecond){
    _velocidadeLeitura = milisecond;
}

void POWER::leitura(){
    
    float volt_temp, amper_temp;

  if(millis()-_velocidadeLeitura >= tempLeitura){
        tempLeitura = millis();

        volt_temp = analogRead(_pinVolt);
        amper_temp  = analogRead(_pinAmper);    // <-- instantaneos current 
        _volt = (volt_temp*ADC)/SAMPLE;
        _amper  = (amper_temp*ADC)/SHUNT;    // <-- instantaneos current 
        _power = _volt * _amper;       // <-- instantaneos power of system                                 
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
