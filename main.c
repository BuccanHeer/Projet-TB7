#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "analyselexic.h"



int main()
{
   tokenlist_t*token_test;
   char formule[100]="sin(";

   token_test=analyse(formule);

   printf("%d\n",token_test->token.position);
   printf("%d\n",token_test->token.type);
   printf("%c\n",token_test->token.valeur.operateur);
   printf("%d\n",token_test->suivant->token.type);

   return 0;

}
