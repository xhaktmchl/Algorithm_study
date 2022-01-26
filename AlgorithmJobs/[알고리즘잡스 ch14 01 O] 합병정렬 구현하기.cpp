#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch14 01 O] 합병정렬 구현하기
풀이: 
//1.배열 입력
//2.합병정렬 
// 합병정렬: s부터 e까지 구간을 나누어 정렬한 뒤 합병
//왼구간 합병 나누기
  //오른구간 합병 나누기
  // 정렬된 두 구간 머지
//3.출력: 정렬된 배열
시간복잡도: O(nlog(n))
// 주의: 재귀함수 안에서 계속 초기화-> n만큼 시간 추가-> 시간초과-> 전역변수 이용
*/
#define MAX 100050
int n;
int numbers[MAX];
int tp[MAX];

// 두 구간 정렬면서 머지
void merge(int ar[] ,int s1, int e1, int s2, int e2){
  int p=s1,q=s2;
  //int tp[MAX]={0,}; // 주의: 재귀함수 안에서 계속 초기화-> n만큼 시간 추가-> 시간초과
  int tpIdx=0;
  // 두 구간 모두 있을 때
  while(p<=e1 && q<=e2){
    //왼 구간이 더 작을 때 
    if(ar[p] <= ar[q]){
      tp[tpIdx++] = ar[p++];
    }
    //오른 구간이 더 작을 때 
    else if(ar[p]>ar[q]) {
      tp[tpIdx++] = ar[q++];
    }
  }
  // 왼구간만 남았을 때 왼구간의 남은 모든 수 복사
  if(p<=e1){
    while(p<=e1){
      tp[tpIdx++] = ar[p++];
    }
  }
  // 오른구간만 남았을 때 오른구간의 남은 모든 수 복사
  if(q<=e2){
    while(q<=e2){
      tp[tpIdx++] = ar[q++];
    }
  }
  
  //정렬된 s1~e2구간 원래 배열에 복사
  for(int i=s1;i<=e2;i++){
    ar[i]=tp[i-s1];
  }
}

// 합병정렬: s부터 e까지 구간을 나누어 정렬한 뒤 합병
void mergeSort(int ar[],int s,int e){
  // 기저사례: 숫자가 하나남으면
  if(s>=e){
    return;
  }
  
  int mid = (s+e)/2;
  //왼구간 합병 나누기
  mergeSort(ar,s,mid);
  //오른구간 합병 나누기
  mergeSort(ar,mid+1,e);

  // 두 구간 정렬면서 머지
  merge(ar,s,mid,mid+1,e);
}


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열 입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>numbers[i];
    //cout<<numbers[i]<<" ";
  }//cout<<'\n';
  
  //2.합병정렬 
  mergeSort(numbers,0,n-1);
  //3.출력: 정렬된 배열
  for(int i=0;i<n;i++){
    cout<<numbers[i]<<" ";
  }
  return 0;
}
