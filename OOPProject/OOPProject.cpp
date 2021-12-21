#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Student.h"
#include "StudentTest.h"
#include "GradeBook.h"

using namespace std;

int main()
{

    std::cout << "Hello World!\n";

    Student *student = new Student("adam", "sssss");
    Student* student2 = new Student("aaa", "zzz");

    GradeBook* gradeBook = new GradeBook("lamusy");
    gradeBook->addStudent(*student);
    gradeBook->addStudent(*student2);

    gradeBook->printStudents();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
