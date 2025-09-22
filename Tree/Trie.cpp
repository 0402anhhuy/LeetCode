#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* childNode[26];
    bool wordEnd;

    /*
        Constructor
        Initialize every index of childNode array with NULL
    */

    TrieNode(){
        for(int i = 0; i < 26; i++){
            childNode[i] = NULL;
        }
        wordEnd = false;
    }
};

int main(){
    return 0;
}
