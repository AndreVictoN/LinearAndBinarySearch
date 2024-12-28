/*
 * MeuItem.h
 *
 *  Created on: Dec 10, 2024
 *      Author: andre
 */

#ifndef MEUITEM_H_
#define MEUITEM_H_

#include "Item.h"
#include <sstream>

using namespace std;

template <class TipoChave>
class MeuItem : public Item<TipoChave>{
private:
	TipoChave chave;

public:
	MeuItem(TipoChave chave);
	virtual int compara(const Item<TipoChave> *item) const;
	virtual void alteraChave(TipoChave chave);
	virtual TipoChave recuperaChave() const;
	virtual string toString() const;
	~MeuItem(){};
};

template <class TipoChave>
MeuItem<TipoChave>::MeuItem(TipoChave chave) {this->chave = chave;}

template <class TipoChave>
int MeuItem<TipoChave>::compara(const Item<TipoChave> *item) const{
	const MeuItem<TipoChave> *it = dynamic_cast<const MeuItem<TipoChave>*>(item);

	if(this->chave < it->chave) return -1;

	if(this->chave > it->chave) return 1;

	return 0;
}

template <class TipoChave>
void MeuItem<TipoChave>::alteraChave(TipoChave chave) {this->chave = chave;}

template <class TipoChave>
TipoChave MeuItem<TipoChave>::recuperaChave() const{return this->chave;}

template <class TipoChave>
string MeuItem<TipoChave>::toString() const{
	ostringstream chaveString;

	chaveString << this->chave;

	return chaveString.str();
}

#endif /* MEUITEM_H_ */
