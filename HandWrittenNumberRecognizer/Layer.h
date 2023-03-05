#pragma once
#include "Global.h"
#include "Neuron.h"
class Layer // ≤„¿‡
{
public:
	unsigned presentLayer;
	vector<Neuron> neuron;
	vector<double> out;
	Layer(unsigned PresentLayer);
	void deliver();
	void fetch();
};
