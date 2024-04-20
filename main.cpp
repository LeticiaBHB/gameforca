#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// char palavra_secreta[20]; // vetor de caracteres
const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou; //tipo da vchave é char, e logo em seguida o tipo de valor
vector<char> chutes_errados; //vetor dinamico

bool letra_Existe(char chute)
{
    // for(int i = 0; i < PALAVRA_SECRETA.size(); i++){ //size é o tamanho
    //   if (chute == PALAVRA_SECRETA[i]){
    //     return true;
    //}
    // }
    for (char letra : PALAVRA_SECRETA)
    { // interamos pela palavra letra a letra
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}

int main()
{

   // cout << PALAVRA_SECRETA << endl;
    cout<<"+_+_+_+_+_+_+_+ \n JOGO DA FORCA \n+_+_+_+_+_+_+_+"<<endl;
    cout<<endl;
    bool nao_acertou = true;
    bool nao_enforcou = true;
    while (nao_acertou && nao_enforcou)
    { //&& significa e/and

        cout <<"chutes errados:";
        for(char letra: chutes_errados){
            cout<<letra<< " ";
        }
        cout <<endl;

        for(char letra : PALAVRA_SECRETA){
            if(chutou [letra]){
                cout<<letra<<" ";
            }else{
                cout <<"_ ";
            }
        }
        cout<<endl;

        cout<<"seu chute:"<<endl;
        char chute;
        cin >> chute;
        chutou[chute] = true;
        if (letra_Existe(chute))
        {
            cout << "você acertou! seu chute está na palavra" << endl;
        }
        else
        {
            cout << "você errou! seu chute não está na palavra" << endl;
            chutes_errados.push_back(chute);//adiciona a lista do vector
        }
        cout<<endl;
    }
}