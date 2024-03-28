#include <bits/stdc++.h>
using namespace std;

// brutforce O(n^3)
 string longestPalindrome(string s) {
        int len=s.size();
        int index=-1;
        int maxlen=0;
        // looping over the string for substring
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                int isPalindrome=1;
                // checking the substring is palindrom of nor
                for(int k=i;k<=j;k++){
                    if(s[k]!=s[(j-(k-i))]){
                        isPalindrome=0;
                    }
                }
                if(isPalindrome==1 && j-i+1 > maxlen){
                    index=i;
                    maxlen=j-i+1;
                }
            }
        }
        string ans="";
        for(int i=index;i<index+maxlen;i++){
            ans+=s[i];
        }
        return ans;
    }

string longestPali(string s){ // using dynamic programing
    int n=s.size();
    // creating a boolean table
    bool dp[n][n];
    memset(dp,0,sizeof(dp));// setting all val 0

    int max_pal_len=1;// max posible length of palindrom min 1

    for(int i=0;i<n;i++){// for same char 
        dp[i][i]=1;
    }

    // for substrings of length 2
	int start = 0;
	for (int j = 0; j < n - 1; j++){
		// checking if there are 2 consecutive characters that are same
		if (s[j] == s[j + 1]){
			dp[j][j + 1] = true;
			start = j;
			max_pal_len = 2;
		}
	}

    	// now for longer length palindromes
	for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the end index of the substring from start index i and length k
            int j = i + k - 1;
 
            // check the sub-string from ith index to the jth index if s[i+1] to s[j-1] is a palindrome
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
				// if current palindrome length is larger than previous largest length, update the maximum length
                if (k > max_pal_len) {
                    start = i;
                    max_pal_len = k;
                }
            }
        }
    }
return s.substr(start,max_pal_len);

}

int expand_around_center(string s, int left, int right){
    int L = left, R = right;
	while (L >= 0 && R < s.size() && s[L] == s[R]) {
		L--;
		R++;
	}
	return R - L - 1;
}
string expand(string s){
    // if length of string is less than 1 return empty string
	if (s.length() < 1) return "";
	int start = 0, end = 0;
	for (int i = 0; i < s.size(); i++) {
		int len1 = expand_around_center(s, i, i);
		int len2 = expand_around_center(s, i, i + 1);
		int len = max(len1, len2);
		if (len > end - start) {
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	// return longest palindromic substring
	return s.substr(start, end - start + 1);
}

int main()
{
    string word="findnitianhere";
   // cout<<longestPalindrome(word);
   // cout<<longestPali(word);
    cout<<expand(word);
    return 0;
}