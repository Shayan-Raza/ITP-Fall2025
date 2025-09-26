#include <iostream>
using namespace std;

int main() { 
    float w = 0.3;
    float b = 0.6;
    int num = 3;
    int trueval = 2*num*num+3*num-4; 
    float loss = 1.00;
    float perceptron;
    int epoch = 0;
    string inp;
    cout <<"Starting training with initial W: "<<w<<" , b: "<<b<<endl;
    cout <<"Target point: (3,f(3) = 23)"<<endl;
    cout<<"Press enter to start training: "<<endl;
    getline(cin, inp);
    while (loss>0.001) { 
        perceptron = (w*num)+b;
        loss = trueval - perceptron;
        cout<<"Epoch: "<<epoch<<endl;
        cout<<"Perceptron guess: y = "<<perceptron<<endl;
        cout<<"Loss: "<<loss<<endl;
        cout<<"Updated W: "<<w<<" Updated B: "<<b<<endl;
        cout<<endl; 
        w = w+0.01*loss*num;
        b = b+0.01*loss;
        epoch++;
    }
    cout << "Training finished after: " <<epoch<<" Epoch"<<endl;
    cout << "Final y: "<<perceptron<<endl;
    cout<<"final w: "<<w<<endl;
    cout<<"Final b: "<<b<<endl;
    if (perceptron == trueval) 
        cout<<"Perceptron learned the correct value";

    return 0;
}