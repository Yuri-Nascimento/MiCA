#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAbrir_Usuarios,
            &QAction::triggered,
            this,
            &MainWindow::abrirUsuarios);

    connect(ui->btnConectar,
            &QPushButton::clicked,
            this,
            &MainWindow::conectarArduino);

    connect(ui->btnDesconectar,
            &QPushButton::clicked,
            this,
            &MainWindow::desconectarArduino);

    connect(ui->btnLigar,
            &QPushButton::clicked,
            this,
            &MainWindow::ligarLed);

    connect(ui->btnDesligar,
            &QPushButton::clicked,
            this,
            &MainWindow::desligarLed);

    connect(&arduino,
            &SerialArduino::dadosRecebidos,
            this,
            &MainWindow::receberDados);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::conectarArduino()
{
    MainWindow::usuarioLogado();
    if(arduino.conectar("COM5"))
    {
        ui->statusbar->showMessage("Arduino conectado");
    }
    else
    {
        ui->statusbar->showMessage("Erro ao conectar");
    }
}

void MainWindow::desconectarArduino()
{
    MainWindow::usuarioLogado();
    arduino.desconectar();
        ui->statusbar->showMessage("Arduino desconectado");
}

void MainWindow::ligarLed()
{
    arduino.enviarDados("1");
}

void MainWindow::desligarLed()
{
    arduino.enviarDados("0");
}

void MainWindow::receberDados(QString dados)
{
    ui->textEdit->append(dados);
}


void MainWindow::abrirUsuarios()
{
    menuUsuarios = new UsuariosWindow(this);
    menuUsuarios->show();
}

void MainWindow::usuarioLogado(){
    QString nome = "adm";
    ui->listUsuarioLogado->addItem(
        menuUsuarios->getUsuarioLogado());
}