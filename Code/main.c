#include "header.c"

int main()
{
char mat_sost[4][8]={{'8','J','E','Q','D','N','5','O'},
                     {'P','U','3','A','R','F','L','W'},
                     {'4','V','C','2','T','M','B','I'},
                     {'K','7','Z','S','G','X','H','Y'}};




    int i,j;
   char mess[100];
   char mess_corretto[100];
   char mess_cifrato[100];
   char mess_decifrato[100];
   printf(" ________________________________________\n");
   printf("|                                        |\n");
   printf("|                                        |\n");
   printf("|         REPLACEMENT MATRIX             |\n");
   printf("|                                        |\n");
   printf("|                                        |\n");
   printf("|________________________________________|\n");
   printf("******************************************\n");

   for(i=0;i<RIGHE;i++)   ////Replacement matrix Printing

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
   formattazione(mess, mess_corretto,mat_sost);                          //call the function formattazione
   printf("________________________________________\n\n");
   printf("Messaggio corretto:  %s\n", mess_corretto);
   cifratura(mess_corretto, mess_cifrato,mat_sost);                      //call encryption function
   printf("Messaggio cifrato: %s\n", mess_cifrato);
   decifratura(mess_cifrato, mess_decifrato,mat_sost);                   //call decryption function
   printf("Messaggio decifrato: %s\n", mess_decifrato);
   printf("________________________________________\n");

   return 0;
}

