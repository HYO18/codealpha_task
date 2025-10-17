#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    double totalCredits = 0, totalGradePoints = 0;

    for (int i = 1; i <= numCourses; i++) {
        double grade, credit;
        cout << "\nEnter grade points for course " << i << " (e.g., 4.0, 3.7, etc.): ";
        cin >> grade;
        cout << "Enter credit hours for course " << i << ": ";
        cin >> credit;

        totalCredits += credit;
        totalGradePoints += grade * credit;
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
