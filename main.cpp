#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

bool logado(){
    string username, password, un, pw;
    cout << "Digite seu usuário: "; cin >> username;
    cout << "Digite a sua senha: "; cin >> password;
    
    ifstream read("c\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);
    
    if(un == username && pw == password){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int escolha;
    
    cout << "Menu:\n1:Registrar\n2:Login\nEscolha:"; cin >> escolha;
    if (escolha == 1){
        string username, password;
        
        cout << "Digite o seu usuário: "; cin >> username;
        cout << "Digite a sua senha: "; cin >> password;
        
        ofstream file;
        file.open("c\\" + username + ".txt");
        file << username << endl << password;
        file.close();
        
        main();
    }
    else if (escolha == 2){
        bool status = logado();
        
        if (!status){
            cout << "Usuário não logado!!" << endl;
            bool escolha2;
            cout << "Deseja se registrar?\n1:Sim\n2:Não" << endl; cin >> escolha2;
            if (escolha2 == 1) {
                main();
            }
            else{
                exit;
            }
        }
        else {
            cout << "Logado com sucesso!" << endl; 
            return 1;
        }
    }
    return 0;
}
