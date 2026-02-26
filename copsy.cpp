#include <iostream>
#include <string>
using namespace std;

struct Farmer {
    int id;
    string name;
    double area;
    string crop;
};

Farmer list[100];
int total = 0;

int line[100];
int lineCount = 0;

void addFarmer() {
    if (total >= 100) {
        cout << "Farmer list is full!\n";
        return;
    }

    Farmer f;
    cout << "\n--- Add Farmer ---\n";
    cout << "Enter ID: ";
    cin >> f.id;

    // Linear Search to check duplicate ID
    for (int i = 0; i < total; i++) {
        if (list[i].id == f.id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, f.name);

    cout << "Enter Land Area (in acres): ";
    cin >> f.area;

    cin.ignore();
    cout << "Enter Crop Name: ";
    getline(cin, f.crop);

    list[total++] = f;
    cout << "Farmer added successfully!\n";
}

void showFarmers() {
    if (total == 0) {
        cout << "\nNo farmers available.\n";
        return;
    }

    cout << "\n--- Farmer List ---\n";
    cout << "ID\tName\t\tArea\tCrop\n";
    for (int i = 0; i < total; i++) {
        cout << list[i].id << "\t"
             << list[i].name << "\t"
             << list[i].area << "\t"
             << list[i].crop << "\n";
    }
}

void sortFarmers() {
    if (total < 2) {
        cout << "Not enough farmers to sort.\n";
        return;
    }

    // Bubble Sort by ID
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (list[j].id > list[j + 1].id) {
                Farmer temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    cout << "Farmers sorted by ID.\n";
}

void removeFarmer() {
    if (total == 0) {
        cout << "No farmers to remove.\n";
        return;
    }

    int id;
    cout << "Enter ID to remove: ";
    cin >> id;

    int pos = -1;
    for (int i = 0; i < total; i++) {
        if (list[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Farmer not found.\n";
        return;
    }

    for (int i = pos; i < total - 1; i++) {
        list[i] = list[i + 1];
    }

    total--;
    cout << "Farmer removed successfully.\n";
}

void calcProfit() {
    double area, profitPerAcre;
    cout << "\n--- Profit Calculator ---\n";
    cout << "Enter Area: ";
    cin >> area;
    cout << "Enter Profit per Acre: ";
    cin >> profitPerAcre;

    cout << "Total Expected Profit: "
         << area * profitPerAcre << "\n";
}

void suggestCrop() {
    string season;
    cout << "\nEnter Season (Kharif/Rabi/Zaid): ";
    cin >> season;

    if (season == "Kharif" || season == "kharif")
        cout << "Suggested Crops: Rice, Maize, Cotton\n";
    else if (season == "Rabi" || season == "rabi")
        cout << "Suggested Crops: Wheat, Mustard, Gram\n";
    else if (season == "Zaid" || season == "zaid")
        cout << "Suggested Crops: Watermelon, Cucumber\n";
    else
        cout << "Invalid season.\n";
}

void requestFertilizer() {
    int id;
    cout << "Enter Farmer ID: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (list[i].id == id) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Farmer not found!\n";
        return;
    }

    line[lineCount++] = id;
    cout << "Added to fertilizer queue. Position: " << lineCount << "\n";
}

void processFertilizer() {
    if (lineCount == 0) {
        cout << "No one in queue.\n";
        return;
    }

    cout << "Fertilizer given to Farmer ID: " << line[0] << "\n";

    for (int i = 0; i < lineCount - 1; i++) {
        line[i] = line[i + 1];
    }

    lineCount--;
}

int main() {
    int choice;

    while (true) {
        cout << "\n Farm Management System \n";
        cout << "1. Add Farmer\n";
        cout << "2. Show Farmers\n";
        cout << "3. Sort Farmers\n";
        cout << "4. Remove Farmer\n";
        cout << "5. Calculate Profit\n";
        cout << "6. Suggest Crop\n";
        cout << "7. Request Fertilizer\n";
        cout << "8. Process Fertilizer\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addFarmer(); break;
            case 2: showFarmers(); break;
            case 3: sortFarmers(); break;
            case 4: removeFarmer(); break;
            case 5: calcProfit(); break;
            case 6: suggestCrop(); break;
            case 7: requestFertilizer(); break;
            case 8: processFertilizer(); break;
            case 9: cout << "Exiting Program...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}