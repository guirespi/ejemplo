#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOG(format, ...) printf(format "\n", ##__VA_ARGS__)
#define LENGTH_LIST (10)
#define GUARDIAN "FIN"

/**
 * @brief Print a list of words.
 * 
 * @param words_list List of words.
 * @param words_qty Words quantity-
 */
static void print_word_list(char ** words_list, int words_qty){
    if(words_qty == 0){
        LOG("Lista de palabras vacía...");
        return;
    }

    for(int i = 0; i < words_qty; i++){
        LOG("%i. %s", (i+1), words_list[i]);
    }
}

/**
 * @brief Bubble sort to arrange words in ascending order.
 * 
 * @param words_list List of words.
 * @param words_qty Words quantity.
 */
static void sort_word_list(char ** words_list, int words_qty){
    for(int i = 0; i < words_qty; i++){
        for(int j = (i+1); j < words_qty; j++){
            if(strcmp(words_list[i],words_list[j]) > 0){
                char * temp = words_list[i];
                words_list[i] = words_list[j];
                words_list[j] = temp;
            }
        }
    }
}

int main()
{
    /* Start index */
    int index = 0;
    int valid_words = 0;
    /* Let's make possible the words doesn't have a limit */
    char * lista_cadenas[LENGTH_LIST] = {0};

    LOG("Bienvenido al ordenador de palabras!");
    LOG("-----------------------------------");
    LOG("Escriba hasta %d palabras a ordenar o escriba \"" GUARDIAN "\" para acabar con su lista", LENGTH_LIST);
    LOG("\nComience a ingresar palabras:");

    char aux[128] = {0};

    do{
        if(index >= LENGTH_LIST){
            LOG("\nMáximo número de palabras alcanzaddas");
            break;
        };

        memset(aux,0,sizeof(aux));
        scanf("%s", aux);
        
        char * temp = calloc(strlen(aux) + 1, sizeof(*temp));
        strcpy(temp, aux);
        
        if(temp == NULL){
            LOG("No hay memoria disponible!");
            return -1;
        }

        lista_cadenas[index] = temp;
    }while(strcmp(lista_cadenas[index++], GUARDIAN));
    
    valid_words = index;
    if(strcmp(lista_cadenas[index - 1], GUARDIAN) == 0)
    {
        valid_words = index - 1;
    }

    sort_word_list(lista_cadenas, valid_words);

    LOG("\nPalabras ingresadas ordenadas de manera ascendente:\n");
    print_word_list(lista_cadenas, valid_words);
    LOG("\n");

    for(int i = 0; i < index; i++){
        free(lista_cadenas[i]);
    }
    
    LOG("Fin del programa. Hasta pronto!");

    return 0;
}