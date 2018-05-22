// CPP program to count least number
// of manipulations to have two strings
// set of same characters
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// return the count of manipulations
// required
int leastCount(string s1, string s2, int n)
{
	int count1[MAX_CHAR] = { 0 };
	int count2[MAX_CHAR] = { 0 };

	// count the number of different
	// characters in both strings
	for (int i = 0; i < n; i++) {
		count1[s1[i] - 'a'] += 1;
		count2[s2[i] - 'a'] += 1;
	}

	// check the difference in characters
	// by comparing count arrays
	int res = 0;
	for (int i = 0; i < MAX_CHAR; i++) {
		if (count1[i] != 0) {
			res += abs(count1[i] - count2[i]);
		}
	}
	return res;
}

// driver program
int main()
{
	string s1 = "abcd";
	string s2 = "cddd";
	int len = s1.length();
	int res = leastCount(s1, s2, len);
	cout << res << endl;
	return 0;
}
