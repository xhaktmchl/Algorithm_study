#include <string>
#include <vector>
#include <algorithm>
// [프로그래머스 c++ V] 가장 큰 수
// 문제: 주어진 숫자배열의 원소들을 이어붙힌 수 중 최댁값을 구하라
// 접근: 첫 번째 숫자가 클 수록 최대-> 정렬 ->첫 번째 숫자가 같은 경우(3,30) 330,303 예외남 
// 첫 번째 숫자가 같은 경우 -> 두개의 문자열을 더한 값의 크기를 비교
// 예외처리: 0,0,0,0,0,0인 경우 0 하나의 숫자로 반환해야 해서 예외처리
// 풀이: 
// 숫자들을 문자열로 변환후 벡터에 저장
// 첫번째 숫자가 다른 경우과 같은 경우 문자열 합의 크기를 비교하는 사용자 지정 함수
// 정렬
// 0,0,0, 인 경우 예외처리
// 문자열 합한뒤 정답 반환

using namespace std;
bool mysort(string a, string b){
    if(a[0] != b[0]){
        return a[0] > b[0];
    }
    else{
        return a+b > b+a;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> ar;
    for(int i=0;i<numbers.size();i++){
        ar.push_back(to_string(numbers[i]));
    }
    sort(ar.begin(),ar.end(),mysort);
    
    if(ar[0] == "0"){ return answer = "0"; }
    for(int i=0;i<ar.size();i++){
        answer+=ar[i];
    }
    return answer;
}
