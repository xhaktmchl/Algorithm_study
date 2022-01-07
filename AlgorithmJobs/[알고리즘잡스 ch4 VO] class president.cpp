#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch4 VO] class president
풀이1:
시간복잡도: O(n*n*5)=500만
주의: 같은반 했던 학생은 여러번 겹처도 카운트1 => 체크배열 사용
*/
#define MAX 1001
int n,maxN=0,maxIdx=0;
int a[MAX][6];
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
  // 1.이차반복 완탐으로 각 학년별 같은 학생 체크
  for(int i=0;i<n;i++){
    int check[MAX]={0,};
    for(int j=0;j<5;j++){
      // 2.같은 반이었던 학생 모두 체크
      for(int k=0;k<n;k++){
        if(k==i){continue;} // 자기자신은 제외
        if(a[i][j] == a[k][j]){
          check[k]=1;
        }
      }
      
    }
    // 3.최대값, 학생번호 저장
    int sum=0;
    for(int j=0;j<n;j++){
      sum+= check[j];
    }
    if(sum > maxN){
      maxN=sum;
      maxIdx =i;
    }
  }
  
  // 출력
  cout<<maxIdx+1<<'\n';
  return 0;
}
