#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "biblioteca.h"
#include "quebrador-senha.h"

void testa_quebrador_senha(){
    unsigned int backtracking, exaustiva;
    double porcentagem_login;
    double backtracking_tempo, exaustiva_tempo;
    double porcentagem_tempo;
    clock_t tempo_ini, tempo_fim; // Variáveis para armazenar o tempo decorrido

    while(proxima_senha()){
        printf("------------------------------------------\n");
        printf("Testando senha: %s\n", senha_atual());

        tempo_ini = 0;
        tempo_fim = 0;
        backtracking = 0;
        backtracking_tempo = 0.0;
        exaustiva = 0;
        exaustiva_tempo = 0.0;

        printf("Rodando Backtracking com Poda: \n");
        inicia_tempo(&tempo_ini); // Passa o ponteiro para a variável 'bt_tempo'
        if (!quebrador_senha_poda())
	        printf("Erro, senha nao encontrada!\n");
        finaliza_tempo(&tempo_fim); // Passa o ponteiro para a variável 'bt_tempo'
        backtracking = total_login();
        backtracking_tempo += tempo_decorrido(&tempo_ini,&tempo_fim); // Salva o valor do tempo para usar na comparação
        printf("\t%u tentativas de login\n",backtracking);
        printf("\tTempo decorrido: %lf s\n",backtracking_tempo);


        tempo_ini = 0;
        tempo_fim = 0;

        printf("Rodando Backtracking de Forca Bruta: \n");
        inicia_tempo(&tempo_ini); // Passa o ponteiro para a variável 'ex_tempo'
        if(!quebrador_senha_exaustivo())
	        printf("Erro, senha nao encontrada!\n");
        finaliza_tempo(&tempo_fim); // Passa o ponteiro para a variável 'ex_tempo'
        exaustiva = total_login();
        exaustiva_tempo += tempo_decorrido(&tempo_ini,&tempo_fim) ; // Salva o valor do tempo para usar na comparação
        printf("\t%u tentativas de login\n",exaustiva);
        printf("\tTempo decorrido: %lf s\n",exaustiva_tempo);

        porcentagem_login = ((double)backtracking / exaustiva) * 100;
        porcentagem_tempo = (1 - (double)(exaustiva_tempo / backtracking_tempo)) * -100;
        printf("\nBacktracking reduziu as tentativas de login em %.2f%% e o tempo em %.2f%%\n", porcentagem_login, porcentagem_tempo );
    }
}

int main(){
    carregar_senhas("senhas.txt");
    testa_quebrador_senha();
    return 0;
}

