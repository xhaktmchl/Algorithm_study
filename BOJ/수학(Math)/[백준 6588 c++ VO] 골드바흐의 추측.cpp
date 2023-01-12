#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
#include <vector>
using namespace std;
/*
[백준 6588 c++ VO] 골드바흐의 추측
문제:t개의 n을 입력받으면 규칙에 따른 소수의 합으로 출력
접근1: 완전탐색 1~n-1 까지 -> 시간초과 예상
접근2: 2~루트n 까지 -> 시도 안 해봄
루트n 은 i*i<n 이렇게 구현
접근3: 에라토스테네스-> 배열에 미리 소수판별 -> 입력받는 숫자 소수판별
똑같이 루트n 은 i*i<n 이렇게 구현
소수만 따로 저장해서 소수의 합 판별할 때 씀
시간복잡도:
풀이:
// 숫자 입력
// 에라토스테네스 체로 check배열에 소수인지 표시 , prime벡터에 소수 따로 저장
// 테스트 케이스로 n입력
// 구해놓은 소수에서 작은 수부터 n-소수 = 소수인지 판별
// 주의:
//: 에라토스테네스의 체도 루트n까지 탐색하면 됨

*/
int n;
bool visit[1000000 + 10];

vector<int> primeList;

void eratos() {

    visit[0] = visit[1] = 1;
    for (int i = 2; i * i <= 1000000; i++) {
        if (visit[i] == 1) continue;
        primeList.push_back(i);
        for (int j = i+i; j <= 1000000; j += i) {
            visit[j] = 1;
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //에라토스테네스의 체
    eratos();
    //테케
    //입력
    //작은 소수부터 탐색하며 두 홀수의 합이 소수인것 조회
    //소수의 합이면 출력
    while (1) {
        cin >> n;
        if (n == 0) break;

        int len = primeList.size();
        for (int i = 0; i < len; i++) {
           
            if (primeList[i]%2!=0 && visit[n - primeList[i]] == 0) {
                cout << n << " = " << primeList[i] << " + " << n - primeList[i] << '\n';
                break;
            }
        }
    }
    return 0;
}
