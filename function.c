#include "header.h"



void formattazione(char testo_entrata[], char testo_uscita[],char mat_sost[][8])  //In this function spaces are removed and X is added in pairs
{
   int l = strlen(testo_entrata);

   int i, j;
   i = 0;
   j = 0;
   while (i<l)
   {
      if (testo_entrata[i]!=' ')                                // Check that the character is not a space
      {
         testo_uscita[j] = testo_entrata[i];                    // Adds character to the output string(testo_uscita)

         if (testo_uscita[j]>96 && testo_uscita[j]<123)
            testo_uscita[j] -= 32;                              // Conversion from lowercase to uppercase by subtracting the value 32 from the variable on the left

         if ((j % 2)==1)                                        // A pair of characters is grouped outgoing
         {
                                                                // Check if there are equal characters in the couple
            if (testo_uscita[j-1]==testo_uscita[j])
            {
               testo_uscita[j] = 'X';
               i--;
            }
         }

         j++;
      }
      i++;
   }

   if ((j % 2)==1)                                                 // When the string has an odd length, an X is added at the end so that it becomes even
   {
      testo_uscita[j] = 'X';
      testo_uscita[j+1] = '\0';
   }
   else
   {
      testo_uscita[j] = '\0';
   }

}

void cifratura(char testo_entrata[], char testo_uscita[],char mat_sost[][8])
{
   int l = strlen(testo_entrata);
   int i, j, k;
   int r1, r2, rr1, rr2;
   int c1, c2, cc1, cc2;
   char buf[2];

   int pp;

   for (i=0;i<l/2;i++)
   {
      buf[0] = testo_entrata[2*i];
      buf[1] = testo_entrata[2*i+1];

                                                                                             // Look for characters in mat_sost
      for (j=0;j<RIGHE;j++)
      {
         for (k=0;k<COLONNE;k++)
         {
            if (mat_sost[j][k]==buf[0])
            {
               r1 = j;
               c1 = k;
            }
            if (mat_sost[j][k]==buf[1])
            {
               r2 = j;
               c2 = k;
            }
         }
      }

                                                                                                    //  Encryption method.
      if (r1==r2)                                                                                   // case a
      {
         rr1 = r1;
         rr2 = r2;
         cc1 = (c1 + 1) % COLONNE;
         cc2 = (c2 + 1) % COLONNE;

      }
      else if (c1==c2 && r1!=r2)                                                                     // case b
      {
         rr1 = (r1 + 1) % RIGHE;
         rr2 = (r2 + 1) % RIGHE;
         cc1 = c1;
         cc2 = c2;

      }
      else if (c1!=c2 && r1!=r2)                                                                      // case c
      {
         rr1 = r1;
         cc1 = c2;
         rr2 = r2;
         cc2 = c1;

      }

    testo_uscita[2*i] = mat_sost[rr1][cc1];
    testo_uscita[2*i+1] = mat_sost[rr2][cc2];
   }

   testo_uscita[l] = '\0';

}
void decifratura(char testo_entrata[], char testo_uscita[],char mat_sost[][8])
{
   int l = strlen(testo_entrata);
   int i, j, k;
   int r1, r2, rr1, rr2;
   int c1, c2, cc1, cc2;
   char buf[2];

   int pp;

   for (i=0;i<l/2;i++)
   {
      buf[0] = testo_entrata[2*i];
      buf[1] = testo_entrata[2*i+1];

                                                                                    // Look for characters in mat_sost
      for (j=0;j<RIGHE;j++)
      {
         for (k=0;k<COLONNE;k++)
         {
            if (mat_sost[j][k]==buf[0])
            {
               r1 = j;
               c1 = k;
            }
            if (mat_sost[j][k]==buf[1])
            {
               r2 = j;
               c2 = k;
            }
         }
      }

                                                                                     // Decryption method

      if (r1==r2)                                                                       // case a
      {
         rr1 = r1;
         rr2 = r2;
         cc1 = (c1 + COLONNE - 1) % COLONNE;
         cc2 = (c2 + COLONNE - 1) % COLONNE;

      }
      else if (c1==c2 && r1!=r2)                                                         // case b
      {
         rr1 = (r1 + RIGHE - 1) % RIGHE;
         rr2 = (r2 + RIGHE - 1) % RIGHE;
         cc1 = c1;
         cc2 = c2;

      }
      else if (c1!=c2 && r1!=r2)                                                          // case c
      {
         rr1 = r1;
         cc1 = c2;
         rr2 = r2;
         cc2 = c1;

      }


      testo_uscita[2*i] = mat_sost[rr1][cc1];
      testo_uscita[2*i+1] = mat_sost[rr2][cc2];
   }

   testo_uscita[l] = '\0';
}

