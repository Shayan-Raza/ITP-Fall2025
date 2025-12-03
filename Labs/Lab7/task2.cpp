#include <iostream> 
using namespace std; 

int main() { 
    int arr[10];
    char direction;
    int rotations;
    
    while (true) {
        cout << "Enter 10 integers: ";
        bool valid = true;
        for (int i = 0; i < 10; i++) {
            cin >> arr[i];
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
            for (int i = 0; i < 10; i++) {
                arr[i] = 0;
            } 
        }
    }
    do { 
        cout<<"Enter rotation direction (L/R): ";
        cin>>direction;
        direction = toupper(direction);
        cin.clear();
        cin.ignore(10000, '\n');
    } while (direction != 'R' && direction != 'L');

    do {
        cout << "Enter number of rotations: ";
        cin >> rotations;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number."<<endl;
            continue; 
        }
    } while (rotations<=0 || rotations>10);

    if (direction == 'L') {
        // Left rotation
        for (int i = 0; i < rotations; i++) {
            int first = arr[0];
            for (int j = 0; j < 9; j++) {
                arr[j] = arr[j + 1];
            }
            arr[9] = first;
        }
    } else if (direction == 'R') {
        // Right rotation
        for (int i = 0; i < rotations; i++) {
            int last = arr[9];
            for (int j = 9; j > 0; j--) {
                arr[j] = arr[j - 1];
            }
            arr[0] = last;
        }
    }
    
    cout<<"Array after "<<rotations;
    if (direction == 'L') { 
        cout<<" left ";
    } else { 
        cout<<" right ";
    }
    cout<<"rotations"<<endl;
    for (int i =0; i<10;i++) { 
        cout<<arr[i]<<" ";
    }   
    return 0;
}
