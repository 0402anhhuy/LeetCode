#include<bits/stdc++.h>
using namespace std;

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2){
    int answer1 = 0, answer2 = 0;

    map<int, int> nums1Freq, nums2Freq;

    for(int num : nums1) nums1Freq[num]++;
    for(int num : nums2) nums2Freq[num]++;

    for(auto &[n, f] : nums1Freq){
        answer1 += nums2Freq[n];
    }

    for(auto &[n, f] : nums2Freq){
        if(f > 0){
            answer2 += nums1Freq[n];
        }
    }

    return {answer2, answer1};
}

int main(){
    int m, n; cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for(int i = 0; i < m; i++) cin >> nums1[i];
    for(int i = 0; i < n; i++) cin >> nums2[i];

    vector<int> ans = findIntersectionValues(nums1, nums2);
    cout << ans[0] << " " << ans[1];
    return 0;
}