#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class Usuario
{
private:
    QString login;
    QString senha;

public:
    Usuario();
    Usuario(QString login, QString senha);

    QString getLogin() const;
    QString getSenha() const;

    void setLogin(QString login);
    void setSenha(QString senha);
};

#endif