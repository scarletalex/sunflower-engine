#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSerialPort serial;

    QString power;
    QString volt;
    QString amper;
    QString energy;


    int estrelinhaModo;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void dadosRecebidos();
    void on_btnPlug_clicked();
    void on_btnModo_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool plugStatus = false;
    QString text[4] = {

        "No modo Fotossensível, o rastreador solar utiliza sensores para calcular a posição da luz",
        "No modo Cronologico, o rastreador solar utiliza um relogio interno para acompanhar o sol",
        "No modo Demo, o rastreador execulta movimentos no eixo y para demonstrar seu funcionamento",
        "No modo Fixo, o rastreador imita um painel solar tradicional instalado no telhado"
    };

};
#endif // MAINWINDOW_H
