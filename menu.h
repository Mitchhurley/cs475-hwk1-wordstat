/*
 * menu.h
 *
 *  Created on: Jun 16, 2015
 *      Author: dchiu
 */

#ifndef MENU_H_
#define MENU_STATS = 1;
#define MENU_HISTO = 2;
#define MENU_INPUT = 3;
#define MENU_EXIT = 4;
#define MENU_H_

// function declarations for the menu below
int getMenuOption();
void printFreq(int vCount, int cCount);
void printHisto(int *histo);

#endif /* MENU_H_ */
