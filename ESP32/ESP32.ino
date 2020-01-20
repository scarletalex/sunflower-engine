

/*********************************************************
 *  MIT License - Copyright (c) 2019 EduFreit4s
 *  
 *  Projeto: Rastreador solar com ESP32
 *  Nome: Estrelinha
 *  Autor: Eduardo Freitas
 *  Primeira versão: 04/08/2019
 *  Disponivel em: https://github.com/EduFreit4s/Projetos
 * 
*********************************************************/

#include "power.h"
#include "ldr_sensor.h"
#include "twoAxis.h"
#include "iot.h"



#define LDR_1 27                    // SUPERIOR DIREITO     
#define LDR_2 13                      // SUPERIOR ESQUERDO  
#define LDR_3 12                      // INFERIOR ESQUERDO  
#define LDR_4 14                     // INFERIOR DIREITO     

#define PIN_SERVO_Y 32               // SERVO VERTICAL        
#define PIN_SERVO_X 0                // SERVO HORIZONTAL     

#define PIN_VOLT 33                               
#define PIN_AMPER 25      
                      
const char* WIFI = "Delta";
const char* SENHA = "alfaomega18";
       


bool _cicloDemo = false;
int _mode = 1;
unsigned long temp;
unsigned long _tempKrono, _tempDemo1, _tempDemo2, _tempFoto;

int _angleAxisX = 0, _angleAxisY = 70;

TWO_AXIS Atuadores(PIN_SERVO_X, PIN_SERVO_Y);  
LDR_SENSOR LDR(LDR_1, LDR_2, LDR_3, LDR_4);
POWER Shunt(PIN_VOLT, PIN_AMPER);

IOT iot(WIFI, SENHA);

void setup() {

    Serial.begin(115200);                       

    while(!iot.webStart());
    
    iot.spySpeed(500, 500); //serial - web

    Atuadores.setSpeeds(70, 100, 30);
    
    Atuadores.limiteAxisX(25, 30);
    Atuadores.limiteAxisY(20, 68);

    LDR.sensibilidade(1000);
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

    if(millis() - _tempFoto >= Atuadores.getFotoV()){
        
        _tempFoto = millis();
  
        // ATUADOR VERTICAL -- Eixo Y
        if( abs(LDR.getDeltaAxisY()) > LDR.getLdrSense()){        
          if(LDR.getMediaSuperior() > LDR.getMediaInferior() and _angleAxisY >= Atuadores.getMinAxisY()){
            _angleAxisY--;
          }else if(LDR.getMediaSuperior() < LDR.getMediaInferior() and _angleAxisY <= Atuadores.getMaxAxisY()){
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
    
    Atuadores.moveAxisX(Atuadores.getNormalAxisX());
  
    if((millis() - _tempKrono) >= Atuadores.getCronoV()){
        _tempKrono = millis();
        _angleAxisY++;
    }

    Atuadores.moveAxisY(_angleAxisY); 
}

void demo(){

    Atuadores.moveAxisX(Atuadores.getNormalAxisX());
  
    if(_cicloDemo == false){
        if(millis() - _tempDemo1 >= Atuadores.getDemoV()){
            _tempDemo1 = millis(); 
            _angleAxisY--;
        }
    }
    
    if(_angleAxisY <= Atuadores.getMinAxisY()) _cicloDemo = true;
  
    if(_cicloDemo == true){
        if(millis() - _tempDemo2 >= Atuadores.getDemoV()){ 
            _tempDemo2 = millis();
            _angleAxisY++;
        }
    }
  
    if(_angleAxisY >= Atuadores.getMaxAxisY()) _cicloDemo = false;
  
    Atuadores.moveAxisY(_angleAxisY);

}

void fixo(){
     Atuadores.moveAxisX(Atuadores.getNormalAxisX());
     Atuadores.moveAxisY(Atuadores.getNormalAxisY());
}
