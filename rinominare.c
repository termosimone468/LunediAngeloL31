/**********************************************************************************************/
/* Software per il calcolo del Lunedi dell'angelo secondo il calendario gregoriano e giuliano */
/* A cura di */
/*   Corso di laurea L-31 - sessione invernale - programmazione procedurale a.a. 2023-2024    */
/**********************************************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************/
/* definizione delle costanti simboliche */
/*****************************************/

#define ULTIMA_REV   "04/02/24"  /* data dell'ultima modifica apportata al software */
#define OUTPUT_CHAR  '*'         /* carattere designato per l'output dei caratteri giganti */
#define FONT_FILE    "8x5.bin"   /* contenitore del file binario utilizzato */


/*******************************/
/* dichirazione delle funzioni */
/*******************************/

short int menu();
short int valida_int(char msg[]); 
void calcola_angelo(short int anno);
void output_gigante(char *data);
char *formula_gauss(short int m,
                    short int n,
                    short int anno);

/***********************************/
/* definizione della funzione main */
/***********************************/

int main(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  short int scelta, /* lavoro: risultato della scelta ritornato dalla funzione menu */
            anno;   /* input: anno scelto dall'utente */

  /* Acquisizione e validazione della scelta inerente al menu iniziale */
  printf("\n<Software per il calcolo del giorno del Lunedì dell'Angelo>\n");
  do
  {                      
    scelta = menu();
      switch(scelta)
      {
        case 1:
          do
          {	
            anno = valida_int("Attenzione: Inserisci un anno compreso fra il 1900 e il 2099:\n");
          }
          while((anno < 1900)||(anno > 2099));
        calcola_angelo(anno);
          break;
        case 2: 
          printf("INFORMAZIONI GENERALI: il software calcola la data del Lunedi dell'Angelo\n");
          printf("secondo il calendario gregoriano e secondo il calendario giuliano. Questo\n");
          printf("è reso possibile grazie alla formula di  Gauss, teorizzata nel XX secolo.\n");
          printf("Gli anni computabili dal software vanno dal 1900  al 2099. L'output delle\n");
          printf("date è effettuato attraverso l' utilizzo di caratteri giganti composti da\n");
          printf("caratteri ASCII (%c), le cui fattezze sono espresse in un file, per poter\n",
                 OUTPUT_CHAR);
          printf("facilitare l'eventuale manovra di manutenzione.");
          printf("\nSviluppato da Pietro Leone e Cosimo L. Trani. Ultima revisione: %s\n",
                 ULTIMA_REV);
          break;
      }
  }
  while(scelta != 0);
  return(0);
}

/* Definizione della funzione menu */
short int menu()
{
  /* Dichiarazioni delle variabili locali alla funzione */
  short int opzione_menu; /* input: scelta dell'utente all'interno del menu */
  /* elenco delle scelte presenti nel menu */
  printf("\n<1> Ricerca del giorno del Lunedi dell'angelo inserendo un anno (1900 -2099)\n"); 
  printf("<2> Informazioni generali sul software\n");
  printf("<0> Uscita dal software\n");
        
  /* validazione stretta della scelta */
  do
  {
    opzione_menu = valida_int("Attenzione: Inserisci un numero compreso fra 0 e 2:\n");
  }
  while ((opzione_menu > 2)||(opzione_menu < 0));
  return(opzione_menu);
}

/* Definizione della funzione valida_int */
short int valida_int(char msg[])  /* output: messaggio da presentare ad ogni chiamata */
{
  /* Dichiarazioni delle variabili locali alla funzione */
  short int  dati;      /* input: variabile generica per acquisizione e validazione */
  short int  validato;  /* lavoro: esito complessivo dell'acquisizione */
  do
  {                                                            
    printf("\n%s",
           msg);
    validato = scanf("%hd",
                     &dati);
		
  while(getchar() != '\n');
  }
  while (validato != 1);
  return(dati);
}
/* Definizione della funzione calcola_angelo */
void calcola_angelo(short int anno)  /* input: anno da computare */
{
  /* Stampa dei due Lunedi dell'Angelo */
  printf("\n > Lunedi dell'Angelo dell'anno %hd, calendario gregoriano: \n\n",
         anno);	 
  output_gigante(formula_gauss(24,
                               5,
                               anno));
  printf("\n\n > Lunedi dell'Angelo dell'anno %hd, calendario giuliano: \n\n",
         anno);
  output_gigante(formula_gauss(15,
                               6,
                               anno));
	      
}

