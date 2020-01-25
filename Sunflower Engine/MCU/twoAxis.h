#ifndef TWO_AXIS_H
#define TWO_AXIS_H

#include "Arduino.h"
#include <Servo.h>

class TWO_AXIS : public Servo {

    public:

        TWO_AXIS();

        TWO_AXIS(int PinServoAxisX, int PinServoAxisY);

        void limiteAxisX(int Mov, int Med);
        void limiteAxisY(int Mov, int Med);
        

        void moveAxisX(int Angle);
        void moveAxisY(int Angle);

        void setSpeeds(int foto, int demo, int crono);
        
        int getFotoV();
        int getDemoV();
        int getCronoV();

        int getNormalAxisX();
        int getNormalAxisY();

        int getMaxAxisX();
        int getMaxAxisY();

        int getMinAxisX();
        int getMinAxisY();
        
    private:

        int _speedF = 30;
        int _speedD = 50;
        int _speedC = 240000;

        int PinServoAxisX;
        int PinServoAxisY;

        Servo _ServoAxisY;
        Servo _ServoAxisX;

        int _limiteMinAxisX;
        int _limiteMinAxisY;

        int _limiteMaxAxisX;
        int _limiteMaxAxisY;

        int _angleNormalAxisX = 0;
        int _angleNormalAxisY = 0;
};

#endif
