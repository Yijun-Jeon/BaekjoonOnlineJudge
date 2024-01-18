#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    int kor;
    int eng;
    int math;
};

bool comp(Student s1, Student s2){
    if(s1.kor > s2.kor)
        return true;
    if(s1.kor == s2.kor){
        if(s1.eng < s2.eng)
            return true;
        if(s1.eng == s2.eng){
            if(s1.math > s2.math)
                return true;
            if(s1.math == s2.math)
                return s1.name < s2.name;
            return false;
        }
        return false;
    }
    return false;
}

int main(void)
{
    int N;
    scanf("%d",&N);

    vector<Student> students;
    for(int i=0;i<N;i++){
        Student student;
        cin >> student.name >> student.kor >> student.eng >> student.math;
        students.push_back(student);
    }

    sort(students.begin(),students.end(),comp);
    for(int i=0;i<N;i++)
        cout << students[i].name << '\n';
    return 0;
}