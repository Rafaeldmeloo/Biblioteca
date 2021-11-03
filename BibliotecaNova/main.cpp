#include "Emprestimo.h"
#include "Clientes.h"
#include "ClienteVip.h"
#include "ClienteNormal.h"
#include "Controle.h"
#include <iostream>
#include <locale.h>
#include <iomanip>

int main(){
    Controle ctl;
    std::string livros, nomes, cidade;
    Emprestimo emp;
    Clientes *cl[100];
    int qnt = 0;
    int opcao = 0;
    int loop = 1;
    int vip;

    std::string procuraL, procuraN;
    int valorEdita;

    setlocale(LC_ALL, "Portuguese");
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
                "Olá, bem-vindo(a) ao Menu de empréstimo das Bibliotecas PB!\n"
                "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << std::endl;

    while(1){
        ctl.menuPrincipal();

        std::cin >> opcao;
        getchar();

        switch(opcao){
            case 1:
                cidade = "João Pessoa";
                break;

            case 2:
                cidade = "Campina Grande";
                break;

            case 3:
                cidade = "Sapé";

                break;

            case 4:

                std::cout << std::endl;
                std::cout << "-------Lista de empréstimos-------" << std::endl;
                std::cout << std::endl;
                for(int i = 0; i < qnt; i++){
                    cl[i]->MostrarLista();
                }
                break;

            case 5:
                for(int i = 0; i < qnt; i++){
                    delete cl[i];
                }
                return 0;

            default:
                std::cout << "*****Opção inválida*****" << std::endl;
                continue;
        }
        loop = 1;
        while(loop){
            ctl.menuCidade(cidade);

            std::cin >> opcao;
            getchar();

            switch(opcao){
              case 1:
                //adicionar um emprestimo
                std::cout << "\nO cliente possui cartão VIP?\n"
                            "1 - Sim\n"
                            "2 - Não\n";
                std::cin >> vip;
                getchar();

                if(vip == 1)
                    cl[qnt] = new Cliente::ClienteVip();
                else
                    cl[qnt] = new Cliente::ClienteNormal();

                std::cout << "Nome do cliente: ";
                std::getline(std::cin, nomes);

                std::cout << std::endl;
                std::cout << "Nome do livro: ";
                std::getline(std::cin, livros);

                emp = Emprestimo(livros, nomes, cidade);
                cl[qnt]->AdicionaEmprestimo(emp);
                if(vip == 1){
                    std::cout << "\nDeseja adicionar outro empréstimo?\n"
                                "1 - Sim\n"
                                "2 - Não\n";
                    std::cin >> vip;
                    getchar();

                    if(vip == 1){
                        std::cout << std::endl;
                        std::cout << "Nome do livro: ";
                        std::getline(std::cin, livros);
                        emp = Emprestimo(livros, nomes, cidade);
                        cl[qnt]->AdicionaEmprestimo(emp);
                    }
                }
                qnt++;
                break;

              case 2:
                  //atualiza prazos

                for(int i = 0; i < qnt; i++){
                    cl[i]->AtualizaPrazo();
                }
                std::cout << std::endl;
                std::cout << "----Prazos atualizados com sucesso----" << std::endl;
                break;

              case 3:
                  //Mostra lista
                std::cout << std::endl;
                std::cout << "-------Lista de empréstimos-------" << std::endl;
                std::cout << std::endl;
                for(int i = 0; i < qnt; i++){
                    if(cidade == cl[i]->getEmp().getCidade())
                    cl[i]->MostrarLista();
                }
                break;

              case 4:
                  loop = 1;
                    while(loop){
                        switch(cl[0]->opcaoEditar()){
                            case 1:
                                std::cout << "Digite o nome do cliente: ";
                                std::getline(std::cin, procuraN);
                                std::cout << "Digite o nome do livro: ";
                                std::getline(std::cin, procuraL);

                                valorEdita = 0;
                                for(int i = 0; i < qnt; i++){
                                    valorEdita = cl[i]->ExcluirEmprestimo(procuraL, procuraN, cidade);
                                    if(valorEdita == 1 && cidade == cl[i]->getEmp().getCidade()){
                                        for(; i < qnt - 1; i++){
                                            cl[i]->setEmp(cl[i+1]->getEmp());
                                          }
                                          std::cout << std::endl;
                                          std::cout << "----Empréstimo excluído com sucesso----" << std::endl;
                                        qnt--;
                                        break;
                                    }
                                    if(valorEdita == 2){
                                        break;
                                    }
                                    if(qnt - i == 1){
                                        std::cout << "Empréstimo não encontrado" << std::endl;
                                    }
                                }

                                break;

                            case 2:

                                std::cout << "Digite o nome do cliente: ";
                                std::getline(std::cin, procuraN);
                                std::cout << "Digite o nome do livro: ";
                                std::getline(std::cin, procuraL);

                                for(int i = 0; i < qnt; i++){
                                    if(cl[i]->AlterarEmprestimo(procuraL, procuraN, cidade) == true)
                                        break;
                                    if(qnt - i == 1){
                                        std::cout << "Empréstimo não encontrado" << std::endl;
                                    }
                                }
                                break;

                            case 3:
                                loop = 0;
                                break;

                            default:
                                std::cout << "*****Opção inválida*****" << std::endl;
                        }
                    }
                    loop = 1;
                break;

              case 5:
                loop = 0;
                break;

              default:
                std::cout << "*****Opção inválida*****" << std::endl;
            }
        }
    }
}
