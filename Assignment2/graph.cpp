#include <iostream> 
#include <cmath>
using namespace std; 

int main() { 
    int grid_x,grid_y;
    float y,xmin,xmax;
    char grid[20][80];
    
    while (true) {
        cout << "Enter minimum range: ";
        cin >> xmin;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Invalid input. Please enter a number."<<endl;
            continue;
        }

        cout << "Enter maximum range: ";
        cin>>xmax;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Invalid input. Please enter a number."<<endl;
            continue;
        }

        if (xmin >= xmax) {
            cout<<"Minimum must be less than maximum. Please try again."<<endl;
            continue;
        }

        break; 
    }

    for (int i=0;i<20;i++) { 
        for (int j = 0; j<80;j++) { 
            grid[i][j] = ' ';
        }
    }
    for (int i = 0;i<20;i++) { 
        grid[i][40] = '|';
    }
    for (int j = 0;j<80;j++) { 
        grid[10][j] = '-';
    }

    for (float x = xmin;x<=xmax;x=x+(M_PI/32)) { 
        grid_x = ((x-xmin)/(xmax-xmin))*(80-1);
        y = sin(-x);
        grid_y = ((y+1)/(2)) * (20-1);
        grid[grid_y][grid_x+2] = '*';
    }
    
    for (int i=0;i<20;i++) { 
        for (int j = 0; j<80;j++) { 
            cout<<grid[i][j];
        }
        cout<<endl;
    }
return 0;
}