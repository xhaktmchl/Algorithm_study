#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch10 02 V] 공통 조상 찾기
풀이: 트리 탐색 -> 트리의 조상을 배열저장-> 재귀탐색
시간복잡도: O(log2(n))= log2(1000) = 10
*/
#define MAX 1010
int n,x,y,a,b;
int par[MAX];
int cnt[MAX];

// 트리 조상 탐색 재귀
void re(int node){
  // 조상 방문 
  if(node != x && node != y) cnt[node]++;
  // 가장 가까운 공통조상 찾으면 종료
  if(cnt[node]==2){
    cout<<node<<'\n';
    return;
  }
  
  // 기저사례 : 루트노드 만나면 끝
  if(node == 0){
    return;
  }
  re(par[node]);
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n>>x>>y;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    par[b]=a; // 각 노드의 부모 저장
  }
  // x노드의 조상 탐색
  re(x);
  // y노드의 조상 탐색
  re(y);
  return 0;
}
