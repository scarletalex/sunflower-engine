#ifndef IOT_H
#define IOT_H

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "power.h"

class IOT {

    private:

        HTTPClient _http;
        byte _mode;
        int _serialSpeed = 1000;
        int _webSpeed = 1000;
        
        char* _SSID;
        char* _PASS;


        unsigned long _tSerial = 0, _tWeb = 0;
    
    public:

        IOT(char* ssid, char* key);

        void spySpeed(int serial, int web);
        bool webStart();
        void iotSpy(POWER temp);

        byte getModo();

        void tradutor(String spy);
        String jsonMake(POWER temp);
        void web(POWER temp);  

};




#endif
