#ifndef LDR_SENSOR_H
#define LDR_SENSOR_H

#include "Arduino.h"

// LDR_1 A0                      -- SUPERIOR DIREITO
// LDR_2 A1                      -- SUPERIOR ESQUERDO
// LDR_3 A2                      -- INFERIOR ESQUERDO
// LDR_4 A3                      -- INFERIOR DIREITO

class LDR_SENSOR {

    public:

        LDR_SENSOR();

        LDR_SENSOR(int LDR_1, int LDR_2, int LDR_3, int LDR_4);

        void sensibilidade(int sense);
        
        void leitura();

        int getMediaSuperior();
        int getMediaInferior();
        int getMediaEsquerda();
        int getMediaDireita();

        int getDeltaAxisX();
        int getDeltaAxisY();
        int getLdrSense();

        int getIE();
        int getID();
        int getSE();
        int getSD();

    private:

        int _ldrSense;

        int _ldr1Pin;
        int _ldr2Pin;
        int _ldr3Pin;
        int _ldr4Pin;

        int _m_superior;      
        int _m_inferior;      
        int _m_direita;      
        int _m_esquerda; 

        int _sd;         
        int _se;          
        int _ie;          
        int _id;

        int _delta_v;             
        int _delta_h;
};

#endif
