#pragma once
#include "Global.h"
class Neuron // ��Ԫ��
{
public:
	vector<double> weight;
	double bias;
	double delta;
	double weightedSummation;
	unsigned presentLayer;
	unsigned presentNeuron;
	Neuron() = delete;
	Neuron(unsigned PresentLayer, unsigned PresentNeuron);
	void calculate();
	void update();
};

