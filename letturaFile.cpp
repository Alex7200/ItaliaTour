#include "letturaFile.h"

int leggiFile( paese &italia ){
    ifstream infile;
	char riga[MAX_CAR];
	char elemento[MAX_CAR];
    int countCampi;
	
    infile.open("citta.csv");
	if(!infile){
		MessageBoxA(NULL,"Impossibile aprire il file citta.csv assicurarsi di averlo inserito nella stessa directory dell'eseguibile!","ItaliaTour", MB_OK | MB_ICONERROR);
        return 0;
    }
	else{
        italia.numCitta = 0;
        
		infile.getline(riga,MAX_CAR);
		while(!infile.eof()){
            countCampi = 0;
            while(riga[0]){
                estraiElemento(riga,elemento);
                switch( countCampi ){
                    case 0:
                        strcpy( italia.citta[italia.numCitta].nomeCitta, elemento );
                        break;
                    case 1:
                        strcpy( italia.citta[italia.numCitta].nomeRegione, elemento );
                        break;
                    case 2:
                        italia.citta[italia.numCitta].abitanti = atoi( elemento );
                        break;
                    case 3:
                        italia.citta[italia.numCitta].superficie = atof( elemento );
                        break;
                    case 4:
                        italia.citta[italia.numCitta].coord.x = atof( elemento );
                        break;
                    case 5:
                        italia.citta[italia.numCitta].coord.y = atof( elemento );
                        break;
                    default:
                        break;
                }
                countCampi++;
            }
                
            italia.numCitta++;
				
            infile.getline(riga,MAX_CAR);
			}
			
        infile.close();
        return 1;
    }
}

void estraiElemento(char rigaIn[],char elemento[]){
	int i,j=0;
	int trovato=0;	//per segnalare il ritrovamento del carattere '\n' o ' '
	int k;
		
		//ricerca e copia
    for(i=0;rigaIn[i] && !trovato;i++){
        if( rigaIn[i] != CAR_SEPARATORE){
            elemento[j] = rigaIn[i];
            j++;
        }
        else
            trovato = 1;
    }
    elemento[j] = '\0';
		
    //eliminazione dell'elemento nella stringa
    for(k=0;rigaIn[i];k++,i++)
        rigaIn[k] = rigaIn[i];
    rigaIn[k] = '\0';
}