
#include "power.h"
#include "ldr_sensor.h"
#include "twoAxis.h"
#include "iot.h"


#define LDR_1 14                    // SUPERIOR DIREITO      - D1 / 5 -- BRANCO
#define LDR_2 5                      // SUPERIOR ESQUERDO     - D2 / 4 -- AMARELO
#define LDR_3 4                      // INFERIOR ESQUERDO     - D5 / 14 -- VERDE
#define LDR_4 12                     // INFERIOR DIREITO      - D6 / 12  -- AZUL

#define PIN_SERVO_Y 2               // SERVO VERTICAL       - D5 / 14 -- PRETO
#define PIN_SERVO_X 2                // SERVO HORIZONTAL     - D6 / 12 -- AZUL   

#define PIN_VOLT 2                               //    - D7 / 13
#define PIN_AMPER 2                             //     - D8 / 15

#define SHUNT 223

#define WIFI "teste"
#define SENHA "1234"


bool _cicloDemo = false;
int _mode = 1;

int _angleAxisX, _angleAxisY;

TWO_AXIS Atuadores(PIN_SERVO_X, PIN_SERVO_Y);  
LDR_SENSOR LDR(LDR_1, LDR_2, LDR_3, LDR_4);
POWER Shunt(PIN_VOLT, PIN_AMPER, SHUNT);
IOT iot(WIFI, SENHA);


void setup() {

    Serial.begin(115200);                       

    while(!iot.webStart());
    iot.spySpeed(500, 500); //serial - web

    Atuadores.setSpeeds(30, 42, 240000);
    Atuadores.limiteAxisX(25, 72);  
    Atuadores.limiteAxisY(45, 86);

    LDR.sensibilidade(50);
    Shunt.velocidadeLeitura(1000);
    
}

void loop(){

  LDR.leitura();
  Shunt.leitura();

  iot.iotSpy(Shunt);
   
  switch (iot.getModo()){
      case 1: foto();   break;
      case 2: crono();  break;
      case 3: demo();   break;
      case 4: fixo();   break;
  }

}

void foto(){

    unsigned long _tempFoto;

    if(millis() - _tempFoto >= Atuadores.getFotoV()){
        
        _tempFoto = millis();
  
        // ATUADOR VERTICAL -- Eixo Y
        if( abs(LDR.getDeltaAxisY()) > LDR.getLdrSense()){        
          if(LDR.getMediaSuperior() > LDR.getMediaInferior()){
            _angleAxisY--;
          }else if(LDR.getMediaSuperior() < LDR.getMediaInferior()){
            _angleAxisY++;
          }
          Atuadores.moveAxisY(_angleAxisY);                                  
        }
        
        //////////////////////////////////////////////////////////////////////////////////////////////////
      
        // ATUADOR HORIZONTAL  -- Eixo X
        if( abs(LDR.getDeltaAxisX()) > LDR.getLdrSense()){       
            if (LDR.getMediaEsquerda() > LDR.getMediaDireita()){
              _angleAxisX++;    
            }else if(LDR.getMediaEsquerda() < LDR.getMediaDireita()){
              _angleAxisX--;
            }
            Atuadores.moveAxisX(_angleAxisX);                                  
        }  
    }
}

void crono(){
    
    unsigned long _tempKrono;
    
    Atuadores.moveAxisX(Atuadores.getNormalAxisX());
  
    if(millis() - _tempKrono >= Atuadores.getCronoV()){
        _tempKrono = millis();
        _angleAxisY++;
    }
  
    Atuadores.moveAxisY(_angleAxisY); 
}

void demo(){

    unsigned long _tempDemo1, _tempDemo2;

    Atuadores.moveAxisX(Atuadores.getNormalAxisX());
  

    if(_cicloDemo == false){
        if(millis() - _tempDemo1 >= Atuadores.getDemoV()){
            _tempDemo1 = millis(); 
           if(_angleAxisY > Atuadores.getMinAxisY()) _angleAxisY--;
           
        }
    }
    
    if(_angleAxisY == Atuadores.getMinAxisY()) _cicloDemo = true;
  
    if(_cicloDemo == true){
        if(millis() - _tempDemo2 >= Atuadores.getDemoV()){ 
            _tempDemo2 = millis();
           if(_angleAxisY < Atuadores.getMaxAxisY()) _angleAxisY++;
        }
    }
  
    if(_angleAxisY == Atuadores.getMaxAxisY()) _cicloDemo = false;
  
    Atuadores.moveAxisY(_angleAxisY);

}

void fixo(){
     Atuadores.moveAxisX(Atuadores.getNormalAxisX());
     Atuadores.moveAxisY(Atuadores.getNormalAxisY());
}
