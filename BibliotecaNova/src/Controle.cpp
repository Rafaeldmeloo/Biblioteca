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
        std::cout << "--------Escolha o munic�pio--------";
        std::cout << std::endl;
        std::cout << "\n1 - Jo�o Pessoa\n"
                    "2 - Campina Grande\n"
                    "3 - Sap�\n"
                    "4 - Imprimir todos os empr�stimos\n"
                    "5 - Sair do programa\n" << std::endl;

}

void Controle::menuCidade(std::string cidade){
    std::cout << std::endl;
            std::cout << "--------Escolha opera��o--------";
            std::cout << std::endl;
            std::cout << "        (" << cidade <<")" << std::endl;
            std::cout << "\n1 - Adicionar um empr�stimo\n"
                        "2 - Atualizar datas de empr�stimo\n"
                        "3 - Mostrar lista de empr�stimos\n"
                        "4 - Editar empr�stimo\n"
                        "5 - Voltar" << std::endl;

}
