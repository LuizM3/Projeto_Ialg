#include <iostream>
#include <string>
using namespace std;

struct jogador {
    int id;
    int idade;
    char perna;
    string nome;
    string time;
};

// Declarações das funções
void cadastro(jogador jogadores[]);
void procurarNome(jogador jogadores[]);
void listarTudo(jogador jogadores[]);
void listarXY(jogador jogadores[]);
void procurar(jogador jogadores[]);
void excluir(jogador jogadores[]);
void menu(jogador jogadores[]);
bool buscaBinaria(jogador jogadores[], string nomeProcurado, int idadeProcurada);
void ordenar(jogador jogadores[], bool tipo);

void cadastro(jogador jogadores[]) {
    int idadeTemp;
    string nomeTemp, timeTemp;
    char pernaTemp;

    cout << "-- Cadastro --" << "\n";

    cin.ignore();
    cout << "Nome do jogador:" << "\n";
    getline(cin, nomeTemp);
    while (nomeTemp.empty()) {
        cout << "Nome do jogador:" << "\n";
        getline(cin, nomeTemp);
    }

    cout << "Idade do jogador:" << "\n";
    cin >> idadeTemp;
    while (idadeTemp <= 0) {
        cout << "Idade do jogador:" << "\n";
        cin >> idadeTemp;

        if(cin.fail()) {
        cin.clear(); // Limpa o estado de erro do cin
        cin.ignore(); // Ignora a entrada inválida
        }
    }

    cin.ignore();
    cout << "Time atual do jogador:" << "\n";
    getline(cin, timeTemp);
    while (timeTemp.empty()) {
        cout << "Time do jogador:" << "\n";
        getline(cin, timeTemp);
    }

    cout << "Perna boa do jogador: E | D" << "\n";
    cin >> pernaTemp;
    while (pernaTemp != 'D' && pernaTemp != 'E' && pernaTemp != 'e' && pernaTemp != 'd') {
        cout << "Digite 'D' ou 'E': ";
        cin >> pernaTemp;
    }

    for (int i = 0; i < 40; i++) {
        if (jogadores[i].id == -1) {
            jogadores[i].id = i + 1;
            jogadores[i].nome = nomeTemp;
            jogadores[i].time = timeTemp;
            jogadores[i].idade = idadeTemp;
            jogadores[i].perna = pernaTemp;
            i = 40;
        }
    }

    cout << "Cadastro realizado com sucesso!" << "\n";
}

bool buscaBinaria(jogador jogadores[], string nomeProcurado, int idadeProcurada) {
    int posIncial = 0, posFinal = 39, meio;
    if (idadeProcurada < 0) {
        while (posIncial <= posFinal) {
            meio = (posIncial + posFinal) / 2;
            if (nomeProcurado == jogadores[meio].nome) {
                cout << "Jogador encontrado!" << "\n"
                     << "Id: " << jogadores[meio].id << "\n"
                     << "Nome: " << jogadores[meio].nome << "\n"
                     << "Idade: " << jogadores[meio].idade << "\n"
                     << "Time atual: " << jogadores[meio].time << "\n"
                     << "Perna boa: " << jogadores[meio].perna << "\n";
                return true;
            } else {
                if (nomeProcurado > jogadores[meio].nome) {
                    posIncial = meio + 1;
                } else {
                    posFinal = meio - 1;
                }
            }
        }
    } else {
        while (posIncial <= posFinal) {
            meio = (posIncial + posFinal) / 2;
            if (idadeProcurada == jogadores[meio].idade) {
                cout << "Jogador encontrado!" << "\n"
                     << "Id: " << jogadores[meio].id << "\n"
                     << "Nome: " << jogadores[meio].nome << "\n"
                     << "Idade: " << jogadores[meio].idade << "\n"
                     << "Time atual: " << jogadores[meio].time << "\n"
                     << "Perna boa: " << jogadores[meio].perna << "\n";
                return true;
            } else {
                if (idadeProcurada > jogadores[meio].idade) {
                    posIncial = meio + 1;
                } else {
                    posFinal = meio - 1;
                }
            }
        }
    }
    return false;
}

