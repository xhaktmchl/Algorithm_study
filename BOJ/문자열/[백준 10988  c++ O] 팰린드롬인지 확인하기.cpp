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

// [���� 10988  c++ O] �Ӹ�������� Ȯ���ϱ�
// ����: �Ųٷ� �ص� ���� ���ڿ��� �Ӹ�������� Ȯ���ϱ�
// ����: ����Ž������ ���ڿ��� �յڿ��� ���� ��
// Ǯ��: �ݺ������� �յ� ���ú��ϸ� �Ӹ������ �ƴϸ� 0���

using namespace std; // cin,cout ���ϰ� ��� ���̺귯��
#define MAX 51

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[s.size() - i - 1]) { cout << 0; return 0; }
	}
	cout << 1;
	
	return 0;
}



