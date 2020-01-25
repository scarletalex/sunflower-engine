#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for(auto& item : QSerialPortInfo::availablePorts()){
        ui->box_serial->addItem(item.portName());
    }

    for(auto& item : QSerialPortInfo::standardBaudRates()){
        ui->box_velocidade->addItem(QString::number(item));
        serial.setBaudRate(115200);
    }

    connect(&serial,
               SIGNAL(readyRead()),
               this,
               SLOT(dadosRecebidos()));
}

MainWindow::~MainWindow()
{
    serial.close();
    delete ui;
}


void MainWindow::dadosRecebidos()
{
   auto data = serial.readAll();
   auto dados = QJsonDocument::fromJson(data).object().toVariantMap();

   if(dados.contains("POWER")){
    power = dados["POWER"].toString();
    ui->tabelaStats->setItem(1,1, new QTableWidgetItem(power));
   }

   if(dados.contains("VOLT")){
    volt = dados["VOLT"].toString();
    ui->tabelaStats->setItem(2,1, new QTableWidgetItem(volt));
   }

   if(dados.contains("AMPER")){
    amper = dados["AMPER"].toString();
    ui->tabelaStats->setItem(3,1, new QTableWidgetItem(amper));
   }

   if(dados.contains("ENERGY")){
    energy = dados["ENERGY"].toString();
    ui->tabelaStats->setItem(4,1, new QTableWidgetItem(energy));
   }
}

void MainWindow::on_btnPlug_clicked()
{
    plugStatus = !plugStatus;

    if(plugStatus){
        serial.setPortName(ui->box_serial->currentText());
        //serial.setBaudRate(ui->box_velocidade->currentText().toInt());
        serial.setBaudRate(115200);

        if(serial.open(QIODevice::ReadWrite)){
            ui->status_conexao->setText("Status: Conectado");
            ui -> btnPlug ->setText("Desconectar");
            dadosRecebidos();
        }
    }else{
        serial.close();
        ui->status_conexao->setText("Status: Desconectado");
        ui -> btnPlug ->setText("Conectar");
    }
}

void MainWindow::on_btnModo_activated(const QString &arg1)
{
    if(arg1 == "Fotossensivel") serial.write("{\"MODO\": 2}"), ui -> labeltxt ->setText(text[0]);
    if(arg1 == "Cronologico") serial.write("{\"MODO\": 3}"), ui -> labeltxt ->setText(text[1]);
    if(arg1 == "Demo") serial.write("{\"MODO\": 4}"), ui -> labeltxt ->setText(text[2]);
    if(arg1 == "Fixo") serial.write("{\"MODO\": 1}"), ui -> labeltxt ->setText(text[3]);
}
