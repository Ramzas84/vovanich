#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Coord{
  int x, y;
  Coord (int a, int b) : x(a), y(b) {};
};

typedef vector<vector<int>> Desk;
typedef vector<vector<bool>> Visited;
typedef vector<vector<Coord>> Way;

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool chek (int z, int size){
    return (z >= 0) && (z < size);
}

int main (){
    int size = 5;
    Coord st(4, 4);
    Coord fin(4, 3);
    Desk desk;
    Visited v;
    Way w;
    for (int i = 0; i < size; ++i){
        desk.push_back(vector<int>(size, 0));
        v.push_back(vector<bool>(size, false));
        w.push_back(vector<Coord>(size, {0, 0}));
    }
    
    queue<Coord> q;
    q.push(st);
    v[st.x][st.y] = true;
    while (!q.empty()){
        if (v[fin.x][fin.y]) break;
        Coord cur = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i){
            Coord next(cur.x + dx[i], cur.y + dy[i]);
            if (!chek (next.x, size) || !chek(next.y, size)) continue;
            if (v[cur.x + dx[i]][cur.y + dy[i]]) continue;
            desk[next.x][next.y] = desk[cur.x][cur.y] + 1;
            v[next.x][next.y] = true;
            q.push(next);
            w[next.x][next.y] = cur;
        }
    }
    
    if (v[fin.x][fin.y]) {
        cout << desk[fin.x][fin.y]<< endl;
       
        vector<Coord> temp;
        Coord now = fin;
        while ((now.x != st.x) || (now.y != st.y)){
            temp.push_back(now);
            now = w[now.x][now.y];
        }
        for (int i = temp.size() - 1; i >= 0; --i){
            cout <<temp[i].x <<", " <<temp[i].y <<endl;
        }
        
        for (vector<int> i : desk){
            for (int j : i){
               printf("|%2d", j);
            }
            cout <<'|'<<endl;
        }
    }
    else {
        cout << "impossible";
    }
    
    
    return 0;
}
