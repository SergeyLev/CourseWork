#pragma once
#include<iostream>
#include<cstdio>
#include <algorithm>
#include <iomanip>
#include"Constant.h"
#include"File.h"
#include"Id.h"
#include"output.h"


void showAllTape();
void addNewTape();
void deleteTape();
tuple<int, string> getTapeById(int);
void decreaseAmount(int);
void increaseAmount(int);