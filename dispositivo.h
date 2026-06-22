#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <QMainWindow>

namespace Ui {
class Dispositivo;
}

class Dispositivo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dispositivo(QWidget *parent = nullptr);
    ~Dispositivo();

private:
    Ui::Dispositivo *ui;
};

#endif // DISPOSITIVO_H
