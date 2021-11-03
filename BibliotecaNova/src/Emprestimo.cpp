#include <iostream>
#include "Emprestimo.h"
#include <locale.h>
#include <iomanip>

using namespace std;


Emprestimo::Emprestimo()
{
    livros = "";
}

Emprestimo::Emprestimo(std::string livros, std::string nomes, std::string cidade){
    this->livros = livros;
    this->nomes = nomes;
    this->cidade = cidade;
    prazo = 30;

}

Emprestimo::~Emprestimo()
{
    //dtor
}

void Emprestimo::setLivros(string livros){
    this->livros = livros;

}

void Emprestimo::setNomes(string nomes){
    this->nomes = nomes;

}

void Emprestimo::setPrazo(int prazo){
    this->prazo = prazo;

}

void Emprestimo::setCidade(string cidade){
    this->cidade = cidade;

}

string Emprestimo::getLivros(){
    return livros;

}

string Emprestimo::getNomes(){
    return nomes;

}

int Emprestimo::getPrazo(){
    return prazo;

}

string Emprestimo::getCidade(){
    return cidade;

}
