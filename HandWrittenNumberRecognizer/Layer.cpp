#include "Layer.h"
#include "Definition.h"
Layer::Layer(unsigned PresentLayer)
{
	presentLayer = PresentLayer;
	unsigned neuronNum;
	if (presentLayer)
	{
		cout << "��" << presentLayer << "�����Ԫ����:" << endl;
		cin >> neuronNum;
	}
	else
	{
		neuronNum = 12;
	}
	if (presentLayer)
	{
		for (unsigned i = 0; i < neuronNum; i++)
		{
			neuron.push_back(Neuron(presentLayer, i));
		}
		for (unsigned i = 0; i < network.layer[presentLayer - 1].out.size(); i++) //�п������
		{
			out.push_back(0);
		}
	}
	else
	{
		double inValue;
		for (unsigned i = 0; i < neuronNum; i++)
		{
			cout << "�������Ԫ " << i << " :" << endl;
			//cin >> inValue;
			fin >> inValue;
			out.push_back(inValue);
		}
	}
}

void Layer::deliver()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		neuron[i].calculate();
	}
}

void Layer::fetch()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		neuron[i].update();
	}
}