#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void jogar(char *palavra);
void inicializar_palavra_oculta(char *palavra, char *palavra_oculta);
char ler_entrada();
int verificar_letra(char letra, char *palavra, char *palavra_oculta);
int verificar_palavra(char *entrada, char *palavra);
void atualizar_tentativas(int *tentativas_restantes, int acertou);
void exibir_status(int tentativas_restantes, char *palavra_oculta);
void exibir_mensagem_acerto_letra();
void exibir_mensagem_erro_letra(int tentativas_restantes);
void exibir_mensagem_acerto_palavra();
void exibir_mensagem_derrota();
void limpa_tela();
void exibir_menu();
void iniciar_game();
#endif // FUNCOES_H_INCLUDED
