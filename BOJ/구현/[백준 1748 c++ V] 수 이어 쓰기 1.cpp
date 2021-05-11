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

// [���� 1748 c++ V] �� �̾� ���� 1
// ����: �̾��� ���� �� �ڸ��� ���ϱ�
// ����:  ���ڿ��� ���� �� ���� �ڸ��� ���ϱ� -> �ð��ʰ� 
// ����2: ���� ��Ģ�� ã��
// Ǯ��: 
// �� �ڸ��� �϶� ������ ���ϱ�
// �� �ڸ��� �� = �����ڸ� (���� - ù��+1)*�ڸ���
// ��) (99-10+1)*2 = 180

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 

int n;
string ch;
int sum;

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n;
	ch = to_string(n);
	int len = ch.size();
	
	if (len == 1) // 1�ڸ� ���̸� �ٷ� ���ؾ� ��
	{
		cout << n;
		return 0; 
	}
	// 2�ڸ� �� �̻�
	int first = 1, last = 10;
	for (int i = 1; i < len; i++) {
		sum += ((last - 1) - first + 1) * i; // �� �ڸ��� �� = �����ڸ� (���� - ù��+1)*�ڸ���
		first *= 10;
		last *= 10;
	}
	sum += ((n) - first + 1) * len; 

	cout << sum;
	return 0;
}
