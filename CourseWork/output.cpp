#include"output.h"

using namespace std;

const string separator = " | ";
const string tapeId = separator + "Tape ID";
const string tapeTitle = separator + "Title";
const string amount = separator + "Ammount";
const string clientId = separator + "Client Id";
const string clientName = separator + "Client Full Name";
const string rentStart = separator + "Rent started";
const string rentEnd = separator + "Rent to end";
const string phone = separator + "Phone Number";
const string city = separator + "City";
const string street = separator + "Street";
const string houseNo = separator + "House No";
const string flat = separator + "Flat No";
const string zipCode = separator + "zip code";


int getLongest(string *data, int size) {
	int longest = 0;
	int arrSize = sizeof(data);
	for (int i = 0; i < size; i++) {
		longest = data[i].size() > longest ? data[i].size() : longest;
	}
	return longest;
};
tuple<int, string> showClientData(Client c, int name, int phoneNo, int longestCity, int longestStreet, int longestZip) {
	cout << separator << setw(clientId.size() - separator.size()) << left << c.Id
		<< separator << setw(name - separator.size()) << left << c.fullName
		<< separator << setw(phoneNo - separator.size()) << c.phone << left
		<< separator << setw(longestCity - separator.size()) << c.city << left
		<< separator << setw(longestStreet - separator.size()) << c.street << left
		<< separator << setw(houseNo.size() - separator.size()) << c.houseNo << left
		<< separator << setw(flat.size() - separator.size()) << c.flat << left
		<< separator << setw(longestZip - separator.size()) << c.zipCode << left
		<< separator << endl;
	return make_tuple(c.Id, c.fullName);
}

