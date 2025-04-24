#include <iostream>
#include <vector>
#include <string>
#include <fstream>  // For file operations

using namespace std;

// Class to store health records
class HealthDiary {
private:
    struct Entry {
        string date;
        string symptoms;
        string notes;
    };

    vector<Entry> entries;  // Stores multiple entries

public:
    // Function to add a new diary entry
    void addEntry() {
        Entry newEntry;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> newEntry.date;
        cin.ignore();  // Clear input buffer

        cout << "Describe your symptoms: ";
        getline(cin, newEntry.symptoms);

        cout << "Add any medical notes: ";
        getline(cin, newEntry.notes);

        entries.push_back(newEntry);

        // Save to file
        ofstream outFile("health_diary.txt", ios::app);  // Append mode
        if (outFile.is_open()) {
            outFile << "Date: " << newEntry.date << "\n";
            outFile << "Symptoms: " << newEntry.symptoms << "\n";
            outFile << "Notes: " << newEntry.notes << "\n";
            outFile << "---------------------------\n";
            outFile.close();
        } else {
            cout << "Error: Could not open file for writing.\n";
        }

        cout << "Entry added successfully!\n";
    }

    // Function to display all entries
    void displayEntries() {
        if (entries.empty()) {
            cout << "No health records found.\n";
            return;
        }

        cout << "\n--- Health Diary Entries ---\n";
        for (const auto& entry : entries) {
            cout << "Date: " << entry.date << "\n";
            cout << "Symptoms: " << entry.symptoms << "\n";
            cout << "Notes: " << entry.notes << "\n";
            cout << "---------------------------\n";
        }
    }

    // Function to generate a simple health report
    void generateReport() {
        if (entries.empty()) {
            cout << "No health data to generate a report.\n";
            return;
        }

        cout << "\n=== Health Summary Report ===\n";
        cout << "Total Entries: " << entries.size() << "\n";
        cout << "Recent Symptoms: " << entries.back().symptoms << "\n";
        cout << "------------------------------\n";
    }
};

// Main function to run the Health Diary
int main() {
    HealthDiary diary;
    int choice;

    do {
        cout << "\nHealth Diary Menu:\n";
        cout << "1. Add Health Entry\n";
        cout << "2. View Health Entries\n";
        cout << "3. Generate Health Report\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                diary.addEntry();
                break;
            case 2:
                diary.displayEntries();
                break;
            case 3:
                diary.generateReport();
                break;
            case 4:
                cout << "Exiting program. Stay healthy!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
