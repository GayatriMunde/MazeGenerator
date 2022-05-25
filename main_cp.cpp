#include<iostream>
#include<cstdlib>
#include<stack>
#include<ctime>

#define NORTH   0
#define SOUTH   1
#define EAST    2
#define WEST    3
#define SIZEX   9
#define SIZEY   9

using namespace std;

int nGood = 0;
int locX = 1, locY = 1;

void printGrid(char grid[SIZEY][SIZEX]){
    cout << endl << endl << endl;
    for (int i = 1; i < SIZEY-1; i++){
        for(int j = 0; j < SIZEX; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int moveEW(int direction, int x){
    if (direction == EAST)
        return x + 1;
    else if (direction == WEST)
        return x - 1;
    else
        return x;
}

int moveNS(int direction, int y){
    if (direction == NORTH)
        return y - 1;
    else if (direction == SOUTH)
        return y + 1;
    else
        return y;
}

bool isPossible(int x, int y, int direction, char grid[SIZEY][SIZEX]){
    x = moveEW(direction, x);
    y = moveNS(direction, y);

    if (grid[y][x] == '.' || x >= (SIZEX - 1) || x <= 0 || y <= 0 || y >= (SIZEY - 1)){
        return false;
    }

    if (direction == NORTH){
        if (grid[y][x-1] != '.' &&  grid[y-1][x] != '.' && grid[y][x+1] != '.' &&  grid[y-1][x-1] != '.' && grid[y-1][x+1] != '.'){
            return true;
        }
    }
    if (direction == SOUTH){
        if (grid[y][x-1] != '.' &&  grid[y+1][x] != '.' && grid[y][x+1] != '.' && grid[y+1][x-1] != '.' && grid[y+1][x+1] != '.'){
                return true;
        }
    }
    if (direction == EAST){
        if (grid[y][x+1] != '.' &&  grid[y-1][x] != '.' && grid[y+1][x] != '.' && grid[y-1][x+1] != '.' && grid[y+1][x+1] != '.'){
                return true;
        }
    }
    if (direction == WEST){
        if (grid[y][x-1] != '.' &&  grid[y-1][x] != '.' && grid[y+1][x] != '.' && grid[y-1][x-1] != '.' && grid[y+1][x-1] != '.'){
                return true;
        }
    }
    return false;
}


int main(){
    char grid[SIZEY][SIZEX];

    for (int i = 0; i < SIZEY; i++){
        for(int j = 0; j < SIZEX; j++){
                grid[i][j] = '#';
        }
    }

    // srand(time(0));

    stack<int> xValues;
    stack<int> yValues;

    nGood = 0;
    int direction = 0;

    do{
        for (int i = 0; i < 4; i++){
            if (isPossible(locX, locY, i, grid))
                nGood++;
        }

        if (nGood == 1){
            if (isPossible(locX, locY, NORTH, grid))
                locY = moveNS(NORTH,locY);
            else if (isPossible(locX, locY, SOUTH, grid))
                locY = moveNS(SOUTH,locY);
            else if (isPossible(locX, locY, EAST, grid))
                locX = moveEW(EAST,locX);
            else if (isPossible(locX, locY, WEST, grid))
                locX = moveEW(WEST,locX);
        }

        else if (nGood == 0){
            locX = xValues.top();
            locY = yValues.top();
            xValues.pop();
            yValues.pop();
        }

        else if (nGood > 1){
            xValues.push(locX);
            yValues.push(locY);

            do{
                direction = rand() % 4;
            }while (!isPossible(locX,locY,direction,grid));

            locX = moveEW(direction,locX);
            locY = moveNS(direction,locY);
        }

    grid[locY][locX] = '.';
    printGrid(grid);
    nGood = 0;

    }while(!xValues.empty());

    printGrid(grid);
    return 0;
}
//284278
