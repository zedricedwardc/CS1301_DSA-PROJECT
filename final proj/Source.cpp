#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User {
    int userID;
    string username;
    string password;
    User* next;

    User(int userID, const string& username, const string& password)
        : userID(userID), username(username), password(password), next(nullptr) {}
};

class UserList {
private:
    User* head;

public:
    UserList() : head(nullptr) {}

    ~UserList() {
        while (head != nullptr) {
            User* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addUser(int userID, const string& username, const string& password) {
        User* newUser = new User(userID, username, password);
        if (head == nullptr) {
            head = newUser;
        }
        else {
            User* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newUser;
        }
        cout << "User registered successfully.\n";
    }

    bool isUsernameExists(const string& username) const {
        User* temp = head;
        while (temp != nullptr) {
            if (temp->username == username) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool authenticateUser(const string& username, const string& password) const {
        User* temp = head;
        while (temp != nullptr) {
            if (temp->username == username && temp->password == password) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    User* getHead() const {
        return head;
    }
};

// Function to save user data to a file
void saveData(const UserList& userList) {
    ofstream file("users.dat", ios::binary);
    if (file.is_open()) {
        User* temp = userList.getHead();
        while (temp != nullptr) {
            file.write(reinterpret_cast<const char*>(temp), sizeof(User));
            temp = temp->next;
        }
        file.close();
        cout << "Data saved successfully.\n";
    }
    else {
        cout << "Unable to open file for saving data.\n";
    }
}

// Function to load user data from a file
void loadData(UserList& userList) {
    ifstream file("users.dat", ios::binary);
    if (file.is_open()) {
        userList.~UserList();  // Clear existing data if any
        User* temp = new User(0, "", "");
        while (file.read(reinterpret_cast<char*>(temp), sizeof(User))) {
            userList.addUser(temp->userID, temp->username, temp->password);
            temp = new User(0, "", ""); // Allocate new memory for next user
        }
        delete temp; // Delete the last temporary object
        file.close();
        cout << "Data loaded successfully.\n";
    }
    else {
        cout << "Unable to open file for loading data.\n";
    }
}

int main() {
    UserList userList;
    loadData(userList);
    string username, password;
    int choice;
    do {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int userID;
 
            cout << "Enter a username: ";
            cin >> username;

            if (userList.isUsernameExists(username)) {
                cout << "Username already exists. Please choose a different username.\n";
                break;
            }

            cout << "Enter a password: ";
            cin >> password;

            if (userList.getHead() == nullptr) {
                userID = 1;
            }
            else {
                userID = userList.getHead()->userID + 1;
            }

            userList.addUser(userID, username, password);
            break;
        }
        case 2: {
           
            cout << "Enter your username: ";
            cin >> username;

            cout << "Enter your password: ";
            cin >> password;

            if (userList.authenticateUser(username, password)) {
                cout << "Login successful.\n";
            }
            else {
                cout << "Invalid username or password. Please try again.\n";
            }
            break;
        }
        case 3:
            saveData(userList);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        system("pause");
        system("cls");
    } while (choice != 3);

    return 0;
}