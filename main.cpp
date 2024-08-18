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
void cadastro(jogador jogadores[], int tamVetor);
void procurarNome(jogador jogadores[], int tamVetor);
void listarTudo(jogador jogadores[], int tamVetor);
void listarXY(jogador jogadores[], int tamVetor);
void procurar(jogador jogadores[], int tamVetor);
void excluir(jogador jogadores[], int tamVetor);
void menu(jogador jogadores[], int tamVetor);
bool buscaBinaria(jogador jogadores[], int tamVetor, string nomeProcurado, int idadeProcurada);
void ordenar(jogador jogadores[], int tamVetor, bool tipo);
void aumentarVetor(jogador*& jogadores, int& tamVetor);

void cadastro(jogador jogadores[], int tamVetor) {
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

    for (int i = 0; i < tamVetor; i++) {
        if (jogadores[i].id == -1) { // Verifica qual a menor posição vazia
            jogadores[i].id = i + 1;
            jogadores[i].nome = nomeTemp;
            jogadores[i].time = timeTemp;
            jogadores[i].idade = idadeTemp;
            jogadores[i].perna = pernaTemp;
            i = tamVetor;
        } 
    }

    cout << "Cadastro realizado com sucesso!" << "\n";
}

void aumentarVetor(jogador*& jogadores, int& tamVetor) {
    bool aumenta = true;
    for (int i = 0; i < tamVetor; i++) {
        if (jogadores[i].id == -1) {
            aumenta = false;
            i = tamVetor; // Sair do loop
        }
    }

    if (aumenta) {
        int novoTam = tamVetor + 10;
        jogador *tempJogadores = new jogador[novoTam];

        for (int i = 0; i < tamVetor; i++) {
            tempJogadores[i] = jogadores[i];
        }
        for (int i = tamVetor; i < novoTam; i++) {
            tempJogadores[i].id = -1; // Inicializa novos jogadores como vazios
        }

        delete[] jogadores;
        jogadores = tempJogadores;
        tamVetor = novoTam;

        cout << "Capacidade aumentada com sucesso!" << "\n";
    }

    cadastro(jogadores, tamVetor);
}

bool buscaBinaria(jogador jogadores[], int tamVetor, string nomeProcurado, int idadeProcurada) {
    int posIncial = 0, posFinal = tamVetor - 1, meio;
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

void ordenar(jogador jogadores[], int tamVetor, bool tipo) {
    jogador aux;
    if (tipo) {  // Ordenar por nome
        for (int i = 0; i < tamVetor - 1; i++) {
            for (int j = i + 1; j < tamVetor; j++) {
                if (jogadores[i].nome > jogadores[j].nome) {
                    aux = jogadores[i];
                    jogadores[i] = jogadores[j];
                    jogadores[j] = aux;
                }
            }
        }
    } else {  // Ordenar por idade
        for (int i = 0; i < tamVetor - 1; i++) {
            for (int j = i + 1; j < tamVetor; j++) {
                if (jogadores[i].idade > jogadores[j].idade) {
                    aux = jogadores[i];
                    jogadores[i] = jogadores[j];
                    jogadores[j] = aux;
                }
            }
        }
    }
}

void procurarNome(jogador jogadores[], int tamVetor) {
    string nomeProcurado;
    bool encontrado = false;

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, nomeProcurado);

    bool tipo = true;
    jogador jogadoresOrdenados[tamVetor];
    for (int i = 0; i < tamVetor; i++) {
        jogadoresOrdenados[i] = jogadores[i];
    }
    ordenar(jogadoresOrdenados, tamVetor, tipo);

    encontrado = buscaBinaria(jogadoresOrdenados,tamVetor, nomeProcurado, -1);

    if (!encontrado) {
        cout << "Nome não encontrado." << "\n";
    }
}

void procurarIdade(jogador jogadores[], int tamVetor) {
    int idadeProcurada;
    bool encontrado = false;

    cout << "Digite a idade: " << "\n";
    cin >> idadeProcurada;

    bool tipo = false;
    jogador jogadoresOrdenados[tamVetor];
    for (int i = 0; i < tamVetor; i++) {
        jogadoresOrdenados[i] = jogadores[i];
    }
    ordenar(jogadoresOrdenados, tamVetor, tipo);

    encontrado = buscaBinaria(jogadoresOrdenados, tamVetor, "", idadeProcurada);

    if (!encontrado) {
        cout << "Idade não encontrada." << "\n";
    }
}

void listarTudo(jogador jogadores[], int tamVetor) {
    cout << "Todos os jogadores cadastrados: " << "\n";
    for (int i = 0; i < tamVetor; i++) {
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

void procurar(jogador jogadores[], int tamVetor) {
    int num;
    cout << "--- Procurar ---" << "\n"
         << "Nome - 1" << "\n"
         << "Idade - 2" << "\n"
         << "Listar tudo - 3" << "\n"
         << "Listar intervalo - 4" << "\n";
    cin >> num;

    switch (num) {
        case 1:
            procurarNome(jogadores, tamVetor);
            break;
        case 2:
            procurarIdade(jogadores, tamVetor);
            break;
        case 3: 
            listarTudo(jogadores, tamVetor);
            break;
        case 4: 
            listarXY(jogadores);
            break;
        default:
            cout << "Opção inválida!" << "\n";
    }
}

void excluir(jogador jogadores[], int tamVetor) {
    int posIdExcluir;

    cout << "Digite o Id do jogador que deseja excluir: " << "\n";
    cin >> posIdExcluir;

    posIdExcluir = posIdExcluir - 1;
    
    if(jogadores[posIdExcluir].id == -1){
        cout << "Id não cadastrado." << "\n";
    }
    else {
    jogadores[posIdExcluir].id = -1;

    for (int i = posIdExcluir + 1; i < tamVetor; i++){
        if(jogadores[i].id == -1 or i == tamVetor - 1){
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
        i = tamVetor; 
        }
    }    
    
    cout << "Jogador excluído com sucesso!" << "\n";
    }
}

void menu(jogador jogadores[], int tamVetor) {
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
                aumentarVetor(jogadores, tamVetor);
                break;
            case 2:
                procurar(jogadores, tamVetor);
                break;
            case 3:
                excluir(jogadores, tamVetor);
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
    int tamVetor = 2;
    jogador* jogadores = new jogador[tamVetor];
    for (int i = 0; i < tamVetor; i++) {
        jogadores[i].id = -1;
        jogadores[i].idade = -1;
        jogadores[i].nome = "";
        jogadores[i].perna = '\0';
        jogadores[i].time = "";
    }
    menu(jogadores, tamVetor);
    delete[] jogadores; // Libera a memória alocada para jogadores
    return 0;
}
