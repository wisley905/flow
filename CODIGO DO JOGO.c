#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// funções dos jogos
void jogoPerguntasRespostas();
void jogoCobraNaCaixa();
void jogoGousmasWar();

// Função do menu principal
int exibirMenuPrincipal() {
    int escolha;
    system("cls || clear");
    printf("=================================\n");
    printf("       MENU DE JOGOS\n");
    printf("=================================\n");
    printf("1. Jogo de Perguntas e Respostas\n");
    printf("2. Cobra na Caixa\n");
    printf("3. Gousmas War\n");
    printf("4. Sair\n");
    printf("=================================\n");
    printf("Escolha um jogo (1-4): ");
    scanf("%d", &escolha);
    return escolha;
}

// Função principal
int main() {
    srand(time(NULL)); // ele meio que gera os numeros aleatorios
    
    int opcao;
    do {
        opcao = exibirMenuPrincipal();
        
        switch(opcao) {
            case 1:
                jogoPerguntasRespostas();
                break;
            case 2:
                jogoCobraNaCaixa();
                break;
            case 3:
                jogoGousmasWar();
                break;
            case 4:
                printf("Obrigado por jogar! Ate a proxima!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        
        if (opcao != 4) {
            printf("\nPressione Enter para continuar...");
            while(getchar() != '\n'); // Limpa buffer
            getchar(); // Espera Enter
        }
    } while (opcao != 4);
    
    return 0;
}

// Jogo de Perguntas e Respostas
void jogoPerguntasRespostas() {
    system("cls || clear");
    printf("\n=== Jogo de Perguntas e Respostas ===\n\n");
    
    // Função que exibi o menu e obtem a escolha do jogador
    int menu() {
        int escolha;
        printf("\n--- Jogo de Perguntas e Respostas ---\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        return escolha;
    }

    // Função de pergunta e armazenamento de resposta 
    int fazerPergunta(const char *pergunta, const char *opcoes[], int respostaCorreta) {
        int resposta;
        printf("\n%s\n", pergunta);
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, opcoes[i]);
        }
        printf("Escolha a resposta correta (1-4): ");
        scanf("%d", &resposta);
        return resposta;
    }

    // Função principal do jogo
    void jogar() {
        // Perguntas
        const char *perguntas[5] = {
            "Primeira Pergunta\n Qual o nome do primeiro robin?",
            "Segunda Pergunta\njuntos nos temos R$ 250 reais vc tem R$ 200  a mais que eu,quantos reais eu tenho?",
            "Terceira Pergunta\nQual palavra mais se repete na Biblia?",
            "Quarta pergunta\nQual é o maior oceano do mundo?",
            "Quinta pergunta\nQual o maior orgão do corpo humano?"
        };
         //respostas
        const char *opcoes[5][4] = {
            {"jason todd", "richard grayson", "bruce wellis", "tim drake"},
            {"R$25", "R$15", "R$50", "R$100"},
            {"Deus", "Senhor", "Jesus", "Amém"},
            {"Atlântico", "Índico", "Ártico", "Pacífico"},
            {"intestino grosso ", "cabelo", "pele", "pulmão"}
        };

        int respostasCorretas[5] = {2, 1, 2, 4, 3}; // Respostas corretas (índices começam em 1)

        int pontuacao = 0;

        // Loop para cada pergunta
        for (int i = 0; i < 5; i++) {
            int resposta = fazerPergunta(perguntas[i], opcoes[i], respostasCorretas[i]);

            if (resposta == respostasCorretas[i]) {
                printf("Resposta correta!\n");
                pontuacao++;
            } else {
                printf("Resposta incorreta! A resposta correta era: %d. %s\n", respostasCorretas[i], opcoes[i][respostasCorretas[i] - 1]);
            }
        }

        printf("\nFim do jogo! Sua pontuação foi: %d/5\n", pontuacao);
    }

    int opcao;
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                jogar();
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 2);
}

