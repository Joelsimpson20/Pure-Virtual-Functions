#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
public:
    string getName() {
        cout << "Enter name : ";
        cin >> name;
        return name;
    }
    //Anyone who inherits Person will need to provide there own implementation of this function
    virtual void getData() = 0;
    //Anyone who inherits Person will need to provide there own implementation of this function
    virtual bool isOutstanding() = 0;
};

class Student : public Person {
private:
    float gpa;
public:
    void getData() {
        cout << "Enter students GPA : ";
        cin >> gpa;
    }
    bool isOutstanding() {
        if (gpa > 5.0) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Professor : public Person {
private:
    int numPub;
public:
    void getData() {
        cout << "Enter number of professors publications : ";
            cin >> numPub;
    }
    bool isOutstanding() {
        if (numPub > 100) {            
            return true;
       }
        else {
            return false;
        }
    }
};

int main()
{
    Person* arr[2];
    Student s;
    Professor p;
    arr[0] = &s;
    arr[1] = &p;
    vector<string> outstanding;
    string n = "Name is : ";
    string w = " This person is outstanding";
    string com;
    bool repeat = true;
    char ans, ans2;
    while (repeat) {
        cout << "Enter student or professor (s / p) : ";
        cin >> ans;
        if (ans == 's') {

            com = n + arr[0]->getName();
            outstanding.push_back(com);
            arr[0]->getData();
            if (arr[0]->isOutstanding() == true) {
                outstanding.push_back(w);
            }

        }
        else if (ans == 'p') {
            com = n + arr[1]->getName();
            outstanding.push_back(com);
            arr[1]->getData();
            if (arr[1]->isOutstanding() == true) {
                outstanding.push_back(w);
            }

        }
        cout << "Enter another? (y / n) : ";
        cin >> ans2;
        if (ans2 == 'y') {
            repeat = true;
        }
        else if (ans2 == 'n') {
            repeat = false;
        }
    }
    for (int i = 0; i < outstanding.size(); i++) {
        cout << outstanding.at(i);
            cout << "\n";
    }
}

