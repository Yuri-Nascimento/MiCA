#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    arduino = new QSerialPort(this);

    // Identifica a porta do Arduino (mude a descrição se necessário)
    QString portaArduino = "COM5";
    for(const QSerialPortInfo &info : QSerialPortInfo::availablePorts()){
        if(info.description().contains("Arduino")){
            portaArduino = info.portName();
            break;
        }
    }

    if(!portaArduino.isEmpty()){
        arduino->setPortName(portaArduino);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);

        if(arduino->open(QIODevice::ReadWrite)){
            qDebug() << "Arduino conectado na porta:" << portaArduino;
            // Conecta o sinal de recebimento de dados a uma função
            connect(arduino, &QSerialPort::readyRead, this, &MainWindow::lerSerial);
        }
    }

    // Conecta os botões da sua interface gráfica às funções (Slots)
    connect(ui->btnLigar, &QPushButton::clicked, this, &MainWindow::ligarLED);
    connect(ui->btnDesligar, &QPushButton::clicked, this, &MainWindow::desligarLED);
    connect(ui->lcdNumber, &QLCDNumber::overflow, this, &MainWindow::lerSerial);
    connect(ui->ligarVermelho, &QPushButton::clicked, this, &MainWindow::on_ligarVermelho_clicked);
}

MainWindow::~MainWindow() {
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void MainWindow::ligarLED() {
    if(arduino->isWritable()){
        arduino->write("2");
    }
}

void MainWindow::desligarLED() {
    if(arduino->isWritable()){
        arduino->write("0");
    }
}

void MainWindow::lerSerial() {
    if(arduino->isReadable()){
        QByteArray dadosRecebidos = arduino->readAll();
        qDebug() << "Dados vindos do Arduino:" << dadosRecebidos;
    }
}

void MainWindow::on_ligarVermelho_clicked()
{
    if(arduino->isWritable()){
        arduino->write("2");
    }
}



