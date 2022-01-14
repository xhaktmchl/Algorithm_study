#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch8 02 OO] 순열구하기
풀이: 팩토리얼 재귀: 
시간복잡도: O(n^r)=10^7 = 1000만
*/
#define MAX 15
int n,r;
char result[MAX];
bool visit[MAX];

// 재귀 n개중 r 개 순열
void re(int idx){
  // 기저사례: r개를 뽑으면 출력
  if(idx>=r){
    for(int i=0;i<r;i++){
      cout<<result[i];
    }cout<<'\n';
    return;
  }
  // 1~n까지 탐색, 재귀
  for(int i=0;i<n;i++){
    if(visit[i]==1){ continue;}
    // 방문처리
    result[idx]='a'+i;
    visit[i]=1;
    re(idx+1);// 재귀
    // 방문 초기화
    result[idx]=0;
    visit[i]=0;
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n>>r;
  // 재귀
  re(0);
  return 0;
}
