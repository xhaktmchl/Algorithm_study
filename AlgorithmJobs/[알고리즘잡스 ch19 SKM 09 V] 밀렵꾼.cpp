#include <iostream>
#include <algorithm>
#include <cstring> // memset

using namespace std;
/*
[알고리즘잡스 ch19 SKM 09 V] 밀렵꾼
풀이: 구현,완탐
1.테케 입력
2.배열들 초초기화
3.멧돼지 정보 입력
4.1~c초 반복
돼지 무게와, 위치 저장배열 초기화
5.1~m 번 돼지 이동
//주기로 이동거리 줄줄이기
6.배열 끝까지 이동하는 경우 계속 반복
상하 방향일때 이동해야하는 거리 계산
행 좌표 갱신
방향 전환
좌우 방향일때 이동해야하는 거리 계산
행 좌표 갱신
방향 전환
7.남은 이동거리로 좌표 갱신
8.이동 후 멧돼지 겹치는지 확인
//새로운 멧돼지가 무거운 경우
//기존 멧돼지가 무거운 경우
//겹치지 않는 경우
9.손전등으로 t위치의 멧돼지 확인, 포포획된
10.포획된 멧돼지 합 출력
시간복잡도: O()=
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.
*/
#define MAX 110
int T,r,c,m;
int x[10010],y[10010],d[10010],f[10010],w[10010];
int dx[]={0,0,0,-1,1};
int dy[]={0,-1,1,0,0};
int dist[10010];
int pigArr[MAX][MAX];
int pigWeight[MAX][MAX];
int deleted[10010];
long long sum=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.테케 입력
  cin>>T;
  for(int t=1;t<=T;t++){
    
    sum=0;
    memset(pigWeight,0,sizeof(pigWeight));
    memset(pigArr,0,sizeof(pigArr));
    memset(deleted,0,sizeof(deleted));
    memset(dist,0,sizeof(dist));
    
    //2.멧돼지 정보 입력
    cin>>r>>c>>m;
    for(int i=1;i<=m;i++){
      cin>>y[i]>>x[i]>>d[i]>>f[i]>>w[i];
    }
    //3.1~c 초  1~M 마리 멧돼지 움직이기
    for(int j=1;j<=c;j++){
      // 1초마다 초기화 해줘야 이동하기 전의 멧돼지와 겹치지 않는다.
      memset(pigWeight,0,sizeof(pigWeight));
      memset(pigArr,0,sizeof(pigArr));
      for(int i=1;i<=m;i++){
        if(deleted[i]==1){continue;}// 삭제된 멧돼지는 넘기기
        // i번 멧돼지 d 방향으로 f만큼 이동
        // 행렬의 끝이면 방향 전전환

        // 주기로 이동거리 줄이기
        if(d[i]==1 || d[i]==2){ dist[i]%= 2*r-2;}
        if(d[i]==3 || d[i]==4){ dist[i]%= 2*c-2;} // 주기로 이동거리 줄이기
        dist[i]=f[i]; // 1초마다 이동 해야하는 거리
        /// 상하
        if(d[i]==1 || d[i]==2){
          while(y[i]+dy[d[i]]*dist[i]<1 || y[i]+dy[d[i]]*dist[i]>r){
            //상
            if(d[i]==1){
              dist[i]-=(y[i]-1);
              y[i]=1;
              d[i]=2;
            }
            //하
            else if(d[i]==2){
              dist[i]-=(r-y[i]);
              y[i]=r;
              d[i]=1;
            }
          }
        }// 좌우
        else if(d[i]==3 || d[i]==4){
          while(x[i]+dx[d[i]]*dist[i]<1 || x[i]+dx[d[i]]*dist[i]>c){
            //좌
            if(d[i]==3){
              dist[i]-=(x[i]-1);
              x[i]=1;
              d[i]=4;
            }
            //우
            else if(d[i]==4){
              dist[i]-=(c-x[i]);
              x[i]=c;
              d[i]=3;
            }
          }
        }
        // 남은 거리 이동
        y[i]=y[i]+dy[d[i]]*dist[i];
        x[i]=x[i]+dx[d[i]]*dist[i];
        
        //이동 후 멧돼지 겹치면 가벼운 돼지 제거
        
          if(pigWeight[y[i]][x[i]]!=0){ // 겹첬는데 
            if(pigWeight[y[i]][x[i]]< w[i]){ // 새로온 멧돼지가 더 무거운 경우
              pigWeight[y[i]][x[i]]=w[i]; 
              deleted[pigArr[y[i]][x[i]]]=1; // 원래있던 멧돼지 삭제
              pigArr[y[i]][x[i]]=i; 
              
            }
            else{ // 개로온 멧돼지가 가벼운 경우
              deleted[i]= 1; // 새로온 멧돼지 삭제
            }
          }
          else{// 멧돼지 겹치지 않으면 새로운 돼지 저장
            pigWeight[y[i]][x[i]]=w[i];
            pigArr[y[i]][x[i]]=i; 
          }
        
      }

      //모든 멧돼지 이동 후 손전등 검사
        for(int p=r;p>=1;p--){
          if(pigWeight[p][j]!=0){
            sum+=pigWeight[p][j]; // 포획된 멧돼지 무게 함
            pigWeight[p][j]=0; // 무게 갱신
            deleted[pigArr[p][j]]=1; // 멧돼지 삭제
            pigArr[p][j]=0; // 벳돼지 위치 삭제
            break;
          }
        }
    }
    // 4.츨력: 테케, 포획한 메돼지 무게 합
    cout<<"#"<<t<<" "<<sum<<'\n';
  }
  return 0;
}
