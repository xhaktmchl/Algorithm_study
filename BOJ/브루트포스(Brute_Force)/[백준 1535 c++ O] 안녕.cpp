#include <iostream>
#include <algorithm>
using namespace std;
// [백준 1535 c++ O] 안녕
// 문제:
// 접근1:
// 시간복잡도: O(2^n) = 2^20
// 풀이: 
    //1.입력
    //2.완탐 재귀: 각 사람을 인사할 것인지 아닌지
    //1) 기저: 만약 마지막 사람이거나, 체력이 0이하이면
    //기쁨 최대치 갱신
    //중단
    //2) 재귀
    //인사하는 경우
    //인사 안하는 경우
    //3.출력: 최대 기쁨
int n;
int a[25];
int b[25];
int maxHap = 0;

void re(int idx, int heal, int hap) {

    if (idx >= n || heal <= 0) {
        maxHap = max(maxHap, hap);
        return;
    }

    if (heal - a[idx] > 0) {
        re(idx + 1, heal - a[idx], hap + b[idx]);
    }
    re(idx + 1, heal, hap);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    //1.입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    //2.완탐 재귀: 각 사람을 인사할 것인지 아닌지(idx, 체력, 기쁨)
    //1) 기저: 만약 마지막 사람이거나, 체력이 0이하이면
    //기쁨 최대치 갱신
    //중단
    //2) 재귀
    //인사하는 경우
    //인사 안하는 경우
    //3.출력: 최대 기쁨
    re(0, 100, 0);
    cout << maxHap << '\n';
}
