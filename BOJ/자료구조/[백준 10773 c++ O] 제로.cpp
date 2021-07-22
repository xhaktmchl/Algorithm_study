#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
// [백준 10773 c++ O] 제로 
// 문제: 숫자를 입력받아 저장하되 0이 입력되면 저장된 수중 가장 나중의 수 제거 후 숫자들의 합 구하기
// 접근: 스택
// 풀이: 
// 스택에 숫자들 입력
// 반복문 이용해 숫자들의 합 구하기
//주의: 스택을 탐색할 때는 while 쓰는것 좋은듯 , for 쓰면 st의 사이즈 저장해놓고 사용

int k;
stack<long long> st;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
								  
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 0) { st.pop(); continue; }
		st.push(num);
	}

	// 스택에 있는 수의 합 
	long long sum = 0;
	//cout << st.size() << '\n';
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}
