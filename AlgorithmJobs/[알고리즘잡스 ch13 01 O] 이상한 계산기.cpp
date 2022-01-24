#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
[알고리즘잡스 ch13 01 O] 이상한 계산기
접근1: 재귀 완탐 -> 시간초과 예상
접근2: dp : /3으로 뒤로 돌아가는 것 때문에 못 씀
풀이: bfs
시간복잡도: O(n+m)=  100010
*/
#define MAX 100010 // 계산기 고자으로 5자리가 최대이기 때문에 
int n;
bool visit[MAX];
int dist[MAX];
 
//bfs
void bfs(int node){
  queue<int> q;// 큐 생성
  q.push(node); visit[node]=1;// 큐에 1푸쉬, 방문처리
  dist[node]=0;
  //bfs시작
  while(!q.empty()){
    //큐 팝
    node= q.front();
    q.pop();
    
    // *2, /3 경우 좌표검사, 방문안했으면
    int nn1 = node*2;
    int nn2 = node/3;
    // 방문처리, 거리저장, 큐에 푸쉬
    if(nn1>0 && nn1<MAX && visit[nn1]==0){
      q.push(nn1); visit[nn1]=1;
      dist[nn1] = dist[node]+1;
      
    }
    if(nn2>0 && nn2<MAX && visit[nn2]==0){
      q.push(nn2); visit[nn2]=1;
      dist[nn2] = dist[node]+1;
    }
  }
}


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.n입력
  cin>>n;
  //2.1부터 bfs시작
  bfs(1);
  //3.출력: 최소 버튼 클릭 횟수
  cout<<dist[n]<<'\n';
  return 0;
}
