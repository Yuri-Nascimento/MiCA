#include "serialarduino.h"

SerialArduino::SerialArduino(QObject *parent)
    : QObject(parent)
{
    connect(&serial,
            &QSerialPort::readyRead,
            this,
            &SerialArduino::lerDados);
}

bool SerialArduino::conectar(QString porta, int baudRate)
{
    serial.setPortName(porta);
    serial.setBaudRate(baudRate);

    return serial.open(QIODevice::ReadWrite);
}

void SerialArduino::desconectar()
{
    if(serial.isOpen())
        serial.close();
}

bool SerialArduino::enviarDados(QString dados)
{
    if(!serial.isOpen())
        return false;

    serial.write(dados.toUtf8());

    return true;
}

bool SerialArduino::estaConectado()
{
    return serial.isOpen();
}

void SerialArduino::lerDados()
{
    QByteArray dados = serial.readAll();

    emit dadosRecebidos(QString(dados));
}