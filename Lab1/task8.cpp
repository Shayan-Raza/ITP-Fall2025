#include <iostream>
#include <cmath>

using namespace std; 

int main() { 
	int a;
	int b; 
	int c; 
	a = 3;
	b = 4;
	c = sqrt(pow(a,2) + pow(b,2));
	cout << "Side A = "<<a<<endl;
	cout << "Side B = "<<b<<endl;
	cout << "Hypotenuse = "<< c;
	return 0;
}