#pragma once
#include "Emprestimo.h"

namespace Cliente{
class ClienteNormal:public Clientes
{
    public:
        ClienteNormal();
        virtual ~ClienteNormal();

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
        Emprestimo emprestimo;

    private:
};
}
