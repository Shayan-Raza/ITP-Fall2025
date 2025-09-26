#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a;
	int b;
	int c;
	int discriminant;
	
	cout<<"Enter the coefficients of the quadratic equation (a,b,c)"<<endl;
	cin>>a>>b>>c;

	discriminant = (b*b)-4*a*c;

	if (discriminant>0) { 
		cout<<"The equation has two real roots: "<<(-b + sqrt(discriminant)) / (2 * a) <<" and " << (-b - sqrt(discriminant)) / (2 * a)<<endl;
	} else if (discriminant == 0) { 
		cout <<"The equation has one root only: " << (-b + sqrt(discriminant)) / (2 * a)<<endl;
	} else { 
		cout <<"The equation has no real roots";
	}

	return 0;
}