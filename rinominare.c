/*Software per il calcolo del giorno dell'angelo secondo il calendario gregoriano e giuliano */
/*A cura di: Leone, Trani Uniurb, L-31 (Dipartimento delle scienze pure ed applicate)        */
/*sessione invernale di programmazione procedurale a.a 2023-2024                             */

/************************************/
/*SPECIFICA DEL PROBLEMA:           */
/*-Mettere il testo integrale qui-  */
/************************************/										




/*Inclusione delle librerie*/
/********************************************************************************************************/
/*<stdio.h> : necessaria per gestire le operazioni di input/output                                      */
/*<stdlib.h>: necessaria per la lettura del file binario, shift binario delle configurazioni esadecimali*/
/*<string.h>: liberiria necessaria per la gestione delle stringhe                                       */
/********************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*definizione delle costanti simboliche*/
/********************************************************************************************************************************/
/*ULTIMA_REV : costante adibita al contenimento della data dell'ultima modificz apportata al software                           */
/*OUTPUT_CHAR: costante simbolica di tipo carattere atta a contenere il carattere designagto per l'output dei caratteri giganti */
/*FONT_FILE  : costante simbolica di tipo array di caratteri atto a contenere il nome del file binario utilizzato               */
/********************************************************************************************************************************/


#define ULTIMA_REV "02/02/24"
#define OUTPUT_CHAR '#'
#define FONT_FILE "8x5.bin"




/*prototipi delle funzioni coinvolte*/
short int menu();
short int validaInt(char msg[]); 
void calcolaAngelo(short int anno);
void outputGigante(char *data);
char *gaussFormula(short int m, short int n, short int anno);




/*funzione main*/
/*************************************************************/
/*Funzione principale, nessun parametro in ingresso*/

int main()
{

	short int scelta, anno;                          /*variabili di input, adibite rispettivamente alla memroizzazione della scelta dell'utente per percorrere il menu, memorizzazione dell'anno interessato*/
	printf("<Software per il calcolo del giorno del lunedì dell'angelo>");
        do{                      

	scelta = menu();                                /*assegnazione della scelta, in funzione della procedura adibita al menu, descritta successivamente*/
	switch(scelta){

		case 1:                                                                                                                                           /*scelta uno: blocco dedicato al calcolo del giorno dell'angelo proponendo l'inputazione all'utente*/
			do{

                           anno = validaInt("   --> Inserire in numeri l'anno di riferimento (tra il 1900 e il 2099 inclusi): ");                                 /*assegnazione dell'anno avvalendosi della funzione validaInt per la validazione stretta dell'input*/

			}while((anno<1900)||(anno >2099));                                                                                                        /*verifica del valore contenuto nella variabile anno*/
			calcolaAngelo(anno);                                                                                                                      /*utilizzo della procedura calcolaAngelo, adibita a presentare i risultati*/
			break;

		case 2:                                                                                                                                           /*scelta due: stampa di informazioni ausiliari*/
			
			printf("\n\n>IaaaNFORMAZIONI SUL SOFTWARE: il seguente applicativo ha la pretesa di computare la data del giorno dell'angelo, secondo il calendario gregoriano \n");
			printf("\t\t\t    e giuliano. Per raggiungere tale scopo, si sfrutta la formula di Gauss, teorizzata nella meta' del XX secolo.  Gli anni\n");
			printf("\t\t\t    sono quelli intercorrenti tra il XX ed il XXI secolo. L'output delle due date computate, è effettuato attraverso l'utilizzo\n");
			printf("\t\t\t    di caratteri giganti composti da caratteri ASCII (%c), le cui fattezze sono espresse in un file separato, in modo da facilitare\n", OUTPUT_CHAR);
			printf("\t\t\t    eventuali manovre di manutenzione.  \n\n");
			printf("	----------------------------------------------------------\n\n");
			printf("Sviluppato da Trani e Leone, Universita' degli studi di Urbino - INFORMATICA APPLICATA (L31),\n dipartimento delle scienze pure e applicate, A.A 2023-2024. Ultima revisione: %s\n\n", ULTIMA_REV);
			break;
                      


	}
       } while(scelta != 0);                                                                                                                                      /*scelta zero: uscita*/



	return 0;

}






/* funzione menu */
/*procedura con ritorno short int, atta a presentare e gestire il menu */


