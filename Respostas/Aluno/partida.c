#include <stdio.h>
#include <string.h>

#include "partida.h"

/// @brief "Getters" da estrutura. Todas as funções abaixo recebem como parâmetro
///         uma variável que armazena uma partida e retorna um de seus campos.
/// @param partida
/// @return um campo (depende da função!)
int tPartida_getIdPartida(tPartida partida)
{
    return (partida.idPartida);
}
int tPartida_getIdEquipe1(tPartida partida)
{
    return (partida.idEquipe1);
}
int tPartida_getIdEquipe2(tPartida partida)
{
    return (partida.idEquipe2);
}
int tPartida_getNumGolsEquipe1(tPartida partida)
{
    return (partida.numGolsEquipe1);
}
int tPartida_getNumGolsEquipe2(tPartida partida)
{
    return (partida.numGolsEquipe2);
}

/// @brief Função que lê os dados de uma partida (scanf)
///         E retorna a variável inicializada e preenchida.
///         Obs: Essa função NÃO LÊ os autores dos gols (lê apenas a linha única com os dados da partida).
/// @return
tPartida tPartida_lerPartida()
{
    tPartida p;
    /*int idPartida;
        int idEquipe1;
        int idEquipe2;
        int numGolsEquipe1;
        int numGolsEquipe2;*/

    scanf("%d %d %d %d %d", &p.idPartida, &p.idEquipe1, &p.idEquipe2, &p.numGolsEquipe1, &p.numGolsEquipe2);
    scanf("%*c");
    return p;
}