#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch3 O] 주사위 게임
풀이: 
시간복잡도: O(n*3)=3000
*/
int n,num,maxN=0,maxResult=0,maxIdx;


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
 
  cin>>n;
  for(int i=0;i<n;i++){
    int a[7]={0};
    maxN=0; maxIdx=0;
    for(int k=0;k<3;k++){
      cin>>num;
      a[num]++;
    }
    
    // 반복 경우 나누기
    for(int k=1;k<7;k++){
      if(a[k] > maxN){
        maxN = a[k];
        maxIdx = k;
      }
    }// 상금의 경우 나누기
    if(maxN == 3){
      maxResult = max(maxResult,10000+maxIdx*1000);
    }
    else if(maxN ==2){
      maxResult = max(maxResult,1000+maxIdx*100);
    }
    else{
      maxResult = max(maxResult,maxIdx*100);
    }
  }// 최대상금 출력
  cout<<maxResult<<'\n';
  return 0;
}
