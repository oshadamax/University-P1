/*
	Favero Andrea
	Esercizio Programmazione numero 4 dell'11/11/2015
	Stile di indentazione utilizzato K&R
*/

#include<iostream>
using namespace std;


/*PRE=( cin contiene almeno 2 valori interi. Il primo deve essere compreso tra
0 e 50, il secondo tra 0 e 10 )*/
int main(int argc, char const *argv[])
{
	const int RIGHE = 10;
	const int COLONNE = 5;
	const int COLONNE_VET = 10;
	int T[RIGHE][COLONNE], P[COLONNE_VET], dimT, dimP;


	cin >> dimT;
	cin >> dimP;

	int valdefriga = dimT % 5;	//numero di valori caricati nell'ultima riga se, questa non è piena del tutto
	int righepiene = dimT / 5;	//righe che contengono solo valori caricati

	//PRE=(cin contiene almeno righepiene valori)
	for (int i = 0; i < righepiene; i++)	//R=((0<=i<=righepiene) && (riempite righe[0..i-1] con 5 valori ) )
		for (int j = 0; j < COLONNE; j++)	//R=((0<=j<=COLONNE) && ((riempito T[i][0..j-1] con valori letti da cin))
			cin >> T[i][j];
	//POST=(riempite 0..righrpiene-1 righe di T con 5 valori letti da cin ciascuna)

	//nel caso in cui ci fossero altri elementi su una riga, mezza piena
	//PRE=(cin contiene almeno valdefriga valori)
	//R=((0<=i<=valdefriga) && (riempite T[righepiene][0..i] con valori letti da cin))
	for (int i = 0; i < valdefriga; i++)
		cin >> T[righepiene][i];
	//POST=(riempite 0..valdefriga-1 colonne di T alla riga righepiene)
	
	// caricamento array P
	//PRE=(cin contiene almento dimP valori)
	//R=((0<=i<=dimP) && (riempite 0..i-1 colonne con i valori letti da cin))
	for (int i = 0; i < dimP; i++)
		cin >> P[i];
	//POST=(caricati dimP valori in P)

	
	int colmaxmatch=-1, contmaxmatch=-1;
	int rigaultimacolonna = righepiene + 1;		
	/*
	 * faccio il pattern matching solamente dei blocchi di colonne (verticali)
	 *  che hanno un elemento in più rispetto alle altre*/
	/*
	 * R1=((0<=i<=valdefriga) && ( se i = 0  => colmaxmatch=-1 && contmaxmatch=-1) 
	 * && (se i>0 => esaminate le colonne da 0 a i/??-1??/ e colmaxmatch è la colonna tra queste con il massimo
	 * numero di match e, contmaxmatch è il massimo numero di match trovati*/
	/*
	 * R2=((0<=j<=((rigaultimacolonna-dimP)) && 
	 * (matcchcol > 0 se trovato 1 o più match nella colonna))*/
	//R3=((0<=h<=dimP)&&(trovatomatch <=> P[0..h-1]=T[j..j+h-1][i]))
	for(int i = 0; i < valdefriga; i++) {
		int matchcol = 0;
		//ciclo che scorre le righe di una colonna
		//PRE2=()
		for (int j = 0; j < rigaultimacolonna-dimP+1 ; j++) {
			bool trovatomatch=true;
			//faccio il match della colonna con l'array P
			//PRE=()
			for(int h=0; (h < dimP) && trovatomatch;h++)
				if (P[h]!=T[j+h][i])
					trovatomatch = false;
			//POST3=(trovatomatch => P[0..h-1]=T[j..jdimP-1][i])
			if (trovatomatch)
				matchcol++;
		}
		//POST2=(matchcol > 0 se trovato match = true e quindi, ho trovato 1 o più match nella colonna)
		if (matchcol > contmaxmatch) {
			contmaxmatch = matchcol;
			colmaxmatch = i;
		}
	}
	//POST1=(colmaxmatch contiene il numero della colonne (se esiste) con il maggior numero di occorrenze)

	//SIMILE A SOPRA
	for (int i = valdefriga; i < 5; i++) {
		int matchcol = 0;
		//ciclo che scorre le righe di una colonna
		for (int j = 0; j < (righepiene)-dimP; j++) {
			bool trovatomatch=true;
			//faccio il match della colonna con l'array di p
			for(int h=0; (h < dimP) && trovatomatch;h++)
				if (P[h]!=T[j+h][i])
					trovatomatch = false;
			if (trovatomatch)
				matchcol++;
		}
		if (matchcol > contmaxmatch) {
			contmaxmatch = matchcol;
			colmaxmatch = i;
		}
	}


	cout << "la miglior colonna e' " << colmaxmatch << " con " << contmaxmatch << " match";
	
	return 0;
}
//POST=(colmaxmatch contiene il numero della colonna di T che ha il massimo numero di match contigui e completi di P)

/*
		PROVA DI CORRETTEZZA R3
		Dimostrazione del ciclo interno
		1) All'inizio 
		-- test vero posto che P[0..h-1]==T[j..j+h-1][i]
			h=0 e trovatomatch = true qui3ndi R3 vale perchè h <= 0 e P[h]=T[j+h-1][i]
		--test falso posto che P[0..h-1] != T[j..j+h-1][i]
			h=0 e trovatomatch = false perchè h <= 0 ma P[h]!=T[j+h-1][i]
		2) invarianza di R3
		h=2 && trovatomatch {corpo del ciclo} R3
		--test vero P[h]==T[j+h][i]  => test vero, il valore della colonna T[j+h][i] è uguale al valore
			di P[h]
		--test falso P[h]!=T[j+h][i] => test falso, il valore della colonna T[j+h][i] non è uguale al valore
			di P[h] e quindi il match non è possibile

		3) All'uscita: Basta sostituire 3 a h per avere POST3:
		Nella stringa è stato trovato un match perchè ho comparato 1 ad uno gli elementi delle 2 strutture dati ed
		è verificata la condizione di POST 
		P[0..h-1]=T[j..jdimP-1][i])
		
 */
