#ifndef IOT_H
#define IOT_H

#include <HTTPClient.h>
#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>





#include "power.h"

class IOT {

    private:

        HTTPClient _http;
        int _mode = 1;
        int _serialSpeed = 1000;
        int _webSpeed = 1000;
        
        const char* _SSID;
        const char* _PASS;


        unsigned long _tSerial = 0, _tWeb = 0;
    
    public:

        IOT(const char* ssid,const char* key);

        bool webStart();
        void iotSpy(POWER temp);

        int getModo();

        void tradutor(String spy);
        String serial(POWER temp);
        void web(POWER temp);  

};

#endif
