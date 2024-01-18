#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void bootstrap();
short int menu();
short int validaInt(char msg[]); 
void calcolaAngelo(short int anno);
void outputGigante(char *data);
char *gaussFormula(short int m, short int n, short int anno);

#define ULTIMA_REV "18/01/24"
#define OUTPUT_CHAR '#'
#define FONT_FILE "8x5.bin"



int main()
{

	short int scelta, anno;

	bootstrap();
        do{

	scelta = menu();
	switch(scelta){

		case 1: 
			do{

                           anno = validaInt("   --> Inserire in numeri l'anno di riferimento (tra il 1900 e il 2099 inclusi): ");

			}while((anno<1900)||(anno >2099));
			calcolaAngelo(anno);
			break;

		case 2: 
			
			printf("\n\n>INFORMAZIONI SUL SOFTWARE: il seguente applicativo ha la pretesa di computare la data del giorno dell'angelo, secondo il calendario gregoriano \n\t\t\t    e giuliano. Per raggiungere tale scopo, si sfrutta la formula di Gauss, teorizzata nella meta' del XX secolo.  Gli anni\n\t\t\t    sono quelli intercorrenti tra il XX ed il XXI secolo. L'output delle due date computate, è effettuato attraverso l'utilizzo\n\t\t\t    di caratteri giganti composti da caratteri ASCII (%c), le cui fattezze sono espresse in un file separato, in modo da facilitare\n\t\t\t    eventuali manovre di manutenzione.  \n\n----------------------------------------------------------\n\nSviluppato da Trani e Leone, Universita' degli studi di Urbino - INFORMATICA APPLICATA (L31),\n dipartimento delle scienze pure e applicate, A.A 2023-2024\n\n", OUTPUT_CHAR);
			break;
                      


	}
       } while(scelta != 0);
}

void bootstrap(){


printf("\n\n      |V|          '||'                                     '||   ||      |                              '||                 -=-      \n");
printf("   .::| |::.        ||       ... ...  .. ...     ....     .. ||  ...     |||    .. ...     ... .   ....   ||    ...       (\  _  /)   \n");
printf("  ::__| |__::       ||        ||  ||   ||  ||  .|...||  .'  '||   ||    |  ||    ||  ||   || ||  .|...||  ||  .|  '|.     ( \( )/ )   \n");
printf(" >____   ____<      ||        ||  ||   ||  ||  ||       |.   ||   ||   .''''|.   ||  ||    |''   ||       ||  ||   ||     (       )   \n");
printf("  ::  | |  ::      .||.....|  '|..'|. .||. ||.  '|...'  '|..'||. .||. .|.  .||. .||. ||.  '||||.  '|...' .||. '|..|'       `>   <'    \n");
printf("   '::| |::'                                                                                   .|....'                     /     \    \n");            
printf("      | |          ##################################################################################################      `-._.-'    \n");
printf("      | |          ##################################################################################################                 \n");
printf("      |A|                                                                                                                             \n\n");

printf("------------------- Software per il calcolo del giorno dell'angelo tra il XX e il XXI secolo. Ultima revisione: %s. ------------------\n", ULTIMA_REV);

if(access(FONT_FILE, R_OK) == -1){

	printf("> ERRORE: il file \"%s\" risulta danneggiato o assente. Si procede con il ripristino automatico della risorsa ai valori originali", FONT_FILE);
	system("./genera_bmpf");
	printf("\n> Risorsa caricata correttamente");
}


}





short int menu(){

	short int opt;
        
	
	printf("\n-----------------------------------------------------------------\n");
        printf("<1> Ricerca del giorno dell'angelo per data (1900 -2099)\n");
	printf("<2> informazioni sul software\n");
	printf("<0> Uscita dal software\n----------------------------------------------------------\n\n");
        
	do{

	    opt = validaInt("   --> Inserire il numero corrispondente all'operazione desiderata:");	
	
	}while ((opt > 2)||(opt < 0));

        return opt;

}

short int validaInt(char msg[]){

	short int dati;
	short int  validato_flag;
	do{
         
         	printf("\n%s", msg);		
        	validato_flag = scanf("%hd", &dati);
		
	        while(getchar() != '\n');

	}while (validato_flag != 1);
	return dati;
        
}

void calcolaAngelo(short int anno){
        
     
	
        printf("\n > Giorno dell'angelo dell'anno %hd, calendario gregoriano: \n\n", anno);	 
	outputGigante(gaussFormula(24, 5, anno));
	printf("----------------------------------------------------\n\n > Giorno dell'angelo dell'anno %hd, calendario giuliano \n\n", anno);
	outputGigante(gaussFormula(15, 6, anno));
	      
	

}

void outputGigante(char data_lun_angelo[]){
       
	FILE* bitmap = fopen("8x5.bin", "rb");
        int data_gigante[6][5];
	short int apr[3] = {11, 13, 14};
	short int mar[3] = {12, 11, 14};
	short int j,b, pixel;
        int i = 0;
                 
	if(bitmap){
               
			if ( i <  2){
                
					if( strlen(data_lun_angelo) == 2 ){
			  			fseek(bitmap, 0, SEEK_SET);
			  			fread(data_gigante[0], sizeof(int), 5, bitmap);
					  	fseek(bitmap, (data_lun_angelo[0])*5*sizeof(int), SEEK_SET);
		         			fread(data_gigante[1], sizeof(int), 5, bitmap);
			 		 	i = i + 2;
			}else{  	
		
				fseek(bitmap, (data_lun_angelo[0])*5*sizeof(int), SEEK_SET);
                		fread(data_gigante[0], sizeof(int), 5, bitmap);
			
				fseek(bitmap, (data_lun_angelo[1])*5*sizeof(int), SEEK_SET);
                			fread(data_gigante[1], sizeof(int), 5, bitmap);
			            
              				 }
				
    
			}
					
					
               fseek(bitmap, 50, SEEK_SET);
	       fread(data_gigante[2], sizeof(int), 5, bitmap);
		i++;
		if(data_lun_angelo[strlen(data_lun_angelo) - 1] == 3){
                      
			for (i = 0; i < 3; i++){
				
			   fseek(bitmap, mar[i] * 5 * sizeof(int), SEEK_SET);
			   fread(data_gigante[3 + i], sizeof(int), 5, bitmap);
			}
			
		}else{

			for (i = 0; i < 3; i++){
			  fseek(bitmap, apr[i] * 5 * sizeof(int), SEEK_SET);
			  fread(data_gigante[3 +i ], sizeof(int), 5, bitmap);
			}
                      
                      
		}

									          
               for (i = 0; i < 5; i++){


		       for (j = 0; j < 6; j++){
 
			       for(b = 0; b < 8; b++){
					
			       		pixel = data_gigante[j][i] & 1 << 7-b;   //and logico del bit esaminato attraverso shift binario
					printf("%c", pixel ? OUTPUT_CHAR : ' ');		

			       }


		       }

		       printf("\n");

		}

	}else{
		printf("errore");
	}  
free(data_lun_angelo);
fclose(bitmap);

}


char *gaussFormula(short int m, short int n, short int anno) {

	short int a, b, c, d, e, mese, giorno;
	char mese_str[3];
	char date_str[3];
	char *ris = malloc(5 * sizeof(char));
        int i;        
              
	a = anno % 19;
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

        sprintf(mese_str, "%hd", mese);
	sprintf(date_str, "%hd", giorno + 1);
	strcpy(ris, date_str);
	strcat(ris, mese_str);

	for(i=0; i<strlen(ris); i++){
	
			ris[i] = ris[i] - 48;
	        	
        
	}

        
        return ris;	

}


