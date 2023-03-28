#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include <sstream>
#include<string>
#include<ctime>
#include <map>
#include"Client.h"
#include"Tape.h"
#include"Constant.h"

void showAllRent();
char getName(int tapeID);
bool newRent();
void tapeReturn(int searchID);
tuple<int, string> clientLookup();
tuple<int, string> getClient();
tuple<int, string> getTapeId();