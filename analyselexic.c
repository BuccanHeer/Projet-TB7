#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "analyselexic.h"


tokenlist_t* initialisation()
{
    tokenlist_t*token=NULL;

    return token;

}
/*char sinus[]="sin";
char cosinus[]="cos";
char tangente[]="tan";
char arccosinus[]="arccos";
char arcsinus[]="arcsin";
char arctangente[]="arctan";
char sinushyper[]="sinh";
char cosinushyper[]="cosh";
char tangentehyper[]="tanh";
char racine[]="sqrt"*/

char fonction [17][20]={"cos","sin","tan","arccos","arcsin","arctan","cosh","sinh","tanh","sqrt","exp","ln","log","abs","ent","dec","!"};

tokenlist_t*ajout_variable(tokenlist_t*token_p,int position)
{
    if(token_p==NULL)
        {
            token_p=malloc(sizeof(tokenlist_t));
            token_p->token.type=VAR;
            token_p->token.position=position;
            token_p->suivant=NULL;
        }
        else
        {
            tokenlist_t*tokenbis;
            tokenlist_t*token_ter;
            token_ter=token_p;
            while(token_p->suivant!=NULL)
            {
                token_ter=token_ter->suivant;
            }
            tokenbis=malloc(sizeof(tokenlist_t));
            tokenbis->token.type=VAR;
            tokenbis->token.position=position;
            tokenbis->suivant=NULL;
            token_ter->suivant=tokenbis;
        }

        return token_p;


}



tokenlist_t*ajout_parenthese_ouvrante(tokenlist_t*token_p,int position)
{
    if(token_p==NULL)
        {
            token_p=malloc(sizeof(tokenlist_t));
            token_p->token.type=PAR_O;
            token_p->token.position=position;
            token_p->suivant=NULL;
        }
        else
        {
            tokenlist_t*tokenbis;
            tokenlist_t*token_ter;
            token_ter=token_p;
            while(token_p->suivant!=NULL)
            {
                token_ter=token_ter->suivant;
            }
            tokenbis=malloc(sizeof(tokenlist_t));
            tokenbis->token.type=PAR_O;
            tokenbis->token.position=position;
            tokenbis->suivant=NULL;
            token_ter->suivant=tokenbis;
        }

        return token_p;


}
tokenlist_t*ajout_parenthese_fermante(tokenlist_t*token_p,int position)
{
    if(token_p==NULL)
        {
            token_p=malloc(sizeof(tokenlist_t));
            token_p->token.type=PAR_F;
            token_p->token.position=position;
            token_p->suivant=NULL;
        }
        else
        {
            tokenlist_t*tokenbis;
            tokenlist_t*token_ter;
            token_ter=token_p;
            while(token_p->suivant!=NULL)
            {
                token_ter=token_ter->suivant;
            }
            tokenbis=malloc(sizeof(tokenlist_t));
            tokenbis->token.type=PAR_F;
            tokenbis->token.position=position;
            tokenbis->suivant=NULL;
            token_ter->suivant=tokenbis;
        }

        return token_p;


}
tokenlist_t*ajout_operateur(tokenlist_t*token_p,char operateur,int position)
{
        if(token_p==NULL)
        {
            token_p=malloc(sizeof(tokenlist_t));
            token_p->token.type=OPERATEUR;
            token_p->token.position=position;
            token_p->token.valeur.operateur=operateur;
            token_p->suivant=NULL;
        }
        else
        {
            tokenlist_t*tokenbis;
            tokenlist_t*token_ter;
            token_ter=token_p;
            while(token_ter->suivant!=NULL)
            {
                token_ter=token_ter->suivant;
            }
            tokenbis=malloc(sizeof(tokenlist_t));
            tokenbis->token.type=OPERATEUR;
            tokenbis->token.position=position;
            tokenbis->token.valeur.operateur=operateur;
            tokenbis->suivant=NULL;
            token_ter->suivant=tokenbis;
        }

        return token_p;


}
tokenlist_t*ajout_fonction(tokenlist_t*token_p,char * fonction,char comparaison[17][20],int position)
{
    int k=666;
    int i;
    for(i=0;(i<=16)&&(k==666);i++)
    {
        if (strcmp(fonction,comparaison[i])==0)
        {
            k=i;
        }

    }
    if(k!=666)
    {
          if(token_p==NULL)
        {
            token_p=malloc(sizeof(tokenlist_t));
            token_p->token.type=FONCTION;
            token_p->token.position=position;
            token_p->token.valeur.fonction=k;
            token_p->suivant=NULL;
        }
        else
        {
            tokenlist_t*tokenbis;
            tokenlist_t*token_ter;
            token_ter=token_p;
            while(token_ter->suivant!=NULL)
            {
                token_ter=token_ter->suivant;
            }
            tokenbis=malloc(sizeof(tokenlist_t));
            tokenbis->token.type=FONCTION;
            tokenbis->token.position=position;
            tokenbis->token.valeur.fonction=k;
            tokenbis->suivant=NULL;
            token_ter->suivant=tokenbis;
        }


    }
    else
    {
          if(token_p==NULL)
        {
            token_p=malloc(sizeof(tokenlist_t));
            token_p->token.type=ERREUR;
            token_p->token.position=position;
            token_p->suivant=NULL;
        }
        else
        {
            tokenlist_t*tokenbis;
            tokenlist_t*token_ter;
            token_ter=token_p;
            while(token_ter->suivant!=NULL)
            {
                token_ter=token_ter->suivant;
            }
            tokenbis=malloc(sizeof(tokenlist_t));
            tokenbis->token.type=ERREUR;
            tokenbis->token.position=position;
            tokenbis->suivant=NULL;
            token_ter->suivant=tokenbis;
        }
    }
return token_p;

}

char * fonction_recuperation(char * arecup,int *i,char fonction_recupi[20] )
{

    int k;
    for(k=0;arecup[*i]>='a'&&arecup[*i]<='z';k++)
    {
        fonction_recupi[k]=arecup[*i];
        printf("%c\n",fonction_recupi[k]);
        (*i)++;

    }
    printf("%s\n",fonction_recupi);

    return fonction_recupi;
}



tokenlist_t*analyse(char*tableau)
{
    tokenlist_t*token_p;
    token_p=initialisation();
    int i;
    int position=1;




    for(i=0;tableau[i]!='\0';i++)
    {

        switch(tableau[i])
        {


        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':

          token_p=ajout_operateur(token_p,tableau[i],position);
          position++;
          break;


        case '(':

            token_p=ajout_parenthese_ouvrante(token_p,position) ;
            position++;
            break;

        case ')':

            token_p=ajout_parenthese_fermante(token_p,position) ;
            position++;
            break;

        case 'x':case 'X':

           token_p=ajout_variable(token_p,position);
           position++;
           break;

        default :

           if ((tableau[i]>='a')&&(tableau[i]<='z'))
           {
               char fonction_recup [20];

               fonction_recuperation(tableau,&i,fonction_recup);
               token_p=ajout_fonction(token_p,fonction_recup,fonction,position);
               i--;
               position++;
           }

           break;



        }


    }

    return token_p;
}
