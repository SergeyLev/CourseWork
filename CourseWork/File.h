#pragma once
#include<fstream>
#include <any>
#include <memory>
#include <stdexcept>
#include<tuple>
#include<string>
#include "Constant.h"
using namespace std;

template <typename T> tuple<T*, int> readFile(const string);

template <typename T> void writeToFile(const T*, string);

