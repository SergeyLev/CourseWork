#pragma once
#include"Client.h"
using namespace std;


//SHOW ALL CLIENT WITH TAPES RENTED
void showAll() {
	int clientsSize;
	Client* clients;

	tie(clients, clientsSize) = readFile(new Client);
	show(clients, clientsSize);
	system("pause");
}


//ADD NEW CLIENT
tuple<int, string> addNew() {
	int newID;
	int clientsSize = 0;
	bool sortById;
	Client* clients;
	Client *newClient = new Client[1];
	
	tie(clients, clientsSize) = readFile(new Client);
	system("cls");
	// Auto generate ID	
	tie(newID, sortById) = generateID(clientsSize, clients);

	// Get input
	string tmpString;
	newClient->Id = newID;
	cout << "Enter Full Name: ";
	getline(cin >> ws, tmpString);
	strcpy(newClient->fullName, tmpString.c_str());
	cout << "Phone No: ";
	getline(cin >> ws, tmpString);
	strcpy(newClient->phone, tmpString.c_str());
	cout << "City: ";
	getline(cin >> ws, tmpString);
	strcpy(newClient->city, tmpString.c_str());	
	cout << "Street: ";
	getline(cin >> ws, tmpString);
	strcpy(newClient->street, tmpString.c_str());
	cout << "House No: "; cin >> newClient->houseNo;
	cout << "Flat No: "; cin >> newClient->flat;
	cout << "ZIP Code: ";
	getline(cin >> ws, tmpString);
	strcpy(newClient->zipCode, tmpString.c_str());
	
	// Save to file
	if (!sortById) {
		writeToFile(newClient);		
	}
	else {
		sortWriteToFile(clientsSize, clients, newClient);
	}
	system("cls");
	cout << "New Client: \"" << newClient->fullName << "\" added to the database." << endl;
	delete[]newClient;
	system("pause");
	return make_tuple(newClient->Id, newClient->fullName);
}


//SHOW DETAILED INFORMATION ABOUT CLIENT
tuple<int, string> showClient(int id, string name) {
	int clientsSize;
	tuple<int, string> resId;
	Client* clients;

	tie(clients, clientsSize) = readFile(new Client);
	resId = show(clients, clientsSize, id, name);




	
	
	/*
	cout << "Name: " << client->name << endl;
	cout << "Lastname: " << client->lastname << endl;
	cout << "Phone No: " << client->phone << endl;
	cout << "City: " << client->city << endl;
	cout << "Street: " << client->street << endl;
	cout << "Flat No: " << client->flat << endl;
	cout << "ZIP Code: " << client->zipCode << endl;
	cout << "Tape rented: " << client->tapeOnLease << endl;*/
	
	system("pause");
	return resId;
}
