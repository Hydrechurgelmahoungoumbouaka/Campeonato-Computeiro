#include <stdio.h>
#include <string.h>

#include "busca.h"
#include "jogador.h"
#include "equipe.h"

/// @brief Função que recebe um vetor de equipes, o seu tamanho e um id único.
///         A utilidade dela é retornar qual o índice do vetor possui uma equipe com
///         aquele id único. Ou -1 caso não encontre.
/// @param equipes - vetor de equipes
/// @param nEquipes - número de equipes cadastrados
/// @param idUnico - id único a ser buscado
/// @return conforme descrito na seção @brief
int tEquipe_encontraIndiceVetorComIdUnico(tEquipe equipes[], int nEquipes, int idUnico)
{
    for (int i = 0; i < nEquipes; i++)
    {
        if (tEquipe_getIdUnico(equipes[i]) == idUnico)
        {
            return i;
        }
    }
    return 1;
}

/// @brief Função que recebe um vetor de jogadores, o seu tamanho e um id único.
///         A utilidade dela é retornar qual o índice do vetor possui um jogador com
///         aquele id único. Ou -1 caso não encontre.
/// @param jogadores - vetor de jogadores
/// @param nJogadores - número de jogadores cadastrados
/// @param idUnico - id único a ser buscado
/// @return conforme descrito na seção @brief
int tJogador_encontraIndiceVetorComIdUnico(tJogador jogadores[], int nJogadores, int idUnico)
{
    for (int i = 0; i < nJogadores; i++)
    {
        if (tJogador_getIdUnico(jogadores[i]) == idUnico)
        {
            return i;
        }
    }
    return 1;
}
