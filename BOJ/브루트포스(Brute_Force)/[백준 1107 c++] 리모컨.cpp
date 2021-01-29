#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수
#include <set>

// [백준 1107 c++] 리모컨 
// 접근: 채널보다 큰수중에 최소차이,채널보다 작은 수 중에 최소차이, 100에서 ++버튼으로 최소차이 
// 중 최소값 찾으려 했으나 저건이 넘 많아지
// 풀이: 그래서 0부터 1000000까지 탐색하며 최소차이이며 고장난 버튼 없는지 검사함
// 주의: 채널과 최소차이는 채널버튼 누르는것 까지 더해야 한다
// 개념: abs() : 절댓값 

#define MAX 1000001
using namespace std; // cin,cout 편하게 사용 라이브러리

int n;
int m;

int map[20] = { 0, };
int from100;
int numbutton;
int main()
{
	// IO 속도 향상
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
	// n이 100일 경우 제외
	if (n == 100)
	{
		cout << 0 << '\n';
		return 0;
	}
	// 100에서 ++이나 -- 만 하는 경우
	from100 = abs(100 - n); // abs(): 절댓값 구하는 메소드
	int minnum = from100;
	// 채널입력해서 ++,-- 하는 경우
	for (int i = 0; i < MAX; i++)
	{
		int c = 0;
		numbutton = abs(n - i); 
		string s = to_string(i);
		// 최소값보다 작으면
		if (minnum > numbutton)
		{
			// 고장난 버튼 포함하는지 검사
			for (int j = 0; j < s.length(); j++)
			{
				if (map[s[j]-'0'] != 0)
				{
					c++;
				}
			}
		}
		// 고장난 버튼 포함 안돼 있으면 
		if (c == 0)
		{
		    int tp = numbutton + s.length(); 
			minnum = min(minnum, tp);
		}
		
	}
	cout << minnum << '\n';
	
	
    return 0;
}



