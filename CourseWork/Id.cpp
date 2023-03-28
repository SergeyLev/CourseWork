#include"id.h"
using namespace std;

template <typename T> tuple<int, bool> generator(int size, T* data) {
	const int initialId = 1;
	int newID = -1;
	bool sortById;
	if (size == 0) { 
		return make_tuple(1, false);
	}
	else if (size == 1 && data[0].Id > initialId) { newID = data[0].Id - 1; }
	else if (size == 1 && data[0].Id == initialId) { newID = data[0].Id + 1; }

	// Fill ID "holes" if any
	for (int i = 0; i < size - 1; i++) {
		if (i == 0 && data[i].Id > 1) {
			newID = data[i].Id - 1;
			sortById = true;
		}
		else if (data[i].Id + 1 != data[i + 1].Id) { 
			newID = data[i].Id + 1; 
			sortById = true; 
		}
	}
	// If no "holes" make new ID
	if (newID == -1) {
		newID = data[size - 1].Id + 1; 
		sortById = false;
	}
	return make_tuple(newID, sortById);
}
tuple<int, bool> generateID(int size, Tape* data) {	
		return generator<Tape>(size, data);
	
}
tuple<int, bool> generateID(int size, Client* data) {		
		return generator<Client>(size, data);
}


string getById(int id, Tape* data, int size) {
	string result;
	for (int i = 0; i < size; i++) {
		if (data[i].Id == id) {
			result = data[i].title;
		}
	}
	return result;
}
string getById(int id, Client* data, int size) {
	string result;
	for (int i = 0; i < size; i++) {
		if (data[i].Id == id) {
			result = data[i].fullName;
		}
	}
	return result;
}