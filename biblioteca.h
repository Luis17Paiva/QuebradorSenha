#ifndef _BIBLIOTECA_H_
#define _BIBLIOTECA_H_
#include <time.h>  

unsigned int login(char *senha);
void carregar_senhas(char *nome_arquivo);
char *senha_atual(void);
unsigned int proxima_senha(void);

void zera_contadores(void);
unsigned int total_login(void);
void inicia_tempo(clock_t *tempo);
void finaliza_tempo(clock_t *tempo);
double tempo_decorrido(clock_t *inicio, clock_t *fim);

#endif
