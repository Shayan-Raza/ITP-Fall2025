#include <iostream> 
#include <cmath>

using namespace std; 

int main() { 
	int radius;
	int side; 
	string shape; 
	int shape_num;
	
	cout<<"Enter your choice (Circle/Square/Triangle): ";
	cin>>shape;
	
	// If else
	if (shape == "Circle") {
		cout<<"Enter the radius of the circle: ";
		cin>>radius; 
		cout<<"The area of the circle is: "<< M_PI * radius * radius<<endl;
		cout<<"The perimeter of the circle is: " << M_PI * 2 * radius<<endl;
	} else if (shape == "Square"){
		cout<<"Enter the size of one side";
		cin>>side;
		cout<<"Area of the square is: "<<side*side<<endl;
		cout<<"Perimeter of the square is: "<<side *4<<endl;
	} else if (shape == "Triangle") {
		cout<<"Enter the size of one side";
		cin>>side;
		cout<<"The area of the triangle is: "<<(sqrt(3) / 4) * (side * side)<<endl;
		cout<<"The perimeter of the triangle is: "<< side*3<<endl;
	}
	
	// Switch case
	//Using if else as switch doesnt support strings 
	if (shape == "Circle") {
		shape_num = 0;
	} else if (shape == "Square"){
		shape_num = 1;
	} else if (shape == "Triangle") {
		shape_num = 2;
	}  

	switch (shape_num) { 
		case 0: 
			cout<<"Enter the radius of the circle: ";
			cin>>radius; 
			cout<<"The area of the circle is: "<< M_PI * radius * radius<<endl;
			cout<<"The perimeter of the circle is: " << M_PI * 2 * radius<<endl;
			break;
		case 1:
			cout<<"Enter the size of one side";
			cin>>side;
			cout<<"Area of the square is: "<<side*side<<endl;
			cout<<"Perimeter of the square is: "<<side *4<<endl;
			break;
		case 2:
			cout<<"Enter the size of one side";
			cin>>side;
			cout<<"The area of the triangle is: "<<(sqrt(3) / 4) * (side * side)<<endl;
			cout<<"The perimeter of the triangle is: "<< side*3<<endl;
			break;
	}
		
	return 0;
} 