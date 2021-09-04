#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main (){
    cout<<"************************************"<<endl;
    cout<<"**bem vindos ao jogo da advinhacao**"<<endl;
    cout<<"************************************"<<endl;
    
    cout<<"escolha o seu nivel de dificuldade"<<endl;
    cout<<"Fácil (F), Médio (M) ou Difícil(D)"<<endl;

    char dificuldade;
    cin>> dificuldade;

    int numero_de_tentativas;

    if (dificuldade == 'F')
    {
       numero_de_tentativas = 15; 
    }
    else if (dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else
    {
        numero_de_tentativas = 5;
    }
    
    
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    
    bool nao_acertou = true;
    int tentativas = 0;
    
    double pontos = 1000.0;


    for(tentativas = 1;tentativas <= numero_de_tentativas; tentativas++){
        int chute;
        cout<<"Tentativa "<<tentativas<<endl;
        cout<<"qual seu chute"<<endl;
        cin>>chute;
    
        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        cout<<"O valor do seu chute e "<<chute<<endl;

        bool acertou = chute==NUMERO_SECRETO;
        bool maior = chute>NUMERO_SECRETO;

        if(acertou){
            cout<<"parabens voce acertou o numero secreto"<<endl;
            nao_acertou = false;
            break;
        }
         else if (maior)
        {
            cout<<"Seu chute foi maior que o numero secreto"<<endl;
        }
        else
        {
            cout<<"seu chute foi menor que o numero secreto"<<endl;
        }
    }
    cout<<"FIM DE JOGO"<<endl;
    if (nao_acertou)
    {
        cout<<"Voce perdeu! o numero secreto era "<<NUMERO_SECRETO<<" tente novamente"<<endl;
    }
    else
    {
        cout<<"Voce acertou o numero secreto em "<<tentativas<<" tentativas"<<endl;
        cout.precision(2);// determina quantas casas decimais eu adiciono na pontuação
        cout << fixed;//deixa o numero fixo 
        cout<<"Sua pontucao foi de "<< pontos <<" pontos. "<<endl;
    }


}   
