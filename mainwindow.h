#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialarduino.h"
#include "usuarioswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void conectarArduino();
    void desconectarArduino();
    void ligarLed();
    void desligarLed();
    void receberDados(QString dados);

    void abrirUsuarios();
    void usuarioLogado();

private:
    Ui::MainWindow *ui;

    SerialArduino arduino;
    UsuariosWindow *menuUsuarios;
};

#endif // MAINWINDOW_H