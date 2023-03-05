#include "Network.h"
#include "Definition.h"
Network::Network()
{
	// 随机数种子
	srand((unsigned)time(NULL));
	// 构建神经网络结构
	unsigned layerNum;
	cout << "神经网络隐藏层数:" << endl;
	cin >> layerNum;
	layerNum += 2; // 加上输入层和输出层
	layer.push_back(Layer(0));
	for (unsigned i = 1; i < layerNum; i++)
	{
		layer.push_back(Layer(i));
	}
	// 输入正解
	/*for (unsigned i = 0; i < layer[layer.size() - 1].neuron.size(); i++)
	{
		double inValue;
		cout << "正解 " << i << " :" << endl;
		cin >> inValue;
		truth.push_back(inValue);
	}*/
	int t;
	fin >> t;
	if (t == 0)
	{
		truth.push_back(1);
		truth.push_back(0);
	}
	else
	{
		truth.push_back(0);
		truth.push_back(1);
	}
	// 循环次数
	cout << "学习次数:" << endl;
	cin >> times;
}

void Network::reset()
{
	layer[0] = Layer(0);
	int t;
	fin >> t;
	if (t == 0)
	{
		truth[0] = 1;
		truth[1] = 0;
	}
	else
	{
		truth[0] = 0;
		truth[1] = 1;
	}
	/*if (t == 0)
	{
		truth.push_back(1);
		truth.push_back(0);
	}
	else
	{
		truth.push_back(0);
		truth.push_back(1);
	}*/
}

void Network::forward()
{
	for (unsigned i = 1; i < layer.size(); i++)
	{
		layer[i].deliver();
	}
}

void Network::backward()
{
	for (unsigned i = unsigned(layer.size() - 1); i > 0; i--)
	{
		layer[i].fetch();
	}
}

double Network::cost()
{
	double C = 0;
	for (unsigned i = 0; i < layer[layer.size() - 1].neuron.size(); i++)
	{
		C += SQR(layer[layer.size() - 1].out[i] - truth[i]);
	}
	return 0.5 * C;
}
