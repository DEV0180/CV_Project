#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Land {
    int id;
    float area;
    string location;
};

struct Worker {
    int id;
    string name;
    string role;
};

struct Sales {
    int id;
    string crop;
    float amount;
    float price;
};

// ---------------- Add Records Functions ----------------
void addLand() {
    Land l;
    ofstream file("land.txt", ios::app);
    cout << "Enter Land ID: "; 
    cin >> l.id;
    cout << "Enter Area (in acres): ";
    cin >> l.area;
    cin.ignore();
    cout << "Enter Location: "; 
    getline(cin, l.location);
    file << l.id << "\t" << l.area << "\t" << l.location << "\n";
    file.close();
    cout << "Land record added.\n";
}

void addWorker() {
    Worker w;
    ofstream file("worker.txt", ios::app);
    cout << "Enter Worker ID: "; 
    cin >> w.id;
    cin.ignore();
    cout << "Enter Name: "; 
    getline(cin, w.name);
    cout << "Enter Role: "; 
    getline(cin, w.role);
    file << w.id << "\t" << w.name << "\t" << w.role << "\n";
    file.close();
    cout << "Worker record added.\n";
}

void addSale() {
    Sales s;
    ofstream file("sales.txt", ios::app);
    cout << "Enter Sale ID: "; 
    cin >> s.id;
    cin.ignore();
    cout << "Enter Crop Name: "; 
    getline(cin, s.crop);
    cout << "Enter Amount (in tons): "; 
    cin >> s.amount;
    cout << "Enter Price per ton: "; 
    cin >> s.price;
    file << s.id << "\t" << s.crop << "\t" << s.amount << "\t" << s.price << "\n";
    file.close();
    cout << "Sales record added.\n";
}

// ---------------- View Records Functions ----------------
void viewLandRecords() {
    ifstream file("land.txt");
    string line;
    cout << "\n--- Land Records ---\n";
    cout<<"ID\t"<<"Area\t"<<"Location\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void viewWorkerRecords() {
    ifstream file("worker.txt");
    string line;
    cout << "\n--- Worker Records ---\n";
    cout<<"ID\t"<<"Name\t"<<"Role\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void viewSalesRecords() {
    ifstream file("sales.txt");
    string line;
    cout << "\n--- Sales Records ---\n";
    cout<<"ID\t"<<"Crop\t"<<"Amount\t"<<"Price\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

// ---------------- Delete Function ----------------
void deleteLandRecord() {
    int deleteId;
    cout << "Enter Land ID to delete: ";
    cin >> deleteId;

    ifstream inFile("land.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        int id = stoi(line.substr(0, line.find('\t'))); // extract ID
        if (id != deleteId) {
            tempFile << line << "\n";
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("land.txt");
    rename("temp.txt", "land.txt");

    if (found)
        cout << "Land record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}
void deleteWorkerRecord() {
    int deleteId;
    cout << "Enter Worker ID to delete: ";
    cin >> deleteId;

    ifstream inFile("worker.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        int id = stoi(line.substr(0, line.find('\t'))); // extract ID
        if (id != deleteId) {
            tempFile << line << "\n";
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("worker.txt");
    rename("temp.txt", "worker.txt");

    if (found)
        cout << "Worker record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}
void deleteSalesRecord() {
    int deleteId;
    cout << "Enter Sales ID to delete: ";
    cin >> deleteId;

    ifstream inFile("sales.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        int id = stoi(line.substr(0, line.find('\t')));
        if (id != deleteId) {
            tempFile << line << "\n";
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("sales.txt");
    rename("temp.txt", "sales.txt");

    if (found)
        cout << "Sales record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}

// ---------------- Menu ----------------
void menu() {
    int choice;
    do {
        cout << "\n========== Agro-Tech Menu ==========\n";
        cout << "1. Add Land Record\n";
        cout << "2. Add Worker Record\n";
        cout << "3. Add Sales Record\n";
        cout << "4. View Land Records\n";
        cout << "5. View Worker Records\n";
        cout << "6. View Sales Records\n";
        cout << "7. Delete Land Record\n";
        cout << "8. Delete Worker Record\n";
        cout << "9. Delete Sales Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addLand(); break;
            case 2: addWorker(); break;
            case 3: addSale(); break;
            case 4: viewLandRecords(); break;
            case 5: viewWorkerRecords(); break;
            case 6: viewSalesRecords(); break;
            case 7: deleteLandRecord(); break;
            case 8: deleteWorkerRecord(); break;
            case 9: deleteSalesRecord(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

int main() {
    cout << "Welcome to Agri-Data Record System.\n";
    menu();
    return 0;
}
