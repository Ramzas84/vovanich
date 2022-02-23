#include <iostream>

using namespace std;

void prnt (int desk[30][30]){
    for (int i = 0; i < 30; ++i){
        for (int j = 0; j < 30; ++j){
            if (desk[i][j] == 0) {printf("|_");}
            else if (desk[i][j] == 100){printf("FN");}
            else {printf("%2d", desk[i][j]);}
        }
        printf("|\n");
    }
}

struct Coords {
    int i;
    int j;
    Coords (int a, int b) : i(a), j(b) {}
    friend bool operator== (Coords a, Coords b);
};
bool operator== (Coords a, Coords b){
    if ((a.i == b.i) && (a.j == b.j)){return true;}
    return false;
}
Coords mov (Coords now, int i, int j){
    Coords a (now.i + i, now.j + j);
    return a;
}

Coords posMoov (Coords now, Coords fin){
    if (mov(now, 1, 2) == fin) return fin;
    if (mov(now, 1, -2) == fin) return fin;
    if (mov(now, -1, 2) == fin) return fin;
    if (mov(now, -1, -2) == fin) return fin;
    if (mov(now, 2, 1) == fin) return fin;
    if (mov(now, 2, -1) == fin) return fin;
    if (mov(now, -2, 1) == fin) return fin;
    if (mov(now, -2, -1) == fin) return fin;
}



Coords nextStep (int iNow, int jNow, int iFin, int jFin){
    int iVec  = 1;
    if ((iFin - iNow) < 0) {iVec = -1;}
    int jVec  = 1;
    if ((jFin - jNow) < 0) {jVec = -1;}
    int iSum = iFin - iNow;
    if (iSum < 0) {iSum *= -1;}
    int jSum = jFin - jNow;
    if (jSum < 0) {jSum *= -1;}
    if (iSum < jSum){
        return Coords(iNow + iVec, jNow + jVec * 2);
    }
    return Coords(iNow + iVec * 2, jNow + jVec);
}

void founder (Coords now, Coords fin){
    int desk[30][30] = {0};
    int a = 1;
    desk[now.i][now.j] = a++;
    desk[fin.i][fin.j] = 100;
    while((((fin.i - now.i) < -2) || ((fin.i - now.i) > 2)) ||
            (((fin.j - now.j) < -2) || ((fin.j - now.j) > 2))){
        now = nextStep (now.i, now.j, fin.i, fin.j);
        desk[now.i][now.j] = a++;
    }
    if (posMoov(now,fin) == fin){
        desk[fin.i][fin.j] = a;
        now = fin;
    }
    else {
        if (posMoov(Coords(now.i + 1, now.j + 2),fin) == fin){
            desk[now.i + 1][now.j + 2] = a++;
            desk[fin.i][fin.j] = a;
        }
        if (posMoov(Coords(now.i + 1, now.j - 2),fin) == fin){
            desk[now.i + 1][now.j - 2] = a++;
            desk[fin.i][fin.j] = a;
        }
        if (posMoov(Coords(now.i - 1, now.j + 2),fin) == fin){
            desk[now.i - 1][now.j + 2] = a++;
            desk[fin.i][fin.j] = a;
        }
        if (posMoov(Coords(now.i - 1, now.j - 2),fin) == fin){
            desk[now.i - 1][now.j - 2] = a++;
            desk[fin.i][fin.j] = a;
        }
        if (posMoov(Coords(now.i + 2, now.j + 1),fin) == fin){
            desk[now.i + 2][now.j + 1] = a++;
            desk[fin.i][fin.j] = a;
        }
        if (posMoov(Coords(now.i + 2, now.j - 1),fin) == fin){
            desk[now.i + 2][now.j - 1] = a++;
            desk[fin.i][fin.j] = a;
        }
        if (posMoov(Coords(now.i - 2, now.j + 1),fin) == fin){
            desk[now.i - 2][now.j + 1] = a++;
            desk[fin.i][fin.j] = a;
        }
        if (posMoov(Coords(now.i - 2, now.j - 1),fin) == fin){
            desk[now.i - 2][now.j - 1] = a++;
            desk[fin.i][fin.j] = a;
        }

    }

    prnt(desk);

    printf("CoordNow = %d:%d", now.i, now.j);

}

int main (){

    Coords n(25,25);
    Coords f(6,4);
    founder (n, f);

    return 0;
}
