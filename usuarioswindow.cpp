#include "usuarioswindow.h"
#include "ui_usuarioswindow.h"

#include <QMessageBox>

UsuariosWindow::UsuariosWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UsuariosWindow)
{
    ui->setupUi(this);
    controller.adicionarUsuario("admin",
                                "123");

    atualizarLista();
}

UsuariosWindow::~UsuariosWindow()
{
    delete ui;
}

void UsuariosWindow::atualizarLista()
{
    ui->listUsuarios->clear();

    for(auto usuario :
         controller.listarUsuarios())
    {
        ui->listUsuarios->addItem(
            usuario.getLogin());
    }
}

void UsuariosWindow::on_btnAdicionar_clicked()
{
    QString login = ui->txtLogin->text();
    QString senha = ui->txtSenha->text();

    if(login.isEmpty())
        QMessageBox::information(
            this,
            "Erro",
            "Nome de usuário obrigatório");

    else if(senha.length() < 6)
        QMessageBox::information(
            this,
            "Erro",
            "Senha muito curta");

    else if(controller.adicionarUsuario(login,
                                    senha))
    {
        QMessageBox::information(
            this,
            "Sucesso",
            "Usuário cadastrado");

        atualizarLista();
    }
    else
    {
        QMessageBox::warning(
            this,
            "Erro",
            "Usuário já existe");
    }
}

void UsuariosWindow::on_btnExcluir_clicked()
{
    QString login = ui->txtLogin->text();

    if(controller.removerUsuario(login))
    {
        QMessageBox::information(
            this,
            "Sucesso",
            "Usuário removido");

        atualizarLista();
    }
    else
    {
        QMessageBox::warning(
            this,
            "Erro",
            "Usuário não encontrado");
    }
}

void UsuariosWindow::on_btnLogin_clicked()
{
    QString login = ui->txtLogin->text();
    QString senha = ui->txtSenha->text();



    if(controller.autenticar(login,
                              senha))
    {
        QMessageBox::information(
            this,
            "Login",
            "Acesso permitido");
        ui->listUsuarioLogado->clear();
        ui->listUsuarioLogado->addItem(
            login);
        UsuariosWindow::setUsuarioLogado(login);
    }
    else
    {
        QMessageBox::critical(
            this,
            "Login",
            "Usuário ou senha inválidos");
    }
}

void UsuariosWindow::setUsuarioLogado(QString login){
    usuarioLogado = login;
}

QString UsuariosWindow::getUsuarioLogado(){
    return usuarioLogado;
}