short int menu(){

	short int opt;                                                                                             /*variabile di input, atta a contenere l'opzione selezionata dopo che sono state presentate all'utente*/
        
	
	printf("\n-----------------------------------------------------------------\n");
        printf("<1> Ricerca del giorno dell'angelo per data (1900 -2099)\n");                                      /*stampa delle opzioni contemplate */
	printf("<2> informazioni sul software\n");
	printf("<0> Uscita dal software\n----------------------------------------------------------\n\n");
        
	do{

	    opt = validaInt("   --> Inserire il numero corrispondente all'operazione desiderata:");	         /*validazione stretta di quanto immesso servendosi dell'apposita funzione validaInt */
	
	}while ((opt > 2)||(opt < 0));                                                                           /*verifica del range del valore*/

        return opt;

}

/*funzione validaInt*/
/*procedura con ritorno short int, adibita al corretto inserimento dei dati.*/
/*parametri in ingresso: */
/*char_msg: stringa contenente il messaggio da presentare ad ogni chiamata */




short int validaInt(char msg[]){

	short int dati;                                                  /*variabile di input atta a rappresentare i dati immessi dall'utente */
	short int  validato_flag;                                        /*variabile di lavoro, atta a verificare la correttezza dei dati immessi, assegnata ad ogni chiamata della funzione di input scanf */
	do{                                                            
         
         	printf("\n%s", msg);		                         /*stampa del messaggio passato come input alla funzione */
        	validato_flag = scanf("%hd", &dati);                     /*verifica della correttezza dei dati immessi           */
		
	        while(getchar() != '\n');                                /*pulizia del buffer stdin*/

	}while (validato_flag != 1);                                     /*in caso di mancato riscontro sulla correttezza, ripetere di nuovo il blocco*/
	return dati;
        
}




/*funzione calcolAngelo*/
/*parametri di ingresso:*/
/*short int anno: parametro atto a proporre alla procedura l'anno da computare*/

void calcolaAngelo(short int anno){
        
     
	
        printf("\n > Giorno dell'angelo dell'anno %hd, calendario gregoriano: \n\n", anno);        /*presentazione della stampa del giorno dell'angelo secondo il calendario gregoriano*/	 
	outputGigante(gaussFormula(24, 5, anno));
	printf("----------------------------------------------------\n\n > Giorno dell'angelo dell'anno %hd, calendario giuliano \n\n", anno);   /*presentazione della stampa del giorno dell'angelo secondo il calendario giuliano*/
	outputGigante(gaussFormula(15, 6, anno));
	      
	

}

/*funzione outputGigante*/
/*procedura senza ritorno atta a mostrare a schermo con caratteri giganti (matrice da 5x5 caratteri) la data computata grazie all'algoritmo di gauss descritto nella funzione gaussformula*/
/*parametri in ingresso: */
/*char_data_lun_angelo[]: stringa adibita al contenimento di quanto computato precedentemente e trasposto sotto forma di caratteri, nella procedura gaussFormula */