/* Definizione della funzione output_gigante */
void output_gigante(char data_lun_angelo[])  /* lavoro: risultato funzione formula_gauss */
{
  /* Dichiarazione delle variabili locali alla funzione */
  FILE* bitmap = fopen(FONT_FILE,   /* input: file binario e contestuale apertura in  */
                       "rb");       /* modalita' lettura binaria tramite file pointer */

  int       data_gigante[6][5];     /* input/output:lettura file binario */	
  short int apr[3] = {11, 13, 14};  /* lavoro: posizione dei caratteri APR nel file binario */                
  short int mar[3] = {12, 11, 14};  /* lavoro: posizione dei caratteri MAR nel file binario */
  short int j,                      /* lavoro: indice di scorrimento per stampa caratteri giganti */
            b,                      /* lavoro: indice di scorrimento per stampa caratteri giganti */
            pixel;                  /* lavoro: controllo per stampa del carattere designato */
        int i = 0;                  /* lavoro: indice di scorrimento per stampa caratteri giganti */
  /* inserimento dello 0 alla 2a cifra decimale qualora il giorno del mese sia < 10 */
  if(bitmap)
  {
    if( strlen(data_lun_angelo) == 2 )
    {
      fseek(bitmap, 		
            0,
            SEEK_SET);  /* spostamento del file pointer */                                       

        while((fread(data_gigante[i], sizeof(int), 5, bitmap))&& (i < 2))
        {
          fseek(bitmap,
                (data_lun_angelo[i]) * 5 * sizeof(int),
                SEEK_SET);
          i++;
        }
      }
      else
      {
      /* lettura dei primi due caratteri */
      fseek(bitmap,
            (data_lun_angelo[i]) * 5 * sizeof(int),
            SEEK_SET);
        while(fread(data_gigante[i], sizeof(int), 5, bitmap)&&(i < 2))
        {
           i++;
           fseek(bitmap,
                 (data_lun_angelo[i]) * 5 * sizeof(int),
                 SEEK_SET);	 
        }
      }
              /* lettura dello spazio presente fra i giorni e il mese */
              fseek(bitmap,
                    50,
                    SEEK_SET);
      if(!fread(data_gigante[2],
                sizeof(int),
                5,
                bitmap))
      {
        printf("errore");	
      }
    i = 0;
    /* selezione del mese di riferimento */
    if(data_lun_angelo[strlen(data_lun_angelo) - 1] == 3)
    {
      fseek(bitmap,
            mar[i] * 5 *sizeof(int),
            SEEK_SET);
      while(fread(data_gigante[3+i], sizeof(int), 5, bitmap) && (i < 2))
      {
         i++;	
         fseek(bitmap,
               mar[i] * 5 * sizeof(int),
               SEEK_SET);
      }
    }
    else
    {
    fseek(bitmap,
          apr[i] * 5 * sizeof(int),
          SEEK_SET);
      while(fread(data_gigante[3 + i], sizeof(int), 5, bitmap) && (i < 2))
			{
        i++;  
        fseek(bitmap,
              apr[i] * 5 * sizeof(int),
              SEEK_SET);
      }                      
    }
    /* stampa caratteri giganti */
    for (i = 0; i < 5; i++)
    {
      for (j = 0; j < 6; j++)
      {
        for(b = 0; b < 8; b++)
        {
          pixel = data_gigante[j][i] & 1 << (7 - b);  
          printf("%c",
                 pixel ? OUTPUT_CHAR : ' ');
        }
      }
        printf("\n");
    }
  }
  else
  {
    printf("errore");
  }
  /* rilascio della memoria allocata dinamicamente e chiusura del file binario */  
  free(data_lun_angelo);
  fclose(bitmap);
}
/* Definizione della funzione formula_gauss*/
char *formula_gauss(short int m,    /* input: variabile formula di Gauss */
                    short int n,    /* input: variabile formula di Gauss */
                    short int anno) /* input: anno scelto dall'utente */
{
  short int a,      /* lavoro: variabile formula di Gauss */
            b,      /* lavoro: variabile formula di Gauss */
            c,      /* lavoro: variabile formula di Gauss */
            d,      /* lavoro: variabile formula di Gauss */
            e,      /* lavoro: variabile formula di Gauss */
            mese,   /* lavoro: variabile formula di Gauss */
            giorno; /* lavoro: variabile formula di Gauss */
  char mese_str[4];                       /* stringa contenente il mese */                   
  char giorno_str[4];                     /* stringa contenente il giorno */
  char *ris = malloc(5 * sizeof(char));   /* stringa risultante, giorno e mese */
  int  i;                                 /* indice di scorrimento della stringa finale */
  /* Applicazione algoritmica della formula di Gauss */
  a = anno % 19;
  b = anno % 4;
  c = anno % 7;

  d = ((19 * a) + m) % 30;
  e = ((2 * b) + (4 * c) + (6 * d) + n) % 7;

  if ((d + e) < 10)
  {
    mese = 3;
    giorno = d + e + 22;
  }
  else
  {
    mese = 4;
    if (( d + e - 9) == 26)
    {
      giorno = 19;
    }
    else
    {
      if ((d == 28 )&&(e == 6)&&( a > 10))
      {
        giorno = 18;
      }
      else
      {
        giorno = d + e - 9;
      }
    }
  }	
  /* Stampa 1 aprile qualora la data da stampare sia immediatamente successiva al 31 marzo */
  sprintf(mese_str,
          "%hd",
          ((giorno + 1) / 31 == 1) ? 4 : mese );                                         
  sprintf(giorno_str,
          "%hd",
          ((short int)giorno + 1) % 31 ? ((short int)giorno + 1) % 31 : 31);
  strcpy(ris,
         giorno_str);
  /* Concatenazione di giorno e mese */                                              
  strcat(ris,
         mese_str);
  for(i=0; i<strlen(ris); i++)
  {
    ris[i] = ris[i] - '0';
  }
  return (ris);	
}
