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

// [���� 9184 c++ O] �ų��� �Լ� ����
// ����: �Է°��� ���� �־��� ����Լ��� �ð��ʰ��� �����ʴ� �ڵ� ¥��
// ����1: ��� �ð� ���� -> dp�� �Լ� ��ȯ�� dp�迭�� �����ϸ� ��ȯ
// Ǯ��: �־��� ��� ����Լ��� �ۼ��Ѵ�
// ��ȯ�� �� ������ �� �ڵ��̸� dp �迭 �ٷ� ��ȯ
// ������ �ʵǾ������� dp �迭�� ��Ͱ� �����ϸ� ��ȯ

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
#define MAX 51

int dp[MAX][MAX][MAX];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) { return 1; }
	else if (a > 20 || b > 20 || c > 20) {
		if (dp[a][b][c] == 0) { return dp[a][b][c] = w(20, 20, 20); } // ���� �ʉ����� �����ϸ� ��ȯ
		else { return  dp[a][b][c]; } // ���� ������ �ٷ� ��ȯ
		
	}
	else if (a < b && b < c) {
		if (dp[a][b][c] == 0) { return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); }
		else { return  dp[a][b][c]; }
	}
	else { 
		if (dp[a][b][c] == 0) { return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); }
		else { return  dp[a][b][c]; }
	}
}

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	int x, y, z;
	while (1) {
		cin >> x >> y >> z;
		if (x == -1 && y == -1 && z == -1) { break; }
		printf("w(%d, %d, %d) = %d\n", x, y, z, w(x, y, z));
	}

	return 0;
}

