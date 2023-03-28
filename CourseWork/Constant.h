#pragma once
#include<string>
using namespace std;

const string tapesFilename = "tapes.dat";
const string clientsFilename = "clients.dat";
const string clientsRentFilename = "rent.dat";

const struct Tape {
	int Id;  // PK
	char title[100];
	int ammount;
};

const struct Date {
	int day;
	int month;
	int year;
};


const struct Rent {
	int clientId;  // FK -> Client.ID
	int tapeId;  // FK -> Tape.ID
	Date rentStart;
	Date rentEnd;
};

const struct Client {
	int Id;  // PK
	char fullName[100];
	char phone[25];
	char city[100];
	char street[100];
	int houseNo;
	int flat;
	char zipCode[25];
};