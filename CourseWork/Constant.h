#pragma once
#include<string>
using namespace std;

const string tapesFilename = "tapes.dat";

const struct Tape {
	int ID;  // PK
	char title[100];
	int ammount;
};

const struct Date {
	int day;
	int month;
	int year;
};

const struct Clients {
	int ID;  // FK -> Client.ID
	int tapeOnLease;  // FK -> Tape.ID
	Date rentStart;
	Date rentEnd;
};

const struct Client {
	int ID;  // PK
	char name[100];
	char lastname[100];
	int phone;
	char city[100];
	char street[100];
	int houseNo;
	int flat;
	int zipCode;
	char tapeOnLease;
};

const struct FileTypes {
	static Tape TAPE;
	static Client CLIENT;
};
