#include <iostream>
#include <vector> 
using namespace std; 

const int MAX_COLS = 50;
const int MAX_ROWS = 50;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool is_valid_pos(int x, int y, int rows, int cols) { 
    if (x<=0 || x > rows || y<=0 || y>cols) { 
        return true;
    } else { 
        return false;
    }
};
bool solve_maze(char maze[][MAX_COLS], int rows, int cols, int x, int y,vector<vector<int>>& path) { 
    // check for out of bounds
    if (is_valid_pos(x,y,rows,cols)) { 
        return false;
    }

    // check for wall or already visited place
    if (maze[x][y] == '#' || maze[x][y] == '*') { 
        return false;
    } 
    // check for exit found
    if (maze[x][y] == 'E') { 
        path.push_back({x,y});
        return true;
    }

    //marking moves and adding to path
    char original_char = maze[x][y];
    if (original_char == '.') { 
        maze[x][y] = '*';
    }
    path.push_back({x,y});

    // making the moves
    for (int i = 0; i<4;i++) { 
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (solve_maze(maze,rows,cols,next_x,next_y,path)) { 
            return true;
        }
    }

    // backtracking
    path.pop_back();
    
    if (maze[x][y] == '*') { 
        maze[x][y] = '.';
    }
    
    return false;
}

int main() { 
    int rows,cols;
    int start_x = -1,start_y = -1;
    int start_count=0, end_count=0;
    do { 
        cout<<"Enter maze dimensions (row col): ";
        cin>>rows>>cols;
         if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue; 
        }
    } while (rows<0 || rows>50 || cols<0 || cols>50);

    char maze[MAX_ROWS][MAX_COLS];
    cout<<"Enter the maze row by row: \n";
    for (int i = 0; i<rows;i++) {
        string userinput; 
        do { 
            cout<<"Row "<<i+1<<" ";
            cin>>userinput;
        } while (userinput.length() != cols);
        for (int j = 0;j<cols;j++) { 
            maze[i][j] = userinput[j];
        }
    }

    for (int i = 0; i<rows;i++) { 
        for (int j = 0; j<cols;j++) { 
            if (maze[i][j] == 'S') { 
                start_x = i;
                start_y = j;
                start_count++;
            } else if (maze[i][j] == 'E') { 
                end_count++;
            }
        }
    }

    if (start_count != 1 || end_count != 1) { 
        cout<<"Error there should be only one start and end\n";
        return 1;
    }

    if (start_x == -1) { 
        cout<<"No starting position found\n";
        return 1;
    }

    vector<vector<int>> solution_path;
    char final_maze[MAX_COLS][MAX_ROWS];
    for (int i = 0; i<rows;i++) { 
        for (int j = 0; j<cols;j++) { 
            final_maze[i][j] = maze[i][j];
        }
    }

    if (solve_maze(final_maze,rows,cols,start_x,start_y,solution_path)) { 
        cout<<"Solution found\n";
        cout<<"Path length: "<<solution_path.size()<<endl;
        cout<<"Final Maze: \n";
        for (int i = 0; i<rows;i++) { 
            for (int j = 0; j<cols;j++) {
                cout<<final_maze[i][j];
            }
            cout<<endl;
        }
        for (int i = 0; i<solution_path.size();i++) { 
            cout<<"{"<<solution_path[i][0]<<","<<solution_path[i][1]<<"}";
            if (i<solution_path.size() - 1) { 
                cout<<" -> ";
            }
        }
    } else { 
        cout<<"No solution exists \n";
        cout<<"Explored maze: \n";
        for (int i = 0; i<rows;i++) { 
            for (int j = 0; j<cols;j++) {
                cout<<maze[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}