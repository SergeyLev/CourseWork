#pragma once
#include<tuple>
#include"Constant.h"


template <typename T> tuple<int, bool> generator(int, T*);
tuple<int, bool> generateID(int, Tape*);
tuple<int, bool> generateID(int, Client*);

string getById(int, Tape*, int);
string getById(int, Client*, int);


