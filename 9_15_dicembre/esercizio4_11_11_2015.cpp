#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	const int RIGHE = 10;
	int T[RIGHE][5], P[10], dimT, dimP;

	cin >> dimT;
	cin >> dimP;



	//numero di elementi di una riga che ha valori indefiniti
	// e i miei valori
	int valdefriga = dimT % 5;
	int righepiene = dimT/5;

	

	for (int i = 0; i < righepiene; i++)
		for (int j = 0; j < 5; j++)
			cin >> T[i][j];

	//nel caso in cui ci fossero altri elementi su una riga, mezza piena
	for (int i = 0; i < valdefriga; i++)
		cin >> T[righepiene][i];
		
	// caricamento array
	for (int i = 0; i < dimP; i++)
		cin >> P[i];
	


	int colmaxmatch=-1, cmaxmatch=0; 
	//scorro solo le colonne che hanno lunghezza maggiore
	for (int i = 0; i < valdefriga; i++) {
		int matchcol = 0;
		//ciclo che scorre le righe di una colonna
		for (int j = 0; j <= (righepiene + 1)-dimP; j++) {
			cout << "Sono entrato nel ciclo"<<endl;
			bool trovatomatch=true;
			//faccio il match della colonna con l'array di p
			for(int h=0; (h < dimP) && trovatomatch;h++)
				if (P[h]!=T[j+h][i])
					trovatomatch = false;
			if (trovatomatch)
				matchcol++;
		}
		if (matchcol > cmaxmatch) {
			cmaxmatch = matchcol;
			colmaxmatch = i;
		}
	}


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
		if (matchcol > cmaxmatch)
			cmaxmatch = matchcol;
			colmaxmatch = i;
	}


	cout << "la miglior colonna e' " << colmaxmatch << " con " << cmaxmatch << " match";

	return 0;
}
