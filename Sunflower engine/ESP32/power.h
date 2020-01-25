#ifndef POWER_H
#define POWER_H

#define ADC 0.00122100122
#define SAMPLE 0.2
#define SHUNT 223

#include "Arduino.h"

class POWER {

    public:

        POWER();

        POWER(int pinVolt, int pinAmper);

        void velocidadeLeitura(int milisecond);

        void leitura();

        double getPower();
        double getAmper();
        double getVolt();
 
    private:

        int _pinVolt;
        int _pinAmper;

        int _velocidadeLeitura = 1000;
        
        unsigned long tempLeitura = 0;
        
        double _power;
        double _amper;
        double _volt;
};

#endif
