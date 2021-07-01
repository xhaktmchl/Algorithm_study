#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// [프로그래머스 c++ O] 제일 작은 수 제거하기
// 문제: 주어진 벡터에서 숫서를 바꾸지않고 최솟값 제거하기
// 접근: 정렬시킨다음 최솟값 제거 -> 주어진 순서 바꾸면 안됨
// 접근2: 배열을 복사해서 최솟값 찾고 최솟값의 위치를 이용해 제거
// 풀이: 
// 주어진 배열 복사
// tp정렬시켜 최솟값 찾음
// arr.erase(find(arr.begin(),arr.end(),minNum));// find로 최속값의 iterator찾고 erase로 삭제
// 배열에 원소 없으면 -1추가
// 개념: 
// vector.erase(이터레이터 위치) : 특정위치 원소제거
// find(arr.begin(),arr.end(),찾는 값) : 찾는 값의 iterator 반환
// 보통 arr.erase(find(arr.begin(),arr.end(),minNum)); 혼합해서 사용
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> tp;
    // tp를 이용해 최솟값 찾기
    tp = arr;
    sort(tp.begin(),tp.end());  // 오름차순 정렬의 맨앞이 최솟값
    int minNum = tp[0];
    arr.erase(find(arr.begin(),arr.end(),minNum)); // find로 최속값의 iterator찾고 erase로 삭제
    
    answer = arr;
    if(answer.size() == 0){ // 원소 없는 경우 -1 추가
        answer.push_back(-1);
    }
    return answer;
}
