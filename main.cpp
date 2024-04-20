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

bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;

}

bool nao_enforcou (){
    return chutes_errados.size()<5;
}

int main()
{

   // cout << PALAVRA_SECRETA << endl;
    cout<<"+_+_+_+_+_+_+_+ \n JOGO DA FORCA \n+_+_+_+_+_+_+_+"<<endl;
    cout<<endl;

    while (nao_acertou () && nao_enforcou ()){

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

    cout<<"FIM DE JOGO!"<<endl;
    cout<<"A palavra secreta era: "<<PALAVRA_SECRETA <<endl;
    if (nao_acertou()){
        cout<<"você perdeu!Tente novamente"<<endl;
    }
    else{
        cout<<"Parabéns você acertou a palavra secreta!"<<endl;

    }
}