// integração do Cobra na Caixa
void jogoCobraNaCaixa() {
    system("cls || clear");
    printf("\n=== Cobra na Caixa ===\n\n");
    
    #define NUM_CAIXAS 5
    #define NUM_NOMES 7

    // Constantes para oque tem na caixa
    #define VAZIA 0
    #define COBRA 1
    #define BOTAO 2

    // Nomes para os jogadores escolherem(gosto muito da franquia uncharted)
    const char *nomes[NUM_NOMES] = {
        "Indiana jones", "Lara croft", "Nathan", "sherlock", "Drake", "Sully", "Riley"
    };

    // Função para limpar o buffer de entrada
    void limparBuffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Função para exibir o menu principal
    int exibirMenu() {
        int opcao;
        system("cls || clear");
        printf("=================================\n");
        printf("        COBRA NA CAIXA!\n");
        printf("=================================\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Sair\n");
        printf("=================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        return opcao;
    }

    // Função para sortear quem começa
    int sortearJogador() {
        return rand() % 2; // 0 ou 1
    }

    // Função para inicializar as caixas
    void inicializarCaixas(int caixas[NUM_CAIXAS]) {
        // Inicializa todas como vazias
        for (int i = 0; i < NUM_CAIXAS; i++) {
            caixas[i] = VAZIA;
        }
        
        // Sorteia o botão
        int botaoPos = rand() % NUM_CAIXAS;
        caixas[botaoPos] = BOTAO;
        
        // Sorteia a cobra (diferente do botão)
        int cobraPos;
        do {
            cobraPos = rand() % NUM_CAIXAS;
        } while (cobraPos == botaoPos);
        
        caixas[cobraPos] = COBRA;
    }

    // Função principal do jogo
    void jogar() {
        int caixas[NUM_CAIXAS];
        char jogador1[20], jogador2[20];
        int vez, escolha, resultado;
        
        // Seleção dos nomes
        printf("\nJogador 1, escolha seu nome (1-%d):\n", NUM_NOMES);
        for (int i = 0; i < NUM_NOMES; i++) {
            printf("%d. %s\n", i+1, nomes[i]);
        }
        printf("Escolha: ");
        scanf("%d", &escolha);
        limparBuffer();
        strcpy(jogador1, nomes[escolha-1]);
        
        printf("\nJogador 2, escolha seu nome (1-%d):\n", NUM_NOMES);
        for (int i = 0; i < NUM_NOMES; i++) {
            printf("%d. %s\n", i+1, nomes[i]);
        }
        printf("Escolha: ");
        scanf("%d", &escolha);
        limparBuffer();
        strcpy(jogador2, nomes[escolha-1]);
        
        // Sorteia quem começa
        vez = sortearJogador();
        printf("\n%s comeca!\n", vez == 0 ? jogador1 : jogador2);
        
        // Loop principal do jogo
        do {
            // Inicializa as caixas para a nova rodada
            inicializarCaixas(caixas);
            
            printf("\nNova rodada! As posicoes foram alteradas.\n");
            
            // Loop da rodada
            while (1) {
                printf("\n%s, escolha uma caixa (1-%d): ", vez == 0 ? jogador1 : jogador2, NUM_CAIXAS);
                scanf("%d", &escolha);
                limparBuffer();
                
                if (escolha < 1 || escolha > NUM_CAIXAS) {
                    printf("Escolha invalida! Tente novamente.\n");
                    continue;
                }
                
                // Verifica oq tem na caixa
                switch(caixas[escolha-1]) {
                    case VAZIA:
                        printf("A caixa %d esta vazia. Proximo jogador!\n", escolha);
                        vez = !vez; // Alterna o jogador
                        break;
                    case COBRA:
                        printf("ARGHHH! A caixa %d tinha uma cobra! %s perdeu!\n", 
                               escolha, vez == 0 ? jogador1 : jogador2);
                        printf("%s venceu!\n", vez == 0 ? jogador2 : jogador1);
                        resultado = 1;
                        break;
                    case BOTAO:
                        printf("PARABENS! A caixa %d tinha o botao! %s venceu!\n", 
                               escolha, vez == 0 ? jogador1 : jogador2);
                        resultado = 1;
                        break;
                }
                
                if (caixas[escolha-1] != VAZIA) break;
            }
            
            // Pergunta se quer jogar novamente
            printf("\nDeseja jogar novamente? (S/N): ");
            char opcao;
            scanf("%c", &opcao);
            limparBuffer();
            
            if (toupper(opcao) != 'S') {
                break;
            }
            
        } while (1);
    }

    int opcao;
    do {
        opcao = exibirMenu();
        
        switch(opcao) {
            case 1:
                jogar();
                break;
            case 2:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        
        if (opcao != 2) {
            printf("\nPressione Enter para continuar...");
            limparBuffer();
        }
    } while (opcao != 2);
}

// integração do Gousmas War
void jogoGousmasWar() {
    system("cls || clear");
    printf("\n=== Gousmas War ===\n\n");
    
    typedef struct {
        int furia;
        bool ativa;
    } Gousma;

    typedef struct {
        Gousma gousmas[2];
    } Jogador;

    Jogador jogadores[2];
    int jogadorAtual = 0;

    void inicializarJogo() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                jogadores[i].gousmas[j].furia = 1;
                jogadores[i].gousmas[j].ativa = true;
            }
        }
    }

    void mostrarEstado() {
        printf("\n--- Estado do Jogo ---\n");
        for (int j = 0; j < 2; j++) {
            printf("Jogador %d:\n", j + 1);
            for (int g = 0; g < 2; g++) {
                if (jogadores[j].gousmas[g].ativa) {
                    printf("  Gousma %d: Fúria %d\n", g + 1, jogadores[j].gousmas[g].furia);
                } else {
                    printf("  Gousma %d: Desintegrada\n", g + 1);
                }
            }
        }
        printf("----------------------\n");
    }

    bool verificarFimDeJogo() {
        for (int j = 0; j < 2; j++) {
            bool perdeu = true;
            for (int g = 0; g < 2; g++) {
                if (jogadores[j].gousmas[g].ativa) {
                    perdeu = false;
                    break;
                }
            }
            if (perdeu) {
                printf("\nJogador %d perdeu todas as Gousmas!\n", j + 1);
                printf("Jogador %d venceu o jogo!\n", (j == 0) ? 2 : 1);
                return true;
            }
        }
        return false;
    }

    void atacar() {
        int gAtacante, jAlvo, gAlvo;
        
        printf("\nEscolha sua Gousma atacante (1 ou 2): ");
        while (scanf("%d", &gAtacante) != 1 || gAtacante < 1 || gAtacante > 2) {
            printf("Entrada inválida. Escolha 1 ou 2: ");
            while (getchar() != '\n'); // Limpa buffer
        }
        gAtacante--;
        
        if (!jogadores[jogadorAtual].gousmas[gAtacante].ativa) {
            printf("Esta Gousma está desintegrada!\n");
            return;
        }
        
        printf("Escolha o jogador alvo (1 ou 2): ");
        while (scanf("%d", &jAlvo) != 1 || jAlvo < 1 || jAlvo > 2) {
            printf("Entrada inválida. Escolha 1 ou 2: ");
            while (getchar() != '\n');
        }
        jAlvo--;
        
        if (jAlvo == jogadorAtual) {
            printf("Você não pode atacar a si mesmo!\n");
            return;
        }
        
        printf("Escolha a Gousma alvo (1 ou 2): ");
        while (scanf("%d", &gAlvo) != 1 || gAlvo < 1 || gAlvo > 2) {
            printf("Entrada inválida. Escolha 1 ou 2: ");
            while (getchar() != '\n');
        }
        gAlvo--;
        
        if (!jogadores[jAlvo].gousmas[gAlvo].ativa) {
            printf("Esta Gousma alvo está desintegrada!\n");
            return;
        }
        
        // Transferencia da  fúria
        jogadores[jAlvo].gousmas[gAlvo].furia += jogadores[jogadorAtual].gousmas[gAtacante].furia;
        jogadores[jogadorAtual].gousmas[gAtacante].ativa = false;
        
        printf("Gousma atacante transferiu toda sua fúria (%d) para a Gousma alvo e foi desintegrada!\n", 
               jogadores[jogadorAtual].gousmas[gAtacante].furia);
        
        // Verificar se a Gousma alvo deve se desintegrar
        if (jogadores[jAlvo].gousmas[gAlvo].furia > 5) {
            printf("Gousma alvo atingiu fúria %d e se desintegrou!\n", jogadores[jAlvo].gousmas[gAlvo].furia);
            jogadores[jAlvo].gousmas[gAlvo].ativa = false;
        }
    }

    void dividir() {
        int gOrigem, furiaTransferida;
        
        printf("\nEscolha a Gousma de origem (1 ou 2): ");
        while (scanf("%d", &gOrigem) != 1 || gOrigem < 1 || gOrigem > 2) {
            printf("Entrada inválida. Escolha 1 ou 2: ");
            while (getchar() != '\n');
        }
        gOrigem--;
        
        if (!jogadores[jogadorAtual].gousmas[gOrigem].ativa) {
            printf("Esta Gousma está desintegrada!\n");
            return;
        }
        
        if (jogadores[jogadorAtual].gousmas[gOrigem].furia < 2) {
            printf("Esta Gousma não tem fúria suficiente para dividir (mínimo 2)!\n");
            return;
        }
        
        // Encontrar Gousma inativa para receber a divisão
        int gDestino = -1;
        for (int g = 0; g < 2; g++) {
            if (!jogadores[jogadorAtual].gousmas[g].ativa) {
                gDestino = g;
                break;
            }
        }
        
        if (gDestino == -1) {
            printf("Você já tem o número máximo de Gousmas ativas (2)!\n");
            return;
        }
        
        printf("Digite a quantidade de fúria para transferir (1-%d): ", 
               jogadores[jogadorAtual].gousmas[gOrigem].furia - 1);
        while (scanf("%d", &furiaTransferida) != 1 || furiaTransferida < 1 || 
               furiaTransferida >= jogadores[jogadorAtual].gousmas[gOrigem].furia) {
            printf("Valor inválido. Digite um valor entre 1 e %d: ", 
                   jogadores[jogadorAtual].gousmas[gOrigem].furia - 1);
            while (getchar() != '\n');
        }
        
        // Realiza a divisão
        jogadores[jogadorAtual].gousmas[gOrigem].furia -= furiaTransferida;
        jogadores[jogadorAtual].gousmas[gDestino].furia = furiaTransferida;
        jogadores[jogadorAtual].gousmas[gDestino].ativa = true;
        
        printf("Fúria dividida com sucesso! Nova Gousma criada com fúria %d.\n", furiaTransferida);
    }

    void jogar() {
        bool jogoAtivo = true;
        
        while (jogoAtivo) {
            mostrarEstado();
            printf("\nVez do Jogador %d\n", jogadorAtual + 1);
            printf("1 - Atacar\n");
            printf("2 - Dividir Gousma\n");
            printf("Escolha uma ação (1-2): ");
            
            int opcao;
            while (scanf("%d", &opcao) != 1 || (opcao != 1 && opcao != 2)) {
                printf("Opção inválida. Escolha 1 ou 2: ");
                while (getchar() != '\n');
            }
            
            switch (opcao) {
                case 1:
                    atacar();
                    break;
                case 2:
                    dividir();
                    break;
            }
            
            if (verificarFimDeJogo()) {
                jogoAtivo = false;
            } else {
                jogadorAtual = (jogadorAtual + 1) % 2;
            }
        }
    }

    int opcao;
    
    printf("=== GOUSMAS WAR ===\n");
    printf("Um jogo de estratégia com criaturas furiosas!\n\n");
    
    do {
        inicializarJogo();
        jogadorAtual = 0; // Reseta o jogador inicial
        jogar();
        
        printf("\n1 - Jogar novamente\n");
        printf("2 - Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        
        while (scanf("%d", &opcao) != 1 || (opcao != 1 && opcao != 2)) {
            printf("Opção inválida. Escolha 1 ou 2: ");
            while (getchar() != '\n');
        }
        
    } while (opcao == 1);
}
