#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student
{
    char fio[30];
    int age;
    char gender;
    int course;
    double marks;

    Student() = default;
};

void Add_stud(const char* filename, const Student& student)
{
    ofstream fout(filename, ios::binary | ios::app);
    fout.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    fout.close();
}

void viewFile(const char* filename)
{
    ifstream fin(filename, ios::binary);
    Student student;
    while (fin.read(reinterpret_cast<char*>(&student), sizeof(Student)))
    {
        cout << "FIO: " << student.fio
             << "\n Age: " << student.age
             << "\n Gender: " << student.gender
             << "\n Course: " << student.course
             << "\n Marks: " << student.marks << endl << endl;
    }
    fin.close();
}

void Create_new_file(const char* inputFilename, const char* outputFilename)
{
    ifstream fin(inputFilename, ios::binary);
    ofstream fout(outputFilename, ios::binary | ios::app);
    Student student;
    while (fin.read(reinterpret_cast<char*>(&student), sizeof(Student)))
        if (student.marks >= 9.0)
            fout.write(reinterpret_cast<const char*>(&student), sizeof(Student));
}

int main()
{
    int n;
    Student student;
    const char* inFile = "data.bin";
    const char* outFile = "result.bin";
    cout << "enter number of students\n";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "FIO: ";
        cin.ignore(); cin.getline(student.fio, 30);
        cout << "Age: "; cin >> student.age;
        cout << "Gender: "; cin >> student.gender;
        cout << "Course: "; cin >> student.course;
        cout << "Marks: "; cin >> student.marks;
        Add_stud(inFile, student);
    }
    cout << "\nstudents\n\n";
    viewFile(inFile);
    Create_new_file(inFile, outFile);
    cout << "\notlichniki:\n\n";
    viewFile(outFile);
    ofstream a(inFile);
    a.write("", 0);
    a.close();
    ofstream b(outFile);
    b.write("", 0);
    b.close();
    return 0;
}
