#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void prnt (int** desk, int size){
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (desk[i][j] == 0){
                printf ("|__");
            }
            else {
                printf("|%2d", desk[i][j]);
            }
        }
        printf ("|\n");
    }
}

struct Coord {
    int x;
    int y;
Coord() : x(0), y(0) {}
Coord(int a, int b) : x(b), y(a) {}
};

Coord moove (Coord st, const Coord moove){
    Coord fn(st.x + moove.x, st.y + moove.y);
    return fn;
}

void possibleMoove (int** desk, int size, Coord st, int step, queue<Coord>& q){
    vector<Coord> mv {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                    {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
    for (Coord vec : mv){
        Coord cur = moove(st, vec);
        if (((cur.x >= 0) && (cur.y >=0)) && ((cur.x < size) && (cur.y < size)) && desk[cur.y][cur.x] == 0){
            desk[cur.y][cur.x] = step;
            q.push(cur);
        }
    }
}

void lookFoFin (int** desk, int size, Coord st, Coord fin){
    int step = 1;
    queue<Coord> q;
    q.push(st);
    while (desk[fin.x][fin.y] == 0){
        if (q.empty()){
            printf ("Impossibl\n");
            break;
        }
        queue<Coord> q1;
        while (!q.empty()){
            possibleMoove (desk, size, q.front(), step, q1);
            q.pop();
        }
        ++step;
        q = q1;
    }
}

int main (){
    int size = 3;
    int** desk;
    desk = new int*[size];
    for (int i = 0; i < size; ++i){
        desk[i] = new int[size];
    }
    Coord start (1, 0);
    Coord fin (1, 1);
    desk[start.x][start.y] = -1;
    
    //queue<Coord>q;
    
    //possibleMoove(desk, size, start, 1, q);
    lookFoFin(desk, size, start, fin);
    
    prnt (desk, size);
    
    return 0;
}
