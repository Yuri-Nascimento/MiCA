#include "usuario.h"

Usuario::Usuario()
{
}

Usuario::Usuario(QString login, QString senha)
{
    this->login = login;
    this->senha = senha;
}

QString Usuario::getLogin() const
{
    return login;
}

QString Usuario::getSenha() const
{
    return senha;
}

void Usuario::setLogin(QString login)
{
    this->login = login;
}

void Usuario::setSenha(QString senha)
{
    this->senha = senha;
}