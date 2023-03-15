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
tuple<Tape*, int> readFile(Tape* fileData, const string);
tuple<Client*, int> readFile(Client* fileData, const string);


template <typename T> void writeToF(const T*, string);
void writeToFile(const Tape*, string);
void writeToFile(const Client*, string);


void truncateFile(const string fileName);
