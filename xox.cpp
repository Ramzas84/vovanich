#include <iostream>

void printArr (char** desk, int sz){
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j){
            printf("%c ", desk[i][j]);
        }
        printf("\n");
    }
}

bool chechStr (char** arr, int sz, char &win){
    for (int i = 0; i < sz; ++i){
        for (int j = 1; j < sz; ++j){
            if (arr[i][j] != arr[i][0]){break;}
            if (j == sz - 1) {
                win = arr[i][0];
                return true;
            }
        }
    }
    return false;
}

bool checkColmn(char** arr, int sz, char &win){
    if (chechStr(arr, sz, win)){return true;}
    for (int i = 0; i < sz; ++i){
        for (int j = 1; j < sz; ++j){
            if (arr[j][i] != arr[0][i]){break;}
            if (j == sz - 1) {
                win = arr[0][i];
                return true;
            }
        }
    }
    return false;
}

bool checkDiag(char** arr, int sz, char &win) {
    if  (checkColmn(arr, sz, win)){return true;}
    for (int i = 1; i < sz; ++i){
        if (arr[i][i] != arr[0][0]) break;
        if (i == sz - 1) {
            win = arr[0][0];
            return true;
        }
    }
    for (int i = 1; i < sz; ++i){
        if (arr[i][sz - 1 - i] != arr[0][sz - 1]) break;
        if (i == sz - 1) {
            win = arr[0][sz - 1];
            return true;
        }
    }
    return false;
}


int main (){
    int sz = 3;
    char** desk;
    desk = new char*[sz];
    for (int i = 0; i < sz; ++i){
        desk[i] = new char[sz];
    }

    desk[0][0] = 'z';
    desk[0][1] = 'x';
    desk[0][2] = '3';
    desk[1][0] = 'h';
    desk[1][1] = '3';
    desk[1][2] = 'x';
    desk[2][0] = '3';
    desk[2][1] = 'h';
    desk[2][2] = 'z';

    printArr (desk, sz);
    char win;
    if (checkDiag(desk, sz, win)){
        printf("%c -- win!!", win);
    }

    return 0;
}
