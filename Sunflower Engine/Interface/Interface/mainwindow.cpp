#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
   qDebug()<<data;

   if(dados.contains("POWER")){
    power = dados["POWER"].toString();
    ui->tabelaStats->setItem(1,-1, new QTableWidgetItem(power));
   }

   if(dados.contains("VOLT")){
    volt = dados["VOLT"].toString();
    ui->tabelaStats->setItem(1,0, new QTableWidgetItem(volt));
   }

   if(dados.contains("AMPER")){
    amper = dados["AMPER"].toString();
    ui->tabelaStats->setItem(1,1, new QTableWidgetItem(amper));
   }



}

void MainWindow::on_btnPlug_clicked()
{
    plugStatus = !plugStatus;

    if(plugStatus){
        serial.setPortName(ui->box_serial->currentText());
        serial.setBaudRate(ui->box_velocidade->currentText().toInt());


        if(serial.open(QIODevice::ReadWrite)){
            ui->status_conexao->setText("Status: Conectado");
            ui -> btnPlug ->setText("Desconectar");
        }
    }else{
        ui->status_conexao->setText("Status: Desconectado");
        ui -> btnPlug ->setText("Conectar");
        serial.close();
    }
}

void MainWindow::on_btnModo_activated(const QString &arg1)
{
    if(arg1 == "Modo fotossensivel") serial.write("{\"MODO\": 1}"), ui -> labeltxt ->setText(text[0]);
    if(arg1 == "Modo cronologico") serial.write("{\"MODO\": 2}"), ui -> labeltxt ->setText(text[1]);
    if(arg1 == "Modo demo") serial.write("{\"MODO\": 3}"), ui -> labeltxt ->setText(text[2]);
    if(arg1 == "Modo fixo") serial.write("{\"MODO\": 4}"), ui -> labeltxt ->setText(text[3]);
}

void MainWindow::on_manual_clicked()
{
    QUrl url = QUrl("https://github.com/scarletalex/sunflower-engine/blob/master/README.md");

        QDesktopServices::openUrl(url);
}
