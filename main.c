/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

int * updateHistogram(int array[], char *myWord);
int countVowels(int arr[]);
int countConsonants(int arr[], int vCount);

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	//Ints to keep track of the stats
	int wordCount = 0;
	int vowelCount = 0;
	int consonantCount = 0;
	char curStr[MAX_INPUT_LEN];
	// declare and initialize the histogram 
	int histogram[ALPHABET_SIZE] = {0};
	printf("Enter strings (# to stop):\n");
	//loop for getting words
	while (1){
		
		fgets(curStr, MAX_INPUT_LEN, stdin);
		//TODO ingnore input past 128
		if (curStr[0] != '#')
		{
			char* token = strtok(curStr, " ");
			//checks if theres more tokens
			while (token != NULL){
				//check if token starts with digit, if so get next 
				if (isalpha(token[0])){
					updateHistogram(histogram, token);
					wordCount = wordCount + 1;
					vowelCount = countVowels(histogram);
					consonantCount = countConsonants(histogram, vowelCount);
				}
				token = strtok(NULL, " ");
			}
		}
		else{
			int choice = -1;
			//while loop for getting menu input
			while (choice != MENU_INPUT){
				choice = getMenuOption();

				if (choice == MENU_EXIT){
					printf("Exiting...\n");
					return 0;
				}
				
				else if (choice == MENU_STATS){
					printFreq(vowelCount, consonantCount);
				}else if (choice == MENU_HISTO){
					printHisto(histogram);
				}
				else printf("Error: unknown option %d", choice);
			}
			printf("Enter strings (# to stop):\n");
		}
		
	}
	
	
	
}

/** Method that updates the histogram

*/
int * updateHistogram(int array[], char *myWord){
	int lett = 0;
	for (int i = 0; i < strlen(myWord) - 1; i++){
		//start by turning the char to its ascii code, then subtracting 55
		//which would make 'A' into 0.
		lett = (int)myWord[i] - 65;
		//Handles lowercase input here
		if (lett > 30) {
			lett -= 32;
		}
		//increments the position
		array[lett] += 1;
	}
	return array;
}

/**
 * Gives the number of entered vowels
*/
int countVowels(int arr[]){
	//just adds all the vowel positions together
	return arr[0] + arr[4] + arr[8] + arr[14] + arr[20];
}

/**
*
*/
int countConsonants(int arr[], int vCount){
	int total = 0;
	//totals the number of letters and subtracts the number of vowels
	for (int i = 0; i < ALPHABET_SIZE; i++){
		
		total += arr[i];
	}
	total -= vCount;
	return total;
}
