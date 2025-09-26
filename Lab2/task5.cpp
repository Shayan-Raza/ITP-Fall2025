#include <iostream>

using namespace std;

int main() { 
	char secret; 
	char key; 
	char encrypted;
	char decrypted;
	
	cout<<"Enter secret character: ";
	cin>>secret;
	
	cout<<"Enter key: ";
	cin>>key;
	
	encrypted = secret ^ key;	

	cout<<"Encrypted Character: "<<encrypted<<endl;
	
	cout<<"Enter key: ";
	cin>>key;
	decrypted = key ^ encrypted;
	
	
	bool result = ((secret == decrypted) ? (0) : (1)); 
	((result==0) ? (cout<<"Decrypted Character: "<<secret) : (cout<<"Key error"));
	
	
	return 0;
}