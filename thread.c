#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mysql/mysql.h>
#include "exe.h"

//############# connexion ###########################################################


//############################### programme principal ###########################################
int main(void){

    // adressage des threads

    pthread_t thread_1;
    pthread_t thread_2;
    pthread_t thread_3;
    pthread_t thread_4;

    // Creation des threads
    
    pthread_create(&thread_1, NULL, firstpartmoy, NULL);
    //printf("mon pid est : %d \n", getpid());

    pthread_create(&thread_2, NULL, twothpartmoy, NULL);
    //printf("mon pid est : %d \n", getpid());

    pthread_create(&thread_3, NULL, threethpartmoy, NULL);
    //printf("mon pid est : %d \n", getpid());

    pthread_create(&thread_4, NULL, fourthpartmoy, NULL);
    //printf("mon pid est : %d \n", getpid());

    // cellule d'attente successive des threads

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    pthread_join(thread_4, NULL);
   
}