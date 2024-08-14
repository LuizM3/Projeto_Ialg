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
void listarTudo(jogador jogadores[]);
void listarXY(jogador jogadores[]);
void procurar(jogador jogadores[]);
void excluir(jogador jogadores[]);
void menu(jogador jogadores[]);

void cadastro(jogador jogadores[]) {
    int idadeTemp;
    string nomeTemp, timeTemp;
    char pernaTemp;

    cout << "-- Cadastro --" << "\n";

    cin.ignore(); 
    cout << "Nome do jogador:" << "\n";
    getline(cin, nomeTemp);
    while(nomeTemp.empty()){
        cout << "Nome do jogador:" << "\n";
        getline(cin, nomeTemp);  
    }

    cout << "Idade do jogador:" << "\n";
    cin >> idadeTemp;
    while(idadeTemp <= 0){
        cout << "Idade do jogador:" << "\n";
       cin >> idadeTemp;  
    }

    cin.ignore(); 
    cout << "Time atual do jogador:" << "\n";
    getline(cin, timeTemp);
    while(timeTemp.empty()){
        cout << "Time do jogador:" << "\n";
        getline(cin, timeTemp);  
    }

    cout << "Perna boa do jogador: E | D" << "\n";
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

    cout << "Cadastro realizado com sucesso!" << "\n";
}

void procurarID(jogador jogadores[]) {
    int idProcurado;

    cout << "Digite o Id: ";
    cin >> idProcurado;

    if (idProcurado > 0 && idProcurado <= 40 && jogadores[idProcurado - 1].id != -1) {
        cout << "Jogador de Id: " << idProcurado << "\n"
             << "Nome: " << jogadores[idProcurado - 1].nome << "\n"
             << "Idade: " << jogadores[idProcurado - 1].idade << "\n"
             << "Time atual: " << jogadores[idProcurado - 1].time << "\n"
             << "Perna boa: " << jogadores[idProcurado - 1].perna << "\n";
    } else {
        cout << "Id não encontrado!" << "\n";
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
            cout << "Jogador encontrado!" << "\n"
                 << "Id: " << jogadores[i].id << "\n"
                 << "Nome: " << jogadores[i].nome << "\n"
                 << "Idade: " << jogadores[i].idade << "\n"
                 << "Time atual: " << jogadores[i].time << "\n"
                 << "Perna boa: " << jogadores[i].perna << "\n";
            encontrado = true;
            i = 40;
        }
    }

    if (!encontrado) {
        cout << "Nome não encontrado." << "\n";
    }
}

void procurarIdade(jogador jogadores[]) {
    int idadeProcurada;

    cout << "Digite a idade: " << "\n";
    cin >> idadeProcurada;
}

void listarTudo(jogador jogadores[]) {

    cout << "Todos os jogadores cadastrados: " << "\n";
    for (int i = 0; i < 40; i++){ 
        if (jogadores[i].id != -1){
            cout << "\n" << "Jogador " << i + 1 << "\n"
            << "Id: " << jogadores[i].id << "\n"
            << "Nome: " << jogadores[i].nome << "\n"
            << "Idade: " << jogadores[i].idade << "\n"
            << "Time: " << jogadores[i].time << "\n"
            << "Perna boa: " << jogadores[i].perna << "\n";
        }        
    }
}

void listarXY(jogador jogadores[]){
    int x, y;
    cout << "A partir de qual jogador (Id) deseja listar: " << "\n";
    cin >> x;
    cout << "\n" << "Até qual jogador (Id) deseja listar: " << "\n";
    cin >> y;

    for (int i = x - 1; i < y - 1; i++){
        if(jogadores[i].id != -1){
            cout << "\n" << "Jogador " << i + 1 << "\n"
            << "Id: " << jogadores[i].id << "\n"
            << "Nome: " << jogadores[i].nome << "\n"
            << "Idade: " << jogadores[i].idade << "\n"
            << "Time: " << jogadores[i].time << "\n"
            << "Perna boa: " << jogadores[i].perna << "\n";
        }
    }
}

void procurar(jogador jogadores[]) {
    int num;
    cout << "--- Procurar ---" << "\n"
         << "Id - 1" << "\n"
         << "Nome - 2" << "\n"
         << "Idade - 3" << "\n"
         << "Listar tudo - 4" << "\n"
         << "Listar de X a Y - 5" << "\n";
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

    cout << "Digite o Id do jogador que deseja excluir: " << "\n";
    cin >> posIdExcluir;

    posIdExcluir = posIdExcluir - 1; // O jogador de id 1 está na posição 0, por isso essa linha
    
    if(jogadores[posIdExcluir].id == -1){
        cout << "Id não cadastrado." << "\n";
    }
    else {
    jogadores[posIdExcluir].id = -1;

    for (int i = posIdExcluir + 1; i < 40; i++){
        if(jogadores[i].id == -1){ // Encontrar a primeira posição vazia do vetor
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
        } else if (i == 39){ // Se a última posição for escolhida para exclusão, apenas a marca como vazia
            jogadores[i].id = -1;
            i = 40;
        }
    }    
    for (int a = 0; a < 40; a++){
        if(jogadores[a].id < -1){
            jogadores[a].id == -1;
        }
    }
    
    cout << "Jodador excluido com sucesso!" << "\n";
    }
}

void menu(jogador jogadores[]) {
    bool run = true;
    while (run) {
        int num;
        cout << "\n" << "--- Menu ---" << "\n"
             << "Cadastrar - 1" << "\n"
             << "Procurar - 2" << "\n"
             << "Excluir - 3" << "\n"
             << "Salvar no arquivo - 4" << "\n"
             << "Sair - 5" << "\n";

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
                cadastro(jogadores);
                break;
            case 5:
                run = false;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << "\n";
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
