/*
    Feiv
    esercizio_2_2_3_2016.cpp        (Testo in fondo al file)
*/

#include<iostream>
using namespace std;

void set_false(bool* X)
{
	for(int i = 0; i < 8; i++)
		X[i] = false;
}


//PRE=( cin contiene almeno 48 interi )
int main()
{
	int A[6][8];
	bool B[8][6], X[8];
	
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 8; j++)
			cin >> A[i][j];

    //ciclo più eseterno di verifica funzione iniettiva
	for(int i = 0; i < 8; i++) {
	
		for(int j = 0; j < 6; j++) {
		    
			bool colok = true;
			set_false(X);
			
			for(int h = 0; h < 6 && colok; h++) {
			    
				bool trovato = false;
				
				for(int k = 0; k < 8 && !trovato; k++) {
					if( !X[k] && A[h][i] == A[j][k]) {
						trovato = true;
						X[k] = true;	
					}
				}
				
				if(!trovato) {
					colok = false;
					B[i][j] = false;
				}
			}
			
			if(colok)
				B[i][j] = true;
			
		}
		
	}
	
	for(int i = 0; i < 8; i++) {
	    for(int j = 0; j < 6; j++)
	        cout << B[i][j] << " ";
        cout << endl;
	}
	cout << "end" << endl;
	
	return 0;
}
//POST=()

/**
	PROVA DI CORRETTEZZA:
*/


/**
	TESTO ESERCIZIO:
	Esercizio 2 del 2/3/2016
Questo esercizio è una variazione dell'esercizio 1. Ci sono due array , int A [6][8] e bool B[8][6]. Notate che
ora B ha i limiti delle 2 dimensioni rovesciati rispetto ad A. In quest'esercizio il valore di ciascun elemento
B[i][j] deve rispettare la seguente proprietà:
(*) B[i][j] è true sse esiste una funzione iniettiva che per ogni elemento della colonna i di A fornisce
l'indice di un uguale valore nella riga j di A.
La richiesta che ci sia la funzione iniettiva implica che questa volta teniamo conto della numerosità degli
elementi, quindi se, per esempio, ci sono 3 elementi della colonna i con valore 5, per soddisfare la
condizione (*), la riga j di A deve contenere almeno 3 valori 5. E questo per tutti i valori distinti che
appaiono nella colonna i di A.
Si chiede di scrivere un programma che esegua le seguenti azioni:
1) Dichiari gli array , int A [6][8] e bool B[8][6].
2) legga in A 48 interi da cin inserendoli per riga (cioè prima riempie la riga di indice 0, poi quella d indice 1
e così via fino alla riga di indice 5).
3) assegni valori di tipo bool agli elementi di B in modo tale che, per ogni i in [0..7] e j in [0..5], il valore di
B[i][j] soddisfi la condizione (*)
4) stampi B per riga sul file "output" e come ultima cosa stampi anche "end".
Il programma deve rispettare le seguenti pre- e post-condizioni:
PRE=("input" contiene almeno 48 interi)
POST=("output" contiene i 48 valori 0/1 di B (stampati per riga) che rispettano la condizione specificata in
(*)).
Correttezza: Associare un invariante ed una post-condizione ad ogni ciclo. Dimostrare la correttezza dei 2
cicli più interni rispetto agli invarianti e alle post-condizioni che avete specificato per loro.
Consiglio: per verificare la condizione (*) può essere utile usare un array ausiliario X di 8 elementi che
attraverso appropriati valori (che dovete decidere voi, per esempio bool) potrà mostrare in ogni momento
la seguente proprietà: se stiamo verificando la proprietà (*) tra la colonna i e la riga j di A, e se stiamo
verificando se per A[z][i] c'è un corrispondente elemento della riga A[j], allora X[0..7] indicherà quali
elementi della riga A[j] sono stati usati per corrispondere agli elementi A[0..z-1] [i] già considerati e quali
elementi della riga A[j] sono ancora "liberi" per i restanti elementi A[z..5][i] della colonna i.
Uso dei file: Potete decidere di usare i file o meno nel vostro programma. La maniera di farlo è illustrata nel
file "come_usare_files.txt" in questo Moodle. I file sono spiegati nella Sezione 3.1.1 del libro di testo. L'uso
dei file può rendere l'i/o più semplice se lavorate sul vostro computer. Se invece lavorate direttamente nel
browser di moodle il programma deve fare i/o su cin/cout. Quindi dovrete togliere le istruzioni che
riguardano i file prima di consegnare il programma sul moodle.
*/
