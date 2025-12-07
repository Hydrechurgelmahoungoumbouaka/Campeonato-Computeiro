#ifndef _PARTIDA_H_
#define _PARTIDA_H_

/*  Definição da estrutura 
    NÃO ALTERAR
*/

typedef struct {
    int idPartida;
    int idEquipe1; 
    int idEquipe2;
    int numGolsEquipe1;
    int numGolsEquipe2;
} tPartida;

/// @brief "Getters" da estrutura. Todas as funções abaixo recebem como parâmetro
///         uma variável que armazena uma partida e retorna um de seus campos.
/// @param partida 
/// @return um campo (depende da função!)
int tPartida_getIdPartida(tPartida partida);
int tPartida_getIdEquipe1(tPartida partida);
int tPartida_getIdEquipe2(tPartida partida);
int tPartida_getNumGolsEquipe1(tPartida partida);
int tPartida_getNumGolsEquipe2(tPartida partida);

/// @brief Função que lê os dados de uma partida (scanf)
///         E retorna a variável inicializada e preenchida.
///         Obs: Essa função NÃO LÊ os autores dos gols (lê apenas a linha única com os dados da partida).
/// @return 
tPartida tPartida_lerPartida();

#endif