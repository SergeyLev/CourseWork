#pragma once
#include<iostream>
#include"Client.h"
#include"Rent.h"
#include"Tape.h"
#include<fstream>
#include<ctime>
#include<string>
#include<cstdlib>

using namespace std;

int main() {
	int menu, submenu, searchType;
	int searchID;
	char title;

	string logo;
	string logoLine;
	string searchName;
	ifstream in;
	in.open("Text.txt");

	while (!in.eof()) {
		getline(in, logoLine);		
		logo += logoLine + "\n";		
	}
	in.close();
	

	cout << logo << endl;
	system("pause");
	
	
	do {
		system("cls");
		cout << "Main Menu\n 1. Customers\n 2. Stock\n 3. Rent\n 0. Exit"<< endl;
		cout << "Your choice: ";  cin >> menu;
		switch (menu){

			//customer menu
		case 1:
			do {
				system("cls");				
				cout << "Customers.\n 1. Show all\n 2. Show one\n 3. Create new\n 0. Previous menu" << endl;
				cout << "Your choice: "; cin >> submenu;
				switch (submenu) {
				case 1:
					system("cls");
					showAll();
					break;
				case 2:
					system("cls");
					cout << "Customers.\n 1. By Name\n 2. By Id\n 0. Previous menu" << endl;
					cout << "Your choice: "; cin >> searchType;
					switch (searchType)	{
					case 1:
						system("cls");
						cout << "Enter clients Name: "; cin >> searchName;
						showClient(-1, searchName);
						break;
					case 2:
						system("cls");
						cout << "Enter clients ID: "; cin >> searchID;
						showClient(searchID, "None");
						break;
					case 0:
						break;
					default:
						system("cls");
						cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
						system("pause");
						break;
					}
					break;
				case 3:
					system("cls");
					addNew();
					break;
				case 0:
					break;
				default:
					system("cls");
					cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
					system("pause");
					break;
				}
			} while (submenu != 0);
			break;

		// STOCK MENU
		case 2:
			do {
				system("cls");				
				cout << "Stock\n 1. Show all\n 2. Add new movie\n 3. Delete movie\n 0. Previous menu" << endl;
				cout << "Your choice: "; cin >> submenu;
				switch (submenu) {
				case 1:
					system("cls");
					showAllTape();
					break;
				case 2:
					system("cls");
					addNewTape();
					break;
				case 3:
					system("cls");
					deleteTape();
					break;
				case 0:
					break;
				default:
					system("cls");
					cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
					system("pause");
					break;
				}
				
			} while (submenu != 0);
			break;
		case 3:
			do {
				system("cls");
				cout << " 1. Show All\n 2. Rent\n 3. Return\n 0. Previous menu" << endl;
				cout << "Your choice: "; cin >> submenu;
				switch (submenu){
				case 1:
					system("cls");
					showAllRent();
					break;
				case 2:
					system("cls");
					newRent();
					break;
				case 3:
					system("cls");
					cout << "Customer ID: "; cin >> searchID;
					tapeReturn(searchID);
					break;
				case 0:
					break;
				default:
					system("cls");
					cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
					system("pause");
					break;
				}
			} while (submenu != 0);
		case 0:
			break;
		default:
			cout << "Make sure that you made a correct choice.\nPress any key to continue." << endl;
			system("pause");
			break;
		}
	} while (menu != 0);
	
	system("pause");
	return(0);
}