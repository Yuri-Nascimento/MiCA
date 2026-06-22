#include "usuariocontroller.h"

UsuarioController::UsuarioController()
{
}

bool UsuarioController::adicionarUsuario(QString login,
                                         QString senha)
{
    for(auto u : usuarios)
    {
        if(u.getLogin() == login)
            return false;
    }

    usuarios.append(Usuario(login, senha));

    return true;
}

bool UsuarioController::removerUsuario(QString login)
{
    for(int i=0; i<usuarios.size(); i++)
    {
        if(usuarios[i].getLogin() == login)
        {
            usuarios.removeAt(i);
            return true;
        }
    }

    return false;
}

bool UsuarioController::autenticar(QString login,
                                   QString senha)
{
    for(auto u : usuarios)
    {
        if(u.getLogin() == login &&
            u.getSenha() == senha)
        {
            return true;
        }
    }

    return false;
}

QList<Usuario> UsuarioController::listarUsuarios()
{
    return usuarios;
}