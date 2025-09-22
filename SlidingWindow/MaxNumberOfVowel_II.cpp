#include<bits/stdc++.h>
using namespace std;

long long countOfSubstrings(string word, int k){
    set<char> vowels = {'u', 'e', 'o', 'a', 'i'};
    int n = word.length(), consonant_count = 0, left = 0;
    long long res = 0;
    unordered_map<char, int> vowel_count;
    vector<int> nextConsonant(n, n);
    int lastConsonant = n;

    for(int i = n - 1; i >= 0; i--){
        nextConsonant[i] = lastConsonant;
        if(vowels.count(word[i]) == 0){
            lastConsonant = i;
        }
    }

    for(int right = 0; right < n; right++){
        if(vowels.count(word[right])){
            vowel_count[word[right]]++;
        }
        else{
            consonant_count++;
        }

        while(consonant_count > k){
            if(vowels.count(word[left])){
                vowel_count[word[left]]--;
                if(vowel_count[word[left]] == 0){
                    vowel_count.erase(word[left]);
                }
            }
            else{
                consonant_count--;
            }
            left++;
        }
        if(vowel_count.size() == 5 && consonant_count == k){
            res += (nextConsonant[right] - right);
        }
    }
    return res;
}

int main(){
    string s; cin >> s;
    int k; cin >> k;
    long long res = countOfSubstrings(s, k);
    cout << res;
    return 0;
}