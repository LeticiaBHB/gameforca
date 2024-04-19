#include <iostream>
#include <string>

using namespace std;

//char palavra_secreta[20]; // vetor de caracteres
const string PALAVRA_SECRETA = "MELANCIA";

bool letra_Existe(char chute){
    for(int i = 0; i < PALAVRA_SECRETA.size(); i++){ //size é o tamanho
        if (chute == PALAVRA_SECRETA[i]){
            return true;
        }
    }
    return false;
}

int main(){

    cout <<PALAVRA_SECRETA<<endl;
    bool nao_acertou = true;
    bool nao_enforcou = true;
    while(nao_acertou && nao_enforcou){ //&& significa e/and
    char chute;
    cin>>chute;
    if(letra_Existe(chute)) {
    cout<<"você acertou! seu chute está na palavra"<<endl;
    } else{
        cout<<"você errou! seu chute não está na palavra"<<endl;
    }
    }
}