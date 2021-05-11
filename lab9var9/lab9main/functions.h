#pragma once
#include "includes.h"

void menu();
void listCreation(Tlist*& head, Tlist*& tail, int& count, int point, int size);
void listPrintFromHead(Tlist* head);
void listPrintFromTail(Tlist* tail);
int searchByParamFromHead(Tlist* head, int count);
int searchByParamFromTail(Tlist* tail, int count);
void addToList(Tlist*& head, int& count, int poz);
void deleteFromList(Tlist*& head, int& count, int poz);
void listSorting(Tlist* head, int count);
void createFile(Tlist* head, int count);
void oldListKill(Tlist*& head);
void createListFromFile(Tlist*& head, Tlist*& tail);
