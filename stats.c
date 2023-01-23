/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"

// Function definitions for dealing with histogram below
int getMax(int *histo){
    int max = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (histo[i] > max){
            max = histo[i];
        }
    }
    return max;
}


void printHisto(int *histogram){
    int maxnum = getMax(histogram);
    for (int i = maxnum; i > 0; i--){
        char line[ALPHABET_SIZE * 2] = ""; 
        for (int j = 0; j < ALPHABET_SIZE; j++){
            if (histogram[j] >= i){
                strcat(line, "* ");
            }
            else {
                strcat(line, "  ");
            }
            }

        printf("\n%s", line);
    }
    printf("\na b c d e f g h i j k l m n o p q r s t u v w x y z \n");
    
    for (int j = 0; j < ALPHABET_SIZE; j++){
        printf("%d ", histogram[j]);
    }
    printf("\n");
}