#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/*
[알고리즘잡스 ch15 05 V] 중복 없는 구간
풀이: 이진탐색
 //1.숫자배열 입력
  //2.이진탐색으로 탐색할 구간의 길이 결정
  //3.구해진 구간의 길이로 중복이 없는지 배열 탐색
  // 구간의 길이만큼 저장해놨다면 맨 앞의 숫자 빼고, 다음 숫자 더하기
  //구간의 숫자갯수 카운트 배열에 저장
  // 만약 1->2로 더해진다면 2이상의 숫자 갯수 증가
  //만약 2->1로 빼진다면 2이상의 숫자 갯수 감소
시간복잡도: O(nlog(n))= 10만 이상
*/
#define MAX 100010
int n;
int ar[MAX];
int numCnt[MAX];

int maxLen=1;

//3.구해진 구간의 길이로 중복이 없는지 배열 탐색
// 첫 구간의 길이만큼 탐색
// 중복구간 없으면 체크, 최대값 비교
// 구간의 길이만큼 저장해놨다면 맨 앞의 숫자 빼고, 다음 숫자 더하기
  //구간의 숫자갯수 카운트 배열에 저장
  // 만약 1->2로 더해진다면 2이상의 숫자 갯수 증가
  //만약 2->1로 빼진다면 2이상의 숫자 갯수 감소
// 중복구간 없으면 체크, 최대값 비교
bool checkDup(int len){
  int dupCnt=0;
  bool check=false;
  // 첫 구간의 길이만큼 탐색
  for(int i=0;i<len;i++){
    numCnt[ar[i]]+=1;
    if(numCnt[ar[i]]== 2){
      dupCnt++;
    }
  }
  if(dupCnt==0){
    check=true;
    maxLen = max(maxLen,len);
  }
    
  for(int i=len;i<n;i++){
    numCnt[ar[i-len]]-=1;
    if(numCnt[ar[i-len]]==1){
      dupCnt--;
    }
    numCnt[ar[i]]+=1;
    if(numCnt[ar[i]]== 2){
      dupCnt++;
    }
    if(dupCnt==0){
      check=true;
      maxLen = max(maxLen,len);
    }
  }
  
  if(check==true){
    return true;
  }
  else{ return false;}
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.숫자배열 입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  //2.이진탐색으로 탐색할 구간의 길이 결정
  int start=1, end=n+1;
  while(start+1<end){
    int mid = (start+end)/2; // 탐색할 구간의 길이
    
    //3.구해진 구간의 길이로 중복이 없는지 배열 탐색
    memset(numCnt,0,sizeof(numCnt));
    bool ok = checkDup(mid);
    // 중복 없는 구간이 있다면 start = mid;
    // 모두 중복이 일어났다면 end = mid;
    if(ok){
      start=mid;
    }
    else{
      end=mid;
    }
  }
  
  cout<<maxLen<<'\n';
  return 0;
}
