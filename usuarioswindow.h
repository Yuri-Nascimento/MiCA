#ifndef USUARIOSWINDOW_H
#define USUARIOSWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "usuariocontroller.h"

namespace Ui {
class UsuariosWindow;
}

class UsuariosWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    void on_btnAdicionar_clicked();

    void on_btnExcluir_clicked();

    void on_btnLogin_clicked();


public:
    explicit UsuariosWindow(QWidget *parent = nullptr);
    ~UsuariosWindow();


    void setUsuarioLogado(QString login);
    QString getUsuarioLogado();

private:
    Ui::UsuariosWindow *ui;
    void atualizarLista();
    UsuarioController controller;
    QString usuarioLogado;
};

#endif // USUARIOSWINDOW_H
