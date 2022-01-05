#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch4 V] class president
풀이1: 완탐
시간복잡도: O(n*n)=100만
주의: 같은반 했던 학생은 여러번 겹처도 카운트1 => 체크배열 사용
*/
#define MAX 1001
int n,a[MAX][6],maxN=0,maxIdx=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  // 배열 입력
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<5;j++){
      cin>>a[i][j];
    }
  }
  // 1.각 학생당 같은반 한 학생 수 체크
  for(int i=0;i<n;i++){
    int check[n]={0,}; 
    for(int j=0;j<5;j++){
      // 학년 별 같은 학생  배열체크
      for(int k=0;k<n;k++){
        if(k == i)continue;
        if(a[i][j] == a[k][j]){ check[k]=1;}
      }
    }
    // 2.최댓값이면 최댓값, 학생번호 저장 
    int cnt=0;
    for(int i=0;i<n;i++){
      cnt+=check[i];
    }
    if(cnt > maxN){ 
      maxN = max(maxN,cnt);
      maxIdx = i;
    }
  }
  cout<<maxIdx+1<<'\n';
  return 0;
}
