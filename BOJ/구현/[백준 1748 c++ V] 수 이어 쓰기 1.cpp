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

// [백준 1748 c++ V] 수 이어 쓰기 1
// 문제: 이어진 수의 총 자릿수 구하기
// 접근:  문자열로 직접 수 만들어서 자릿수 구하기 -> 시간초과 
// 접근2: 수학 규칙성 찾기
// 풀이: 
// 각 자릿수 일때 길이합 구하기
// 총 자릿수 합 = 같은자리 (끝수 - 첫수+1)*자릿수
// 예) (99-10+1)*2 = 180

using namespace std; // cin,cout 편하게 사용 라이브러리 

int n;
string ch;
int sum;

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	cin >> n;
	ch = to_string(n);
	int len = ch.size();
	
	if (len == 1) // 1자리 수이면 바로 구해야 함
	{
		cout << n;
		return 0; 
	}
	// 2자리 수 이상
	int first = 1, last = 10;
	for (int i = 1; i < len; i++) {
		sum += ((last - 1) - first + 1) * i; // 총 자릿수 합 = 같은자리 (끝수 - 첫수+1)*자릿수
		first *= 10;
		last *= 10;
	}
	sum += ((n) - first + 1) * len; 

	cout << sum;
	return 0;
}
