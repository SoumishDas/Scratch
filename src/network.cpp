//Header Files
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <array>

using namespace std;




//Classes
class Node{
    
    public:

        //Creating Vectors for weights and biases
        vector<double> weights;
        
        double biasN;

        //Constructor
        Node(int numNodeIn){

            //The Loop enters all the inputs and weights from the array into their respective vectors
            for (int i = 0; i < numNodeIn; i++)
            {
                double z = (double)(rand() % 100) /100;;
                cout << z<<"##"<<endl;
                weights.push_back(z);
                
                
            }
            
            //The bias value of a particular Node
            biasN = (double)(rand() % 1000) /100;
            cout << biasN<<"#"<<endl;
        }
};


class Layer{
    public:

        //Vars
        int numNodesIn,numNodesOut;
        vector<Node> nodes;
        
        Layer(int NodesIn,int NodesOut){
            this->numNodesIn = NodesIn;
            this->numNodesOut = NodesOut;

            //Creates and adds Nodes as per requirement
            for (int i = 0; i < numNodesOut; i++)
            {

                //Creates a object of class Node
                Node N(numNodesIn);

                //Adds the object in the vector
                nodes.push_back(N);


            }
            
        }
        vector<double> calcOutput(double inputs[]){
            //Dynamic array for storing weighted inputs after computation
            vector<double> weightedInputs ;

            //For loop to iterate over the Outnodes and compute weighted inputs
            for (int nodeOut = 0; nodeOut < numNodesOut; nodeOut++)
            {
                // Adding Bias to the weighted input
                double weightedInput = nodes[nodeOut].biasN;

                // Adding all the inputs multiplied with weights 
                for (int nodeIn = 0; nodeIn < numNodesIn; nodeIn++)
                {
                    weightedInput += inputs[nodeOut] * nodes[nodeOut].weights[nodeIn];
                }
                weightedInputs.push_back(weightedInput);


            }
            return weightedInputs;
        }
};

class Neural_Net{

    public:

        //Variables
        vector<Layer> layout;
        int inputSize;
        int arraySize;
        int outputSize;

        Neural_Net(int a[], int S){

            arraySize = S;
            inputSize = a[0];
            outputSize = a[S-1];

            for (int i = 0; i < S-1; i++)
            {

                //Creates a object of class Layer
                Layer L(a[i],a[i+1]);

                //Adds the object in the vector
                layout.push_back(L);


            }



            //Testing
            // cout<<arraySize<<" ";
            // cout<<outputSize<<" ";
            // cout<<inputSize;

        }
};


//Main Function
int main() {
  
//   long double out =  input[0]*weight[0] + input[1]*weight[1] + input[2]*weight[2] + input[3]*weight[3] + input[4]*weight[4] + bias[0];

    // Setting random seed as current time
    // srand (static_cast <unsigned> (time(0)));

    
    // double inp[3] = {2.5,2.5,1.5};
    // vector<double> out = layer.calcOutput(inp);
    
    int a[3] = {2,3,2};

    Neural_Net NN(a, sizeof(a)/sizeof(a[0]));
    
}