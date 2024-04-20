#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>


using namespace std;

// char palavra_secreta[20]; // vetor de caracteres
string PALAVRA_SECRETA = "MELANCIA";
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

void imprime_cabeçalho(){
    cout<<"+_+_+_+_+_+_+_+ \n JOGO DA FORCA \n+_+_+_+_+_+_+_+"<<endl;
    cout<<endl;
}

void imprime_erros(){
    cout <<"chutes errados:";
    for(char letra: chutes_errados){
        cout<<letra<< " ";
    }
    cout <<endl;
}

void imprime_palavra(){
    for(char letra : PALAVRA_SECRETA){
        if(chutou [letra]){
            cout<<letra<<" ";
        }else{
            cout <<"_ ";
        }
    }
    cout<<endl;
}

void chuta(){
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

vector<string> le_arquivo(){//void não retorna nada
    ifstream arquivo; //tipo de dados que vamos usar para ler valores de um arquivo
    arquivo.open("palavras.txt"); //vai abrir
    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >>quantidade_palavras;

        //cout<<"O arquivo possui "<< quantidade_palavras<< " palavras." << endl;

        vector<string> palavras_do_arquivo;

        for (int i=0; i<quantidade_palavras; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            //cout <<"Na linha "<< i <<" : "<< palavra_lida << endl;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close(); //boa pratica é fechar o arquivo depois de usar
        return palavras_do_arquivo;
    }
    else{
        cout<<"não foi possível acessar o banco de palavras!"<<endl;
        exit(0);
    }
}

void sorteia_palavra(){
    vector<string>palavras = le_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    PALAVRA_SECRETA = palavras [indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if(arquivo.is_open()) {
        arquivo << nova_lista.size() << endl;
        for (string palavra: nova_lista) {
            arquivo << palavra << endl;
        }
        arquivo.close();
    }  else{
            cout<<"não foi possível acessar o banco de palavras!"<<endl;
            exit(0);
        }
}

void adiciona_palavra(){
    cout<<"Digite a nova palavra, usando letras maiúsculas"<<endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string>lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}

int main()
{
    imprime_cabeçalho();
    le_arquivo();
    sorteia_palavra();

    while (nao_acertou () && nao_enforcou ()){
        imprime_erros();
        imprime_palavra();
        chuta();
    }

    cout<<"FIM DE JOGO!"<<endl;
    cout<<"A palavra secreta era: "<<PALAVRA_SECRETA <<endl;
    if (nao_acertou()){
        cout<<"você perdeu!Tente novamente"<<endl;
    }
    else{
        cout<<"Parabéns você acertou a palavra secreta!"<<endl;
        cout<<"Você deseja adionar uma nova palavra ao jogo? (S/N)"<<endl;
        char resposta;
        cin >>resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }

    }
}