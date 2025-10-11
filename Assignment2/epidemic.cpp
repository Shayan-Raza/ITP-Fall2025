#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std; 

int main() { 
    int r = 5, t = 30; 
    int grid[20][20];
    int days_infected[20][20];
    int initial,x,y,severity;
    double infect_prob,worse_prob; 

    srand(time(0)); 
    
    do { 
        cout<<"Enter initial infected: ";
        cin>> initial;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue; 
        }
    } while (initial<=0 || initial>=400);
    
    do { 
        cout<<"Enter infected probability: ";
        cin>>infect_prob;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input. Please enter a number.\n";
            continue; 
        }
    } while ( infect_prob<=0 || infect_prob>=1);

    do { 
        cout<<"Enter worsening probability: ";
        cin>>worse_prob;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n"; 
            continue; 
        }
    } while (worse_prob<=0 || worse_prob>=1);

    // initial values for the grid 
    for (int i = 0; i<20;i++) { 
        for (int j = 0; j<20;j++) { 
            grid[i][j] = 0;
        }
    }

    // initial infected on the grid
    for (int i=0; i<=initial; i++) { 
        x = rand() % 20; 
        y = rand() %20;
        severity = (rand() % 9)+1;
        grid[x][y] = severity;
    }

    cout<<"Initial grid state: "<<endl;
    for (int i = 0; i<20;i++) { 
        for (int j = 0; j<20;j++) { 
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int day = 1; day <= t; day++) {
        int newGrid[20][20];
        int newDays[20][20];

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                newGrid[i][j] = grid[i][j];
                newDays[i][j] = days_infected[i][j];
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {

                // healthy
                if (grid[i][j] == 0) {
                    int maxSeverity = 0;
                    bool hasInfectedNeighbor = false;

                    // check 4 neighbors
                    int dx[4] = {-1, 1, 0, 0};
                    int dy[4] = {0, 0, -1, 1};

                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20) {
                            if (grid[nx][ny] > 0 && grid[nx][ny] < 10) {
                                hasInfectedNeighbor = true;
                                if (grid[nx][ny] > maxSeverity)
                                    maxSeverity = grid[nx][ny];
                            }
                        }
                    }

                    if (hasInfectedNeighbor) {
                        double r = (double)rand() / RAND_MAX;
                        if (r < infect_prob) {
                            int newSeverity = (rand() % maxSeverity) + 1;
                            newGrid[i][j] = newSeverity;
                            newDays[i][j] = 0;
                        }
                    }
                }

                // infected
                else if (grid[i][j] > 0 && grid[i][j] < 10) {
                    newDays[i][j]++;

                    double r = (double)rand() / RAND_MAX;
                    if (r < worse_prob) {
                        newGrid[i][j] += 1; // worsens
                        if (newGrid[i][j] > 9) {
                            newGrid[i][j] = 10; // dies
                        }
                    } else {
                        newGrid[i][j] -= 1; // improves
                        if (newGrid[i][j] < 1)
                            newGrid[i][j] = 1;
                    }

                    // Check if recovery time reached
                    if (newDays[i][j] >= r && newGrid[i][j] < 10) {
                        newGrid[i][j] = -1; // recovered
                        newDays[i][j] = 0;
                    }
                }

                // recovered
                else if (grid[i][j] == -1) {
                    // stays immune
                    newGrid[i][j] = -1;
                }

                // dead
                else if (grid[i][j] == 10) {
                    // stays dead
                    newGrid[i][j] = 10;
                }
            }
        }

        // Copy newGrid to grid
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                grid[i][j] = newGrid[i][j];
                days_infected[i][j] = newDays[i][j];
            }
        }
        
        int healthy = 0, recovered = 0, dead = 0,infected = 0; 
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (grid[i][j] == 0)
                    healthy++;
                else if (grid[i][j] == -1)
                    recovered++;
                else if (grid[i][j] == 10)
                    dead++;
                else if (grid[i][j] > 0 && grid[i][j] < 10)
                    infected++;
            }
        }
    cout<<"Day :"<<day<<" Healthy: "<<healthy<<" Infected: "<<infected<<" Recovered: "<<recovered<<" Dead: "<<dead<<endl;
    }
    
    cout<<"Final grid state: "<<endl;
    for (int i = 0; i<20;i++) { 
        for (int j = 0; j<20;j++) { 
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}