#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short int menu();
short int validaInt(char msg[]); 
void calcolaAngelo(short int anno);
void outputGigante(char *data);
char* gaussFormula(short int m, short int n, short int anno);

int main()
{

	short int scelta, anno;
        do{

	scelta = menu();
	switch(scelta){

		case 1: 
			do{

                           anno = validaInt("   --> Inserire in numeri l'anno di riferimento (tra il 1900 e il 2099 inclusi): ");

			}while((anno<1900)||(anno >2099));
			calcolaAngelo(anno);
			break;


	}
       } while(scelta != 0);
}


short int menu(){

	short int opt;
        
	printf("    |V|     \n");
	printf(" .::| |::.  \n");
	printf("::__| |__:: \n");
	printf(">___   ___< \n");
	printf("::  | |  :: \n");
	printf(" '::| | ::' \n");
	printf("    | |     \n");
	printf("    | |     \n");
	printf("    |A|     \n\n\n");


	printf("<Software per il calcolo del lunedì dell'angelo tra il XX e XXI secolo.>\n\n\n<- Sviluppato da Cosimo e Leone (Uniurb, Dipartimento delle scienze pure ed applicate L-31, A.A 2023-24.>\n\n");
	printf("-----------------------------------------------------------------\n");
        printf("<1> Ricerca del giorno dell'angelo per data (1900 -2099)\n");
	printf("<0> Uscita dal software\n----------------------------------------------------------\n\n");
        
	do{

	    opt = validaInt("   --> Inserire il numero corrispondente all'operazione desiderata:");	
	
	}while ((opt > 1)||(opt < 0));

        return opt;

}

short int validaInt(char msg[]){

	short int dati;
	short int  validato_flag = 1;
	do{
         
         	printf("\n%s", msg);		
        	scanf("%hd", &dati);
	        while(getchar() != '\n');

	}while (validato_flag != 1);
	return dati;
        
}

void calcolaAngelo(short int anno){

        char* output = gaussFormula(24, 5, anno);
        printf("%s", output);

	outputGigante(gaussFormula(24,5,anno));
	outputGigante(gaussFormula(15, 6, anno));
               
	

}

void outputGigante(char *data){
       
	FILE* bitmap = fopen("8x5.bin", "rb");
        int data_gigante[6][5];
	short int i,j,b, pixel;
        

	if(bitmap){
            
               for(i = 0; i < 2; i++){
                  fseek(bitmap, (data[i] - 48)*5*sizeof(int), SEEK_SET);
                  fread(data_gigante[i], sizeof(int), 5, bitmap); 
	       }

               fseek(bitmap, 50, SEEK_SET);
	       fread(data_gigante[2], sizeof(int), 5, bitmap);

		if(data[1] == '3'){

			fseek(bitmap, 60 * sizeof(int), SEEK_SET);
			fread(data_gigante[3], sizeof(int), 5, bitmap);
			fseek(bitmap, 55 *sizeof(int), SEEK_SET);
			fread(data_gigante[4], sizeof(int), 5, bitmap);
			fseek(bitmap, 70 * sizeof(int),SEEK_SET);
			fread(data_gigante[5], sizeof(int), 5, bitmap);
			

		}else{

                        fseek(bitmap, 55 * sizeof(int), SEEK_SET);
			fread(data_gigante[3], sizeof(int), 5, bitmap);
			fseek(bitmap, 65 * sizeof(int), SEEK_SET);
			fread(data_gigante[4], sizeof(int), 5, bitmap);
			fseek(bitmap, 70 * sizeof(int), SEEK_SET);
			fread(data_gigante[5], sizeof(int), 5, bitmap);
                      
		}

									/*stampa effettiva dei caratteri giganti*/            
               for (i = 0; i < 5; i++){


		       for (j = 0; j < 6; j++){
 
			       for(b = 0; b < 8; b++){
					
			       		pixel = data_gigante[j][i] & 1 << 7-b;   //and logico del bit esaminato attraverso shift binario
					printf("%c", pixel ? '*' : ' ');		

			       }


		       }

		       printf("\n");

		}

	}else{
		printf("errore");
	}

}


char* gaussFormula(short int m, short int n, short int anno) {

	short int a, b, c, d, e, mese, giorno;
        char angelo[7];
	char mese_str[3];
	char date_str[4];

	a = anno % 19;
	b = anno % 4;
	c = anno % 7;

	d = (19 * a + m) % 30;
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
        sprintf(mese_str, " %hd", mese);
	sprintf(date_str, "%hd", giorno + 1);
	strcat(date_str, mese_str);
        printf("%s", date_str);
        return date_str;	

}



