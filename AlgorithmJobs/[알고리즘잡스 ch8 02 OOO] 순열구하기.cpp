#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch8 02 OOO] 순열구하기
풀이:  재귀: 
  //1.입력
  //2.완탐 재귀 :
  //기저조건: r 개를 뽑았을 때 수열 출력
  //1~n개의 알파벳 탐색
  //방문안했으면
  //방문처리
  //재귀
시간복잡도: O(n^r)=10^7 = 1000만
*/

#define MAX 20
int n,r;
char result[MAX];
bool visit[MAX];

void re(int idx){
  //기저조건: r 개를 뽑았을 때 수열 출력
  if(idx>=r){
    for(int i=0;i<r;i++){
      cout<<result[i];
    }cout<<'\n';
    return;
  }
  //1~n개의 알파벳 탐색
  for(int i=0;i<n;i++){
    if(visit[i]==0){//방문안했으면
      visit[i]=1;//방문처리
      result[idx]='a'+i;
      re(idx+1);//재귀
      visit[i]=0;
    }
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  //1.입력
  cin>>n>>r;
  //2.완탐 재귀 :
  re(0);
  //기저조건: r 개를 뽑았을 때 수열 출력
  //1~n개의 알파벳 탐색
  //방문안했으면
  //방문처리
  //재귀
  return 0;
}
