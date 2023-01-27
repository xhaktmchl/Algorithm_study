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
[백준 16562 c++ V] 친구비
접근: 접근 맞음 -> 유니온 파인드 -> 최소비용을 가진 루트가 되도록 유니온
시간복잡도:
풀이1:
    //1.입력
    //2.유니온
    //1)부모배열 초기화
    //2)유니온
    //이미 같은 집합 아니면, 비용 더 작은 쪽을 루트로 유니온
    //3.출력:각 집합의 루트만 방문 -> 루트의 최소비용 합이 k보다 크면 Oh no, 아니면 최소비용
주의: 비용이 작은 쪽 로트로 유니온 하는 조건을 uni 메소드안에서 걸어야 한다. main함수에서 걸어서 계속 틀림
*/
int n, m,n1,n2;
int ar[10005];
int par[10005];
bool visit[10005];
long long sum = 0,k;

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로 압축: 시간 단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);

    if (ar[rootA] > ar[rootB]) par[rootA] = rootB; // 비용 더 작은 쪽을 루트로 유니온
    else par[rootB] = rootA;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    //2.유니온
    //1)부모배열 초기화
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    //2)유니온
    //이미 같은 집합 아니면, 비용 더 작은 쪽을 루트로 유니온
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        if (fin(n1) != fin(n2)) uni(n1, n2);
    }
    //3.출력:각 집합의 루트만 방문 -> 루트의 최소비용 합이 k보다 크면 Oh no, 아니면 최소비용
    for (int i = 1; i <= n; i++) {
        int rootN = fin(i);
        if (!visit[rootN]) {
            visit[rootN] = 1;
            sum += ar[rootN];
        }
    }
    
    if (sum > k) cout << "Oh no"<<'\n';
    else cout << sum<<'\n';
    return 0;
}  
