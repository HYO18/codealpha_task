#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if username already exists
    ifstream checkFile(username + ".txt");
    if (checkFile.is_open()) {
        cout << "Username already exists! Try a different one.\n";
        checkFile.close();
        return;
    }

    // Create file to store credentials
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, storedUser, storedPass;
    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (!file.is_open()) {
        cout << "User not found! Please register first.\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);
    file.close();

    if (username == storedUser && password == storedPass)
        cout << "Login successful! Welcome, " << username << "!\n";
    else
        cout << "Incorrect password. Try again.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== LOGIN & REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
