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

// [백준 2504 c++ X] 괄호의 값 
// 문제:  괄호식이 맞는지 검사하고 규칙에 따라 결과값 출력
// 접근:  괄호 검사하며 계산숫자를 스택에 넣어가며 -> 조건문 너무 많음
// 접근2: 계산 식을 써보면은 분배법칙에 따라 곱해지는 결과값이 결국엔 그때그때 () 쌍만 보ㄴ면 됨 
// 풀이: 
// ( [ 나올때마다 tp 값2,3 곱해줌
// 식 에러처리 먼저 해야 함
// ) ] 나올떼마다 값 더해주고 tp/ 2,3 해줌
// 결국 전개된 숫자식과 같음
// 마지막 예외 때문에 에러처리 한번 더 해야함

using namespace std; // cin,cout 편하게 사용 라이브러리 
#define MAX 31

stack<char> st;
string str;

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	
	cin >> str;

	long long result = 0;
	int tp = 1;
	int n = str.size();

	for (int i = 0; i < n; i++) {
		// 1. '(' 인 경우
		if (str[i] == '(') {
			st.push('(');
			tp *= 2;
		}
		// 2. '['인 경우
		else if (str[i] == '[') {
			st.push('[');
			tp *= 3;
		}

		// 괄호식이 틀린 경우
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
		// 3. ')' 경우
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				result += tp;
			}
			tp /= 2;
			st.pop();
		}
		// 4. ']' 경우
		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				result += tp;
			}
			tp /= 3;
			st.pop();
		}
		
		//cout << st.top() <<'\n';
	}

	if (!st.empty()) { // 예외사항 있기 때문에 마지막 스택 검사해서 괄호 검사
		cout << 0 << '\n';
	}
	else
	{
		cout << result << '\n';
	}

	return 0;
}
