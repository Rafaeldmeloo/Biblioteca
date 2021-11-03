#include <iostream>
#include "Controle.h"

using namespace std;


Controle::Controle()
{
    //ctor
}

Controle::~Controle()
{
    //dtor
}

void Controle::menuPrincipal(){
std::cout << std::endl;
        std::cout << "--------Escolha o município--------";
        std::cout << std::endl;
        std::cout << "\n1 - João Pessoa\n"
                    "2 - Campina Grande\n"
                    "3 - Sapé\n"
                    "4 - Imprimir todos os empréstimos\n"
                    "5 - Sair do programa\n" << std::endl;

}

void Controle::menuCidade(std::string cidade){
    std::cout << std::endl;
            std::cout << "--------Escolha operação--------";
            std::cout << std::endl;
            std::cout << "        (" << cidade <<")" << std::endl;
            std::cout << "\n1 - Adicionar um empréstimo\n"
                        "2 - Atualizar datas de empréstimo\n"
                        "3 - Mostrar lista de empréstimos\n"
                        "4 - Editar empréstimo\n"
                        "5 - Voltar" << std::endl;

}
