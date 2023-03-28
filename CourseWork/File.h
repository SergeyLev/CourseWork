#pragma once
#include<iostream>
#include<fstream>
#include <any>
#include <memory>
#include <stdexcept>
#include<tuple>
#include<string>
#include "Constant.h"
using namespace std;


template <typename T> tuple<T*, int> readF(const string);
tuple<Tape*, int> readFile(Tape* fileData);
tuple<Client*, int> readFile(Client* fileData);
tuple<Rent*, int> readFile(Rent* fileData);


template <typename T> void writeToF(const T*, string);
void writeToFile(const Tape*);
void writeToFile(const Client*);
void writeToFile(const Rent*);

void sortWriteToFile(int, const Tape*, const Tape*);
void sortWriteToFile(int, const Client*, const Client*);


void truncateFile(const string fileName);
