#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch8 02 O] 순열구하기
풀이: 팩토리얼 재귀: 
시간복잡도: O(n^r)=10^7 = 1000만
*/
#define MAX 14
int n,r;
char result[MAX]; // 순열 배열
bool visit[MAX]; // 방문 배열
// 재귀: r 자리 순열 출력
void re(int idx){
  // 기저사례: 순열 완성되면 출력
  if(idx >= r){
    for(int i=0;i<r;i++){
      cout<<result[i];
    }cout<<'\n';
    return;
  }
  // 재귀 탐색
  for(int i=0;i<n;i++){
    char alpha = 'a'+i;
    if(visit[i] == false){// 사용하지 않은 알파벳이면
      // 방문처리
      result[idx] = alpha;
      visit[i] = true;
      re(idx+1);
      // 방문 초기화
      result[idx]=0;
      visit[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n>>r;
  re(0);
  return 0;
}
