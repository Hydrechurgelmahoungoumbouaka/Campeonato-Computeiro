#ifndef _INCONSISTENCIAS_H_
#define _INCONSISTENCIAS_H_

#include "equipe.h"

/// @brief Função que verifica se há inconsistências na entrada dos dados. 
///         Imprime a mensagem e retorna 1 caso haja inconsistência. As possíveis inconsistências são:
///         1) CAMPEONATO NAO FINALIZADO - Menos partidas cadastradas do que deveria
///         2) ERRO DE CADASTRO - Campeonato finalizado mas há times com nº de jogos diferente do esperado
///         Valores esperados estão descritos no pdf.
/// @param nPartidas - número de partidas cadastradas
/// @param nEquipes - núemro de equipes cadastradas
/// @param equipes - Vetor de equipes cadastradas
/// @return 1, se houver, e 0 caso contrário
int verificaInconsistencias(int nPartidas, int nEquipes, tEquipe equipes[]);

#endif