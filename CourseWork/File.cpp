#pragma once
#include"File.h"
using namespace std;


template <typename T> tuple<T*, int> readF(T* fileData, string filename) {
	ifstream file;
	file.open(filename, ios::binary);
	if (!file) {
		cout << "File doesn't exist.\n";
		fileData = new T[0];
		return make_tuple(fileData, 0);
	}
	else {
		file.seekg(0, ios::end);
		int size = file.tellg();
		size = size / sizeof(T);
		file.seekg(0, ios::beg);

		fileData = new T[size];
		file.read((char*)fileData, size * sizeof(T));
		file.close();
		cout << endl;

		return make_tuple(fileData, size);
	}
};
tuple<Tape*, int> readFile(Tape* data) {
	return readF<Tape>(data, tapesFilename);
};
tuple<Client*, int> readFile(Client* data) {
	return readF<Client>(data, clientsFilename);
};
tuple<Rent*, int> readFile(Rent* data) {
	return readF<Rent>(data, clientsRentFilename);
};


template <typename T> void writeToF(const T* fileData, string filename) {
	ofstream file;
	file.open(filename, ios::binary | ios::app);

	try {
		if (!file) {
			throw invalid_argument("File doesn't exist, creating a new file.");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << '\n';
		file.close();
		fstream f;
		f.open(filename, fstream::in | fstream::out | fstream::trunc);
		f.close();
		file.open(filename, ios::binary | ios::app);
	}
	file.write((char*)fileData, sizeof(T));
	file.close();
};
void writeToFile(const Tape* data) {
	writeToF<Tape>(data, tapesFilename);
};
void writeToFile(const Client* data) {
	writeToF<Client>(data, clientsFilename);
};
void writeToFile(const Rent* data) {
	writeToF<Rent>(data, clientsRentFilename);
};


void sortWriteToFile(int size, const Tape* data, const Tape* newData) {
	truncateFile(tapesFilename);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (data[j].Id - 1 == i) {

				writeToFile(newData);
			}
			else if (newData->Id - 1 == i) {
				writeToFile(newData);
			}
		}
	}
}
void sortWriteToFile(int size, const Client* data, const Client* newData) {	
	truncateFile(clientsFilename);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (data[j].Id - 1 == i) {

				writeToFile(newData);
			}
			else if (newData->Id - 1 == i) {
				writeToFile(newData);
			}
		}
	}
	
}

void changeDataInFile(const Tape* tapes, int size) {
	truncateFile(tapesFilename);
	for (int i = 0; i < size; i++) {		
		writeToFile(&tapes[i]);
	}
}

void truncateFile(const string fileName) {
	ofstream file;
	file.open(fileName, ios::binary | ios::trunc);
	file.close();
};