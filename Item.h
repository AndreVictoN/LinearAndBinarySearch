/*
 * Item.h
 *
 *  Created on: Dec 10, 2024
 *      Author: andre
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <string>
using namespace std;

template <class TipoChave> class Item{
public:
	virtual int compara(const Item<TipoChave>* it) const = 0;
	virtual void alteraChave(TipoChave chave) = 0;
	virtual TipoChave recuperaChave() const = 0;
	virtual string toString() const = 0;
	virtual ~Item() {};
};

#endif /* ITEM_H_ */
