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

// [���� 2504 c++ X] ��ȣ�� �� 
// ����:  ��ȣ���� �´��� �˻��ϰ� ��Ģ�� ���� ����� ���
// ����:  ��ȣ �˻��ϸ� �����ڸ� ���ÿ� �־�� -> ���ǹ� �ʹ� ����
// ����2: ��� ���� �Ẹ���� �й��Ģ�� ���� �������� ������� �ᱹ�� �׶��׶� () �ָ� ������ �� 
// Ǯ��: 
// ( [ ���ö����� tp ��2,3 ������
// �� ����ó�� ���� �ؾ� ��
// ) ] ���ö����� �� �����ְ� tp/ 2,3 ����
// �ᱹ ������ ���ڽİ� ����
// ������ ���� ������ ����ó�� �ѹ� �� �ؾ���

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
#define MAX 31

stack<char> st;
string str;

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	
	cin >> str;

	long long result = 0;
	int tp = 1;
	int n = str.size();

	for (int i = 0; i < n; i++) {
		// 1. '(' �� ���
		if (str[i] == '(') {
			st.push('(');
			tp *= 2;
		}
		// 2. '['�� ���
		else if (str[i] == '[') {
			st.push('[');
			tp *= 3;
		}

		// ��ȣ���� Ʋ�� ���
		else if (str[i] == ')' && (st.empty() || st.top() != '('))
		{
			
			cout << 0 << '\n';
			return 0;
		}
		else if (str[i] == ']' && (st.empty() || st.top() != '['))
		{
			cout << 0 << '\n';
			return 0;
		}
		// 3. ')' ���
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				result += tp;
			}
			tp /= 2;
			st.pop();
		}
		// 4. ']' ���
		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				result += tp;
			}
			tp /= 3;
			st.pop();
		}
		
		//cout << st.top() <<'\n';
	}

	if (!st.empty()) { // ���ܻ��� �ֱ� ������ ������ ���� �˻��ؼ� ��ȣ �˻�
		cout << 0 << '\n';
	}
	else
	{
		cout << result << '\n';
	}

	return 0;
}
