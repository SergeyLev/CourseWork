#pragma once

struct Tape {
	int ID;
	char title[100];
	int ammount;
};

void showAllTape();
void addNewTape();
void deleteTape();
