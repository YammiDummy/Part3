#include <iostream>
#include <fstream>
#include <optional>
#include <algorithm>
#include "car.pb.h"

//School.proto
//syntax = "proto 3";
//
//package school;
//
//message FullName {
//	string name = 1;
//	string surname = 2;
//	string patronymic = 3;
//	}
//
//message Student {
//	FullName full_name = 1;
//	repeated int32 grades = 2;
//	int32 average_grade = 3;
//	}
//
//message StudentsGroup {
//	repeated Student students = 1;
//	}



using namespace std;

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
    virtual double GetAverageScore(const FullName& name) = 0;
    virtual string GetAllInfo(const FullName& name) = 0;
    virtual string GetAllInfo() = 0;
};

class FullName {
private:
    string m_name;
    string m_surname;
    optional<string> m_patronymic;
public:
    FullName(string name, string surname, optional<string> patronymic = nullopt)
        :m_name(name), m_surname(surname), m_patronymic(patronymic) {};
    FullName() {};

    bool operator== (FullName other) {
        return tie(m_name, m_surname, m_patronymic) == tie(other.m_name, other.m_surname, other.m_patronymic);
    };
};

class Student {
private:
    FullName full_name;
    vector<int> grades; 
};

class StudentsGroup : public IRepository, IMethods {
private:
    vector<Student> group;
public:
    double GetAverageScore(const FullName& name) override{
        for( Student student : group) {

        }
    };
    string GetAllInfo(const FullName& name) override {};
    string GetAllInfo() override {};
};

int main() {

}
