/*
 * Andre_Nascimento_10_12_ArvoreBinaria.cpp
 *
 *  Created on: Dec 10, 2024
 *      Author: andre
 */

#include <iostream>
#include <string>
#include <vector>
#include "Tabela.h"
#include "MeuItem.h"
#include "PermutacaoRandomica.h"

using namespace std;

void Binaria() {
	int maxN = 10;
	Tabela<int>* T = new Tabela<int>(maxN);
	Tabela<char>* TC = new Tabela<char>(maxN);
	MeuItem<int> *reg = NULL;
	MeuItem<char> *regC = NULL;
	int *vetor = new int[maxN + 1];
	char *vetorC = new char[maxN + 1];
	int i;
	char caracteres = 'a';
	int pos;

	//insere as chaves em ordem na tabela
	for(i = 1; i < maxN; i++){
		vetor[i] = i;
		reg = new MeuItem<int>(vetor[i]);

		T->insere(reg);
		cout << "Inseriu: " << vetor[i] << endl;
	}

    //Pesquisa binária em cada chave
    cout << "Pesquisa Binaria (chaves ordenadas):" << endl;
    for (i = 1; i < maxN; i++) {
    	reg = new MeuItem<int>(i);
    	pos = T->binaria (reg);

    	if (pos == 0) {
    		cout << "Pesquisa Falhou" << endl;

    		return;
    	}

    	cout << "Registro " << i << " na posicao: " << pos << endl;
    	delete reg;
    }
    delete T;

    for(i = 1; i < maxN; i++){
    	vetorC[i] = caracteres;
    	regC = new MeuItem<char>(vetorC[i]);

    	TC->insere(regC);
    	cout << "Inseriu: " << vetorC[i] << endl;

    	caracteres++;
    }

    caracteres = 'a';

    for (i = 1; i < maxN; i++) {
    	regC = new MeuItem<char>(caracteres);
    	pos = TC->binaria (regC);

    	if (pos == 0) {
    		cout << "Pesquisa Falhou" << endl;

    		return;
    	}

    	cout << "Registro " << caracteres << " na posicao: " << pos << endl;
    	caracteres++;
    	delete regC;
    }

    delete TC;
    delete []vetor;
    delete []vetorC;
}

void Sequencial()
{
	int maxN = 10;
	Tabela<int>* T = new Tabela<int>(maxN);
	Tabela<char>* TC = new Tabela<char>(maxN);
	MeuItem<int> *reg = NULL;
	MeuItem<char> *regC = NULL;
	int *vetor = new int[maxN + 1];
	string vetorC;
	size_t cont;
	int i;
	char caractere;
	vector<int> indices;
	int pos;
	int num;

	for(i = 1; i < maxN; i++)
		vetor[i] = i;

	PermutacaoRandomica<int>::permut(vetor, maxN);

	T = new Tabela<int>(maxN);

	for(i = 1; i < maxN; i++){
	    reg = new MeuItem<int>(vetor[i]);
	    T->insere(reg);

	    cout << "Inseriu: " << vetor[i] << endl;
	}

	cout << "Pesquisa Sequencial (chaves desordenadas)" << endl;
	for(i = 1; i < maxN; i++){
	    reg = new MeuItem<int>(i);
	    pos = T->pesquisa(reg);

	    if(pos == 0){
	    	cout << "Pesquisa Falhou" << endl;

	    	return;
	    }

	    cout << "Registro " << i << " na posição: " << pos << endl;

	    delete reg;
	}

	/*cout << endl << "Qual número deseja pesquisar no vetor?" << endl;
	cin >> num;

	reg = new MeuItem<int>(num);
	pos = T->pesquisa(reg);

	if(pos == 0){
		cout << "Pesquisa Falhou" << endl;

		return;
	}

	cout << "Registro" << num << " na posição: " << pos << endl;*/

	cout << endl << "Digite a palavra que queira usar na pesquisa: " << endl;
	getline(cin, vetorC);

	TC = new Tabela<char>(vetorC.size());

	for(cont = 1; cont < vetorC.size() + 1; cont++){
		regC = new MeuItem<char>(vetorC.at(cont - 1));
		TC->insere(regC);

		cout << "Inseriu: " << vetorC.at(cont - 1) << endl;
	}

	cout << endl << "Digite a letra que quer pesquisar: " << endl;
	cin >> caractere;

	regC = new MeuItem<char>(caractere);
	indices = TC->pesquisaIgual(regC);

	if(indices.empty()){
		cout << "Pesquisa Falhou" << endl;

		return;
	}

	bool primeiro = true;

	cout << "Registro " << caractere << " na(s) posição(ões): ";
	for(cont = 0; cont < indices.size(); cont++){
		if(primeiro){
			cout << indices.at(cont);

			primeiro = false;
		}else{
			cout << ", " << indices.at(cont);
		}
	}

	cout << endl;

	delete regC;
	delete TC;
	delete T;
	delete []vetor;
}

int main(int argc, char **argv) {
	cout << "Pesquisa binária:" << endl;
	Binaria();

	cout << endl << "Pesquisa sequencial:" << endl;
	Sequencial();

	return 0;
}