void outputGigante(char data_lun_angelo[]){
       
	FILE* bitmap = fopen(FONT_FILE, "rb");    														/*apertura del file binario, in modalità lettura binaria, attraverso file pointer (variabile di input) */
        int data_gigante[6][5];																	/*matrice di interi adibita alla lettura dal file binario                 (variabile di input/output) */	
	short int apr[3] = {11, 13, 14};                                                                                                                        /*array di short int, atti a definire le posizioni nel file binario di ciascuno dei 3 caratteri, per entrambi i mesi contemplati*/
	short int mar[3] = {12, 11, 14};                                                                                         
	short int j,b, pixel;                                                                                                                                   /*variabili di lavoro utili nel blocchi di codice iterativi */
        int i = 0;
                 
	if(bitmap){
               
			
                
			if( strlen(data_lun_angelo) == 2 ){                                                                                                     /*controllo della lunghezza del parametro di ingresso. Qualora uguale a due, vorrà dire che ci sarà una sola cifra destinata al giorno, pertanto si procede a prelevare anche il carattere zero da anteporre rispettivamente*/
			  			fseek(bitmap, 0, SEEK_SET);                                                                                     /*prima di eseguire una lettura, spostare il file pointer nella posizione interessata. Il carattere zero è memorizzato nei primi 5 byte del file binario*/

			  	            	while((fread(data_gigante[i], sizeof(int), 5, bitmap)) && (i < 2)){                                             /*lettura eseguita attraverso un ciclo while in modo da gestire eventuali errori*/
						        fseek(bitmap, (data_lun_angelo[i])*5*sizeof(int), SEEK_SET);
							i++;
						}
					        					
					  	
			}
			else
			{  	
		              
			fseek(bitmap, (data_lun_angelo[i])*5*sizeof(int), SEEK_SET);
                	        while(fread(data_gigante[i], sizeof(int), 5, bitmap)&&(i < 2)){                                                                   /*lettura dei primi due caratteri, qualora il giorno del mese non sia inferiore a 10*/
				   i++;
				   fseek(bitmap, (data_lun_angelo[i])*5*sizeof(int), SEEK_SET);	 
				}
			
			
			            
              		}
							
               fseek(bitmap, 50, SEEK_SET);                                                                                                                     /*lettura del carattere spazio, presente in posizione 10 (5 byte moltiplicato per 10) */
	       if(!fread(data_gigante[2], sizeof(int), 5, bitmap)){
		printf("errore");	
		}
	       
		i = 0;
		if(data_lun_angelo[strlen(data_lun_angelo) - 1] == 3){                                                                                           /*analisi dell'ultimo carattere della stringa passata come ingresso alla funzione. Qualora uguale a tre, si procede con la stampa di marzo, altrimenti si tratta di aprile */
               		fseek(bitmap, mar[i] * 5 *sizeof(int), SEEK_SET);
			       
			while(fread(data_gigante[3+i], sizeof(int), 5, bitmap) && (i < 2)){
			   i++;	
			   fseek(bitmap, mar[i] * 5 * sizeof(int), SEEK_SET);
			   
			}
			
		}else{
			fseek(bitmap, apr[i] * 5 * sizeof(int), SEEK_SET);                                                                                      /*si utilizza la stessa logica utilizzata in precedenza */
			
			while(fread(data_gigante[3 + i], sizeof(int), 5, bitmap) && (i < 2)){
			i++;  
			fseek(bitmap, apr[i] * 5 * sizeof(int), SEEK_SET);
			  
			}                      
		}

									          
               for (i = 0; i < 5; i++){


		       for (j = 0; j < 6; j++){
 
			       for(b = 0; b < 8; b++){
					
			       		pixel = data_gigante[j][i] & 1 << (7-b);  
					printf("%c", pixel ? OUTPUT_CHAR : ' ');		                    /*con cicli nidificati si procede ora con la stampa dei caratteri giganti, in particolare si stampa la prima riga di ogni carattere gigante, la quale viene determinata grazie a uno shift binario. Dopo aver stampato la riga, si va a capo */

			       }


		       }

		       printf("\n");

		}

	}else{
		printf("errore");
	}  
free(data_lun_angelo);                                                                              /*rilascio della memoria allocata dinamicamente e chiusura del file binario */
fclose(bitmap);

}



/*funzione gaussFormula*/
/*procedura atta a computare la data del lunedì dell'angelo al variare dei tre parametri in input */


char *gaussFormula(short int m, short int n, short int anno) {

	short int a, b, c, d, e, mese, giorno;            /*variabili di lavoro, utili per effettuare i calcoli e trasporre i risultati in una stringa da ritornare */
	char mese_str[4];                                 /*stringa atta a contenere il mese*/                   
	char date_str[4];                                 /*stringa atta a contenere la data*/
	char *ris = malloc(5 * sizeof(char));             /*stringa risultante, unisce la data e il mese [data, mese]*/
        int i;        
              
	a = anno % 19;                                    /*algoritmo di gauss*/
	b = anno % 4;
	c = anno % 7;

	d = ((19 * a) + m) % 30;
	e = ((2 * b) + (4 * c) + (6 * d) + n) % 7;

	if ((d + e) < 10){

		mese = 3;
		giorno = d + e + 22;

	}else{

               mese = 4;

	       if (( d + e - 9) == 26){

                        giorno = 19;
	       }else{
	       
	       
	     
	       if ((d == 28 )&&(e == 6)&&( a > 10)){
			giorno = 18;
	       }else{
	      		 giorno = d + e - 9;

	       }

	}

}	

        sprintf(mese_str, "%hd", ((giorno+1)/31==1) ? 4 : mese );                                         /*trasposizione del mese computato in stringa, corretto qualora il giorno sia uguale a 32 tramite operatore condizionale */
	sprintf(date_str, "%hd", ((short int)giorno + 1)%31 ? ((short int)giorno + 1)%31 : 31);           /*trasposizione del giorno computato in stringa, corretto qualora uguale a 32, attraverso operatore modulo e condizionale */
	strcpy(ris, date_str);                                               
	strcat(ris, mese_str);                                                                            /*concatenzazione delle due stringhe risultanti */

	for(i=0; i<strlen(ris); i++){
	
			ris[i] = ris[i] - '0';                                                              /*privazione dei valori aggiuntivi contenuti nella stringa del risultato, in quanto si tratta di caratteri */
	        	
        
	}

        
        return ris;	

}


