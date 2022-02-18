#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch20 SKM 04 O] 알파윷 - D
풀이: 구현,완탐
  //1.배열 저장
  //2.중간에 연결된 지점들은 조건을 달아준다
  // 각 이동할 칸에 말 존재하면 -1 출력 , 중단
  // 5번칸 22 23 24 25 26
  // 22번칸 23 24 25 26 15
  // 23번칸 24 25 26 15 16
  // 24번칸 30 31 20 21 21
  // 25번칸 26 15 16 17 18
  // 26번칸 15 16 17 18 19
  
  // 10번칸 27 28 24 29 30
  // 27번칸 28 24 29 30 20
  // 28번칸 29 30 20 21 21
  // 29번칸 30 20 21 21 21
  // 30번칸 20 21 21 21 21
  // 그 외 말 정상 이동
  // 3.각 말의 마지막 칸의 점수 합
  //4.출력
시간복잡도: O()=
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
#define MAX 100
int n;
int a[MAX]={0,5,10,15,20,50,
30,35,40,45,100,
55,60,65,70,75,
80,85,90,95,500,1000, 
275, 250, 300 , 150, 175,
150, 125, 350, 400};
int dist[MAX];
int a5[MAX]={22,23, 24, 25, 26};
int a22[MAX]={23, 24, 25, 26, 15};
int a23[MAX]={24, 25, 26, 15, 16};
int a24[MAX]={30, 31, 20, 21, 21};
int a25[MAX]={26, 15, 16, 17, 18};
int a26[MAX]={15, 16, 17, 18, 19};

int a10[MAX]={27, 28, 24, 29, 30};
int a27[MAX]={28, 24, 29, 30, 20};
int a28[MAX]={29, 30, 20, 21, 21};
int a29[MAX]={ 30, 20, 21, 21, 21};
int a30[MAX]={20, 21, 21, 21, 21};
int order[MAX];
int idx[6];
int visit[MAX];
int sum=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배열 저장
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>dist[i];
  }
  for(int i=0;i<n;i++){
    cin>>order[i]; //움직일 말 입력
  }
  //2.중간에 연결된 지점들은 조건을 달아준다
  // 5번칸 22 23 24 25 26
  // 22번칸 23 24 25 26 15
  // 23번칸 24 25 26 15 16
  // 24번칸 30 31 20 21 21
  // 25번칸 26 15 16 17 18
  // 26번칸 15 16 17 18 19
  
  // 10번칸 27 28 24 29 30
  // 27번칸 28 24 29 30 20
  // 28번칸 29 30 20 21 21
  // 29번칸 30 20 21 21 21
  // 30번칸 20 21 21 21 21
  // 그 외 말 정상 이동
  // 각 이동할 칸에 말 존재하면 -1 출력 , 중단
  for(int i=0;i<n;i++){
    visit[idx[order[i]]]=0; // 말 시작 위치 없앱
    if(idx[order[i]]==5){ idx[order[i]]=a5[dist[i]-1];}
    else if(idx[order[i]]==22){ idx[order[i]]=a22[dist[i]-1];}
    else if(idx[order[i]]==23){ idx[order[i]]=a23[dist[i]-1];}
    else if(idx[order[i]]==24){ idx[order[i]]=a24[dist[i]-1];}
    else if(idx[order[i]]==25){ idx[order[i]]=a25[dist[i]-1];}
    else if(idx[order[i]]==26){ idx[order[i]]=a26[dist[i]-1];}
    else if(idx[order[i]]==10){ idx[order[i]]=a10[dist[i]-1];}
    else if(idx[order[i]]==27){ idx[order[i]]=a27[dist[i]-1];}
    else if(idx[order[i]]==28){ idx[order[i]]=a28[dist[i]-1];}
    else if(idx[order[i]]==29){ idx[order[i]]=a29[dist[i]-1];}
    else if(idx[order[i]]==30){ idx[order[i]]=a30[dist[i]-1];}
    else { 
      idx[order[i]]+=dist[i]; // 말 이동
      if(idx[order[i]]>=21){ idx[order[i]]=21;}
    }  
    if(visit[idx[order[i]]]==1){
      cout<<-1<<'\n';
      return 0;
    }
    visit[idx[order[i]]]=1; // 말 위치 표시
  }
  // 3.각 말의 마지막 칸의 점수 합
  for(int i=1;i<=4;i++){
    sum+=a[idx[i]];
  }
  //4.출력
  cout<<sum<<'\n';
  return 0;
}
