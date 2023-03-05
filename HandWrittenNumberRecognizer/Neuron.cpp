#include "Neuron.h"
#include "Definition.h"
Neuron::Neuron(unsigned PresentLayer, unsigned PresentNeuron)
{
	presentLayer = PresentLayer;
	presentNeuron = PresentNeuron;
	for (unsigned i = 0; i < network.layer[presentLayer - 1].neuron.size(); i++)
	{
		weight.push_back(randomDouble());
	}
	bias = randomDouble();
	delta = 0;
	weightedSummation = 0;
}

void Neuron::calculate()
{
	weightedSummation = 0;
	for (unsigned i = 0; i < network.layer[presentLayer - 1].neuron.size(); i++)
	{
		weightedSummation += weight[i]*network.layer[presentLayer - 1].out[i];
	}
	weightedSummation += bias;
	network.layer[presentLayer].out[presentNeuron] = sigmoid(weightedSummation);
}

void Neuron::update()
{
	if (presentLayer == network.layer.size() - 1)
	{
		delta = network.layer[presentLayer].out[presentNeuron] * a_(weightedSummation);
	}
	else
	{
		delta = 0;
		for (unsigned i = 0; i < network.layer[presentLayer + 1].neuron.size(); i++)
		{
			delta += network.layer[presentLayer + 1].neuron[i].delta *
				network.layer[presentLayer + 1].neuron[i].weight[presentNeuron];
		}
		delta *= a_(weightedSummation);
	}
	for (unsigned i = 0; i < network.layer[presentLayer - 1].neuron.size(); i++)
	{
		double deltaWeight = -eta * delta * network.layer[presentLayer - 1].out[i];
		weight[i] += deltaWeight;
	}
	double deltaBias = -eta * delta;
}
