#pragma once

#include "KenoBet.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <ctime>

/**
 * @brief retorna a tabela de retorno correspondente
 * ao numero de spots do jogador
 *
 * @param num numero de spots do jogador
 * @return std::vector<cash_type> a tabela de retorno correspondente
 * ao numero de spots do jogador
 */
std::vector<cash_type> tableval(size_t num);

/**
 * @brief retorna um vetor com 20 hits sorteados
 *
 * @return set_of_numbers_type um vetor com 20 hits sorteados
 */
set_of_numbers_type randhits(void);

/**
 * @brief imprime um vetor na tela
 *
 * @param v vetor a ser imprimido
 */
void printvec(set_of_numbers_type v);

/**
 * @brief imprime uma tabela de retornos
 *
 * @param t tabela a ser imprimida
 */
void printtable(std::vector<cash_type> t);

/**
 * @brief cuida de erros genericos na formatação
 * do arquivos de apostas
 *
 */
void generror(void);

/**
 * @brief função para ordenar um vetor
 *
 * @param v vetor a ser ordenado
 */
void inserts(set_of_numbers_type& v);