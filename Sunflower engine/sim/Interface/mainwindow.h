#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QDesktopServices>
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
    void on_manual_clicked();

private:
    Ui::MainWindow *ui;
    bool plugStatus = false;
    QString text[4] = {

        "Neste modo, o rastreador solar utiliza sensores para calcular a posição da luz Solar",
        "Neste modo, um relógio interno controla os movimentos para acompanhar o sol",
        "Neste modo, o rastreador executa movimentos para demonstrar seu funcionamento",
        "Neste modo, o rastreador imita um painel solar tradicional instalado fixo no telhado"
    };

};
#endif // MAINWINDOW_H
