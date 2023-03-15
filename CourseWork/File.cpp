#pragma once
#include"File.h"
using namespace std;


template <typename T> tuple<T*, int> readFile(string filename) {
	ifstream file;
	file.open(filename, ios::binary);
	if (!file) {
		cout << "File doesn't exist.\n";
		T* t = new T[0];
		return make_tuple(t, 0);
	}
	else {
		file.seekg(0, ios::end);
		int size = file.tellg();
		size = size / sizeof(T);
		file.seekg(0, ios::beg);

		T* fileData = new T[size];
		file.read((char*)fileData, size * sizeof(T));
		file.close();
		cout << endl;

		return make_tuple(fileData, size);
	}
};


template <typename T> void writeToFile(const T* fileData, string filename) {
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


