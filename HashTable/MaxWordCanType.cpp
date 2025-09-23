#include<bits/stdc++.h>
using namespace std;


int canBeTypedWords(string text, string brokenLetters){
    int charFreq[26] = {0};
    for(char letter : brokenLetters){
        charFreq[letter - 'a'] = 1;
    }

    int ans = 0;
    bool valid = true;
    for(char c : text){
        if(c == ' '){
            if(valid) ans++;
            valid = true;
        } 
        else{
            if (charFreq[c - 'a']) valid = false;
        }
    }
    if(valid) ans++;
    return ans;
}


int main(){
    string text, brokenLetters;
    getline(cin, text);
    cin >> brokenLetters;
    int ans = canBeTypedWords(text, brokenLetters);
    cout << ans;
    return 0;
}