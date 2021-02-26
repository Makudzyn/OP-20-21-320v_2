#pragma once
#define foo
#ifdef foo
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;
#include "functions.h"
void arrFilling(int mainSize, int mainArr[], int minusArr[], int plusArr[], int nullArr[],
	int* size1, int* size2, int* size3);
void mainFilling(int mainArr[], int nullArr[], int plusArr[], int minusArr[],
	int size1, int size2, int size3);
#endif // foo
