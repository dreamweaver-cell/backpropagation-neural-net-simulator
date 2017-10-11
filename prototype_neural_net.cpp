//============================================================================
// Name        : 
// Author      :
// Version     :
// Copyright   :
// Description : A basic (classic) backpropagation neural net simulator in C++, ISO-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Neuron {};

typedef vector<Neuron> Layer;

class Net
{
public:
 Net (const vector<unsigned> &topology);
 void feedForward(const vector<double> &inputVals) {};
 void backProp(const vector<double> &targetVals) {};
 void getResults(vector<double> &resultVals) const {};

private:
 vector<Layer> m_layers; // m_layer[layerNum][neuronNum]

};

Net::Net (const vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
		// A new layer is made, now fill it with neurons, and
		// one bias neuron to the layer
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
     	{
			m_layers.back().push_back(Neuron());
			cout << "Made a neuron!" << endl;
	    }
	}
}

int main()
{
	// topology e.g. {3,2,1}
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net aNet(topology);           // Instantiate object myNet, it takes topology of net as argument

	vector<double> inputVals;
	aNet.feedForward(inputVals);   // Constructor for training the net

	vector<double> targetVals;
	aNet.backProp(targetVals);    // Tell the net what the values should be

	vector<double> resultVals;
	aNet.getResults(resultVals);  // After training store results
}
