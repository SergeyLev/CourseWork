#pragma once
#include<iostream>
#include"Rent.h"
#include"Client.h"
#include"Tape.h"
#include<fstream>
#include<ctime>
#include<string>
#include<ctime>
using namespace std;

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
			if (tapes[i].ID == tapeID) {
				return(*tapes[i].title);
			}
			else {
				cout << "Student not found." << endl;
			}
		}
	}
	return(0);
}

void newRent(int searchID, char title) {
	int days;
	string fileName = to_string(searchID);
	
	Client *client = new Client;

	ifstream file;
	file.open("clients.dat", ios::binary);
	if (!file) {
		cout << "File could not be loaded\n";
	}
	else {
		file.seekg(0, ios::end);
		int clientsSize = file.tellg();
		clientsSize = clientsSize / sizeof(Clients);
		file.seekg(0, ios::beg);
		Clients *clients = new Clients[clientsSize];
		file.read((char*)clients, clientsSize * sizeof(Clients));
		file.close();

		for (int i = 0; i < clientsSize; i++) {
			if (clients[i].ID == searchID) {
				clients[i].tapeOnLease = 1;
				clients[i].tapeTitle = title;
				cout << "Number of days to rent: "; cin >> days;
				time_t t = time(0) + days;
				struct tm * now = localtime(&t);
				char date;
				strftime(&date, sizeof now, "%F %T", now);
				clients[i].returnDate = date;

				ofstream file;
				file.open("clients.dat", ios::binary);

				if (!file) {
					cout << "File could not be loaded\n";
				}
				else {
					file.write((char*)clients, sizeof(Clients));
					file.close();
					delete[]clients;
				}
			}
		}
	}

	file.open("client_" + fileName + ".dat", ios::binary);
	if (!file) {
		cout << "File could not be loaded\n";
	}
	else {
		file.seekg(0, ios::end);
		int clientSize = file.tellg();
		clientSize = clientSize / sizeof(Client);
		file.seekg(0, ios::beg);
		Client *client = new Client[clientSize];
		file.read((char*)client, clientSize * sizeof(Client));
		file.close();
		
		client->tapeOnLease = title;

		ofstream file;
		file.open("client_" + fileName + ".dat", ios::binary);
		file.write((char*)client, sizeof(Client));
		file.close();
		delete[]client;
	}		
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
		clientsSize = clientsSize / sizeof(Clients);
		file.seekg(0, ios::beg);
		Clients *clients = new Clients[clientsSize];
		file.read((char*)clients, clientsSize * sizeof(Clients));
		file.close();
		for (int i = 0; i < clientsSize; i++) {
			if (clients[i].ID == searchID) {
				clients[i].tapeOnLease = 0;
			}			
		}
		ofstream file;
		file.open("customers.dat", ios::binary);
		file.close();
	}
}