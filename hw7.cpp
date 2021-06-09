#include <iostream>
#include <fstream>
#include <optional>
#include <algorithm>
#include <vector>
#include "car.pb.h"

using namespace std;



class FullName {
public:
    string m_name;
    string m_surname;
    optional<string> m_patronymic = nullopt;

    FullName(string name, string surname, optional<string> patronymic = nullopt)
        :m_name(name), m_surname(surname), m_patronymic(patronymic) {};
    FullName() {};

    bool operator== (FullName other) {
        return tie(m_name, m_surname, m_patronymic) == tie(other.m_name, other.m_surname, other.m_patronymic);
    };

    friend ostream& operator<< (ostream& out, FullName& fn);
};

ostream& operator<< (ostream& out, FullName& fn) {
    out << fn.m_surname << " " << fn.m_name << " " << fn.m_patronymic.value();
    return out;
};

class Student {
public:
    FullName full_name;
    vector<int> grades; 
};

ostream& operator<< (ostream& out, Student s) {
    out << s.full_name << " grades: ";
    copy(s.grades.begin(), s.grades.end(), ostream_iterator<int>(out, ", "));
    return out;
};

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
    virtual double GetAverageScore(const FullName& name) = 0;
    virtual string GetAllInfo(const FullName& name) = 0;
    virtual string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, IMethods {
public:
    vector<Student> group;

    double GetAverageScore(const FullName& name) {
        Student temp;
        double av_score;
        int count_check = 0;
        for (Student student : group) {
            if (student.full_name == name) {
                count_check++;
                temp = student;
            }
        };
        if (count_check == 0) {
            cout << "There is no ";
            cout << temp.full_name;
            return 0;
        }
        else if (count_check > 1) {
            cout << "There is more than 1 of ";
            cout << temp.full_name;
        }
        else {
            double sum = 0;
            for_each(temp.grades.begin(), temp.grades.end(), [&sum](int grade) {sum = +grade; });
            av_score = sum / (temp.grades.size());
            return av_score;
        };
    };

    string GetAllInfo(const FullName& name){

    };

    string GetAllInfo() {};
};

int main() {
    cout << "test" << endl;
}
