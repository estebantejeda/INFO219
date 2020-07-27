#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void findnm(string text, int *x, int *y);
void initArray(string **Array, int x, int y);
void initArray(string *Array, int x);
void wordToArray(string **Array, int iteration);
void wordToArray(string *Array, int iteration);
bool searchPosLetter(string **Grid, int x, int y, string letter, int *a, int *b);
bool isLetterEqual(string a, string b);
bool searchRight(string **Grid, string word, int x, int y);
bool searchLeft(string **Grid, string word, int x, int y);
bool searchUp(string **Grid, string word, int x, int y);
bool searchDown(string **Grid, string word, int x, int y);
void printArray(string **Array, int x, int y);
void printArray(string *Array, int x);

int main(){
  
    string text;
    int m, n;
    int w;

    //Grid
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

    //Search
    for(int i = 0; i < w; i++){
        int u, v;
        searchPosLetter(G, m, n, W[i].substr(0,1) ,&u, &v);
        if(isLetterEqual(G[u][v+1], W[i].substr(1,2)) && searchRight(G, W[i], u, v)) cout << u << " " << v << endl;
        // if(isLetterEqual(G[u][v-1], W[i].substr(1,2)) && searchLeft(G, W[i], u, v)) cout << u << " " << v << endl;
        // if(isLetterEqual(G[u+1][v], W[i].substr(1,2)) && searchUp(G, W[i], u, v)) cout << u << " " << v << endl; 
        // if(isLetterEqual(G[u-1][v], W[i].substr(1,2)) && searchDown(G, W[i], u, v)) cout << u << " " << v << endl; 
    }

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

bool searchPosLetter(string **Grid, int x, int y, string letter, int *a, int *b){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(Grid[i][j] == letter){
                *a = i+1;
                *b = j+1;
                return true;
            }
        }
    }
    *a = -1;
    *b = -1;
    return false;
}

bool isLetterEqual(string a, string b){
    if(a == b) return true;
    return false;
}

bool searchRight(string **Grid, string word, int x, int y){
    for(int i = 0; i < word.size(); i++){
        if(Grid[x][y+i] != word.substr(i,i+1)) return false;
    }
    return true;
}

bool searchLeft(string **Grid, string word, int x, int y){
    for(int i = 0; i < word.size(); i++){
        if(Grid[x][y-i] != word.substr(i,i+1)) return false;
    }
    return true;
}

bool searchUp(string **Grid, string word, int x, int y){
    for(int i = 0; i < word.size(); i++){
        if(Grid[x+i][y] != word.substr(i,i+1)) return false;
    }
    return true;
}

bool searchDown(string **Grid, string word, int x, int y){
    for(int i = 0; i < word.size(); i++){
        if(Grid[x-i][y] != word.substr(i,i+1)) return false;
    }
    return true;
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