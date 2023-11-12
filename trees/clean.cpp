/*
    NÃO DESCOBRI COMO IMPLEMENTAR UM make clean NO WINDOWS AINDA...
    ENTÃO ESSE PROGRAMA LIMPA OS ARQUIVOS CRIADOS
    É PRECISO ATUALIZAR A LISTA DE ARQUIVOS QUE DESEJA DELETAR
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    system("del rec_tree.o");
    system("del rec_tree.exe");
    system("del ex5.o");
    system("del ex5.exe");
    system("del ex6.o");
    system("del ex6.exe");
    return 0;
}
