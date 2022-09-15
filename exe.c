#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <pthread.h>
#include "exe.h"

void* firstpartmoy(void *arg)

{  
    double Moyenne;
    MYSQL *connexion;
    char *eptr;

    MYSQL_RES *resultat;
    MYSQL_ROW ligne;
    MYSQL mysql;

    connexion = mysql_init(&mysql);

    mysql_options(connexion, MYSQL_READ_DEFAULT_GROUP, "option");

    //connexion a la base de Donnees

    if(mysql_real_connect(connexion, "localhost", "root", "", "SYSTEME", 0, NULL, 0)){
        printf("connexion reuissie\n");

         if (mysql_query(connexion, "SELECT * FROM ETUDIANTS LIMIT 50"))
        {
            fprintf(stderr, "%s\n", mysql_error(connexion));
            mysql_close(connexion);
            exit(1);
        }

        resultat = mysql_store_result(connexion);  

        //calcul de moyenne

        printf("\t\t\t  |           JE SUIS LE PREMIER THREAD :             |\n");
        while((ligne = mysql_fetch_row(resultat)) != NULL)
        {
            Moyenne = (strtod(ligne[3], &eptr) + strtod(ligne[4], &eptr))/2;

            printf("\t\t\t  +--------------------------------------------+\n");
            printf("\t\t\t  |            VOTRE MOYENNE EST :             |\n");
            printf("\t\t\t  +--------------------------------------------+\n");

            printf("Identifiant %s\nNom et Prenom  %s %s \nNote 1 %s\nNote 2 %s \nMoyenne %f \n", ligne[0] , ligne[1] , ligne[2] , ligne[3], ligne[4], Moyenne);
               
        }
        printf("\t\t\t  |           JE ME TERMINE ICI :             |\n");
        pthread_exit(NULL);
        mysql_free_result(resultat);
        mysql_close(connexion); 
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion a la base de Donnees");
    }
    
}

void* twothpartmoy( void* arg)

{   double Moyenne;
    MYSQL *connexion;
    char *eptr;

    MYSQL_RES *resultat;
    MYSQL_ROW ligne;
    MYSQL mysql;

    connexion = mysql_init(&mysql);

    mysql_options(connexion, MYSQL_READ_DEFAULT_GROUP, "option");

    //connexion a la base de Donnees

    if(mysql_real_connect(connexion, "localhost", "root", "", "SYSTEME", 0, NULL, 0)){
        printf("connexion reuissie\n");

         if (mysql_query(connexion, "SELECT * FROM ETUDIANTS LIMIT 50, 50"))
        {
            fprintf(stderr, "%s\n", mysql_error(connexion));
            mysql_close(connexion);
            exit(1);
        }

        resultat = mysql_store_result(connexion);  

        //calcul de moyenne
        printf("\t\t\t  |           JE SUIS LE DEUXIEME THREAD :             |\n");
        while((ligne = mysql_fetch_row(resultat)) != NULL)
        {
            Moyenne = (strtod(ligne[3], &eptr) + strtod(ligne[4], &eptr))/2;

            printf("\t\t\t  +--------------------------------------------+\n");
            printf("\t\t\t  |            VOTRE MOYENNE EST :             |\n");
            printf("\t\t\t  +--------------------------------------------+\n");

            printf("Identifiant %s\nNom et Prenom  %s %s \nNote 1 %s\nNote 2 %s \nMoyenne %f \n", ligne[0] , ligne[1] , ligne[2] , ligne[3], ligne[4], Moyenne);
               
        }
        printf("\t\t\t  |           JE ME TERMINE ICI :             |\n");
        pthread_exit(NULL);
        mysql_free_result(resultat);
        mysql_close(connexion); 
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion a la base de Donnees");
    }
   
}

void* threethpartmoy( void* arg)

{   double Moyenne;
    MYSQL *connexion;
    char *eptr;

    MYSQL_RES *resultat;
    MYSQL_ROW ligne;
    MYSQL mysql;

    connexion = mysql_init(&mysql);

    mysql_options(connexion, MYSQL_READ_DEFAULT_GROUP, "option");

    //connexion a la base de Donnees

    if(mysql_real_connect(connexion, "localhost", "root", "", "SYSTEME", 0, NULL, 0)){
        printf("connexion reuissie\n");

         if (mysql_query(connexion, "SELECT * FROM ETUDIANTS LIMIT 100, 50"))
        {
            fprintf(stderr, "%s\n", mysql_error(connexion));
            mysql_close(connexion);
            exit(1);
        }

        resultat = mysql_store_result(connexion);  

        //calcul de moyenne
        printf("\t\t\t  |           JE SUIS LE TROISIEME THREAD :             |\n");
        while((ligne = mysql_fetch_row(resultat)) != NULL)
        {
            Moyenne = (strtod(ligne[3], &eptr) + strtod(ligne[4], &eptr))/2;

            printf("\t\t\t  +--------------------------------------------+\n");
            printf("\t\t\t  |            VOTRE MOYENNE EST :             |\n");
            printf("\t\t\t  +--------------------------------------------+\n");

            printf("Identifiant %s\nNom et Prenom  %s %s \nNote 1 %s\nNote 2 %s \nMoyenne %f \n", ligne[0] , ligne[1] , ligne[2] , ligne[3], ligne[4], Moyenne);
               
        }
        printf("\t\t\t  |           JE ME TERMINE ICI :             |\n");
        pthread_exit(NULL);
        mysql_free_result(resultat);
        mysql_close(connexion); 
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion a la base de Donnees");
    }
    
   
}

void* fourthpartmoy(void* arg)

{   double Moyenne;
    MYSQL *connexion;
    char *eptr;

    MYSQL_RES *resultat;
    MYSQL_ROW ligne;
    MYSQL mysql;

    connexion = mysql_init(&mysql);

    mysql_options(connexion, MYSQL_READ_DEFAULT_GROUP, "option");

    //connexion a la base de Donnees

    if(mysql_real_connect(connexion, "localhost", "root", "", "SYSTEME", 0, NULL, 0)){
        printf("connexion reuissie\n");

         if (mysql_query(connexion, "SELECT * FROM ETUDIANTS LIMIT 150, 50"))
        {
            fprintf(stderr, "%s\n", mysql_error(connexion));
            mysql_close(connexion);
            exit(1);
        }

        resultat = mysql_store_result(connexion);  

        //calcul de moyenne
        printf("\t\t\t  |           JE SUIS LE QUATRIEME THREAD :             |\n");
        while((ligne = mysql_fetch_row(resultat)) != NULL)
        {
            Moyenne = (strtod(ligne[3], &eptr) + strtod(ligne[4], &eptr))/2;

            printf("\t\t\t  +--------------------------------------------+\n");
            printf("\t\t\t  |            VOTRE MOYENNE EST :             |\n");
            printf("\t\t\t  +--------------------------------------------+\n");

            printf("Identifiant %s\nNom et Prenom  %s %s \nNote 1 %s\nNote 2 %s \nMoyenne %f \n", ligne[0] , ligne[1] , ligne[2] , ligne[3], ligne[4], Moyenne);
               
        }
        printf("\t\t\t  |           JE ME TERMINE ICI :             |\n");
        pthread_exit(NULL);
        mysql_free_result(resultat);
        mysql_close(connexion); 
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion a la base de Donnees");
    }
    
}


