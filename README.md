# Sunflower Engine
Aplicação do Sunflower Engine com a framework Qt e HTML, além do microcontrolador ESP8266.
## Sumário
* [O que é o Sunflower Engine?](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-que-%C3%A9-sunflower-engine)
* [Manual do Usuário](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#manual-do-usu%C3%A1rio)
  * [Como Funciona o Sunflower Engine?](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#como-funciona-o-sunflower-engine)
    * [Modo Demo](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-demo)
    * [Modo Cronológico](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-cronol%C3%B3gico)
    * [Modo Fixo](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-fixo)
    * [Modo rastreável](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-rastre%C3%A1vel)
  * [Utilizando o software do Sunflower Engine](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#utilizando-o-software-do-sunflower-engine)
    * [Monitorando a potência](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#monitorando-a-pot%C3%AAncia)
  * [Utilizando o site do Sunflower Engine](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#utilizando-o-site-do-sunflower-engine)
    * [Monitorando a potência com os valores](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#monitorando-a-pot%C3%AAncia-com-os-valores)
    * [Alterando o estado da placa](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#alterando-o-estado-da-placa)
  * [Informações técnicas](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#informa%C3%A7%C3%B5es-t%C3%A9cnicas)
    * [Materiais](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#materiais)
    * [O Circuito](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-circuito)
    * [A Página Web](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#a-p%C3%A1gina-web)
    * [O Software para Desktop](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-software-para-desktop)
    
## O que é Sunflower Engine?

 Hodiernamente, há a necessidade de tornar a matriz energética global cada vez mais sustentável. E os painéis fotovoltaicos são o jeito mais fácil de obter energia limpa e renovável, pois utilizam dos raios solares para conversão direta em energia elétrica. 

 ![painel](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/sequence6_dU9SXFLBCy.gif)

 Os painéis fixos são a maneira mais barata para isso. Tipicamente os painéis solares são instalados com a face voltada para norte ou sul cartográfico (dependendo do hemisfério onde se encontra) e com uma inclinação abaixo da latitude local. Isso garante que a produção energética anual seja boa, mas não significa que os painéis estejam gerando tanta energia quanto possível. Isso acontece devido ao fato que as células que compõe um painel solar só atingem seu pico de produção quando o ângulo de incidência dos raios solares é perpendicular à superfície desta célula. 

 E essa é a proposta do nosso projeto, fazer com que as células estejam voltadas para o Sol a todo momento, rastreando-o. O Sunflower Engine é um rastreador solar que buscará maximizar a eficiência da produção energética da célula fotovoltaica. Além disso, é possível medir sua eficiência monitorando a corrente e tensão para adquirir a potência produzida.



## Manual do Usuário

### Como Funciona o Sunflower engine?

 ![prototipo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/image2.jpeg)
 
 Existem diversas formas de seguir o Sol. Alguns sistemas se destacam por terem a possibilidade de executar múltiplos movimentos.
Com um eixo, é possível acompanhar a estrela ao longo do dia. Esse sistema é o mais adotado atualmente, principalmente em fazendas solares (usinas) onde mais se empregam essa tecnologia.
 Já com dois eixos é possível compensar a inclinação da terra ao longo das estações. Isso torna o sistema ainda mais produtivo.
Nosso protótipo conta com dois eixos. Isso significa que ele é capaz de se inclinar para quatro direções diferentes, além disso, esses movimentos são coordenados por quatro maneiras diferentes:

 ##### Modo Demo
 
  No modo Demo, o rastreador realiza um movimento apenas para fins de demonstração, como o próprio nome diz. Trata-se de um movimento da estrutura da célula fotovoltaica pelo servo motor apenas de um lado para outro, respeitando angulação máxima de 35° para cada lado, sem preocupação com a melhor posição para a produção de energia elétrica.
  
 ##### Modo Cronológico

 No modo cronológico, mapeamos a trajetória do sol no céu em uma escala de graus/minutos. Utilizamos o relógio interno do arduino para contar um intervalo. A cada lapso de tempo, o arduino envia um sinal para servo mover a estrutura em um grau. Uma vez que o movimento do sol é previsível, podemos descartar o uso de sensores externos e conseguir o mesmo efeito gastando menos energia e reduzindo componentes. 
 
 ##### Modo Fixo
 
 No modo fixo, a estrutura da célula fotovoltaica é fixada em uma posição estacionária em que ao longo do dia, irá receber a maior incidência de luz possível. Tipicamente os painéis solares são instalados com a face voltada para norte ou sul cartográfico (dependendo do hemisfério onde se encontra) e com uma inclinação abaixo da latitude local. Assim, o painel deverá se posicionar voltado para o hemisfério norte, com inclinação de 7 graus.
 
 ##### Modo Fotossensível

 No modo fotossensível, os fotossensores (LDRs) posicionados nas extremidades do painel são responsáveis por informar ao microcontrolador a direção onde a incidência solar é mais instensa, e, consequentemente, responsáveis pela movimentação da estrutura do painel fotovoltaico.

### Utilizando o software do Sunflower engine

![Demo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/demo.png)
![cronológico](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/cronologico.png)
![Fixo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/fixo.png)
![fotossensível](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/fixo.png)

A tela inicial contém os modos de funcionamento do projeto para ser escolhido. Quando selecionado, apresenta uma breve explanação do funcionamento.


##### Monitorando a potência

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
- [1 Módulo Sensor de Tensão] 
- [Mini protoboard]
- [Jumpers]
- [Madeira] 
- [Parafusos] 


#### O Circuito

#### A Página Web

#### O Software para Desktop

