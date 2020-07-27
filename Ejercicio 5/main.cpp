#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int enterInput();
void initArray(int **Array, int x, int y);
void randomArray(int **Array, int x, int y);
void printArray(int **Array, int x, int y);

int main(){
    int m = enterInput();
    int **M = new int*[m];
    initArray(M,m,m);
    randomArray(M,m,m);
    printArray(M,m,m);
    return 0;
}

int enterInput(){
    int input;
    cin >> input;
    return input; 
}

void initArray(int **Array, int x, int y){
    for(int i = 0; i < x; i++) Array[i] = new int[y];
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) Array[i][j] = 0;
    }
}

void randomArray(int **Array, int x, int y){
    srand(time(NULL));
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) Array[i][j] = rand()%2;
    }
}

void printArray(int **Array, int x, int y){
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) cout << Array[i][j] << " ";
        cout << endl;
    }
}