void show(Tape *tapes, int tapesSize) {	
	string hBorder;
	int hBorderSize;
	

	string* title = new string[tapesSize];
	for (int i = 0; i < tapesSize; i++) {
		title[i] = tapes[i].title;
	}
	
	// Header
	hBorderSize = tapeId.size() + getLongest(title, tapesSize) + amount.size();	
	hBorder.append(hBorderSize, '_');
	cout << "  " << hBorder << endl;
	cout << setw(tapeId.size()) << left << tapeId
		<< setw(getLongest(title, tapesSize) + separator.size()) << tapeTitle << left
		<< setw(amount.size()) << left << amount 
		<< separator << endl;
	cout << "  " << hBorder << endl;
	// Data
	for (int i = 0; i < tapesSize; i++) {
		if (tapes[i].ammount > 0) {
			cout << separator << setw(tapeId.size() - separator.size()) << left << tapes[i].Id
				<< separator << setw(getLongest(title, tapesSize)) << left << tapes[i].title
				<< separator << setw(amount.size() - separator.size()) << left << tapes[i].ammount
				<< separator << endl;
		}
	}
	// Footer
	cout << "  " << hBorder << endl << endl;
}
void show(Rent *rent, map<int, string> idClient, map<int, string> idTape, int size) {
	string hBorder;
	int hBorderSize;
	int longestName;
	int longestTitle;

	string* name = new string[size];
	string* title = new string[size];
	for (int i = 0; i < size; i++) {
		name[i] = idClient[rent[i].clientId];
		title[i] = idTape[rent[i].tapeId];
	}
	longestName = getLongest(name, size) + separator.size() > clientName.size() ? getLongest(name, size) + separator.size() : clientName.size();
	longestTitle = getLongest(title, size) + separator.size() > tapeTitle.size() ? getLongest(title, size) + separator.size() : tapeTitle.size();

	// Header
	hBorderSize = clientId.size() + longestName + tapeId.size() + longestTitle + rentStart.size() + rentEnd.size() -1;
	hBorder.append(hBorderSize, '_');
	cout << "  " << hBorder << endl;
	cout << setw(clientId.size()) << left << clientId
		<< setw(longestName) << clientName << left
		<< setw(tapeId.size()) << left << tapeId
		<< setw(longestTitle) << tapeTitle << left
		<< setw(rentStart.size()) << left << rentStart
		<< setw(rentEnd.size()) << left << rentEnd
		<< separator << endl;
	cout << "  " << hBorder << endl;
	// Data
	for (int i = 0; i < size; i++) {
		string s = to_string(rent[i].rentStart.day) + "-" + to_string(rent[i].rentStart.month) + '-' + to_string(rent[i].rentStart.year);
		string e = to_string(rent[i].rentEnd.day) + "-" + to_string(rent[i].rentEnd.month) + '-' + to_string(rent[i].rentEnd.year);

		cout << separator << setw(clientId.size() - separator.size()) << left << rent[i].clientId
			<< separator << setw(longestName - separator.size()) << idClient[rent[i].clientId] << left
			<< separator << setw(tapeId.size() - separator.size()) << left << rent[i].tapeId
			<< separator << setw(longestTitle - separator.size()) << idTape[rent[i].tapeId] << left
			<< separator << setw(rentStart.size() - separator.size()) << left << s
			<< separator << setw(rentEnd.size() - separator.size()) << left << e
			<< separator << endl;
	}
	// Footer
	cout << "  " << hBorder << endl << endl;

	
}
void show(int cId, string name, int tId, string title, string rStart, string rEnd) {
	string hBorder;
	int nameLenght = name.size() + separator.size() > clientName.size() ? name.size() + separator.size() : clientName.size();
	int titleLenght = title.size() + separator.size() > tapeTitle.size() ? title.size() + separator.size() : tapeTitle.size();
	int startLenght = rStart.size() + separator.size() > rentStart.size() ? rStart.size() + separator.size() : rentStart.size();
	int endLenght = rEnd.size() + separator.size() > rentEnd.size() ? rEnd.size() + separator.size() : rentEnd.size();

	// Header
	int hBorderSize = clientId.size() + nameLenght + tapeId.size() + titleLenght + startLenght + endLenght - 1;
	hBorder.append(hBorderSize, '_');
	cout << "  " << hBorder << endl;
	cout << setw(clientId.size()) << left << clientId
		<< setw(nameLenght) << clientName << left
		<< setw(tapeId.size()) << left << tapeId
		<< setw(titleLenght) << tapeTitle << left
		<< setw(startLenght) << left << rentStart
		<< setw(endLenght) << left << rentEnd
		<< separator << endl;
	cout << "  " << hBorder << endl;
	// Data
	cout << separator << setw(clientId.size() - separator.size()) << left << cId
		<< separator << setw(nameLenght - separator.size()) << left << name
		<< separator << setw(tapeId.size() - separator.size()) << left << tId
		<< separator << setw(titleLenght - separator.size()) << left << title
		<< separator << setw(startLenght - separator.size()) << left << rStart
		<< separator << setw(endLenght - separator.size()) << left << rEnd
		<< separator << endl;
	// Footer
	cout << "  " << hBorder << endl << endl;
}
tuple<int, string> show(Client* clients, int size, int id, string nameClient) {
	string s;
	string hBorder;
	tuple<int, string> idTmp;
	int hBorderSize;
	int longestName;
	int longestPhone;
	int longestCity;
	int longestStreet;
	int longestZip;

	string *name = new string[size];
	string *phoneNo = new string[size];
	string *cities = new string[size];
	string *streets = new string[size];
	string *zip = new string[size];
	for (int i = 0; i < size; i++) {
		name[i] = clients[i].fullName;
		phoneNo[i] = clients[i].phone;
		cities[i] = clients[i].city;
		streets[i] = clients[i].street;
		zip[i] = clients[i].zipCode;
	}
	longestName = getLongest(name, size) + separator.size() > clientName.size() ? getLongest(name, size) + separator.size() : clientName.size();
	longestPhone = getLongest(phoneNo, size) + separator.size() > phone.size() ? getLongest(phoneNo, size) + separator.size() : phone.size();
	longestCity = getLongest(cities, size) + separator.size() > city.size() ? getLongest(cities, size) + separator.size() : city.size();
	longestStreet = getLongest(streets, size) + separator.size() > street.size() ? getLongest(streets, size) + separator.size() : street.size();
	longestZip = getLongest(zip, size) + separator.size() > zipCode.size() ? getLongest(zip, size) + separator.size() : zipCode.size();


	// Header
	hBorderSize = clientId.size() + longestName + longestPhone + longestCity + longestStreet + houseNo.size() + flat.size() + longestZip -1;
	hBorder.append(hBorderSize, '_');
	cout << "  " << hBorder << endl;
	cout << setw(clientId.size()) << left << clientId
		<< setw(longestName) << clientName << left
		<< setw(longestPhone) << phone << left
		<< setw(longestCity) << city << left
		<< setw(longestStreet) << street << left
		<< setw(houseNo.size()) << houseNo << left
		<< setw(flat.size()) << flat << left
		<< setw(longestZip) << zipCode << left
		<< separator << endl;
	cout << "  " << hBorder << endl;


	// Data
	for (int i = 0; i < size; i++) {
		if (id != -1 && clients[i].Id == id) {
			idTmp = showClientData(clients[i], longestName, longestPhone, longestCity, longestStreet, longestZip);
		}
		else if (nameClient != "None") {
			s = clients[i].fullName;
			transform(nameClient.begin(), nameClient.end(), nameClient.begin(), ::tolower);
			transform(s.begin(), s.end(), s.begin(), ::tolower);

			idTmp = showClientData(clients[i], longestName, longestPhone, longestCity, longestStreet, longestZip);
		}
	}
	// Footer
	cout << "  " << hBorder << endl << endl;
	return idTmp;
}
void show(Client* clients, int size) {
	string s;
	string hBorder;
	tuple<int, string> idTmp;
	int hBorderSize;
	int longestName;
	int longestPhone;
	int longestCity;
	int longestStreet;
	int longestZip;

	string* name = new string[size];
	string* phoneNo = new string[size];
	string* cities = new string[size];
	string* streets = new string[size];
	string* zip = new string[size];
	for (int i = 0; i < size; i++) {
		name[i] = clients[i].fullName;
		phoneNo[i] = clients[i].phone;
		cities[i] = clients[i].city;
		streets[i] = clients[i].street;
		zip[i] = clients[i].zipCode;
	}
	longestName = getLongest(name, size) + separator.size() > clientName.size() ? getLongest(name, size) + separator.size() : clientName.size();
	longestPhone = getLongest(phoneNo, size) + separator.size() > phone.size() ? getLongest(phoneNo, size) + separator.size() : phone.size();
	longestCity = getLongest(cities, size) + separator.size() > city.size() ? getLongest(cities, size) + separator.size() : city.size();
	longestStreet = getLongest(streets, size) + separator.size() > street.size() ? getLongest(streets, size) + separator.size() : street.size();
	longestZip = getLongest(zip, size) + separator.size() > zipCode.size() ? getLongest(zip, size) + separator.size() : zipCode.size();


	// Header
	hBorderSize = clientId.size() + longestName + longestPhone + longestCity + longestStreet + houseNo.size() + flat.size() + longestZip - 1;
	hBorder.append(hBorderSize, '_');
	cout << "  " << hBorder << endl;
	cout << setw(clientId.size()) << left << clientId
		<< setw(longestName) << clientName << left
		<< setw(longestPhone) << phone << left
		<< setw(longestCity) << city << left
		<< setw(longestStreet) << street << left
		<< setw(houseNo.size()) << houseNo << left
		<< setw(flat.size()) << flat << left
		<< setw(longestZip) << zipCode << left
		<< separator << endl;
	cout << "  " << hBorder << endl;


	// Data
	for (int i = 0; i < size; i++) {		
		idTmp = showClientData(clients[i], longestName, longestPhone, longestCity, longestStreet, longestZip);
		
	}
	// Footer
	cout << "  " << hBorder << endl << endl;
}