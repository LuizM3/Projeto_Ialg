#include <iostream>
#include <string>

using namespace std;

struct jogador
{
    int id;
    int idade;
    char perna;  
    string nome;
    string time;
};


// Declarações das funções
void cadastro(jogador jogadores[]);
void procurarID(jogador jogadores[]);
void procurarNome(jogador jogadores[]);
void procurar(jogador jogadores[]);
void excluir(jogador jogadores[]);
void menu(jogador jogadores[]);

void cadastro(jogador jogadores[]) {
    int idadeTemp;
    string nomeTemp, timeTemp;
    char pernaTemp;

    cout << "-- Cadastro --" << endl;

    cin.ignore(); 
    cout << "Nome do jogador:" << endl;
    getline(cin, nomeTemp);

    cout << "Idade do jogador:" << endl;
    cin >> idadeTemp;

    cin.ignore(); 
    cout << "Time atual do jogador:" << endl;
    getline(cin, timeTemp);

    cout << "Perna boa do jogador: E | D" << endl;
    cin >> pernaTemp;

    while (pernaTemp != 'D' && pernaTemp != 'E' && pernaTemp != 'e' && pernaTemp != 'd'){
        cout << "Digite 'D' ou 'E': ";
        cin >> pernaTemp;
    }

    for (int i = 0; i < 40; i++){ 
        if(jogadores[i].id == -1){
            jogadores[i].id = i + 1;
            jogadores[i].nome = nomeTemp;
            jogadores[i].time = timeTemp;
            jogadores[i].idade = idadeTemp;
            jogadores[i].perna = pernaTemp;
            i = 40;
        }
        // Adicionar lógica para expandir o vetor
    }

    cout << "Cadastro realizado com sucesso!" << endl;
}

void procurarID(jogador jogadores[]) {
    int idProcurado;

    cout << "Digite o Id: ";
    cin >> idProcurado;

    if (idProcurado > 0 && idProcurado <= 40 && jogadores[idProcurado - 1].id != -1) {
        cout << "Jogador de Id: " << idProcurado << endl
             << "Nome: " << jogadores[idProcurado - 1].nome << endl
             << "Idade: " << jogadores[idProcurado - 1].idade << endl
             << "Time atual: " << jogadores[idProcurado - 1].time << endl
             << "Perna boa: " << jogadores[idProcurado - 1].perna << endl;
    } else {
        cout << "Id não encontrado!" << endl;
    }
}

void procurarNome(jogador jogadores[]) {
    string nomeProcurado;
    bool encontrado = false;

    cout << "Digite o nome: ";
    cin.ignore(); 
    getline(cin, nomeProcurado);

    for (int i = 0; i < 40; i++) {
        if (jogadores[i].nome == nomeProcurado) {
            cout << "Jogador encontrado!" << endl
                 << "Id: " << jogadores[i].id << endl
                 << "Nome: " << jogadores[i].nome << endl
                 << "Idade: " << jogadores[i].idade << endl
                 << "Time atual: " << jogadores[i].time << endl
                 << "Perna boa: " << jogadores[i].perna << endl;
            encontrado = true;
            i = 40;
        }
    }

    if (!encontrado) {
        cout << "Nome não encontrado." << endl;
    }
}

void procurarIdade(jogador jogadores[]) {
    int idadeProcurada;

    cout << "Digite a idade: " << endl;
    cin >> idadeProcurada;
}

void listarTudo(jogador jogadores[]) {

    cout << "Todos os jogadores cadastrados: " << endl;
    for (int i = 0; i < 40; i++){ 
        if (jogadores[i].id != -1)
        {
            cout << endl << "Jogador " << i + 1 << endl
            << "Id: " << jogadores[i].id << endl
            << "Nome: " << jogadores[i].nome << endl
            << "Idade: " << jogadores[i].idade << endl
            << "Time: " << jogadores[i].time << endl
            << "Perna boa: " << jogadores[i].perna << endl;
        }        
    }
}

void listarXY(jogador jogadores[]){

}

void procurar(jogador jogadores[]) {
    int num;
    cout << "--- Procurar ---" << endl
         << "Id - 1" << endl
         << "Nome - 2" << endl
         << "Idade - 3" << endl
         << "Listar tudo - 4" << endl
         << "Listar de X a Y - 5" << endl;
    cin >> num;

    switch (num) {
        case 1:
            procurarID(jogadores);
            break;
        case 2:
            procurarNome(jogadores);
            break;
        case 3:
            procurarIdade(jogadores);
            break;
        case 4:
            listarTudo(jogadores);
            break;
        case 5:
            listarXY(jogadores);
            break;
        default:
            procurar(jogadores);
            break;
    }
}

void excluir(jogador jogadores[]) {
    int posIdExcluir;

    cout << "Digite o Id do jogador que deseja excluir: " << endl;
    cin >> posIdExcluir;

    posIdExcluir = posIdExcluir - 1;
    

    if(jogadores[posIdExcluir].id == -1){
        cout << "Id não cadastrado." << endl;
    }
    else {

    jogadores[posIdExcluir].id = -1;

    for (int i = posIdExcluir + 1; i < 40; i++){
        if(jogadores[i].id == -1 or i == 39){
            int auxN;
            string auxT;
            char auxC;

            for (int j = posIdExcluir; j <= i; j++){
                auxN = jogadores[j].id;
                jogadores[j].id = jogadores[j + 1].id - 1;
                jogadores[j + 1].id = auxN ;

                auxN = jogadores[j].idade;
                jogadores[j].idade = jogadores[j + 1].idade;
                jogadores[j + 1].idade = auxN;

                auxC = jogadores[j].perna;
                jogadores[j].perna = jogadores[j + 1].perna;
                jogadores[j + 1].perna = auxC;

                auxT = jogadores[j].nome;
                jogadores[j].nome = jogadores[j + 1].nome;
                jogadores[j + 1].nome = auxT;

                auxT = jogadores[j].time;
                jogadores[j].time = jogadores[j + 1].time;
                jogadores[j + 1].time = auxT;
            }
        i = 40; 
        }
    }    
    
    cout << "Jodador excluido com sucesso!" << endl;
    }
}

void menu(jogador jogadores[]) {
    bool run = true;
    while (run) {
        int num;
        cout << "--- Menu ---" << endl
             << "Cadastrar - 1" << endl
             << "Procurar - 2" << endl
             << "Excluir - 3" << endl
             << "Salvar no arquivo - 4" << endl
             << "Sair - 5";

        cin >> num;

        switch (num) {
            case 1:
                cadastro(jogadores);
                break;
            case 2:
                procurar(jogadores);
                break;
            case 3:
                excluir(jogadores);
                break;
            case 4:
                
                break;
            case 5:
                run = false;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }
}

int main() {

    jogador jogadores[40];

    for (int i = 0; i < 40; i++) {
        jogadores[i].id = -1; // -1 para indicar ID vazio
        jogadores[i].nome = "";
        jogadores[i].time = "";
        jogadores[i].idade = 0;
        jogadores[i].perna = '\0';
    }

    menu(jogadores);

    return 0;
}
