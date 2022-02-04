#include <iostream>



int main (){
    int sz = 3;
    char desk[sz][sz] = {{'r', 't', 'z'},
                        {'z', 'z', 'p'},
                        {'z', 'z', 'r'}};
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j <sz; ++j){
            printf("%c ", desk[i][j]);
        }
        printf("\n");
    }

    bool win = false;
    int i = 0;
    char winner;

    while (i < sz){
        int temp = 1;
        for (int j = 1; i <sz; ++j){
            if (desk[i][j] == desk[i][j-1]){
                ++temp;
            }
            else {
                break;
            }
        }
        if ((temp == sz) && (desk[i][0] != ' ')){
            win = true;
            winner = desk[i][0];
            printf("gorizontal! ");
            break;
        }
        else ++i;
    }

    if (!win) {
        i = 0;
        while (i < sz){
            int temp = 1;
            for (int j = 1; i <sz; ++j){
                if (desk[j][i] == desk[j - 1][i]){
                    ++temp;
                }
                else {
                    break;
                }
            }
            if ((temp == sz) && (desk[0][i] != ' ')){
                win = true;
                winner = desk[0][i];
                printf("vertikal! ");
                break;
            }
            else ++i;
        }
    }

    if (!win) {
        int temp = 1;
        for (i = 1; i < sz; ++i){
            if (desk[i][i] == desk[i - 1][i - 1]){
                ++temp;
            }
        }
        if (temp == sz){
            win = true;
            winner = desk[0][0];
            printf("easy diagonal! ");
        }
    }

    if (!win) {
        int temp = 1;
        for (i = 1; i < sz; ++i){
            if (desk[i][sz - 1 - i] == desk[i - 1][sz - i]){
                ++temp;
            }
        }
        if (temp == sz){
            win = true;
            winner = desk[0][sz - 1];
            printf("dif diagonal! ");
        }
    }

    if (win) {
        printf ("%c win!!", winner);
    }
    return 0;
}
