#include "dispositivo.h"
#include "ui_dispositivo.h"

Dispositivo::Dispositivo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dispositivo)
{
    ui->setupUi(this);
}

Dispositivo::~Dispositivo()
{
    delete ui;
}
