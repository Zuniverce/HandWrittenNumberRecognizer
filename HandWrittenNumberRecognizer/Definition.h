#pragma once
#include "Global.h"
#include "Network.h"
extern double eta;
extern double flag;
extern ifstream fin;
extern Network network;
double randomDouble(double min = -RAND_MAX, double max = RAND_MAX);
double sigmoid(double x);
double a(double x);
double a_(double x);
double SQR(double x);