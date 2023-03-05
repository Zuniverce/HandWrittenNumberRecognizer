#include "Definition.h"
double eta = 0.1;
double flag = 0.6;
ifstream fin("Z:/project/program/learn/ArtificialIntelligence/NeuronNetwork/HandWrittenNumberRecognizer/HandWrittenNumberRecognizer/TrainingData");
Network network;
double randomDouble(double min, double max)
{
	return 1.0 * rand() / RAND_MAX * (max - min) + min;
}

double sigmoid(double x)
{
	return (1 / (1 + exp(-x)));
}

double a(double x)
{
	return sigmoid(x);
}

double a_(double x)
{
	return sigmoid(x) * (1 - sigmoid(x));
}

double SQR(double x)
{
	return x * x;
}