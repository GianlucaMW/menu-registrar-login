#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void registrar(){
    string username, password;
    
    cout << "Digite o seu nome: "; cin >> username;
    cout << "Digite a sua senha: "; cin >> password;
    ofstream file;
    file.open(username + ".txt");
    file << username << endl << password;
    file.close();
    return;
}

void logar() {
    string username, password, un, pw;
    int escolha2;
    
    cout << "Digite seu usuário: "; cin >> username;
    cout << "Digite a sua senha: "; cin >> password;
    
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    
    if (un == username && pw == password){
        cout << "Acesso Liberado" << endl;
        return;
    }
    else {
        cout << "Senha ou usuário incorreto.\n1: Cadastrar-se\n2: Tentar Novamente\n3: Sair\n"; cin >> escolha2;
    }
    switch(escolha2){
        case 1:
        registrar();
        break;
        case 2:
        logar();
        break;
        case 3:
        break;
    }
}

int main(){
    int escolha;
    
    cout << "Menu:\n1:Registrar\n2:Login\nEscolha:"; cin >> escolha;
    
    if (escolha == 1){
        registrar();
    }
    else if (escolha == 2){
        logar();
    }
    return 0;
}









