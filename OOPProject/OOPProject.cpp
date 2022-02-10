#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Student.h"
#include "StudentTest.h"
#include "GradeBook.h"
#include "DataHandler.h"
#include "clearscreen.h"

using namespace std;

int main()
{
    vector<GradeBook> gradeBooks = DataHandler::loadData();
    while (true)
    {
        int option;
        cout << "What are you going to do?" << endl;
        cout << "\t1. Display a list of classes" << endl;
        cout << "\t2. Display a list of students in class" << endl;
        cout << "\t3. Display a GPA of the class" << endl;
        cout << "\t4. Display students grades from a test" << endl;
        cout << "\t5. Add new class" << endl;
        cout << "\t6. Add new student" << endl;
        cout << "\t7. Add new test" << endl;
        cout << "\t8. Display students GPA" << endl;
        cout << "\t0. Exit from the program" << endl;
        cout << "Selected option: ";
        try {
            cin.exceptions(ios::failbit | ios::badbit);
            cin >> option;
        }
        catch(exception &){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
            ClearScreen();
            std::cout << endl << "Wrong type of input, try again." << endl <<endl;
            continue;
        }
        ClearScreen();
        if (option == 1)
        {
            cout << endl;
            for (int i = 0; i < gradeBooks.size(); i++) {
                cout<<i+1<<". " << gradeBooks[i].getName() << endl;
            }
            cout << endl;
        }
        else if (option == 2)
        {
            int classNumber;
            cout << endl << "Which class do you want to display?"<<endl;
            for (int i = 0; i < gradeBooks.size(); i++) {
                cout<<"\t" << i + 1 << ". " << gradeBooks[i].getName() << endl;
            }
            cout << "Selected class: ";
            try {
                cin.exceptions(ios::failbit | ios::badbit);
                cin >> classNumber;
            }
            catch (exception&) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                std::cout << endl << "Wrong type of input, try again." << endl << endl;
                continue;
            }
            ClearScreen();
            cout << endl;
            if (classNumber <= gradeBooks.size() && classNumber>0)
            {
                gradeBooks[(classNumber-1)].printStudents();
            }
            else
            {
                cout << "Wrong class."<<endl;
            }
            cout << endl;

        }
        else if (option == 3)
        {
            int classNumber;
            cout << endl << "Which class GPA do you want to display?" << endl;
            for (int i = 0; i < gradeBooks.size(); i++) {
                cout << "\t" << i + 1 << ". " << gradeBooks[i].getName() << endl;
            }
            cout << "Selected class: ";
            try {
                cin.exceptions(ios::failbit | ios::badbit);
                cin >> classNumber;
            }
            catch (exception&) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                std::cout << endl << "Wrong type of input, try again." << endl << endl;
                continue;
            }
            ClearScreen();
            cout << endl;
            if (classNumber <= gradeBooks.size() && classNumber > 0)
            {
                cout<< "GPA: " <<gradeBooks[(classNumber - 1)].getClassMean()<< endl;
            }
            else
            {
                cout << "Wrong class." << endl;
            }
            cout << endl;
        }
        else if (option == 4)
        {
            int classNumber;
            cout << endl << "Which class do you want to display?" << endl;
            for (int i = 0; i < gradeBooks.size(); i++) {
                cout << "\t" << i + 1 << ". " << gradeBooks[i].getName() << endl;
            }
            cout << "Selected class: ";
            try {
                cin.exceptions(ios::failbit | ios::badbit);
                cin >> classNumber;
            }
            catch (exception&) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                std::cout << endl << "Wrong type of input, try again." << endl << endl;
                continue;
            }
            ClearScreen();
            cout << endl;
            if (classNumber <= gradeBooks.size() && classNumber > 0)
            {
                int testNumber;
                cout << "Which test do you want to display?" << endl;
                gradeBooks[(classNumber - 1)].printTests();
                cout << "Selected test: ";
                try {
                    cin.exceptions(ios::failbit | ios::badbit);
                    cin >> testNumber;
                }
                catch (exception&) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                    std::cout << endl << "Wrong type of input, try again." << endl << endl;
                    continue;
                }
                ClearScreen();
                cout << endl;
                if (testNumber <= gradeBooks[(classNumber - 1)].getStudentTestVectorSize() && testNumber > 0)
                {
                    gradeBooks[(classNumber - 1)].printTestWithScores(testNumber-1);
                }
                else
                {
                    cout << "Wrong test." << endl;
                }
            }
            else
            {
                cout << "Wrong class." << endl;
            }
            cout << endl;
        }
        else if (option == 5)
        {
            string name;
            cout << "Name of new class: ";
            cin >> name;
            gradeBooks.push_back(GradeBook(name));
            cout << "Finished."<<endl;
        }
        else if (option == 6)
        {
            int classNumber;
            cout << endl << "Select class: " << endl;
            for (int i = 0; i < gradeBooks.size(); i++) {
                cout << "\t" << i + 1 << ". " << gradeBooks[i].getName() << endl;
            }
            cout << "Selected class: ";
            try {
                cin.exceptions(ios::failbit | ios::badbit);
                cin >> classNumber;
            }
            catch (exception&) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                std::cout << endl << "Wrong type of input, try again." << endl << endl;
                continue;
            }
            ClearScreen();
            cout << endl;
            if (classNumber <= gradeBooks.size() && classNumber > 0)
            {
                string name, surname;
                cout << "Name of new student: ";
                cin >> name;
                cout << "Surname of new student: ";
                cin >> surname;
                Student student(name, surname);
                gradeBooks[(classNumber-1)].addStudent(student);
                cout << "Finished." << endl;
            }
            else
            {
                cout << "Wrong class." << endl;
            }
            cout << endl;
        }
        else if (option == 7)
        {
            int classNumber;
            cout << endl << "Select class: " << endl;
            for (int i = 0; i < gradeBooks.size(); i++) {
                cout << "\t" << i + 1 << ". " << gradeBooks[i].getName() << endl;
            }
            cout << "Selected class: ";
            try {
                cin.exceptions(ios::failbit | ios::badbit);
                cin >> classNumber;
            }
            catch (exception&) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                std::cout << endl << "Wrong type of input, try again." << endl << endl;
                continue;
            }
            ClearScreen();
            cout << endl;
            if (classNumber <= gradeBooks.size() && classNumber > 0)
            {
                string name, subject;
                int maxScore;
                cout << "Name of new test: ";
                cin >> name;
                cout << "Subject: ";
                cin >> subject;
                cout << "Maximum score: ";
                try {
                    cin.exceptions(ios::failbit | ios::badbit);
                    cin >> maxScore;
                }
                catch (exception&) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                    std::cout << endl << "Wrong type of input, try again." << endl << endl;
                    continue;
                }
                StudentTest *test=new StudentTest(name, subject, maxScore);
                gradeBooks[(classNumber - 1)].addTest(*test);

                gradeBooks[(classNumber - 1)].addScoresForTest(*test);

                cout << "Finished." << endl;
            }
            else
            {
                cout << "Wrong class." << endl;
            }
            cout << endl;
        }
        else if (option == 8)
        {
            int classNumber;
            cout << endl << "Select class: " << endl;
            for (int i = 0; i < gradeBooks.size(); i++) {
                cout << "\t" << i + 1 << ". " << gradeBooks[i].getName() << endl;
            }
            cout << "Selected class: ";
            try {
                cin.exceptions(ios::failbit | ios::badbit);
                cin >> classNumber;
            }
            catch (exception&) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                std::cout << endl << "Wrong type of input, try again." << endl << endl;
                continue;
            }
            ClearScreen();
            cout << endl;
            if (classNumber <= gradeBooks.size() && classNumber > 0)
            {
                gradeBooks[(classNumber - 1)].printStudentsMean();
            }
            else
            {
                cout << "Wrong class." << endl;
            }
            cout << endl;
        }
        else if (option == 0)
        {
            break;
        }
        else {
            ClearScreen();
            cout << endl << "Wrong option, try again." << endl << endl;
        }
    }
    DataHandler::saveData(gradeBooks);
    
}