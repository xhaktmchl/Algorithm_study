#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch9 06 O] 전염병
풀이: 완탐 재귀: 시작 인덱스에서 i*2,i/3 인 경우 각각 재귀 및 방문
시간복잡도: O(log2(n))= log2(100000) = 약 16???
*/
#define MAX 100005
int n,k,c=0;
int visit[MAX];
// 재귀로 i*2, i/3 방문
void re(int idx){
  // 방문
  visit[idx]=1;
  // 기저사례: 
  // i*2
  if(idx*2<= n){
    if(visit[idx*2]==0){
      re(idx*2);
    }
  }
  //i/3
  if(idx/3>= 1){
    if(visit[idx/3]==0){
      re(idx/3);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n>>k;
  // 재귀
  re(k);
  // 전염병 클린마을 카운트
  for(int i=1;i<=n;i++){
    if(visit[i]==0){ c++;}
  }cout<<c<<'\n';
  return 0;
}
