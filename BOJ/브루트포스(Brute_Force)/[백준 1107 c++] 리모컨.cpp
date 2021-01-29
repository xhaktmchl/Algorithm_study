#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c ���� �������
#include<string> // c++ ���ڿ� Ŭ����
#include<vector> // �����迭 ���̺귯��
#include<stack>
#include<queue>
#include<algorithm>  // sort�� unique ���
#include<cmath> // �����̳� ��Ʈ�Լ� ���
#include<cstring> // memset �Լ�
#include <set>

// [���� 1107 c++] ������ 
// ����: ä�κ��� ū���߿� �ּ�����,ä�κ��� ���� �� �߿� �ּ�����, 100���� ++��ư���� �ּ����� 
// �� �ּҰ� ã���� ������ ������ �� ������
// Ǯ��: �׷��� 0���� 1000000���� Ž���ϸ� �ּ������̸� ���峭 ��ư ������ �˻���
// ����: ä�ΰ� �ּ����̴� ä�ι�ư �����°� ���� ���ؾ� �Ѵ�
// ����: abs() : ���� 

#define MAX 1000001
using namespace std; // cin,cout ���ϰ� ��� ���̺귯��

int n;
int m;

int map[20] = { 0, };
int from100;
int numbutton;
int main()
{
	// IO �ӵ� ���
	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m ; 

	vector<int> v;

	for (int i = 0; i < m; i++)
	{
		int tp;
		cin >> tp;
		map[tp] = 1;
	}
	// n�� 100�� ��� ����
	if (n == 100)
	{
		cout << 0 << '\n';
		return 0;
	}
	// 100���� ++�̳� -- �� �ϴ� ���
	from100 = abs(100 - n); // abs(): ���� ���ϴ� �޼ҵ�
	int minnum = from100;
	// ä���Է��ؼ� ++,-- �ϴ� ���
	for (int i = 0; i < MAX; i++)
	{
		int c = 0;
		numbutton = abs(n - i); 
		string s = to_string(i);
		// �ּҰ����� ������
		if (minnum > numbutton)
		{
			// ���峭 ��ư �����ϴ��� �˻�
			for (int j = 0; j < s.length(); j++)
			{
				if (map[s[j]-'0'] != 0)
				{
					c++;
				}
			}
		}
		// ���峭 ��ư ���� �ȵ� ������ 
		if (c == 0)
		{
		    int tp = numbutton + s.length(); 
			minnum = min(minnum, tp);
		}
		
	}
	cout << minnum << '\n';
	
	
    return 0;
}