void ordenar(jogador jogadores[], bool tipo) {
    jogador aux;
    if (tipo) {  // Ordenar por nome
        for (int i = 0; i < 39; i++) {
            for (int j = i + 1; j < 40; j++) {
                if (jogadores[i].nome > jogadores[j].nome) {
                    aux = jogadores[i];
                    jogadores[i] = jogadores[j];
                    jogadores[j] = aux;
                }
            }
        }
    } else {  // Ordenar por idade
        for (int i = 0; i < 39; i++) {
            for (int j = i + 1; j < 40; j++) {
                if (jogadores[i].idade > jogadores[j].idade) {
                    aux = jogadores[i];
                    jogadores[i] = jogadores[j];
                    jogadores[j] = aux;
                }
            }
        }
    }
}

void procurarNome(jogador jogadores[]) {
    string nomeProcurado;
    bool encontrado = false;

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, nomeProcurado);

    bool tipo = true;
    jogador jogadoresOrdenados[40];
    for (int i = 0; i < 40; i++) {
        jogadoresOrdenados[i] = jogadores[i];
    }
    ordenar(jogadoresOrdenados, tipo);

    encontrado = buscaBinaria(jogadoresOrdenados, nomeProcurado, -1);

    if (!encontrado) {
        cout << "Nome não encontrado." << "\n";
    }
}

void procurarIdade(jogador jogadores[]) {
    int idadeProcurada;
    bool encontrado = false;

    cout << "Digite a idade: " << "\n";
    cin >> idadeProcurada;

    bool tipo = false;
    jogador jogadoresOrdenados[40];
    for (int i = 0; i < 40; i++) {
        jogadoresOrdenados[i] = jogadores[i];
    }
    ordenar(jogadoresOrdenados, tipo);

    encontrado = buscaBinaria(jogadoresOrdenados, "", idadeProcurada);

    if (!encontrado) {
        cout << "Idade não encontrada." << "\n";
    }
}

void listarTudo(jogador jogadores[]) {
    cout << "Todos os jogadores cadastrados: " << "\n";
    for (int i = 0; i < 40; i++) {
        if (jogadores[i].id != -1) {
            cout << "\n"
                 << "Jogador " << i + 1 << "\n"
                 << "Id: " << jogadores[i].id << "\n"
                 << "Nome: " << jogadores[i].nome << "\n"
                 << "Idade: " << jogadores[i].idade << "\n"
                 << "Time: " << jogadores[i].time << "\n"
                 << "Perna boa: " << jogadores[i].perna << "\n";
        }
    }
}

void listarXY(jogador jogadores[]) {
    int x, y;
    cout << "A partir de qual jogador (Id) deseja listar: " << "\n";
    cin >> x;
    cout << "\n"
         << "Até qual jogador (Id) deseja listar: " << "\n";
    cin >> y;

    for (int i = x - 1; i < y; i++) {
        if (jogadores[i].id != -1) {
            cout << "\n"
                 << "Jogador " << i + 1 << "\n"
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
         << "Nome - 1" << "\n"
         << "Idade - 2" << "\n"
         << "Listar tudo - 3" << "\n"
         << "Listar intervalo" - 4 << "\n";
    cin >> num;

    switch (num) {
        case 1:
            procurarNome(jogadores);
            break;
        case 2:
            procurarIdade(jogadores);
            break;
        case 3: 
            listarTudo(jogadores);
            break;
        case 4: 
            listarXY(jogadores);
            break;
        default:
            cout << "Opção inválida!" << "\n";
    }
}

void excluir(jogador jogadores[]) {
    int posIdExcluir;

    cout << "Digite o Id do jogador que deseja excluir: " << "\n";
    cin >> posIdExcluir;

    posIdExcluir = posIdExcluir - 1;
    
    if(jogadores[posIdExcluir].id == -1){
        cout << "Id não cadastrado." << "\n";
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
    
    cout << "Jodador excluido com sucesso!" << "\n";
    }
}

void menu(jogador jogadores[]) {
    int opcao;
    do {
        cout << "Escolha uma opção:" << "\n"
             << "1 - Cadastro" << "\n"
             << "2 - Procurar" << "\n"
             << "3 - Excluir" << "\n"
             << "4 - Encerrar" << "\n";
        cin >> opcao;

        switch (opcao) {
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
                cout << "Encerrando..." << "\n";
                break;
            default:
                cout << "Opção inválida, escolha outra." << "\n";
        }
    } while (opcao != 4);
}

int main() {
    jogador jogadores[40];
    for (int i = 0; i < 40; i++) {
        jogadores[i].id = -1;
    }
    menu(jogadores);
    return 0;
}
