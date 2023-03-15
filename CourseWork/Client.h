#pragma once


struct Date {
	int day;
	int month;
	int year;
};

struct Clients {
	int ID;
	char lastname[25];
	bool tapeOnLease = 0;
	char tapeTitle;
	char returnDate;
};


struct Client {
	int ID;
	char name[25];
	char lastname[25];
	int phone;
	char city[25];
	char street[25];
	int houseNo;
	int flat;
	int zipCode;
	char tapeOnLease;
};


void addNew();
void showAll();
void showOne(int fileID);