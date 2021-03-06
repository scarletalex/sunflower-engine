# Sunflower Engine
Aplicação do Sunflower Engine com a framework Qt e HTML, além do microcontrolador ESP32. Link da apresentação: https://prezi.com/view/ndihzhvzIkm6iVshLYSv/

## Sumário
* [O que é o Sunflower Engine?](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-que-%C3%A9-sunflower-engine)
* [Manual do Usuário](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#manual-do-usu%C3%A1rio)
  * [Como Funciona o Sunflower Engine?](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#como-funciona-o-sunflower-engine)
    * [Modo Fotossensível](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-fotossens%C3%ADvel)
    * [Modo Cronológico](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-cronol%C3%B3gico)
    * [Modo Demo](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-demo)
    * [Modo Fixo](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#modo-fixo)
  * [Utilizando o software do Sunflower Engine](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#utilizando-o-software-do-sunflower-engine)
    * [Estabelecendo a conexão](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#estabelecendo-a-conex%C3%A3o)
    * [Escolhendo o modo de funcionamento](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#escolhendo-o-modo-de-funcionamento)
    * [Monitorando a potência](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#monitorando-a-pot%C3%AAncia)
  * [Utilizando o site do Sunflower engine](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#utilizando-o-site-do-sunflower-engine)
  * [Informações técnicas](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#informa%C3%A7%C3%B5es-t%C3%A9cnicas)
    * [Materiais](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#materiais)
    * [O Circuito](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#o-circuito)
    * [A Página Web](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#a-p%C3%A1gina-web)
    * [O Software para computador](https://github.com/scarletalex/sunflower-engine#o-software-para-computador)
* [Obrigado!](https://github.com/scarletalex/sunflower-engine/blob/master/README.md#obrigado)
    
## O que é Sunflower Engine?

 Hodiernamente, há a necessidade de tornar a matriz energética global cada vez mais sustentável. E os painéis fotovoltaicos são o jeito mais fácil de obter energia limpa e renovável, pois utilizam dos raios solares para conversão direta em energia elétrica. 

 ![painel](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/sequence6_dU9SXFLBCy.gif)

 Os painéis fixos são a maneira mais barata de aplicar essa tecnologia. Tipicamente os painéis solares são instalados com a face voltada para norte ou sul cartográfico (dependendo do hemisfério onde se encontra) e com uma inclinação abaixo da latitude local. Isso garante que a produção energética anual seja boa, mas não significa que os painéis estejam gerando tanta energia quanto possível. Isso acontece devido ao fato que as células que compõe um painel solar só atingem seu pico de produção quando o ângulo de incidência dos raios solares é perpendicular à superfície desta célula. 

 E essa é a proposta do nosso projeto, fazer com que as células estejam voltadas para o Sol a todo momento, rastreando-o. O Sunflower Engine é um rastreador solar que buscará maximizar a eficiência da produção energética da célula fotovoltaica. Além disso, é possível medir sua eficiência monitorando a corrente e tensão para aferir a potência produzida.



## Manual do Usuário

### Como Funciona o Sunflower engine?

 ![prototipo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/image2.jpeg)
 
 Existem diversas formas de seguir o Sol. Alguns sistemas se destacam por terem a possibilidade de executar múltiplos movimentos.
Com um eixo, é possível acompanhar a estrela ao longo do dia. Esse sistema é o mais adotado atualmente, principalmente em fazendas solares (usinas) onde mais se empregam essa tecnologia.
 Já com dois eixos é possível compensar a inclinação da terra ao longo das estações. Isso torna o sistema ainda mais produtivo.
Nosso protótipo conta com dois eixos. Isso significa que ele é capaz de se inclinar para quatro direções diferentes, além disso, esses movimentos são coordenados por quatro maneiras diferentes:

 ##### Modo Fotossensível

 No modo fotossensível, os fotossensores (LDRs) posicionados nas extremidades do painel são responsáveis por informar ao microcontrolador a direção onde a incidência solar é mais instensa, e, consequentemente, responsáveis pela movimentação da estrutura do painel fotovoltaico.
 
 ##### Modo Cronológico

 No modo cronológico, mapeamos a trajetória do sol no céu em uma escala de graus/minutos. Utilizamos o relógio interno do arduino para contar um intervalo. A cada lapso de tempo, o arduino envia um sinal para servo mover a estrutura em um grau. Uma vez que o movimento do sol é previsível, podemos descartar o uso de sensores externos e conseguir o mesmo efeito gastando menos energia e reduzindo componentes. 
 
 ##### Modo Demo
 
  No modo Demo, o rastreador realiza um movimento apenas para fins de demonstração, como o próprio nome diz. Trata-se de um movimento da estrutura da célula fotovoltaica pelo servo motor apenas de um lado para outro, respeitando angulação máxima de 35° para cada lado, sem preocupação com a melhor posição para a produção de energia elétrica.
  
 ##### Modo Fixo
 
 No modo fixo, a estrutura da célula fotovoltaica é fixada em uma posição estacionária em que ao longo do dia, irá receber a maior incidência de luz possível. Tipicamente os painéis solares são instalados com a face voltada para norte ou sul cartográfico (dependendo do hemisfério onde se encontra) e com uma inclinação abaixo da latitude local. Assim, o painel deverá se posicionar voltado para o hemisfério norte, com inclinação de 7 graus.

## Utilizando o software do Sunflower engine

##### Estabelecendo a conexão

 Para iniciar o funcionamento da máquina, deve-se abrir a segunda aba "Conexão" e selecionar a porta no qual o ESP32 está conectado ao dispositivo utilizado. Em seguida, selecionar a velocidade em que as informações serão passadas, onde a velocidade padrão ("baudrate") da placa é 115200 bauds. Após isso, ao clicar em "Conectar" e a conexão serial for estabelecida, o status no topo mudará para "Conectado", caso contrário, permanecerá da mesma maneira com o status "Desconectado", até que o usuário clique novamente e uma nova tentativa de conexão for estabelecida.

![conexao](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/Conex%C3%A3o%5D.png)

##### Escolhendo o modo de funcionamento

 Na primeira aba, a tela inicial contém os modos de funcionamento do projeto para serem escolhidos. Quando selecionado um deles, é apresentada uma breve explanação do modo de funcionamento escolhido e mudará o estado de funcionamento da estrutura do projeto. Logo abaixo estão as telas quando o modo é escolhido. A máquina já está funcionando.

![fotossensível](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/fotossensivel.png)
![cronológico](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/cronologico.png)
![Demo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/demo.png)
![Fixo](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/fixo.png)


##### Monitorando a potência

 A terceira aba apresentará os dados de potência, tensão e corrente produzidos pelo painel fotovoltaico em tempo real, caso a conexão serial esteja estabelecida.
 
 ![potencia](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/dados.png)
 
## Utilizando o site do Sunflower engine

O site do Sunflower Engine permite que o usuário tenha acesso remoto às informações atualizadas de produção da máquina, apenas sendo necessário conexão com a internet. Existem três expositores, um para cada informação, sendo eles: Tensão, Corrente e Potência. A partir dessas informações, o usuário pode decidir modificar o modo de funcionamento da estrutura do projeto por meio do software desenvolvido e anteriormente explicado.

![web](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/web.png)

### Informações Técnicas

#### Materiais

- Microcontrolador ESP32
- Célula Fotovoltaica
- Servos SG90
- LDR
- LED
- Módulo Sensor de Tensão

#### O Circuito

![circuito](https://github.com/scarletalex/sunflower-engine/blob/master/Figuras%20do%20manual/Circuito.png)

Utilizamos os sensores LDRs nas extremidades da célula fotovoltaica para realizar o processo de captação de informações da luminosidade, enviar para o ESP32 e, posteriormente, os servos realizarem movimentação da máquina. O módulo sensor de tensão é responsável por recolher os dados de tensão que serão exibidos e utilizados para calcular a corrente e potência. Um LED também é utilizado para mostrar a geração da célula fotovoltaica.

Todos os componentes estão conectados ao ESP32, sendo este o grande responsável por receber e passar informações para o circuito, ou seja, para que ele funcione. Para monitorar os dados via página web, é necessário que o ESP32 esteja conectado à uma rede WiFi com internet. Contudo, o monitoramento também pode ser feito via aplicação de computador de modo offline.

#### A Página Web

Esta página web (http://sunflower-engine.herokuapp.com/) está hospedada gratuitamente no Heroku. Conhecimento de HTML e CSS foram utilizados para para poder organizar o site, além de JavaScript e Python, para reagir à eventos e fazer a comunicação com o software para computador e para a ESP32. A biblioteca Flask feita pela comunidade do Python também foi muito importante para o desenvolvimento da página web, no que tange a realização da comunicação e o deploy do servidor.

#### O Software para computador

O software desenvolvido para computador a fim do usuário ter controle da nossa aplicação mesmo sem acesso à internet, foi utilizado a framework Qt junto com a IDE Qt Creator. A linguagem utilizada foi o C++ e ainda foi necessário a utilização de XML para editar a parte gráfica do programa.

## Obrigado!

Este projeto é resultado do empenho dos alunos **Gustavo Souza**, **Maria Fernanda** e **Victor Nunes**, bacharelandos em Engenharia Elétrica no IFPB - *campus* João Pessoa. Foi desenvolvido para a disciplina de Técnicas de Programação, ministrada pelo Dr. Patric Lacouth da Silva, com o objetivo de adquirição de nota parcial para a conclusão da disciplina em questão. Para quaisquer eventuais dúvidas ou *feedback*, os e-mails para contato são: gustavo.souza@academico.ifpb.edu.br; fernanda.aguiar@academico.ifpb.edu.br; victorramalho101@gmail.com. 
