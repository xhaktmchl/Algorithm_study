#include <iostream>
#include <algorithm>
using namespace std;
// [백준 3085 c++ OV] 사탕 게임
// 문제:
// 접근: 이차원 최대길이 ->완탐,dfs,bfs -> 스왑하고 비교하고 하려면 dfs,bfs애매 -> 완탐
// 시간복잡도: O(n*n*(n*n)), n=50
// 풀이: 
    //1.입력
    //인자
    //배열
    //2.배열 숫자로 변환
    //3.완탐: 모든 위치에서 다른 색상 우,하 색 교환(상,좌 는 결국 중복되므로 생략)
    //2) 우
    //범위 검사
    //색 다르면 교환
    //교환 후 최대 길이: 행
    //교환 후 최대 길이: 열
    //교환 되돌리기
    //3)하
    //범위 검사
    //색 다르면 교환
    //교환 후 최대 길이: 행
    //교환 후 최대 길이: 열
    //교환 되돌리기
int n;
char a[60][60];
int b[60][60];
int cnt = 1;
int maxCnt = 0;

void check(int ar[60][60]) {
    
    //행 최대길이
    for (int i = 0; i < n; i++) {
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (ar[i][j] == ar[i][j - 1]) { cnt++; }
            else { cnt = 1; }// 주의: 문자열 길이라 초기화 =1
            maxCnt = max(maxCnt, cnt);
        }
    }
    //열 최대길이
    for (int j = 0; j < n; j++) {
        cnt = 1;
        for (int i = 1; i < n; i++) {
            if (ar[i][j] == ar[i - 1][j]) cnt++;
            else { cnt = 1; }// 주의: 문자열 길이라 초기화 =1
            maxCnt = max(maxCnt, cnt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    //인자
    //배열
    //2.배열 숫자로 변환
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'C') b[i][j] = 1;
            if (a[i][j] == 'P') b[i][j] = 2;
            if (a[i][j] == 'Z') b[i][j] = 3;
            if (a[i][j] == 'Y') b[i][j] = 4;
        }
    }

    //3.완탐: 모든 위치에서 다른 색상 우,하 색 교환(상,좌 는 결국 중복되므로 생략)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //2) 우
            //범위 검사
            //색 다르면 교환
            //교환 후 최대 길이: 행
            //교환 후 최대 길이: 열
            //교환 되돌리기
            if (j + 1 < n) {
                if (b[i][j] != b[i][j + 1]) {
                    swap(b[i][j], b[i][j + 1]);
                    check(b);
                    swap(b[i][j], b[i][j + 1]);
                }
            }

            //3)하
            //범위 검사
            //색 다르면 교환
            //교환 후 최대 길이: 행
            //교환 후 최대 길이: 열
            //교환 되돌리기
            if (i+1 <n ) {
                if (b[i][j] != b[i + 1][j]) {
                    swap(b[i][j], b[i + 1][j]);
                    check(b);
                    swap(b[i][j], b[i + 1][j]);
                }
            }
        }
    }

    cout << maxCnt << '\n';
}
