#include "biblioteca.h"
#include "quebrador-senha.h"
#include <stdio.h>

/* Trabalho de Luis Eduardo Soares de Paiva - GRR20192614 */

/*Verifica todas as possilidades de senhas com as seguites restrições:
    1 - Letras minúsculas (códigos da tabela ASCII do 97 ao 122 em decimal) e
        números (códigos da tabela ASCII do 48 ao 57 em decimal)
    2 - Senha com exatamente 6 caracteres

    E caso encontre a senha retorna 1
*/
int resolve_exaustivo(int n,char* possivel_senha){
    int i,j;
 
    if (n == 6){
        possivel_senha[n] = '\0';
        return login(possivel_senha);   
    }

    /*Testa os possíveis números*/
    for(i = 48; i < 58; i++){

        possivel_senha[n] = i;
        j = resolve_exaustivo(n+1,possivel_senha);

        if(j == 1){
            return j;
        }
    }

    /*Testa as possíveis letras*/
    for(i = 97; i < 123; i++){

        possivel_senha[n] = i;
        j = resolve_exaustivo(n+1,possivel_senha);

        if(j == 1){
            return j;
        }
    }
    return 0;

}
/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_exaustivo(){
    int n = 0;
    char possivel_senha[7];

    return resolve_exaustivo(n,possivel_senha);

}


/*Verifica todas as possilidades de senha com as seguites restrições:
    1 - Letras minúsculas (códigos da tabela ASCII do 97 ao 122 em decimal) e
        números (códigos da tabela ASCII do 48 ao 57 em decimal)
    2 - Senha com exatamente 6 caracteres  
    3 - Sem repetição de caracteres
    4 -Senha com pelo menos 2 letras
    5 - Senha com pelo menos 2 números

    E caso encontre a senha retorna 1;
*/  
int resolve_poda(int n, int letra, int numero,char* possivel_senha, int v[]){
    int i,j;

    if (n == 6){
        possivel_senha[n] = '\0';
        return login(possivel_senha);   
    }
    
    /*Verifica se contem 4 números na palavra, se tiver chama recursivamente apenas para letras*/
    if (numero == 4){

        /*Verifica a senha já contem o elemento i, se tiver incrementa o i e chama recursivo para 
        o proximo código ASCII*/
        for(i = 97; i < 123; i++){

            /*Verifica a senha já contem o elemento i, se tiver incrementa o i e chama recursivo para 
            o proximo código ASCII*/
            if(v[i] == 1){

                if(i == 122){

                    return 0;
                }else{
                    
                    i++;
                }
            }
            possivel_senha[n] = i;
            v[i] = 1;
            j = resolve_poda(n+1,letra+1,numero,possivel_senha,v);
            v[i] = 0;

            if(j == 1){
                return j;
            }
        }
    }

    /*Verifica se contem 4 letras na palavra, se tiver chama recursivamente apenas para números*/
    if (letra == 4){

        for(i = 48; i < 58; i++){

            /*Verifica a senha já contem o elemento i, se tiver incrementa o i e chama recursivo para 
            o proximo código ASCII*/
            if(v[i] == 1){

                if(i == 57){

                    return 0;
                }else{

                    i++;
                }
            }
            possivel_senha[n] = i;
            v[i] = 1;
            j = resolve_poda(n+1,letra,numero+1,possivel_senha,v);
            v[i] = 0;

            if(j == 1){
                return j;
            }
        }
    }

    /*Testa os possíveis números*/
    for(i = 48; i < 58 && letra != 4 && numero != 4; i++){

        /*Verifica a senha já contem o elemento i, se tiver incrementa o i e chama recursivo para 
        o proximo código ASCII*/
        if(v[i] == 1){

            if( i == 57 ){

                i = i + 40;

            }else{

                i++; /*pula para o pŕoximo código ASCII*/
                possivel_senha[n] = i;
                v[i] = 1; 
                j = resolve_poda(n+1,letra,numero+1,possivel_senha,v);
                v[i] = 0;

                if(j == 1){

                return j;
                }
            }
        }else{

            /*Insere o elemento i na posição n no vetor de string da senha teste*/
            possivel_senha[n] = i;

            /* informa que o elemento i está na palavra, incrementa o contador de números e chama 
            a função recursiva para a proximo posição e depois informa que palavra não contem mais
            esse elemento*/
            v[i] = 1; 
            j = resolve_poda(n+1,letra,numero+1,possivel_senha,v);
            v[i] = 0;

            /*Verifica se encontrou a senha*/
            if(j == 1){

                return j;
            }
        }
        
    }

    /*Testa as possíveis letras*/
    for(i = 97; i < 123 && letra != 4 && numero != 4; i++){

        /*Verifica a senha já contem o elemento i, se tiver pula para próximo elemento*/
        if(v[i] == 1){

            if( i == 122 ){

                return 0;

            }else{

                i++;
                possivel_senha[n] = i;
                v[i] = 1; 
                j = resolve_poda(n+1,letra+1,numero,possivel_senha,v);
                v[i] = 0;

                if(j == 1){

                return j;
                }
            }
        }else{

            /*Insere o elemento i na posição n no vetor de string da senha teste*/
            possivel_senha[n] = i;

            /* informa que o elemento i está na palavra, incrementa o contador de letras e chama 
            a função recursiva para a proximo posição e depois informa que palavra não contem mais
            esse elemento*/
            v[i] = 1; 
            j = resolve_poda(n+1,letra+1,numero,possivel_senha,v);
            v[i] = 0;

            /*Verifica se encontrou a senha*/
            if(j == 1){

                return j;
            }
        }
    }
    return 0;
}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_poda(){
    int i,n = 0;   /* "n" representa a posição atual no vetor de string da senha teste*/
    int num_l = 0; /*número de letras na senha teste*/
    int num_n = 0; /*número de números na senha teste*/

    char possivel_senha[7];
    int v[123]; /*vetor auxiliar onde o indíce representa o código na tabela ASCII, 0 representa 
    que palavra não contem esse elemento e 1 contem*/

    /*inicializa o vetor auxiliar*/
    for(i = 0; i < 123; i++){

        v[i] = 0;
    }

    return resolve_poda(n,num_l,num_n,possivel_senha,v);

}


