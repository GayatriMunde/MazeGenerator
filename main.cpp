#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void printMaze(int n, vector<vector<string>> maze){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j ++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}


void print(vector<pair<int, int>> neighbours){
    for (int i = 0; i < neighbours.size(); i++){
        cout << neighbours[i].first << " " << neighbours[i].second << endl;
    }
}


vector<vector<string>> intializeMaze(int n){
    vector<vector<string>> maze;
    for (int i = 0; i < n; i++){
        vector<string> row;
        for (int j = 0; j < n; j++){
            row.push_back("#");
        }
        maze.push_back(row);
    }

    return maze;
}


vector<pair<int, int>> getNeighbours(int n, pair<int, int> currentCell, vector<vector<string>> maze, map<int, int> visited){
    vector<pair<int, int>> neighbours;
    int x = currentCell.first, y = currentCell.second;
    map<int, int> movements = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (auto itr: movements){
        int temp_x = x + itr.first, temp_y = y + itr.second;
        if (temp_x >= 0 && temp_y >= 0 && temp_x < n && temp_y < n && visited[temp_x] != temp_y)
            neighbours.push_back(make_pair(temp_x, temp_y));
    }

    return neighbours;
}


void generateMaze(int n, pair<int, int> currentCell, vector<vector<string>> &maze, map<int, int> &visited){

    vector<pair<int, int>> neighbours = getNeighbours(n, currentCell, maze, visited);
    print(neighbours);

    // while(visitied.size() < n){
    //     vector<pair<int, int>> neighbours = getNeighbours(currentCell, maze, visited);
    //     print(neighbours);
    // }

}


int main(){
    int n;

    cout << "Enter dimension: ";
    cin >> n;

    vector<vector<string>> maze = intializeMaze(n);
    printMaze(n, maze);
    map<int, int> visited;
    pair<int, int> currentCell = make_pair(0, 0);
    generateMaze(n, currentCell, maze, visited);
    return 0;
}