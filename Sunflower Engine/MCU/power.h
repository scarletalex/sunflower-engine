#ifndef POWER_H
#define POWER_H

using namespace std;

#include "Arduino.h"

class POWER {

    public:

        POWER();

        POWER(int pinVolt, int pinAmper, int shuntValor);

        void velocidadeLeitura(int milisecond);

        void leitura();

        double getPower();
        double getAmper();
        double getVolt();
        double getEnergy();
 
    private:

        int _pinVolt;
        int _pinAmper;
        int _shuntValor = 223;

        int _velocidadeLeitura = 1000;
        
        unsigned long tempLeitura = 0;
        
        double _power;
        double _amper;
        double _volt;
        double _energy = 0;
};

#endif
