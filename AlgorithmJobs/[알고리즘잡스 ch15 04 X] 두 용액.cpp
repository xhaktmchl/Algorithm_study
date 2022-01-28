#include <iostream>
#include <algorithm>
#include <cmath> // abs

using namespace std;
/*
[알고리즘잡스 ch15 04 X] 두 용액
풀이1: 이진탐색 -> 값이 안나옴 실패
//1.특성값 배열 입력
  //2.배열 정렬
  //3.두 개의 용액 선택
  //반복문으로 첫 숫자 저장 
  //첫 숫자 뒤에서 0에 가장 가까운 수 이진탐색
  //0에 가장 가까우면 결과값 저장, 두 용액 값 저장
시간복잡도: O(nlog(n))= 10만 이상
풀이2: 투 포인터 
 //1.특성값 배열 입력
  //2.배열 정렬
  //3.두 개의 용액 선택
  // 투 포인터로 양 끝에서 시작
  //두 수의 합이 0에 가장 가까우면 결과값 저장, 두 용액 값 저장
  //합이 음수이면 start++
  //합이 양수이면 end--
시간복잡도: O(n)= 10만 
*/
#define MAX 100010
int n;
long long ar[MAX];
int a,b;
long long result=2000000000;
long long resultA,resultB;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.특성값 배열 입력
  //2.배열 정렬
  //3.두 개의 용액 선택
  // 투 포인터로 양 끝에서 시작
  //두 수의 합이 0에 가장 가까우면 결과값 저장, 두 용액 값 저장
  //합이 음수이면 start++
  //합이 양수이면 end--
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>ar[i];
  }
  sort(ar+1,ar+n+1);

  long long start=1,end=n;
  while(start<end){
    long long sum = ar[start]+ar[end];
      
    if(abs(sum) < abs(result)){
      resultA = ar[start];
       resultB = ar[end];
       result = ar[start]+ar[end];
    }
      
    if(sum<=0){
      start++;
    }
    else{
     end--;
     }
  }
  
  cout<<resultA<<" "<<resultB<<'\n';
  return 0;
}
