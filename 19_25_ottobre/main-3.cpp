/**
 * Andrea Favero
 * 3/11/2015
 * Esercizio numero 3
 * Leggere da cin fino a che non venga letto un valore sentinella (0) e
 * calcolare la somma dei valori letti.
 */
#include<iostream>
using namespace std;

//PRE=(cin contiene almeno un valore 0)
int main()
{
	int n, somma = 0;
	cin >> n;
	
	/**
	 * R=(letti a valori e somma contiene la somma dei primi
	 * a-1 valori. L'ultima lettura è in n )
	 */
	while(n) {
		somma += n;
		cin >> n;
	}

	cout << "somma=" << somma << endl;
	return 0;
}
//POST=(somma contiene la somma degli a valori letti che precedono lo 0)

/**
DIMOSTRAZIONE INVARIANTE
1) SUPPONIAMO che sia stato letto per primo un numero uguale a 0.
	0 è la sentinella e quindi non è un valore accettato per la somma.
	Ho letto un solo valore a e quindi non considero nessun valore per la somma,
	a-1 = 0
2) SUPPONIAMO vengano letti uno o più valori diversi da 0. somma in questo
	caso assume il suo valore precedente sommato all' a-esimo valore letto
3) SUPPOSTO CHE 2 sia verificata e che venga letto un valore 0, somma è uguale
	al valore a-1 letto. somma quindi contiene la somma di tutti i valori letti
	esclusa la sentinella (0).
*/
