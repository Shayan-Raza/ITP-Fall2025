#include <iostream>
#include <vector>
using namespace std; 

int main() { 
    int r,n,num;
    do {
        cout<<"How many numbers to read: ";
        cin>>n;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number."<<endl;
            continue; 
        }
    } while (n<=0);
    vector <int> numbers(n);
    
    while (true) {
        cout << "Enter " << n << " integers: ";
        bool valid = true;
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter all numbers again.\n";
                valid = false;
                break;
            }
        }

        if (valid) { 
            break;
        }
        else { 
            numbers.clear();
            numbers.resize(n);
        } 
    }

    do {
        cout << "Enter number of rows: ";
        cin >> r;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number."<<endl;
            continue; 
        }
    } while (r<=0 || n%r!=0 || n<r);
    vector<vector<int>> rows(r);
    
    for (int i = 0; i < n; i++) {
        int rowIndex = i % r;
        rows[rowIndex].push_back(numbers[i]);
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j<n/r;j++) {
            cout << rows[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}