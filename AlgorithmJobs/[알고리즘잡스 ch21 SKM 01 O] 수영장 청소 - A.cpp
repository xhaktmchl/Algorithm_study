#include <iostream>
#include <algorithm>
#include <cstring> // memset
using namespace std;
/*
[알고리즘잡스 ch21 SKM 01 O] 수영장 청소 - A
풀이: 구현,완탐 재귀
  //1.n,k입력
  //2.완탐재귀: n개의 수도꼭지 조합 
  //기저조건:n개의 수도꼭지 다 정했고 k번째 조합이면 출력, 중단
  //재귀: idx번째 수도꼭지 저장
시간복잡도: O(4^n)=4^5=1024
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
#define MAX 100
int n,k;
int a[10];
int degree[4]={0,90,180,270};
int cnt=1;

//2.완탐재귀: n개의 수도꼭지 조합 
void re(int idx){
  if(idx>=n){//기저조건:n개의 수도꼭지 다 정했고 k번째 조합이면 출력, 중단
    if(cnt==k){
      for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
      }cout<<'\n';
    }
    cnt++;
    return;
  }
  //재귀: idx번째 수도꼭지 저장
  for(int i=0;i<4;i++){
    a[idx]=degree[i];
    re(idx+1);
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.n,k입력
  cin>>n>>k;
  //2.완탐재귀: n개의 수도꼭지 조합 
  //기저조건:n개의 수도꼭지 다 정했고 k번째 조합이면 출력, 중단
  //재귀: idx번째 수도꼭지 저장
  re(0);
  return 0;
}
