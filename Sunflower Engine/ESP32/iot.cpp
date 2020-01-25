#include "iot.h"

const String SERVIDOR = "https://sunflower-engine.herokuapp.com/upload";

const String WATTS = "\"WATTS\":";
const String AMPER = "\"AMPER\":";
const String VOLT = "\"VOLT\":";
const String MODO = "\"MODO\":";

IOT::IOT(const char* ssid,const char* key){
    _SSID = ssid;
    _PASS = key;
}

bool IOT::webStart(){
    bool state;

    WiFi.begin(_SSID, _PASS);
    delay(2000);

    if(WiFi.status() != WL_CONNECTED){
       state = false;
    }else{
      state = true;
    }
    return state;
}


void IOT::iotSpy(POWER temp){

    if(Serial.available() > 0 ){
        String spy = Serial.readString();
        tradutor(spy);  
    }    
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

String IOT::serial(POWER temp){
  
  double watts = temp.getPower();
  double amper = temp.getAmper();
  double volt = temp.getVolt();
  
  return "{" + WATTS + String(watts) + "," + AMPER + String(amper) + "," + VOLT  + String(volt)  + "," + MODO + String(_mode) + "}";
  
}

void IOT::web(POWER temp){

    double watts = temp.getPower();
    double amper = temp.getAmper();
    double volt = temp.getVolt();

    String jsonWeb = "{" + WATTS + String(watts) + "," + AMPER + String(amper) + "," + VOLT  + String(volt)  + "}";  
  
    _http.begin(SERVIDOR); 
    _http.addHeader("Content-Type", "application/json"); 
    _http.POST(jsonWeb); 
    _http.end();  
}

int IOT::getModo(){
    return _mode;
}
