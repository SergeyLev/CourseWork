#pragma once
#include"Rent.h"
using namespace std;

tuple<int, string> clientLookup() {
	tuple<int, string> clientId;
	int choice;
	int searchID;
	string searchName;
	
	system("cls");
	cout << "Get ID of a Client.\n 1. By Name\n 2. By Id\n 0. Previous menu" << endl;
	cout << "Your choice: "; cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		cout << "Enter clients Name: "; cin >> searchName;
		clientId = showClient(-1, searchName);
		break;
	case 2:
		system("cls");
		cout << "Enter clients ID: "; cin >> searchID;
		clientId = showClient(searchID, "None");
		break;
	case 0:
		break;
	default:
		system("cls");
		cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
		system("pause");
		break;
	}
	return clientId;
}

tuple<int, string> getClient() {
	int clientId = 0;
	int choice;
	int searchID;
	string searchName;
	bool noClientId = true;
	string clientName;

	while (noClientId)
	{
		tie(clientId, clientName) = clientLookup();

		if (clientId == 0) {
			cout << "No client found.\n 1. Try Again\n 2. Register new\n 0. Exit\n";
			cout << "Your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				break;
			case 2:
				tie(clientId, clientName) = addNew();
				break;
			case 0:
				noClientId = false;
				break;
			default:
				system("cls");
				cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
				system("pause");
				break;
			}
		}
		else {
			cout << "Is client correct?\n 1. Yes\n 2. No\n";
			cout << "Your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				noClientId = false;
				break;
			case 2:
				break;
			default:
				system("cls");
				cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
				system("pause");
				break;
			}
		}
	}
	return make_tuple(clientId, clientName);
}

tuple<int, string> getTapeId(){
	int choice;
	int tapeId = 0;
	showAllTape();
	cout << "Is tape available?\n 1. Yes\n 2. No\n";
	cout << "Your choice: "; cin >> choice;
	switch (choice) {
	case 1:
		cout << "Enter tape ID: "; cin >> tapeId;
		return getTapeById(tapeId);
		break;
	case 2:
		break;
	default:
		system("cls");
		cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
		system("pause");
		break;
	}
}

int getDuration() {
	int days = 0;
	cout << "Enter number of days to rent: "; cin >> days;
	return days;
}


//SHOW ALL CLIENT WITH TAPES RENTED
void showAllRent() {
	int clientsSize;
	int clientsRentSize;
	int tapesSize;

	map<int, string> idClient;
	map<int, string> idTape;

	Client* clients;
	Rent* rent;
	Tape* tapes;

	tie(rent, clientsRentSize) = readFile(new Rent);
	tie(clients, clientsSize) = readFile(new Client);
	tie(tapes, tapesSize) = readFile(new Tape);

	for (int i = 0; i < clientsRentSize; i++) {
		idClient.insert({ rent[i].clientId, getById(rent[i].clientId, clients, clientsSize) });
		idTape.insert({ rent[i].tapeId, getById(rent[i].tapeId, tapes, tapesSize) });
	}

	show(rent, idClient, idTape, clientsRentSize);
	system("pause");
}

char getName(int tapeID) {
	
	ifstream file;
	file.open("tapes.dat", ios::binary);
	if (!file) {
		cout << "File could not be loaded\n";
	}
	else {
		file.seekg(0, ios::end);
		int tapeSize = file.tellg();
		tapeSize = tapeSize / sizeof(Tape);
		file.seekg(0, ios::beg);

		Tape *tapes = new Tape[tapeSize];
		file.read((char*)tapes, tapeSize * sizeof(Tape));
		file.close();

		for (int i = 0; i < tapeSize; i++) {
			if (tapes[i].Id == tapeID) {
				return(*tapes[i].title);
			}
			else {
				cout << "Student not found." << endl;
			}
		}
	}
	return(0);
}

bool newRent() {
	int choice;
	int rentDays;
	int clientId = 0;
	int tapeId = 0;
	time_t curr_time;
	tm* curr_tm;
	string clientName;
	string title;
	Date start;
	string s;
	Date end;
	string e;

	Rent *newRent = new Rent[1];

	// get current date
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	start.day = curr_tm->tm_mday;
	start.month = curr_tm->tm_mon + 1;
	start.year = curr_tm->tm_year + 1900;
	s = to_string(start.day) + "-" + to_string(start.month) + '-' + to_string(start.year);

	// get client id
	tie(clientId, clientName) = getClient();
	if (clientId == 0) {
		cout << "New rent cancelled\n";
		system("pause");
		return false;
	}
	// get tape id
	tie(tapeId, title) = getTapeId();
	if (tapeId == 0) {
		cout << "New rent cancelled\n";
		system("pause");
		return false;
	}

	// get rent duration
	rentDays = getDuration();
	if (rentDays == 0) {
		cout << "Minimum rent duration is one day.\nNew rent cancelled\n";
		system("pause");
		return false;
	}
	
	// calculate return date
	curr_tm->tm_mday += rentDays;
	mktime(curr_tm);
	end.day = curr_tm->tm_mday;
	end.month = curr_tm->tm_mon + 1;
	end.year = curr_tm->tm_year + 1900;
	e = to_string(end.day) + "-" + to_string(end.month) + '-' + to_string(end.year);

	show(clientId, clientName, tapeId, title, s, e);
	cout << "Start rent?\n 1. Yes\n 2. No\n";
	cout << "Your choice: "; cin >> choice;
	switch (choice) {
	case 1:
		newRent->clientId = clientId;
		newRent->tapeId = tapeId;
		newRent->rentStart = start;
		newRent->rentEnd = end;
		writeToFile(newRent);
		decreaseAmount(tapeId);
		break;
	case 2:
		cout << "New rent cancelled\n";
		system("pause");
		break;	
	default:
		system("cls");
		cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
		system("pause");
		break;
	}
	return true;
};




void tapeReturn(int searchID) {
	
	ifstream file;
	file.open("clients.dat", ios::binary);
	if (!file) {
		cout << "File could not be loaded\n";
	}
	else {
		file.seekg(0, ios::end);
		int clientsSize = file.tellg();
		clientsSize = clientsSize / sizeof(Rent);
		file.seekg(0, ios::beg);
		Rent *clients = new Rent[clientsSize];
		file.read((char*)clients, clientsSize * sizeof(Rent));
		file.close();
		for (int i = 0; i < clientsSize; i++) {
			if (clients[i].clientId == searchID) {
				//clients[i].tapeOnLease = 0;
			}			
		}
		ofstream file;
		file.open("customers.dat", ios::binary);
		file.close();
	}
}