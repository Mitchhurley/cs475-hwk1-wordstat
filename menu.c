/*
 * menu.c
 *
 *  Created on: Jun 16, 2015
 *      Author: dchiu
 */

#include <stdio.h>
#include "menu.h"

int getMenuOption() {
	int opt = 0;

	printf("\n*** WORD STATS MENU ***\n");
	printf("Enter %d to print vowel and consonant frequency.\n", MENU_STATS);
	printf("Enter %d to print histogram.\n", MENU_HISTO);
	printf("Enter %d to return to inputting more strings.\n", MENU_INPUT);
	printf("Enter %d to quit.\n", MENU_EXIT);
	scanf("%d", &opt);	
	return opt;
}

void printFreq(int vCount, int cCount){
	int total = vCount + cCount;
	float vPercentage = ((float)vCount/(float)total) * 100f;
	float cPercentage = ((float)cCount/(float)total) * 100f;
	printf("\nVowels = %d (%.2f%%), Consonants = %d (%.2f%%), Total= %d\n",
	vCount, vPercentage, cCount, cPercentage, total);
}
void printHistog(int *histo){
	printHisto(histo);
}
