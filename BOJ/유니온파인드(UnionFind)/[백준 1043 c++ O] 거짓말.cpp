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
[백준 1043 c++ O] 거짓말
접근: 유니온파인드-> 진실을 아는 사람및 같은 파티에 포함된 사람도 진실을 얘기하면 안됨 -> 같은집합이면 안됨
시간복잡도: 
풀이1:
    //1.입력
    //2.부모배열 초기화
    //3.유니온: 진실아는사람, 진실아는사람과 같은 파티에 있는 사람
    //만약 파티에 2명 이상이면 계속 유니온 후 진실과 같은 집합 아니면 카운트
    //1명이면 파인드로 진실아는 집합아니면 카운트
    //4.출력:
주의: 파티원들의 입력을 받는 동시에 파인드를 하며 카운트를 하면 안된다. 따라서 유니온을 전부 진행한 다음에 다시 파인드를 한다.
*/
int n, m,tN,t1,t,pN,p1,p;
int par[55];
int cnt = 0;
int pAr[55][55];

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로압축: 시간단축
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
    //2.부모배열 초기화
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    //3.유니온: 진실아는사람, 진실아는사람과 같은 파티에 있는 사람
    cin >> tN;
    if (tN != 0) cin >> t1;
    for (int i = 0; i < tN-1; i++) {
        cin >> t;
        uni(t1, t);
    } 
    for (int i = 0; i < m; i++) {
        cin >> pN >> p1;
        pAr[i][0] = p1; // 파티 어레이 저장
        
        for(int j=0;j<pN-1;j++){
            cin >> p;
            if(fin(p1) != fin(p)) uni(p1, p);
            pAr[i][j + 1] = p;// 파티 어레이 저장
        }
    }

    //만약 파티에 2명 이상이면 계속 유니온 후 진실과 같은 집합 아니면 카운트
    //1명이면 파인드로 진실아는 집합아니면 카운트
    for (int i = 0; i < m; i++) {
        if (tN != 0) {
            if (fin(pAr[i][0]) != fin(t1)) cnt++;
        }
        else cnt++;
    }
    //4.출력:
    cout << cnt << '\n';
    return 0;
}
