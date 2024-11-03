#include <iostream>

using namespace std;

int main(){
    int peopleNum =0;
    
    cout << " Number of People: ";
    cin >> peopleNum;
    char** people = new char*[peopleNum];

    for(int i = 0;i <peopleNum; i++){
        char* person = new char[64];
        cin >> (person);
        people[i] = person;
    } 

    
    int SubjectsNum = 0;
    cout << " Number of subjects: ";
    cin >> SubjectsNum;

    int** grades = new int*[SubjectsNum];

    for(int j = 0; j<peopleNum ;j++)
    {
        grades[j] = new int[SubjectsNum];
        cout << "Grades of " << people[j] << " are: " << endl;
        for(int i =0;i<SubjectsNum; i++){
            cout << "Grade " << i+1 << ": ";
            cin >> grades[j][i];
        }
    
    }

    cout << "Grades are: ";
    for(int i =0;i<peopleNum; i ++){
        cout << people[i] << " ";
        for(int j =0;j<SubjectsNum;j++){
            cout << grades[i][j] << " ";
        }
        cout << endl;

    }

    for(int i =0; i<peopleNum;i++){
        delete[] grades[i];
        delete[] people[i];
    }

    delete[] grades;
    delete[] people;
    return 0;
}