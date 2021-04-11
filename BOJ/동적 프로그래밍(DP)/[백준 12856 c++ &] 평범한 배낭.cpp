#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c ���� �������
#include<string> // c++ ���ڿ� Ŭ����
#include<vector> // �����迭 ���̺귯��
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort�� unique ���
#include<cmath> // �����̳� ��Ʈ�Լ� ���
#include<cstring> // memset �Լ�
#include <set>
#include <map> // map����ü
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [���� 12856 c++ &] ����� �賶
// ����: ���濡 ���� �� �ִ� ���Դ�� �ִ� ��ġ�� ���ϴ� ����
// ����:  ��ͷ� ��� ����� �� Ž�� -> �ð��ʰ� ���� ����
// ����2: dp
// Ǯ��: 
// dp[i-1][j]// ���� Ž���ߴ� ���ǵ�θ� j�� ����� �� //���濡 ������ �ִ��� ������
// dp[i-1][j-w[i]] ���� Ž���ߴ� ���ǵ�� ����j-w[i]�� ����� ���� ������ ���濡 �ִ�  ���// ���濡 ���� �� ������ �ִ°Ͱ� �ȳִ°��� ��ġ ū�� ���椷

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
#define MAX 101

int w[MAX];
int v[MAX];
int dp[MAX][100001];

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	//dp
	for (int i = 1; i <= n; i++) { // i��° ����
		for (int j = 1; j <= k; j++) { // j ����
			if (w[i] <= j) { dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);} // ���� ���� �� �ִµ� �� �ִ� �Ͱ� �� ������ ���� ���Կ��� ���� ���� ū ���� dp �� ����
			else { dp[i][j] = dp[i - 1][j]; } // ���� ������ ��
		}
	}
	
	cout << dp[n][k];
	
	return 0;
}

