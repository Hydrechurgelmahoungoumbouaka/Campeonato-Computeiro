# 🏆 Campeonato-Computeiro — Sistema de Gestão Esportiva (EA)

![C](https://shields.io)
![UFES](https://shields.io)

Este repositório contém a resolução do Exercício Avaliativo focado no desenvolvimento de um **Sistema de Gestão Esportiva e Análise de Desempenho**, submetido na disciplina de **Programação II (UFES)** para a plataforma do **Campeonato-Computeiro**.

O objetivo do projeto é consolidar o uso avançado de **Tipos Abstratos de Dados (TADs)** empilhados, simulando encapsulamento estrito em C para gerenciar equipes, estatísticas de atletas, histórico de confrontos e auditoria de dados.

---

## 🏗️ Engenharia da Solução (TADs do Template)

A arquitetura do software foi rigidamente modularizada seguindo os arquivos de cabeçalho (`.h`) fornecidos no template oficial da disciplina:

* **`jogador`**: Modela os dados individuais do atleta (nome, ID, posição, idade) e suas estatísticas individuais acumuladas (gols, assistências, cartões, minutos jogados).
* **`equipe`**: Agrega um conjunto de jogadores cadastrados sob um mesmo clube, gerenciando a folha de atletas e o desempenho coletivo na temporada.
* **`partida`**: Registra os dados de um confronto direto (equipe mandante x equipe visitante), placar, data, local e eventos ocorridos durante os 90 minutos.
* **`busca`**: Módulo utilitário responsável pelos algoritmos de varredura e indexação (busca linear ou binária) para encontrar jogadores por ID/Nome ou filtrar equipes.
* **`inconsistencia`**: Motor de auditoria do sistema. Valida e reporta erros de dados ou fraudes nas súmulas (ex: jogador não cadastrado atuando, atleta suspenso em campo, ou divergência de placares).
* **`relatorio`**: Responsável pela formatação fina da saída padrão (`stdout`), gerando tabelas de classificação, estatísticas de artilharia e o sumário de inconsistências detectadas.

---

## 🚦 Regras de Negócio e Auditoria (`inconsistencia`)

O sistema processa as súmulas em lote e o módulo de consistência barra registros que violem os seguintes critérios de integridade:
1. **Inconsistência de Inscrição:** Jogador escalado para uma `partida` que não esteja devidamente registrado no TAD `equipe`.
2. **Inconsistência de Idade/Regulamento:** Atletas atuando fora da categoria permitida pelo campeonato.
3. **Inconsistência Estatística:** A soma dos gols atribuídos aos jogadores no relatório de eventos difere do placar final registrado na `partida`.
4. **Duplicidade de Vínculo:** Um mesmo `jogador` registrado em duas equipes simultaneamente.

---

## 📥 Fluxo de Execução e Correção

O programa consome a configuração das equipes e o histórico de partidas via entrada padrão (`stdin`) e gera a análise detalhada de desempenho e erros via saída padrão (`stdout`).

Para compilar e testar localmente contra o corretor automático do Campeonato-Computeiro, utilize:

```bash
# 1. Compilar todo o projeto via Makefile (flags -Wall -Wextra -std=c99)
make

# 2. Executar o script de testes e validação de diffs
./correcao.sh

# 3. Limpar arquivos objetos (.o) e binários gerados
make clean
```
