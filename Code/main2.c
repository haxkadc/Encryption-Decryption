
#include "header.h"
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    char mat_sost[4][8] = {{' '}}, doppie[256]={' '}, lettera, numeri[10], numero;
    char mess[100] = { ' ' };
    char mess_corretto[100] = { '\0' };
    char mess_cifrato[100]={' '};
    char mess_decifrato[100]={' '};
    int i,j, pieno = 0;

    for (i = 0; i < 4; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(pieno != 26)                                 /*Enter the if until it enters all the characters*/
            {
                do lettera = 65 + rand() % (65 - 91);    /*Generate a letter from A to Z*/
                while(lettera == doppie[lettera]);

                mat_sost[i][j] = lettera;                          /*Insert the letter*/
                doppie[lettera] = lettera;
                pieno++;                                    /*Increase counter*/
            }

            else                                            /*Enter all characters, generate a number and enter it*/
            {
                do numero = 48 + rand() % (48 - 58);
                while(numero == numeri[numero]);

                mat_sost[i][j] = numero;
                numeri[numero] = numero;
            }

            //printf("%c ",matrice[i][j]);
        }
        //printf("\n");
    }

 printf(" ________________________________________\n");
   printf("|                                        |\n");
   printf("|                                        |\n");
   printf("|               ALTERNATIVE              |\n");
   printf("|           REPLACEMENT MATRIX           |\n");
   printf("|                                        |\n");
   printf("|________________________________________|\n");
   printf("******************************************\n");

 for(i=0;i<RIGHE;i++)

   {
                        for(j=0;j<COLONNE;j++)
                        {
                                              printf(" %c  ",mat_sost[i][j]);
                        }
                        printf("\n");
    }
   printf("******************************************\n\n");

   printf("\nInserire il messaggio da crittografare:\n");
   gets(mess);
   formattazione(mess,mess_corretto,mat_sost);                          //call the function formattazione
   printf("________________________________________\n\n");
   printf("Messaggio corretto: %s\n",mess_corretto);
   cifratura(mess_corretto, mess_cifrato,mat_sost);                      //call encryption function
   printf("Messaggio cifrato: %s\n", mess_cifrato);
   decifratura(mess_cifrato, mess_decifrato,mat_sost);                   //call decryption function
   printf("Messaggio decifrato: %s\n", mess_decifrato);
   printf("________________________________________\n");

   return 0;

}

