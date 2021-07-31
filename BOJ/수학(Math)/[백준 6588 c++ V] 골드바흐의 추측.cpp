#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 6588 c++ V] 골드바흐의 추측
// 문제:t개의 n을 입력받으면 규칙에 따른 소수의 합으로 출력
// 접근1: 완전탐색 1~n-1 까지 -> 시간초과 예상
// 접근2: 2~루트n 까지 -> 시도 안 해봄
// 루트n 은 i*i<n 이렇게 구현
// 접근3: 에라토스테네스-> 배열에 미리 소수판별 -> 입력받는 숫자 소수판별
// 똑같이 루트n 은 i*i<n 이렇게 구현
// 소수만 따로 저장해서 소수의 합 판별할 때 씀
// 시간복잡도:
// 풀이: 
// 숫자 입력
// 에라토스테네스 체로 check배열에 소수인지 표시 , prime벡터에 소수 따로 저장
// 테스트 케이스로 n입력
// 구해놓은 소수에서 작은 수부터 n-소수 = 소수인지 판별
// 주의:
//: 에라토스테네스의 체도 루트n까지 탐색하면 됨
#define MAX 1000001
int n;
vector<int> prime;
int check[MAX];

// 에라토스테네스 체
void eratos() {
	check[0] = check[1] = 1;
	for (int i = 2; i*i <= 1000000; i++) { // 루트100만 까지 , 넘어가면 이미 다 소수판별 되있음
		if (check[i] == 0) {
			prime.push_back(i); // 소수만 따로 저장
			for (int j = i + i; j <= 1000000; j += i) { // i의 배수들 소수아님 처리
				check[j] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//소수 구해놓기
	eratos();

	while (1) {
		cin >> n;
		if (n == 0) { break; }
		for (int i = 0; i < prime.size(); i++) {
			if (check[n - prime[i]] == 0) { // 구해놓은 소수에서 작은 수부터 n-소수 = 소수인지 판별
				cout << n << " " << '=' << " " << prime[i] << " " << '+' << " " << n - prime[i] << '\n';
				break;
			}
		}
		
	}
	
	return 0;
}
