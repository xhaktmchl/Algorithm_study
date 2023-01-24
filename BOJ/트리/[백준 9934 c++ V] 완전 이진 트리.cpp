#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
#include <cmath>
using namespace std;
/*
[백준 9934 c++ V] 완전 이진 트리
문제: 
접근1: 
중위순회정보로부터
중간값 = 루트 노드
부모노드에서 왼쪽 중간값 = 왼자식 노드
부모노드에서 오른 중간값 = 오른자식 노드
시간복잡도: 
풀이1:
    //1.입력
    //2.dfs: 중위순회 노드배열로 중위순회 탐색
    //3.출력
*/
int n,k;
int a[1024 + 5];
vector<int> tree[1024 + 5];
bool visit[1024 + 5];

void dfs(int depth, int s, int e) {
    int mid = (s + e) / 2;
    visit[mid] = 1; // 방문
    
    // 왼 트리 탐색
    if(!visit[(s+mid-1)/2]) dfs(depth + 1, s, mid-1);
    // 현재 노드
    tree[depth].push_back(a[mid]);
    // 오른 트리 탐색
    if(!visit[(mid+1+e)/2]) dfs(depth + 1, mid + 1, e);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    cin >> k;
    for (int i = 0; i < pow(2,k)-1; i++) {
        cin >> a[i];
    }
    //2.dfs: 중위순회 노드배열로 중위순회 탐색
    dfs(0, 0, pow(2, k) - 2);
    //3.출력
    for (int i = 0; i < k; i++) {
        int size = tree[i].size();
        for (int j = 0; j < size; j++) {
            cout << tree[i][j] << " ";
        }cout << '\n';
    }
    return 0;
}
