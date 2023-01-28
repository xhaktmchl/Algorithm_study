#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 10775 c++ V] 공항 
문제: 처음에 문제이해 잘 안됨, 1~g번까지 게이트에 최대도킹 갯수 -> g번부터 1번까지 게이트 까지 차례대로 도킹해야 최대갯수
접근:
시간복잡도:
풀이1:
    //1.입력
    //2.유니온
    //1) 부모 배열 초기화
    //2) 게이트 입력받으면서 유니온
    // 더이상 게이트 없으면
    // 게이트 있으면
    //3.출력
*/
int n, p,g;
int par[100000 + 5];
int ans = 0;

void init() {
    for (int i = 1; i <= n; i++) par[i] = i;
}

int fin(int node) {
    if (par[node] == node) return node;
    return par[node] = fin(par[node]); // 경로 압축: 시간 단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);
    par[rootA] = rootB;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n>>p;
    //2.유니온 : g번 부터 1번게이트까지 같은 집합인지 확인하고 게이트 남으면 유니온
    //1) 부모 배열 초기화
    init();
    //2) 게이트 입력받으면서 유니온
    // 더이상 게이트 없으면 중단
    // 게이트 있으면
    //3.출력
    for (int i = 0; i < p; i++) {
        cin >> g;
        int pa = fin(g);
        if (pa == 0) break;
        else {
            uni(pa, pa - 1); // 현재까지 도킹된 게이트 바로 전 게이트에 도킹
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}  
