#pragma once
#include<iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include"Constant.h"

int getLongest(string*, int);
void show(Tape*, int);
void show(Rent*, map<int, string>, map<int, string>, int);
void show(int, string, int, string, string, string);

tuple<int, string> showClientData(Client, int, int, int, int, int);
tuple<int, string> show(Client*, int, int, string);
void show(Client*, int);
