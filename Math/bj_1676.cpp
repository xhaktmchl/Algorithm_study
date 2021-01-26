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

// 백준 1676번 팩토리얼 0의 개수
// 접급1: 팩토리얼값 구하고 문자열로 변환 후 뒤에서부터 계산
// 접근2: 팩토리얼값 구한 뒤 mod이용해서 숫자 뒤에서 부터 차례로 
// 접근이 다 시간초과나서 틀리는듯
// 풀이: 소인수 분해 결과 2*5 가 10으로 0이 나오므로 2와5의 개수중 작은것이 0의 개수이다
// 그런데 5의개수가 2의 개수보단 항상 작으므로 5의 개수를 구한다
// 5의 개수를 구하는데 5,25,125 를 나눈 몫을 합한것이 5의 개수
// 주의: string 자료형은 각 인덱스 값 못뽑아오는 듯
using namespace std; // cin,cout 편하게 사용 라이브러리

int n;

int main()
{
	// IO 속도 향상
	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	// n범위가 500 까지므로
	int zero = n / 5 + n / 25 + n / 125;
	cout << zero;
    return 0;
}



