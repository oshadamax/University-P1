/**
 * Andrea FAvero
 * 20/10/2015
 * Scrivere un programma che legga 10
 * interi e ne calcoli la somma stampandola su schermo.
 */

#include<iostream>
using namespace std;

//1 PRE=(cin contiene almeno 10 interi)
main()
{
	int i=0, somma=0,x;
	while( i < 10 ) {	//R =(0<=i<=10, letti i valori da cin, somma contiene 
						// la somma dei valori letti)
		//cout << "Inserisci un intero: ";
		cin >> x;
		somma += x;
		i++;
	}
	cout<<"somma="<<somma<<endl;
}
//POST=(letti 10 interi da cin e somma e' la loro somma)


/**
	Dobbiamo dimostrare che R e' invariante,
	ovvero vale ogni volta che devo dimostare la condizione di permanenza
	
	1) consideriamo la prima volta: i = 0 soddisfa 0 <=i<=10, inoltre abbiamo
		letto 0 valori e, la somma di 0 valori e' 0

	2) SUPPONIAMO che R valga per i qualsiasi < 10, quindi eseguo il corpo del
		ciclo un'altra volta
		- facciamo una lettura in piu',  cioe' la (i=1)-esima
		- i aumenta di 1 quindi avro' letto i valori
		- aggiungo la lettura i-esima a somma che finora conteneva la somma delle
			prime i-1 letture
		- i < 10 all'inizio e quindi i=i+1, vale che i<=10
	3) R && (! i<10) => POST
		- !i<10 equivalente a i >=10, assieme a R ci dice che i = 10 quindi
			letti 10 valori da cin, somma contiene somma dei valori letti

*/

/*
Non dimostriamo che il programma termina, dimostrimo che se termina, è
corretto rispetto alla pre ed alla post*/
