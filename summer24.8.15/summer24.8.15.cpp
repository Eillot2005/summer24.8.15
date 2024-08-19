//这个占用内存是很大的，有占用内存缩小4、5倍左右的，在acwing上有，但是我没看懂
#include <iostream>
#include <string>
using namespace std;

#define MOD  100000000;

int dp[5050][5050];
int ans[5050][5050];
int Count = 0;

int getLCSLength (string A, string B) {
	int m = A.length() - 1;
	int n = B.length() - 1;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				ans[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans[i][j] = ans[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			if (dp[i][j] == dp[i - 1][j]) {
				ans[i][j] += ans[i - 1][j];
			}
			if (dp[i][j] == dp[i][j - 1]) {
				ans[i][j] += ans[i][j - 1];
			}
			if (dp[i][j] == dp[i - 1][j - 1]) {
				ans[i][j] -= ans[i - 1][j - 1];
			}
			ans[i][j] %= MOD;
		}
	}
	Count = ans[m][n] % MOD;
	return dp[m][n];
}

int main() {
	string A, B;
	cin >> A >> B;
	int length = getLCSLength(A, B);
	cout << length << endl;
	cout << Count << endl;
	return 0;
}


/*
#include<iostream>
#define mod 100000000

using namespace std;

int i, j;
string s1, s2;
int dp[5001][5001];
int ans[5001][5001];
void solve() {

	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	for (i = 0; i < s1.size(); i++) ans[i][0] = 1;
	for (j = 0; j < s2.size(); j++) ans[0][j] = 1;

	for (i = 1; i < s1.size() - 1; i++) {
		for (j = 1; j < s2.size() - 1; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans[i][j] = ans[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			if (dp[i][j] == dp[i - 1][j]) ans[i][j] += ans[i - 1][j];
			if (dp[i][j] == dp[i][j - 1]) ans[i][j] += ans[i][j - 1];
			if (dp[i][j] == dp[i - 1][j - 1]) ans[i][j] -= ans[i - 1][j - 1];
			ans[i][j] %= mod;
		}
	}
	cout << dp[s1.size() - 2][s2.size() - 2] << endl;
	cout << ans[s1.size() - 2][s2.size() - 2] << endl;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}
*/