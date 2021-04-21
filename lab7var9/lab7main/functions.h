#pragma once
void fillingFileByHand(FILE* file, packages fpacks, int size, int& lines);
void fillingFileByRandom(FILE* file, packages fpacks, int size, int& lines);
void addToBegining(FILE* file, packages fpacks, int& lines);
void addToEnd(FILE* file, packages fpacks, int& lines);
void printSelectedString(FILE* file, packages fpacks, int& lines);
void printEntireFile(FILE* file, packages fpacks, int& lines);

