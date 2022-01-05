#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch4 V] attackrange
풀이1: 완탐으로 각 좌표에서 유닛까지의 거거리계산
시간복잡도:O(n*n)=10000
풀이2: 완탐으로 각 좌표에 인접좌표에 +1 씩 저장해나가기 
시간복잡도:O(n*n*r)=10000*50
*/
#define MAX 101
int a[MAX][MAX],n,ur,uc,len,dist;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  cin>>ur>>uc>>len;
  for(int i=1;i<=n;i++){
    for(int k=1;k<=n;k++){
      int rdiff = i-ur; // 가로차이
      int cdiff = k-uc; // 세로차이]
      if(rdiff < 0){rdiff*=-1;}
      if(cdiff < 0){cdiff*=-1;}
      // 거리계산 및 배열에 저장
      dist = rdiff+cdiff;
      if(dist == 0){ a[i][k]=-1;} // 유닛만 -1로 저장 후 나중에 x로 출력
      else if(dist<= len){  a[i][k]=dist; }
    }
  }
  // 공격범위 출력
  for(int i=1;i<=n;i++){
    for(int k=1;k<=n;k++){
     if(a[i][k] == -1){
       cout<<"x ";
     }
     else{ cout<<a[i][k]<<" ";}
    }
    cout<<'\n';
  }
  return 0;
}
