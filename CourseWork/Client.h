#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
#include<algorithm>
#include <iomanip>
#include <map>
#include"Constant.h"
#include"File.h"
#include"Id.h"
#include"output.h"


void showAll();
tuple<int, string> addNew();
tuple<int, string> showClient(int id, string name);