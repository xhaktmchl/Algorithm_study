#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch19 SKM 06 O] 중복 조회 2
풀이: 완탐
  //1.n명 사람 좌표 입력
  //2.원하는 좌표에 값보다 작은 번호의 사람으로 최신화
  //3.배열 완탐으로 각 좌표의 가장 작은 번호들의 합을 출력
시간복잡도: O(n)=100000
*/
#define MAX 100010
int n;
int x[MAX],y[MAX];
int a[110][110];
int sum=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.n명 사람 좌표 입력
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>y[i]>>x[i];
  }
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++){
      a[i][j]=100010;
    }
  }
  
  //2.원하는 좌표에 값보다 작은 번호의 사람으로 최신화
  for(int i=1;i<=n;i++){
    a[y[i]][x[i]]=min(a[y[i]][x[i]],i);
    
  }
  //3.배열 완탐으로 각 좌표의 가장 작은 번호들의 합을 출력
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++){
      if(a[i][j]!=100010){
        sum+=a[i][j];
      }
    }
  }
  cout<<sum<<'\n';
  return 0;
}
