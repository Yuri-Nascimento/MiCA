#ifndef SERIALARDUINO_H
#define SERIALARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialArduino : public QObject
{
    Q_OBJECT

public:
    explicit SerialArduino(QObject *parent = nullptr);

    bool conectar(QString porta, int baudRate = QSerialPort::Baud9600);
    void desconectar();

    bool enviarDados(QString dados);
    bool estaConectado();

signals:
    void dadosRecebidos(QString dados);

private slots:
    void lerDados();

private:
    QSerialPort serial;
};

#endif // SERIALARDUINO_H