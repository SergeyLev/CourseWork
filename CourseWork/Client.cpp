#pragma once
#include<iostream>
#include"Client.h"
#include<fstream>
#include<ctime>
#include<string>
#include<algorithm>
using namespace std;


//ADD NEW CLIENT
void addNew() {
	int newID;
	Client *client = new Client[1];
	Clients *clients = new Clients[1];

//AUTO GENERATE ID
	fstream file;
	file.open("clients.dat", ios::in | ios::binary);

	if (!file) {
		cout << "File could not be loaded\n";

	}
	else {
		file.seekg(0, ios::end);
		int clientsSize = file.tellg();
		clientsSize = clientsSize / sizeof(Clients);

		if (clientsSize = 0) {
			newID = 1;
		}
		else {
			file.seekg(0, ios::beg);
			Clients *ID = new Clients[clientsSize];
			file.read((char*)ID, clientsSize * sizeof(Clients));
			file.close();
			newID = ID[clientsSize].ID + 1;
			delete[]ID;
		}
	//ADD NEW CLIENT
	clients->ID = newID;
	cout << "Name: "; cin >> client->name;
	cout << "Lastname: "; cin >> client->lastname;
	cout << "Phone No: "; cin >> client->phone;
	cout << "City: "; cin >> client->city;
	cout << "Street: "; cin >> client->street;
	cout << "House No: "; cin >> client->houseNo;
	cout << "Flat No: "; cin >> client->flat;
	cout << "ZIP Code: "; cin >> client->zipCode;
	
	string fileID = to_string(newID);
	ofstream file;
	file.open("clients.dat", ios::binary | ios::app);
	file.open("client_" + fileID + ".dat", ios::binary);

	if (!file) {
		cout << "File could not be loaded\n";
	}
	else {
		file.write((char*)clients, sizeof(Clients));
		file.write((char*)client, sizeof(Client));
		cout << "New client added to the database." << endl;
		system("pause");
	}
	file.close();
	delete[]clients;
	delete[]client;
	}
	system("pause");
}

//SHOW ALL CLIENT WITH TAPES RENTED
void showAll() {
	Clients swap;
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
		cout << endl;

		for (int i = 0; i < clientsSize - 1; i++) {
			for (int j = 0; j < (clientsSize - i - 1); j++) {
				if (clients[j].ID > clients[j + 1].ID) {
					swap = clients[j];
					clients[j] = clients[j + 1];
					clients[j + 1] = swap;
				}
			}
		}

		for (int i = 0; i < clientsSize; i++) {
			if (clients[i].tapeOnLease != 0) {
				cout << "Client ID: " << clients[i].ID;
				cout << " * Lastname: " << clients[i].lastname;
				cout << " * Tape: " << clients[i].tapeTitle;
				cout << " * Return Date: " << clients[i].returnDate << endl;
			}
		}
	}
	system("pause");
}

//SHOW DETAILED INFORMATION ABOUT CLIENT
void showOne(int fileID) {
	string fileName = to_string(fileID);
	ifstream file;
	file.open("client_"+fileName+".dat", ios::binary);
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
		cout << endl;

		cout << "Name: " << client->name << endl;
		cout << "Lastname: " << client->lastname << endl;
		cout << "Phone No: " << client->phone << endl;
		cout << "City: " << client->city << endl;
		cout << "Street: " << client->street << endl;
		cout << "Flat No: " << client->flat << endl;
		cout << "ZIP Code: " << client->zipCode << endl;
		cout << "Tape rented: " << client->tapeOnLease << endl;
	}
	system("pause");
}
