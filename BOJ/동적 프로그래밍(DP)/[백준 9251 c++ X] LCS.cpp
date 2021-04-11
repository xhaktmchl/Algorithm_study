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

// [���� 9251 c++ *] LCS
// ����: LCS(���� �� ���� �κм���)�� ���̸� ���ϴ� ���� 
// ����:  �� ���� �Ȱ�
// Ǯ��: 
// ���� ������ ���� ���� ������ dp +1
// �ٸ� ������ ���� ����,�� �� ū�� dp ����
// ��ȭ�� : ���� ���� dp[i][j] = dp[i - 1][j - 1]+1
// �ٸ� ���� dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
#define MAX 1001

int dp[MAX][MAX];

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	string str1, str2;
	cin >> str1 >> str2;
	
	// dp
	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++) {
			if (str2[i-1] == str1[j-1]) // ���� ���ڸ� �� �������� ����dp +1
			{
				dp[i][j] = dp[i - 1][j - 1]+1; // ������ �밢�� +1
			}
			else {// �ٸ� ���ڸ� �ٸ� ������ ��� �� dp ���� ū�� ����
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // �����̶�, ���� ū ��
			}
		}
	}

	cout << dp[str2.size()][str1.size()];
	
	return 0;
}

