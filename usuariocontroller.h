#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

#include <QList>
#include "usuario.h"

class UsuarioController
{
private:
    QList<Usuario> usuarios;

public:
    UsuarioController();

    bool adicionarUsuario(QString login,
                          QString senha);

    bool removerUsuario(QString login);

    bool autenticar(QString login,
                    QString senha);

    QList<Usuario> listarUsuarios();
};

#endif