#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 11725 c++ VV] 트리의 부모 찾기
문제: 루트노드 1 이라 하고 모든 노드의 부모노드를 출력
접근1: 트리 -> 구조체 직접 구현 -> 시도는 안함
접근2: 트리 -> 연결리스트 양방향 벡터로 구현-> dfs 탐색 , 부모노드= 배열에 저장
시간복잡도: O(정점갯수+간선갯수) = n+n = 20만??
풀이1:
    //1.입력: 트리를 연결리스트로
    //2.dfs: 루트 노드부터 dfs하면서 부모노드 저장
    //3.출력: 모든 부모노드 출력
*/
int n, a, b;
vector<int> v[100000 + 10];
bool visit[100000 + 10];
int par[100000 + 10];

void dfs(int node) {
    
    int size = v[node].size();
    for (int i = 0; i < size; i++) {
        int nn = v[node][i];
        if (!visit[nn]) {
            visit[nn] = 1;
            par[nn] = node;
            dfs(nn);
            visit[nn] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력: 트리를 연결리스트로
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //2.dfs: 루트 노드부터 dfs하면서 부모노드 저장
    //1) 노드의 인접 리스트 탐색
    //자식 노드의 인덱스에 부모 노드 저장
    dfs(1);
    //3.출력: 모든 부모노드 출력
    for (int i = 2; i <= n; i++) {
        cout << par[i] << '\n';
    }
    return 0;
}
