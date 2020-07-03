#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void findnm(string text, int *x, int *y);
void initArray(string **Array, int x, int y);
void initArray(string *Array, int x);
void wordToArray(string **Array, int iteration);
void wordToArray(string *Array, int iteration);
void printArray(string **Array, int x, int y);
void printArray(string *Array, int x);

int main(){

    string text;
    int m, n, w;

    //Grill
    getline(cin, text);
    findnm(text, &m, &n);
    string **G = new string*[m];
    initArray(G, m, n);
    wordToArray(G,m);
    
    //Word
    cin >> w;
    string *W = new string[w];
    initArray(W, w);
    wordToArray(W, w);

    
    



    return 0;
}

void findnm(string text, int *x, int *y){
    string m = text.substr(0,text.find(" "));
    string n = text.substr(text.find(" ")+1,text.size());
    *x = stoi(m);
    *y = stoi(n);
}

void initArray(string **Array, int x, int y){
    for(int i = 0; i < x; i++) Array[i] = new string[y];
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) Array[i][j] = " ";
    }
}

void initArray(string *Array, int x){
    for (int i = 0; i < x; i++) Array[i] = " ";
}

void wordToArray(string **Array, int iteration){
    for(int i = 0; i < iteration; i++){
        string word;
        cin >> word;
        for(int j = 0; j < word.size(); j++) Array[i][j] = word[j];
    }
}

void wordToArray(string *Array, int iteration){
    for(int i = 0; i < iteration; i++){
        string word;
        cin >> word;
        Array[i] = word;
    }
}

void printArray(string **Array, int x, int y){
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) cout << Array[i][j] << " ";
        cout << endl;
    }
}

void printArray(string *Array, int x){
    for(int i = 0; i < x; i++) cout << Array[i] << endl;
}