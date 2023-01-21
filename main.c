/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

int main(int currCount)

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	// declare and initialize the histogram
	int
	char curStr[MAX_INPUT_LEN];
	//int histogram[ALPHABET_SIZE];
	while (1){
		fgets(curStr, MAX_INPUT_LEN, stdin);
		if (curStr[0] == '#'){
			break;
		}
		char* token = strtok(curStr, " ");
		while (token != NULL){
			//TODO else do stuff
			//updHisto(word, histogram)
			//updWordCount(word, histogram)
			//updHisto(word, histogram)
			//updHisto(word, histogram)
			printf("%s", token);
			token = strtok (NULL, " ");
		}
	}
	// TODO: start by getting strings from users until # is input


	// TODO: after # is input, print menu options
	
	printf("Exiting...\n");
	return 0;
}
