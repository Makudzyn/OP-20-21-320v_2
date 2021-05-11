#pragma once
struct packages {
	char title[20];
	char producer[20];
	int count;
	double price;
};

struct Tlist {
	packages data;
	struct Tlist* next;
	struct Tlist* prev;
};