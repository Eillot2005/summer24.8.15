#include<iostream>
using namespace std;
#define N 10000001
bool isprime[N];
long long num[N];
void getprime()
{
	isprime[1] = 1;
	for (int i = 2; i * 2 <= N; i++)
	{
		if (!isprime[i])
		{
			for (int j = i; j * i <= N; j++)
			{
				isprime[j * i] = 1;
				if (i != j)num[j * i] += 2;
				else num[j * i]++;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < N; i++)num[i] = 2;
	int n;
	cin >> n;
	getprime();
	while (n--)
	{
		long long m;
		cin >> m;
		if (m == 1)cout << 1 << endl;
		else if (!isprime[m])cout << 2 << endl;
		else cout << num[m] << endl;
	}
}