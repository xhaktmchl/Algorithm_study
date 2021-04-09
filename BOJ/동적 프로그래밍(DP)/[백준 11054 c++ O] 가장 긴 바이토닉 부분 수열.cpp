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

// [���� 11054 c++ O] ���� �� ������� �κ� ����
// ����: �� ���Ҹ� �������� ���ʿ��� ���� �� �����ϴ� �κм���(���������� �κм���)�� ���̸� ���ϴ� ����
// ����1: dp�� �̿��� �� �ڸ����� ������ �����ϴ� �κм����� �ִ밪 ���� ���� ������ ���� �� dp ���ϰ� �װ��� ���� dp��
// Ǯ��: ���ʺ��� ������ ���� dp 2���� �迭�� ����
// �� �ڸ��� dp�� �ʱⰪ 1
// ���ʺ��� ���� �� �����ϴ� �κм��� dp ����
// �����ʺ��� ���� �� �����ϴ� �κм��� dp ����
// �� dp�� 2�� ���� ���� �ִ��� ����
// ����: ��,���� �ߺ��Ǽ� �ִ� -1 �ؾ���

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
#define MAX 1001

int n;
int ar[MAX];

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	// dp
	int dp[MAX][2];
	int max_dp = 0;
	// ���ʺ����� dp
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1; // �Ѱ��� ���� ���� 1
		for (int j = 0; j < i; j++) {
			if (ar[i] > ar[j]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}
	// �����ʺ����� dp
	for (int i = n-1; i >=0; i--) {
		dp[i][1]  = 1; // �Ѱ��� ���� ���� 1
		for (int j = n - 1; j > i; j--) {
			if (ar[i] > ar[j]) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}

	// �ִ�dp ���ϱ�
	for (int i = 0; i < n; i++) {
		max_dp = max(max_dp, dp[i][0] + dp[i][1] - 1); // i��° 2�� �ߺ��Ǽ� 1 ������
	}

	cout << max_dp;
	return 0;
}

