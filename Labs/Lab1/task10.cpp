#include <iostream>
#include <cmath>

using namespace std; 

int main() { 
	int radius; 
	int area; 
	radius = 5; 
	area = M_PI * pow(radius,2);
	cout<<"Radius: "<<radius<<endl;
	cout<<"Area of Circle: "<<area;
	return 0;
}