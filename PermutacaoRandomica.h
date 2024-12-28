/*
 * PermutacaoRandomica.h
 *
 *  Created on: Dec 10, 2024
 *      Author: andre
 */

#ifndef PERMUTACAORANDOMICA_H_
#define PERMUTACAORANDOMICA_H_
#include "Item.h"
#include "MeuItem.h"
#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
using std::cout;
using std::endl;
template <class TipoChave> class PermutacaoRandomica {
private:
	static double rand0a1 ();
	public:
    static void permut (Item<TipoChave> **v, int n);
    static void permut (TipoChave *v, int n);
    //static void permut (char *v, int n);
	static void main ();
};

template <class TipoChave>
double PermutacaoRandomica<TipoChave>::rand0a1 () {
	struct timeval semente;
	// @{\it utilizar o tempo como semente para a fun\c{c}\~ao srand ()}@
	 gettimeofday (&semente,NULL);
	 srand ((int)(semente.tv_sec + semente.tv_usec));
	 double resultado = (double) rand ()/ RAND_MAX;
	 return resultado;
}

template <class TipoChave>
void PermutacaoRandomica<TipoChave>::permut (Item<TipoChave> **v, int n) {
	 for (int i = n - 1; i > 0; i--) {
		 int j = 1 + (int) (i * rand0a1 () + 1.0);
		 Item<int> *b = v[i]; v[i] = v[j]; v[j] = b;
	 }
}

template <class TipoChave>
void PermutacaoRandomica<TipoChave>::permut (TipoChave *v, int n) {
	for (int i = n - 1; i > 0; i--) {
		int j = (int) (i * rand0a1 () + 1.0);
		int b = v[i]; v[i] = v[j]; v[j] = b;
	}
}

/*template <class TipoChave>
void PermutacaoRandomica<TipoChave>::permut (char *v, int n) {
	for (int i = n - 1; i > 0; i--) {
		int j = (int) (i * rand0a1 () + 1.0);
		char b = v[i]; v[i] = v[j]; v[j] = b;
	}
}*/

template <class TipoChave>
void PermutacaoRandomica<TipoChave>::main () {
	 int tam = 20, n = 20;
	 Item<int> *v[tam + 1];
	 for (int i = 1; i <= n; i++) v[i] = new MeuItem<TipoChave>(i);
	 permut (v, n);
	 for (int i = 1; i <= n; i++) cout << v[i]->toString () + " ";
	 cout << endl;
	 for (int i = 1; i <= n; i++) delete v[i];
}
#endif

