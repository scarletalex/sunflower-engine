#include "iot.h"

const String SERVIDOR = "https://stellar-engine.herokuapp.com/upload";

const String WATTS = "\"POWER\":";
const String AMPER = "\"AMPER\":";
const String VOLT = "\"VOLT\":";
const String ENERGY = "\"ENERGY\":";
const String MODO = "\"MODO\":";

IOT::IOT(char* ssid, char* key){
    _SSID = ssid;
    _PASS = key;
}

bool IOT::webStart(){

    WiFi.begin(_SSID, _PASS);

    while(WiFi.status() != WL_CONNECTED){
        return false;
    }
    return true;
}

void IOT::spySpeed(int serial, int web){
    _serialSpeed = serial;
    _webSpeed = web;
}

void IOT::iotSpy(POWER temp){

    if(Serial.available() > 0 ){
        String spy = Serial.readString();
        tradutor(spy);  
    }
    
    if(millis() - _tSerial >= _serialSpeed) _tSerial = millis(), Serial.print(jsonMake(temp));
    if(millis() - _tWeb >= _webSpeed) _tWeb = millis(), web(temp);
}

void IOT::tradutor(String spy){
   if(spy.startsWith("{") && spy.endsWith("}")){
        if(spy.indexOf(MODO + " 1") > 0){
          _mode = 1;
        }else if(spy.indexOf(MODO + " 2") > 0){
          _mode = 2;
        }else if(spy.indexOf(MODO + " 3") > 0){
          _mode = 3;
        }else if(spy.indexOf(MODO + " 4") > 0){
          _mode = 4;
        }       
    }
}


String IOT::jsonMake(POWER temp){
  
  double watts =   temp.getPower();
  double amper =   temp.getVolt();
  double volt =    temp.getEnergy();
  double energy =  temp.getEnergy();
  
  return "{" + WATTS + String(watts) + "," +
               AMPER + String(amper) + "," +
               VOLT  + String(volt) +  "," +
               ENERGY + String(energy) + "," +
               MODO + String(_mode) +
         "}";  
}

void IOT::web(POWER temp){
    _http.begin(SERVIDOR); 
    _http.addHeader("Content-Type", "application/json"); 
    _http.POST(jsonMake(temp)); 
    _http.end();  
}

byte IOT::getModo(){
    return _mode;
}
