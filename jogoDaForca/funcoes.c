#include <stdio.h>
#include <string.h>
#define MAX_PALAVRA 20
#define MAX_TENTATIVAS 6

void inicializar_palavra_oculta(char *palavra, char *palavra_oculta) {
    int i;
    int tam_palavra = strlen(palavra);
    for (i = 0; i < tam_palavra; i++) {
        palavra_oculta[i] = '_';
    }
    palavra_oculta[i] = '\0';
    printf("\tA PALAVRA TEM: %d LETRAS!\nBOA SORTE!\n", tam_palavra);
}

char ler_entrada() {
    char entrada;
    printf("Digite uma letra ou a palavra completa: ");
    scanf(" %c", &entrada);
    return entrada;
}

int verificar_letra(char letra, char *palavra, char *palavra_oculta) {
    int i;
    int acertou = 0;
    int tam_palavra = strlen(palavra);
    for (i = 0; i < tam_palavra; i++) {
        if (palavra[i] == letra) {
            palavra_oculta[i] = letra;
            acertou = 1;
        }
    }
    return acertou;
}

int verificar_palavra(char *entrada, char *palavra) {
    return strcmp(entrada, palavra) == 0;
}

void atualizar_tentativas(int *tentativas_restantes, int acertou) {
    if (!acertou) {
        (*tentativas_restantes)--;
    }
}

void exibir_status(int tentativas_restantes, char *palavra_oculta) {
    printf("Tentativas restantes: %d\n", tentativas_restantes);
    printf("Palavra: %s\n", palavra_oculta);
}

void exibir_mensagem_acerto_letra() {
    printf("Letra encontrada!\n");
}

void exibir_mensagem_erro_letra(int tentativas_restantes) {
    printf("Letra não encontrada.\n");
}

void exibir_mensagem_acerto_palavra() {
    printf("Parabéns, você acertou a palavra!\n");
}

void exibir_mensagem_derrota() {
    printf("Você perdeu! Mais sorte na próxima vez.\n");
}

void limpa_tela(){
    //system("cls"); //WINDOWS!!
     system("clear"); //LINUX!!
}

void jogar(char *palavra) {
    int tentativas_restantes = MAX_TENTATIVAS;
    char palavra_oculta[MAX_PALAVRA];

    limpa_tela();
    inicializar_palavra_oculta(palavra, palavra_oculta);

    while (tentativas_restantes > 0) {
        exibir_status(tentativas_restantes, palavra_oculta);

        char entrada = ler_entrada();

        int acertou = verificar_letra(entrada, palavra, palavra_oculta);

        limpa_tela();
        if (acertou) {
            exibir_mensagem_acerto_letra();

        } else {
            exibir_mensagem_erro_letra(tentativas_restantes);

        }

        atualizar_tentativas(&tentativas_restantes, acertou);

        if (verificar_palavra(palavra_oculta, palavra)) {
            limpa_tela();
            exibir_mensagem_acerto_palavra();
            printf("\n\tPALAVRA: %s\n\n", palavra_oculta);
            return;
        }
    }
    limpa_tela();
    exibir_mensagem_derrota();
}
void exibir_menu() {
    printf("----- JOGO DA FORCA -----\n");
    printf("1 - Jogar\n");
    printf("2 - Sair\n");
    printf("Escolha uma opção: ");
}

void iniciar_jogo(){
    int opcao = 0;
    char *palavras[] = {"abacaxi", "computador", "elefante", "programacao", "restaurante"};
    int n_palavras = 5;

    exibir_menu();

    while (opcao != 2) {

        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                srand(time(NULL));
                int indice_palavra = rand() % n_palavras;
                char *palavra_secreta = palavras[indice_palavra];
                jogar(palavra_secreta);
                printf("Deseja Jogar Novamente?(1 ou 2)\n1- SIM\n2- SAIR\n");
                break;
            }
            case 2: {
                limpa_tela();
                printf("O jogo foi encerrado.\n");
                printf("Obrigado por jogar!\n");
                printf("\n\t Desenvolvido por: Thiago L. Maravilha.\n");
                break;
            }

            default: {
                limpa_tela();
                printf("\tOpção inválida. Tente novamente.\n\n");
                exibir_menu();
                break;
            }
        }




    }


}
