#include <iostream>
#include <algorithm>
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
[백준 1976 c++ O] 여행 가자
접근: 유니온 파인드 
중복 허용이므로 같은 그래프에 연결만 되어있으면 어느 순서로도 탐색 가능 -> 같은 집합인지만 확인 -> 유니온 파인드
시간복잡도: 
풀이1:
    //1.입력
    //2.부모 배열 초기화
    //3.유니온
    //4.파인드: 만약 같은 집합이면 YES, 아니면 NO
*/
int n,m,c;
int par[205];
int ad[205][205];
int curFin;
bool ok = 1;

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로 압축: 시간 단축
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
    cin >> n >> m;
    
    //2.부모 배열 초기화
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    //3.유니온
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ad[i][j];
            if (ad[i][j] == 1) {
                uni(i, j);
            }
        }
    }
    //4.파인드: 만약 같은 집합이면 YES, 아니면 NO
    for (int i = 0; i < m; i++) {
        cin >> c;
        if (curFin == 0) curFin = fin(c);
        else {
            if (curFin != fin(c)) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
