#include <stdio.h>
#include <string.h>

#include "busca.h"
#include "equipe.h"
#include "inconsistencias.h"
#include "jogador.h"
#include "partida.h"
#include "relatorio.h"

#define TAM_MAX_NOME 30
#define MAX_JOGADORES 200
#define MAX_EQUIPES 20
#define MAX_GOLS_EQUIPE 200

int main()
{
    tJogador jogadores[200];
    tEquipe equipes[20];
    tPartida partidas[380];
    int nJogadores = 0;
    int nEquipes = 0;
    int nPartidas = 0;

    char c = 0;
    while (c != 'F')
    {
        // printf("%d %d %d\n",nEquipes,nJogadores,nPartidas);
        scanf("%c\n", &c);
        if (c == 'E')
        {
            equipes[nEquipes++] = leEquipe();
        }
        if (c == 'J')
        {
            jogadores[nJogadores++] = lerJogador();
            int indiceTime = tEquipe_encontraIndiceVetorComIdUnico(equipes, nEquipes, tJogador_getIdEquipe(jogadores[nJogadores - 1]));
            equipes[indiceTime] = tEquipe_incrementaNumeroJogadores(equipes[indiceTime]);
        }
        if (c == 'P')
        {
            partidas[nPartidas] = tPartida_lerPartida();
            int nGols1 = tPartida_getNumGolsEquipe1(partidas[nPartidas]);
            int nGols2 = tPartida_getNumGolsEquipe2(partidas[nPartidas]);
            int time1 = tPartida_getIdEquipe1(partidas[nPartidas]);
            int time2 = tPartida_getIdEquipe2(partidas[nPartidas]);
            nPartidas++;
            int indiceTime1 = tEquipe_encontraIndiceVetorComIdUnico(equipes, nEquipes, time1);
            int indiceTime2 = tEquipe_encontraIndiceVetorComIdUnico(equipes, nEquipes, time2);

            equipes[indiceTime1] = tEquipe_adicionaGolsContra(equipes[indiceTime1], nGols2);
            equipes[indiceTime2] = tEquipe_adicionaGolsContra(equipes[indiceTime2], nGols1);

            int idJogador;
            int flag = 0;
            // for (int i=0; i<nGols1; i++) {
            while (flag != nGols1)
            {
                scanf("%d\n", &idJogador);

                int indiceJogador = tJogador_encontraIndiceVetorComIdUnico(jogadores, nJogadores, idJogador);
                if (tJogador_getIdEquipe(jogadores[indiceJogador]) != time1)
                {
                    continue;
                }

                equipes[indiceTime1] = tEquipe_adicionaGolPro(equipes[indiceTime1], idJogador);
                flag++;
            }
            flag = 0;
            // for (int i=0; i<nGols2; i++) {
            while (flag != nGols2)
            {
                scanf("%d\n", &idJogador);

                int indiceJogador = tJogador_encontraIndiceVetorComIdUnico(jogadores, nJogadores, idJogador);
                if (tJogador_getIdEquipe(jogadores[indiceJogador]) != time2)
                {
                    continue;
                }

                equipes[indiceTime2] = tEquipe_adicionaGolPro(equipes[indiceTime2], idJogador);
                flag++;
            }

            if ((tEquipe_getNumeroJogadores(equipes[indiceTime1]) < 5))
            {
                equipes[indiceTime1] = tEquipe_incrementaDerrotas(equipes[indiceTime1]);
                equipes[indiceTime2] = tEquipe_incrementaVitorias(equipes[indiceTime2]);
            }
            else if ((tEquipe_getNumeroJogadores(equipes[indiceTime2]) < 5))
            {
                equipes[indiceTime1] = tEquipe_incrementaVitorias(equipes[indiceTime1]);
                equipes[indiceTime2] = tEquipe_incrementaDerrotas(equipes[indiceTime2]);
            }
            else
            {
                if (nGols1 > nGols2)
                {
                    equipes[indiceTime1] = tEquipe_incrementaVitorias(equipes[indiceTime1]);
                    equipes[indiceTime2] = tEquipe_incrementaDerrotas(equipes[indiceTime2]);
                }
                else if ((nGols1 < nGols2))
                {
                    equipes[indiceTime1] = tEquipe_incrementaDerrotas(equipes[indiceTime1]);
                    equipes[indiceTime2] = tEquipe_incrementaVitorias(equipes[indiceTime2]);
                }
                else
                {
                    equipes[indiceTime1] = tEquipe_incrementaEmpates(equipes[indiceTime1]);
                    equipes[indiceTime2] = tEquipe_incrementaEmpates(equipes[indiceTime2]);
                }
            }
        }
    }

    /* Verificações */
    int existemInconsistencias = verificaInconsistencias(nPartidas, nEquipes, equipes);

    /* Relatório */
    if (!existemInconsistencias)
    {
        geraRelatorio(equipes, nEquipes, jogadores, nJogadores);
    }

    return 0;
}