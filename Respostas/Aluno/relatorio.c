#include <stdlib.h>

#include "relatorio.h"
#include "equipe.h"
#include "jogador.h"

/// @brief Função que gera o relatório de saída, com as informações de
///         "EQUIPE CAMPEA" (basta buscar equipe com mais pontos e imprimir suas informações) e
///         "ARTILHEIRO" (buscar jogador com mais gols e imprimir informações)
///         conforme especificado no pdf.
/// @param equipes - Vetor de equipes cadastradas
/// @param nEquipes - número de equipes cadastradas
/// @param jogadores  - Vetor de jogadores cadastradas
/// @param nJogadores - número de equipes cadastradas
void geraRelatorio(tEquipe equipes[], int nEquipes, tJogador jogadores[], int nJogadores)
{
    int idCampea = 0;
    int pontosCampea = tEquipe_getNumPontos(equipes[0]);
    for (int i = 1; i < nEquipes; i++)
    {
        if (tEquipe_getNumPontos(equipes[i]) > pontosCampea)
        {
            idCampea = i;
            pontosCampea = tEquipe_getNumPontos(equipes[i]);
        }
    }
    char nomeCampea[TAM_MAX_NOME];
    tEquipe_copiaNome(equipes[idCampea], nomeCampea);
    printf("EQUIPE CAMPEA: %s (%d) P:%d J:%d V:%d E:%d D:%d GP:%d GC:%d SG:%d AP:%.2f%%\n",
           nomeCampea,
           tEquipe_getIdUnico(equipes[idCampea]),
           pontosCampea,
           tEquipe_getNumJogos(equipes[idCampea]),
           tEquipe_getNumeroVitorias(equipes[idCampea]),
           tEquipe_getNumeroEmpates(equipes[idCampea]),
           tEquipe_getNumeroDerrotas(equipes[idCampea]),
           tEquipe_getNumeroGolsPro(equipes[idCampea]),
           tEquipe_getNumeroGolsContra(equipes[idCampea]),
           tEquipe_getSaldogols(equipes[idCampea]),
           ((float)100.0 * pontosCampea / ((6.0) * (nEquipes - 1))));

    int maxGols = 0;
    int indiceArtilheiro = -1;
    // int indiceEquipeVetor = 0;
    for (int i = 0; i < nJogadores; i++)
    {
        int idEquipe = tJogador_getIdEquipe(jogadores[i]);

        int indiceEquipeVetor = tEquipe_encontraIndiceVetorComIdUnico(equipes, nEquipes, idEquipe);
        if (tEquipe_getQtdeGolsJogador(equipes[indiceEquipeVetor], tJogador_getIdUnico(jogadores[i])) > maxGols)
        {
            maxGols = tEquipe_getQtdeGolsJogador(equipes[indiceEquipeVetor], tJogador_getIdUnico(jogadores[i]));
            indiceArtilheiro = i;
        }
    }
    char nomeArtilheiro[TAM_MAX_NOME];
    char nomeTimeArtilheiro[TAM_MAX_NOME];
    tJogador_copiaNome(jogadores[indiceArtilheiro], nomeArtilheiro);
    int indiceEquipeArtilheiro = tEquipe_encontraIndiceVetorComIdUnico(equipes, nEquipes, tJogador_getIdEquipe(jogadores[indiceArtilheiro]));
    tEquipe_copiaNome(equipes[indiceEquipeArtilheiro], nomeTimeArtilheiro);
    printf("ARTILHEIRO: %s (%s) - %d GOLS\n",
           nomeArtilheiro,
           nomeTimeArtilheiro,
           maxGols);
}