#pragma once
#include "includes.h"

void menu();
void listCreation(Tlist*& head, int& count, int point, int size);
void listPrint(Tlist* head, int count);
int searchByParam(Tlist* head, int count);
void addToList(Tlist*& head,int& count, int poz);
void deleteFromList(Tlist*& head, int& count, int poz);
void listSorting(Tlist* head, int count);
void createFile(Tlist* head, int count);
void oldListKill(Tlist*& head);
void createListFromFile(Tlist*& head);