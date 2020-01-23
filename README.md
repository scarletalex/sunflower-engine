# Sunflower engine
Aplicação do Sunflower-engine com a framework Qt e html, além do microcontrolador ESP8266.
## Sumário
* [O que é o Sunflower engine?](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-que-%C3%A9-sunflower-engine)
* [Manual do Usuário](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#manual-do-usu%C3%A1rio)
  * [Como Funciona o Sunflower engine?](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#como-funciona-o-sunflower-engine)
    * [Modo Demo](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-demo)
    * [Modo Cronológico](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-cronol%C3%B3gico)
    * [Modo Fixo](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-fixo)
    * [Modo rastreável](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-rastre%C3%A1vel)
  * [Utilizando o software do Sunflower engine](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#utilizando-o-software-do-sunflower-engine)
    * [Monitorando a potência](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#monitorando-a-pot%C3%AAncia)
  * [Utilizando o site do Sunflower engine](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#utilizando-o-site-do-sunflower-engine)
    * [Monitorando a potência com os valores](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#monitorando-a-pot%C3%AAncia-com-os-valores)
    * [Alterando o estado da placa](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#alterando-o-estado-da-placa)
  * [Informações técnicas](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#informa%C3%A7%C3%B5es-t%C3%A9cnicas)
    * [Materiais](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#materiais)
    * [O Circuito](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-circuito)
    * [A Página Web](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#a-p%C3%A1gina-web)
    * [O Software para Desktop](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-software-para-desktop)
    
## O que é Sunflower engine?

Hodiernamente, precisa transformar nossa matriz energética limpa (solar) e global. Tipicamente os painéis solares são instalados com a face voltada para norte ou sul cartográfico (dependendo do hemisfério onde se encontra) e com uma inclinação abaixo da latitude local. Com isso, há garantia que a produção energética anual seja boa, mas não significa que os painéis estejam gerando tanta energia quanto possível. Isso acontece devido ao fato que as células que compõe um painel solar só atingem seu pico de produção quando o ângulo de incidência dos raios solares é perpendicular à superfície desta célula. 

Com efeito, a proposta da nossa maquina é as células da placa está voltada ao sol a todo momento, rastreando-o. Além disso, medir sua eficiência monitorando a corrente e tensão para adquirir a potência produzida.

## Manual do Usuário

### Como Funciona o Sunflower engine?

 ![prototipo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/image2.jpeg)
 
O primeiro passo a ser dado para conseguir maximizar a eficiência da tecnologia atual, não apenas do ponto de vista de consumo, mas também da produção que é a função de um rastreador solar. 
Para isso, será disponibilizado um site no qual haverá as informações da corrente, tensão e potência da produzida durante o processo, medida por um sensor. 

 #### Modo Demo
 
 ![Demo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/demo.png)
 
 #### Modo Cronológico

![cronológico](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/cronologico.png)

 No modo cronológico, mapeamos a trajetória do sol no céu em uma escala de graus/minutos. Utilizamos o relógio interno do arduino para contar um intervalo. A cada lapso de tempo, o arduino envia um sinal para servo mover a estrutura em um grau. Uma vez que o movimento do sol é altamente previsível, podemos descartar o uso de sensores externos e conseguir o mesmo efeito gastando menos energia e reduzindo componentes. 
 
 #### Modo Fixo
 
 ![Fixo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/fixo.png)
 
 Os painéis fixos são a maneira mais barata. Tipicamente os painéis solares são instalados com a face voltada para norte ou sul cartográfico (dependendo do hemisfério onde se encontra) e com uma inclinação abaixo da latitude local. Ademais, a latitude utilizada para nossa região é de 7 graus
 
 #### Modo Fotossensível
 
 ![fotossensível](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/fixo.png)
 
No modo fotossensível, os fotossensores posicionados nas extremidades do painel são responsáveis por informar o microcontrolador a direção da fonte de luz.
Cada ldr está em série com resistor de 10k atuando como divisores de tensão. Quando a intensidade da luz é máxima, a resistência do ldr é desprezível e a assim, a corrente total flui para o pino analógico do arduino. Quando a intensidade da luz cai, a resistência do ldr aumenta proporcionalmente provocando uma queda de tensão que deixa de chegar ao microcontrolador. 

### Utilizando o software do Sunflower engine

#### Monitorando a potência

### Utilizando o site do Sunflower engine

#### Monitorando a potência com os valores

#### Alterando o estado da placa

### Informações Técnicas

#### Materiais

- [2 Servos SG90] 
- [Microcontrolador ESP8266]
- [4 Ldrs 10mm]
- [4 Resistores de 10㏀]
- [1 Resistor 220Ω]
- [1 Sensor de Tensão] 
- [Mini protoboard]
- [Jumpers]
- [Madeira] 
- [Parafusos] 


#### O Circuito

#### A Página Web

#### O Software para Desktop

