/*
 * feiv
 * 16/02/2016
 * esercizio1_10_11_2015.cpp
 * Consegna: https://elearning.studenti.math.unipd.it/labs/pluginfile.php/2322/mod_vpl/intro/Esercizio1_10_11_2015.pdf
 */
#include<iostream>
using namespace std;

const int MAXDIMT = 100;
const int MAXDIMP = 10;

//PRE=(cin contiene 0<dimT<=100 e 0<dimP<=10, seguite da dimT interi e poi ancora dimP interi)
int main(int argc, char **argv)
{
    int T[MAXDIMT], P[MAXDIMT], dimT, dimP;
    
    //lettura dimT
    cin >> dimT;
    /* Un metodo per fare in modo che il valore di dimT sia sempre 0<dimt<=100
    sarebbe quello di aggiungere qui sotto questa parte di codice:
    while(dimT <= 0 || dimt > 100)
        cin << dimT;
        
    Il Prof. però non vuole perchè nella precondizione è dato per scontato che 
    l'input del programma sia conforme a quello specificato nella PRE.
    */
    
    //lettura dimP
    cin >> dimP;
    
    //caricamento valori in T e P
    for(int i = 0; i < dimT; i++)
        cin >> T[i];
    
    for(int i = 0; i < dimP; i++)
        cin >> P[i];
    
    // Trovo i match di P in T
    int h, contatore_match = 0;
    bool trovato;
    
    for(int i = 0; i < dimT-dimP+1; i++) {
        h = i;
        trovato = true;
        
        for(int j = 0; j < dimP; j++, h++)  //potrei incrementare h dopo l'if. Si può fare anche dentro al for, come in questo caso
            if(T[h] != P[j])
                trovato = false;
        
        if(trovato)
            contatore_match++;
    }
    
    cout << "n. match = " << contatore_match <<endl;
    
    return 0;
}
