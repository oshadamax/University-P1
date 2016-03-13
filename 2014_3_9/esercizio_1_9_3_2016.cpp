/*
	Feiv
	esercizio_1_9_3_2016.cpp
	13/03/2016
*/

#include<iostream>
#include<fstream>
using namespace std;

//PRE=("input" contiene 40 interi, seguiti o dalla coppia "H" x o dalla coppia 'V' y
//dove x sarà tra 0 e 3 e y tra 0 e 4)
int main()
{

	int A[2][4][5], iletto;
	ifstream IN("input");
	ofstream OUT("output");
	char cletto;
	
	if(IN) {
		//caricamento di A
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 4; j++)
				for(int h = 0; h < 5; h++)
					IN >> A[i][j][h];

		IN >> cletto;
		IN >> iletto;
	} else {
		return -1;
	}
	
	if(OUT) {
	
		if(cletto == 'H')
			for(int i = 0; i < 2; i++)
				for(int j = iletto; j < iletto+1; j++) {
					for(int h = 0; h < 5; h++)
						OUT << A[i][j][h] << " ";
					OUT << endl;
	            }
		
		if(cletto == 'V' )			
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 4; j++) {
					for(int h = iletto; h < iletto+1; h++)
						OUT << A[i][j][h] << " ";
					OUT << endl;
	            }
	} else {
		return -1;
	}
	
	
	
	return 0;
}
//POST=("output" deve contenere gli elementi della fetta specificata dalla coppia
//letta)


/*
	PROVA DI CORRETTEZZA:
	
*/

/**
	TESTO ESERCIZIO:
scrivere un programma che apra i file "input" e "output", dichiari
un array int A[2][4][5] e legga da input 40 valori inserendoli in A per strati ed ogni strato 
viene riempito per righe. Quindi alla fine della lettura tutti gli elementi di A sono 
definiti.
Successivamente  il programma legge da "input"  un carattere  che potrà essere o 'H' 
o 'V' e poi legge un intero che, nel caso il carattere letto sia 'H', sarà tra 0 e 3, 
mentre, nel caso il carattere sia 'V', sarà tra 0 e 4. Insomma queste due letture 
individuano una delle possibile fette orizzontali o verticali. 
Per ultimo il programma deve stampare su "output" la sequenza degli elementi 
della fetta richiesta nell'ordine usato nell'esempio precedente, cioè procedendo 
dallo strato 0 allo strato 1. 
La pre- e post-condizioneche il programma deve, rispettivamente, assumere e 
rispettare sono le seguenti:
PRE=("input" contiene 40 interi, seguiti  o dalla coppia "H" x o dalla coppia 'V' y 
dove x sarà tra 0 e 3 e y tra 0 e 4)
POST=("output" deve contenere gli elementi della fetta specificata dalla coppia 
letta )
Correttezza: associate un invariante ed una post-condizione ad ogni ciclo del 
programma e dimostrate che i cicli sono corretti.
*/
