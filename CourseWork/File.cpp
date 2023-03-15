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

tuple<Tape*, int> readFile(Tape* data, const string fileName) {
	return readF<Tape>(data, fileName);
};

tuple<Client*, int> readFile(Client* data, const string fileName) {
	return readF<Client>(data, fileName);
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

void writeToFile(const Tape* data, const string fileName) {
	writeToF<Tape>(data, fileName);
}

void writeToFile(const Client* data, const string fileName) {
	writeToF<Client>(data, fileName);
}


void truncateFile(const string fileName) {
	ofstream file;
	file.open(fileName, ios::binary | ios::trunc);
	file.close();
}