#ifndef QUEBRADOR_SENHA
#define QUEBRADOR_SENHA

/*Verifica todas as possilidades de senhas com as seguites restrições:
    1 - Letras minúsculas (códigos da tabela ASCII do 97 ao 122 em decimal) e
        números (códigos da tabela ASCII do 48 ao 57 em decimal)
    2 - Senha com exatamente 6 caracteres

    E caso encontre a senha retorna 1
*/
/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_exaustivo();

/*Verifica todas as possilidades de senha com as seguites restrições:
    1 - Letras minúsculas (códigos da tabela ASCII do 97 ao 122 em decimal) e
        números (códigos da tabela ASCII do 48 ao 57 em decimal)
    2 - Senha com exatamente 6 caracteres  
    3 - Sem repetição de caracteres
    4 -Senha com pelo menos 2 letras
    5 - Senha com pelo menos 2 números

    E caso encontre a senha retorna 1;
*/  
/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_poda();

#endif
