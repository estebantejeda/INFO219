#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int enterInput();
void initArray(int **Array, int x, int y);
void randomArray(int **Array, int x, int y);
void pathArray(int **Array, int x, int y);
void printArray(int **Array, int x, int y);

int main(){
    int m = enterInput();
    int **M = new int*[m];
    initArray(M,m,m);
    randomArray(M,m,m);
    printArray(M,m,m);
    pathArray(M,m,m);
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
    Array[0][0] = 1;
    Array[x-1][y-1] = 1;
}

void pathArray(int **Array, int x, int y){
    int **A = new int*[x];
    initArray(A,x,y);
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++){
            if(Array[i][j] == 1){
                int U, V;
                if (j-1 < 0) U = 0;
                else U = A[i][j-1];
                if (i-1 < 0) V = 0;
                else V = A[i-1][j];
                A[i][j] = U+V;
                if (A[0][0] != 1) A[0][0] = 1;
            }
            else A[i][j] = 0;
        }
    }
    cout << A[x-1][y-1] << endl;
}

void printArray(int **Array, int x, int y){
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) cout << Array[i][j] << " ";
        cout << endl;
    }
}