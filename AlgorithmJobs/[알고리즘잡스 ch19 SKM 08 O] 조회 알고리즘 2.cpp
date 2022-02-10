#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch19 SKM 08 O] 조회 알고리즘 2
풀이: 구현,완탐
  //1.n,k,t 입력
  // 배열 0으로 초기화
  //2.0초 n명 입력
  //3.1~t초 k명씩 추가입력
  //최댓값 갱신
  //출력: 각 초마다 배열의 합 출력
시간복잡도: O(k*t)=10000
*/
#define MAX 10010
int n,k,T;
int a[1010][1010];
int x,y,num;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.n,k,t 입력
  cin>>n>>k>>T;
  // 배열 0으로 초기화
  //2.0초 n명 입력
  for(int i=1;i<=n;i++){
    cin>>y>>x>>num;
    a[y][x]=max(a[y][x],num);// 최댓값 갱신
  }
  //3.1~t초 k명씩 추가입력
  for(int t=1;t<=T;t++){
    for(int i=1;i<=k;i++){
      cin>>y>>x>>num;
      a[y][x]=max(a[y][x],num);//최댓값 갱신
    }
    
    //출력: 각 초마다 배열의 합 출력
    long long sum=0;
    for(int i=1;i<=1000;i++){
      for(int j=1;j<=1000;j++){
        sum+=a[i][j];
      }
    }
    cout<<sum<<'\n';
  }
  return 0;
}
