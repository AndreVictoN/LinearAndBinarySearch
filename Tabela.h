/*
 * Tabela.h
 *
 *  Created on: Dec 10, 2024
 *      Author: andre
 */

#ifndef TABELA_H_
#define TABELA_H_

#include "Item.h"
#include <stdexcept>
#include <vector>

using namespace std;

template <class TipoChave> class Tabela{
private:
	Item<TipoChave> **registros;
	int n, maxN;
public:
	Tabela(int maxN);
	int pesquisa(Item<TipoChave> *reg);
	vector<int> pesquisaIgual(Item<TipoChave> *reg);
	void insere(Item<TipoChave> *reg) throw (logic_error);
	int binaria(Item<TipoChave> *chave) const;
	~Tabela();
};

template <class TipoChave>
Tabela<TipoChave>::Tabela(int maxN){
	this->registros = new Item<TipoChave>*[maxN+1];
	this->n = 0;
	this->maxN = maxN + 1;
}

template <class TipoChave>
int Tabela<TipoChave>::pesquisa (Item<TipoChave> *reg) {
	this->registros[0] = reg; //item sentinela
	int i = this->n;
	while (this->registros[i]->compara (reg) != 0) i--;

	return i;
}

template <class TipoChave>
vector<int> Tabela<TipoChave>::pesquisaIgual(Item<TipoChave> *reg){
	vector<int> indices;
	this->registros[0] = reg;

	for(int i = 1; i <= this->n; i++){
		if(this->registros[i]->compara(reg) == 0){
			indices.push_back(i);
		}
	}

	return indices;
}

template <class TipoChave>
void Tabela<TipoChave>::insere (Item<TipoChave> *reg)
throw ( logic_error ) {
	if (this->n == (this->maxN - 1))
		throw logic_error ("Erro: A tabela esta cheia");

	this->registros[++(this->n)] = reg;
}

template <class TipoChave>
int Tabela<TipoChave>::binaria (Item<TipoChave> *chave) const {
	if (this->n == 0) return 0;

	int esq = 1, dir = this->n, i;
	do {
		i = (esq + dir) / 2;
		if (chave->compara (this->registros[i]) > 0) esq = i + 1;
		else dir = i - 1;
	}while ((chave->compara (this->registros[i]) != 0) && (esq <= dir));

	if (chave->compara (this->registros[i]) == 0) return i;

	else return 0;
}

template <class TipoChave>
Tabela<TipoChave>::~Tabela (){
  for(int i = 1; i <= this->n; i++) delete this->registros[i];

  delete [] this->registros;
}

#endif /* TABELA_H_ */
