#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;
    bool letra_existe(char chute){
        for(char letra : palavra_secreta){
            if(chute == letra){
                return true;
            }
        }
        return false;
    } 
    bool nao_acertou(){ // QUAIS LETRAS JA FORAM CHUTADAS
        for(char letra : palavra_secreta){
            if(!chutou[letra]){
                return true;
            }
        }
        return false;
    }

    bool nao_enforcou(){
        return chutes_errados.size() < 5;
    }
    void imprime_cabecalho(){
    cout<<"*************************"<<endl;
    cout<<"***VOCE SERA ENFORCADO***"<<endl;
    cout<<"*************************"<<endl;
    cout<<endl;
    }

    void imprime_erros(){
        cout<<"chutes errados: ";
        for(char letra : chutes_errados){
            cout<< letra<<" ";
        }
        cout<<endl;
    }

    void imprime_palavra(){
     for(char letra : palavra_secreta){
        if(chutou [letra]){
            cout<< letra << " ";
           }
        else{
            cout<<"_ ";
            }
        }
        cout << endl;
    }
        void chuta(){
            cout<<"seu chute: ";
        char chute;
        cin >> chute;

        chutou[chute] = true;

        if (letra_existe(chute)){
            cout << "você acertou! seu chute esta na palavra." << endl;
        }
        else{
            cout << "voce errou" << endl;
            chutes_errados.push_back(chute);
        }
        cout << endl;
        }

    vector<string> le_arquivo(){
        ifstream arquivo;
        arquivo.open("palavras.txt");

        if(arquivo.is_open()){
            int quantidade_palavras;
            arquivo >> quantidade_palavras;

        

            vector<string> palavras_do_arquivo;

            for(int i=0; i<quantidade_palavras; i++){
                string palavra_lida;
                arquivo >> palavra_lida;
           
                palavras_do_arquivo.push_back(palavra_lida);     
            }
        

            arquivo.close();
            return palavras_do_arquivo;
        }
        else{
            cout<<"Nao foi possivel acessar o banco de palavras"<<endl;
            exit(0);        
        }
    } 

    void salva_arquivo(vector<string> nova_lista){
        ofstream arquivo;
        arquivo.open("palavras.txt");
        if(arquivo.is_open()){
            arquivo << nova_lista.size()<<endl;

            for(string palavra : nova_lista){
                arquivo << palavra << endl;
            }

            arquivo.close();
        }
        else{
           cout<<"Nao foi possivel acessar o banco de palavras"<<endl;
            exit(0); 
        }
    }

    void sorteia_palavra(){
        vector<string> palavras = le_arquivo();

        srand(time(NULL));
        int indice_sorteado = rand() % palavras.size();
        palavra_secreta = palavras[indice_sorteado];
    }

    void adiciona_palavra(){
        cout<<"Diga-me seus segredos, use letras maiusculas"<<endl;
        string nova_palavra;
        cin>> nova_palavra;

        vector<string> lista_palavras = le_arquivo();
        lista_palavras.push_back(nova_palavra);

        salva_arquivo(lista_palavras);
    }

int main(){
    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();
    while(nao_acertou() && nao_enforcou())
    {
        imprime_erros();
       
       imprime_palavra();
        
        chuta();
    }
    
    cout<<"FIM DE JOGO"<<endl;
    cout<<"A PALAVRA SECRETA ERA "<<palavra_secreta<<endl;
    if(nao_acertou()){
        cout<<"FOI ENFORCADO"<<endl;
    }
    else{
        cout<<"VOCE ESCAPOU DA FORCA"<<endl;
    
        cout<<"Sua mente e brilhante conte-me seus segredos"<<endl;
        cout<<"Tudo Bem (S)  Me deixe em paz (N)"<<endl;
        char resposta;
        cin>> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
}