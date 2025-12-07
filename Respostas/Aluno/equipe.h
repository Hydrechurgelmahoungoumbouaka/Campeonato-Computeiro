
#ifndef _EQUIPE_H_
#define _EQUIPE_H_

#define MAX_GOLS_EQUIPE 200
#define TAM_MAX_NOME 30

/*  Definição da estrutura 
    NÃO ALTERAR
*/

typedef struct {
    int nJogadores;
    int nVitorias;
    int nEmpates;
    int nDerrotas;
    int idGols[MAX_GOLS_EQUIPE];
    int nGolsPro;
    int nGolsContra;
    char nome[TAM_MAX_NOME];
    int idUnico;
} tEquipe;

/// @brief Função que copia o conteúdo de um nome de uma equipe para uma nova variável
/// @param e - a equipe que terá seu nome copiado
/// @param dst - o vetor "externo" que receberá o valor copiado
void tEquipe_copiaNome(tEquipe e, char dst[]);

/// @brief Funções getter - retorna um campo da estrutura
/// @param e - uma variável que armazena uma equipe
/// @return O id da equipe do jogador
int tEquipe_getNumeroJogadores(tEquipe e);
int tEquipe_getNumeroVitorias(tEquipe e);
int tEquipe_getNumeroDerrotas(tEquipe e);
int tEquipe_getNumeroEmpates(tEquipe e);
int tEquipe_getIdUnico(tEquipe e);
int tEquipe_getNumeroGolsPro(tEquipe e);
int tEquipe_getNumeroGolsContra(tEquipe e);

/// @brief Funções getter - retorna um cálculo com base nos valores dos campos da estrutura
/// @param e - uma variável que armazena uma equipe
/// @return O id da equipe do jogador
int tEquipe_getNumPontos(tEquipe e);
int tEquipe_getNumJogos(tEquipe e);
int tEquipe_getSaldogols(tEquipe e);

/// @brief  Função que retorna a quantidade de gols feitos
///         Repare que os gols são "armazenados" nas variáveis idGols e nGolsPro.
///         "idGols" armazena os ids dos jogadores que fizeram os gols daquele time;
/// @param e - uma equipe
/// @param idJogador - um id de jogador
/// @return o número de gols que aquele jogador fez
int tEquipe_getQtdeGolsJogador(tEquipe e, int idJogador);

/// @brief Funções de incrementar (somar 1) uma variável específica (olhar título da função)
/// @param e - uma variável que armazena uma equipe
/// @return A variável com os campos atualizados
tEquipe tEquipe_incrementaVitorias(tEquipe e);
tEquipe tEquipe_incrementaDerrotas(tEquipe e);
tEquipe tEquipe_incrementaEmpates(tEquipe e);
tEquipe tEquipe_incrementaNumeroJogadores(tEquipe e);

/// @brief  Adiciona "um gol" aos gols de uma equipe. Na verdade, armazena o id do jogador que fez um gol
///         pelo time (gol pró) no vetor correspondente. 
///         Não esqueça de somar a variável que controla a quantidade de gols 
/// @param e - uma variável que armazena uma equipe 
/// @param idJogador - id do jogador que fez o gol pelo time
/// @return A variável com os campos atualizados
tEquipe tEquipe_adicionaGolPro(tEquipe e, int idJogador);

/// @brief Adiciona um número de gols contra em uma equipe
///         Ao contrário dos gols pro, não é necessário armazenar quem fez os gols;
///         Apenas a quantidade
/// @param e - uma variável que armazena uma equipe
/// @param nGols - número de gols contra que o time sofreu
/// @return A variável com os campos atualizados
tEquipe tEquipe_adicionaGolsContra(tEquipe e, int nGols);

/// @brief Função que lê os dados de um jogador (scanf)
///         E retorna a variável inicializada e preenchida.
/// @return 
tEquipe leEquipe();

#endif