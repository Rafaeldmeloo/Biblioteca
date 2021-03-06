#pragma once
#include "Emprestimo.h"

namespace Cliente{
class ClienteVip:public Clientes
{
    public:
        ClienteVip();
        virtual ~ClienteVip();

        bool getVip();
        void AdicionaEmprestimo(Emprestimo emp);
        void setEmp(Emprestimo emp);
        Emprestimo getEmp();
        void AtualizaPrazo();
        void MostrarLista();
        int ExcluirEmprestimo(std::string procuraL, std::string procuraN, std::string cidade);
        bool AlterarEmprestimo(std::string procuraL, std::string procuraN, std::string cidade);
        int opcaoEditar();



    protected:

    private:
        Emprestimo emprestimo, emprestimo2;
};
}
