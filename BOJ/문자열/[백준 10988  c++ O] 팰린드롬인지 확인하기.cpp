#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수
#include <set>
#include <map> // map구조체
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [백준 10988  c++ O] 팰린드롬인지 확인하기
// 문제: 거꾸로 해도 같은 문자열인 팰린드롬인지 확인하기
// 접근: 완전탐색으로 문자열의 앞뒤에서 서로 비교
// 풀이: 반복문으로 앞뒤 동시비교하며 팰린드롬이 아니면 0출력

using namespace std; // cin,cout 편하게 사용 라이브러리
#define MAX 51

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[s.size() - i - 1]) { cout << 0; return 0; }
	}
	cout << 1;
	
	return 0;
}



