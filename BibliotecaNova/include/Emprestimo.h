#pragma once
#include <iostream>


class Emprestimo
{
    public:
        Emprestimo();
        Emprestimo(std::string livros, std::string nomes, std::string cidade);
        virtual ~Emprestimo();

        void setLivros(std::string livros);
        void setNomes(std::string nomes);
        void setPrazo(int prazo);
        void setCidade(std::string cidade);
        std::string getLivros();
        std::string getNomes();
        int getPrazo();
        std::string getCidade();

    protected:

    private:
        std::string livros;
        std::string nomes;
        int prazo;
        std::string cidade;
};
