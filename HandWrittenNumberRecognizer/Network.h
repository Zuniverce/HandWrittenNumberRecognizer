#pragma once
#include "Global.h"
#include "Layer.h"
class Network // ��������
{
public:
	unsigned zeroNeuronNum = -1;
	unsigned times;
	vector<Layer> layer;
	vector<double> truth;
	Network();
	void reset();
	void forward();
	void backward();
	double cost();
};
