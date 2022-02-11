#include <iostream>
#include <vector>

using namespace std;

void printVec (vector<vector<char>>a){
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a[i].size(); ++j){
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}

bool checkString (vector<vector<char>>a, char& win, int sGor, int sVert, int gor, int vert){
    if (a[sGor][sVert] == ' '){return false;}
    for (int i = 1; i < a.size(); ++i){
        if (a[sGor][sVert] != a[sGor + gor * i][sVert + vert * i]) {break;}
        if (i == a.size() - 1){
            win = a[sGor][sVert];
            return true;
        }
    }
    return false;
}

bool genCheck (vector<vector<char>>a, char& win){
    if (checkString (a, win, 0, 0, 1, 1)) return true;
    if (checkString (a, win, 0, a.size() - 1, 1, -1)) return true;
    for (int i = 0; i < a.size(); ++i){
        if (checkString (a, win, i, 0, 0, 1)) return true;
        if (checkString (a, win, 0, i, 1, 0)) return true;
    }
    return false;
}

bool fillerStr (vector<vector<char>>a, char fil, int stGor, int stVert, int gor, int vert, int numinator){
    char win;
    for (int i = 0; numinator > 0 && i < a.size(); ++i){
        if (a[stGor + gor * i][stVert + vert * i] == ' '){
            a[stGor + gor * i][stVert + vert * i] = fil;
             --numinator;
        }
    }
    if (checkString(a, win, stGor, stVert, gor, vert)){return true;}
    return false;
}

bool nobodyWin (vector<vector<char>>a){
    char win;
    int emptyPl = 0;
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a[i].size(); ++j){
            if (a[i][j] == ' '){++emptyPl;}
        }
    }
    emptyPl = ((emptyPl - 1) / 2) + 1;
    if (fillerStr(a, 'x', 0, 0, 1, 1, emptyPl)){return false;}
    if (fillerStr(a, 'y', 0, 0, 1, 1, emptyPl)){return false;}
    if (fillerStr(a, 'x', 0, a.size()-1, 1, -1, emptyPl)){return false;}
    if (fillerStr(a, 'y', 0, a.size()-1, 1, -1, emptyPl)){return false;}
    for (int i = 0; i < a.size(); ++i){
        if (fillerStr(a, 'x', i, 0, 0, 1, emptyPl)){return false;}
        if (fillerStr(a, 'y', i, 0, 0, 1, emptyPl)){return false;}
        if (fillerStr(a, 'x', 0, i, 1, 0, emptyPl)){return false;}
        if (fillerStr(a, 'y', 0, i, 1, 0, emptyPl)){return false;}
    }
    return true;
}

int main (){
    int sz = 5;
    vector<vector<char>> desk (sz);
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j){
            desk[i].push_back(' ');
        }
    }
    desk = {{'y', 'y', 'x', 'x'},
            {'y', 'x', ' ', 'x'},
            {'x', ' ', ' ', 'y'},
            {'y', 'x', 'y', ' '}};
    printVec (desk);
    char win;

    if (genCheck (desk, win)){
        printf("Congratulation!!! %c -- win!!", win);
    }
    else if (nobodyWin (desk)){
        printf("Nobody win");
    }
    return 0;
}
