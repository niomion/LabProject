#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Grades
{
private:
    T math;
    T language;
    T physics;
    T history;
    T geography;
    T average;
public:
    Grades();

    T getMathGrade();
    T getLanguageGrade();
    T getPhysicsGrade();
    T getHistoryGrade();
    T getGeographyGrade();
    T getAverageGrade();

    void setMathGrade(T grade);
    void setLanguageGrade(T grade);
    void setPhysicsGrade(T grade);
    void setHistoryGrade(T grade);
    void setGeographyGrade(T grade);
    void calculateAverageGrade();
    void setAverageGrade(T mat, T languag, T physic, T histor, T geograph);
};

template <typename T>
Grades<T>::Grades() : math(0), language(0), physics(0), history(0), geography(0), average(0) {}

template <typename T>
T Grades<T>::getMathGrade() {
    return math;
}

template <typename T>
T Grades<T>::getLanguageGrade() {
    return language;
}

template <typename T>
T Grades<T>::getPhysicsGrade() {
    return physics;
}

template <typename T>
T Grades<T>::getHistoryGrade() {
    return history;
}

template <typename T>
T Grades<T>::getGeographyGrade() {
    return geography;
}

template <typename T>
T Grades<T>::getAverageGrade() {
    return average;
}

template <typename T>
void Grades<T>::setMathGrade(T grade) {
    math = grade;
}

template <typename T>
void Grades<T>::setLanguageGrade(T grade) {
    language = grade;
}

template <typename T>
void Grades<T>::setPhysicsGrade(T grade) {
    physics = grade;
}

template <typename T>
void Grades<T>::setHistoryGrade(T grade) {
    history = grade;
}

template <typename T>
void Grades<T>::setGeographyGrade(T grade) {
    geography = grade;
}

template <typename T>
void Grades<T>::calculateAverageGrade() {
    average = ((math + language + physics + history + geography) / 5);
}

template <typename T>
void Grades<T>::setAverageGrade(T mat, T languag, T physic, T histor, T geograph) {
    average = ((mat + languag + physic + histor + geograph) / 5);
}