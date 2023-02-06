#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct Phone {
    string brand_name;
    string model_name;
    string form_factor;
    int year_of_issue;
    double screen_size;
    double price;
};

vector<Phone> phones;

void AddPhone() {
    Phone phone;
    cout << "Enter brand name: ";
    cin >> phone.brand_name;
    if (phone.brand_name.empty()) {
        std::cout << "Error: Brand name cannot be empty." << std::endl;
        return;
    }
    cout << "Enter model name: ";
    cin >> phone.model_name;
    cout << "Enter form factor: ";
    cin >> phone.form_factor;
    try {
        if (phone.form_factor != "bar" && phone.form_factor != "slider" && phone.form_factor != "flip") {
            cout << "Error: Invalid form factor." << endl;
            return;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: Invalid form factor." << endl;
        return;
    }

    cout << "Enter year of issue: ";
    cin >> phone.year_of_issue;
    try {
        if (phone.year_of_issue <= 1979 || phone.year_of_issue >=2023) {
            cout << "Error: year of issue must be a number between 1979 and 2023." << endl;
            return;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: Invalid year of issue." << endl;
        return;
    }
    cout << "Enter screen size: ";
    cin >> phone.screen_size;
    try {
        if (phone.screen_size <= 0) {
            cout << "Error: Screen size must be a positive number." << endl;
            return;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: Invalid screen size." << endl;
        return;
    }
    cout << "Enter price: ";
    cin >> phone.price;
    try {
        if (phone.price <= 0) {
            cout << "Error: Price must be a positive number." << endl;
            return;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: Invalid price." << endl;
        return;
    }

    phones.push_back(phone);
    cout << "Phone added successfully!" << endl;
}

void DeletePhone() {
    if (phones.empty()) {
        cout << "There are no phones to delete." << endl;
        return;
    }
    int index;
    cout << "Enter index of phone to delete: ";
    cin >> index;

    if (index < 0 || index >= phones.size()) {
        cout << "Invalid index." << endl;
        return;
    }

    phones.erase(phones.begin() + index);
    cout << "Phone deleted successfully!" << endl;
}

void ShowReport()
{
    for (int i = 0; i < phones.size(); ++i)
    {
        cout << "Index: " << i << endl;
        cout << "Brand name: " << phones[i].brand_name << endl;
        cout << "Model name: " << phones[i].model_name << endl;
        cout << "Form factor: " << phones[i].form_factor << endl;
        cout << "Year of issue: " << phones[i].year_of_issue << endl;
        cout << "Screen size: " << phones[i].screen_size << endl;
        cout << "Price: " << phones[i].price << endl;
        cout << endl;
    }
}

void ShowPhonesByBrand() {
    string brand_name;
    cout << "Enter brand of phone: " << endl;
    cin >> brand_name;
    bool found = false;
    for (int i = 0; i < phones.size(); i++) {
        if (phones[i].brand_name == brand_name) {
            cout << "Index: " << i << endl;
            cout << "Brand name: " << phones[i].brand_name << endl;
            cout << "Model name: " << phones[i].model_name << endl;
            cout << "Form factor: " << phones[i].form_factor << endl;
            cout << "Year of issue: " << phones[i].year_of_issue << endl;
            cout << "Screen size: " << phones[i].screen_size << endl;
            cout << "Price: " << phones[i].price << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No phones found with brand " << brand_name << endl;
    }
 
}

void ShowPhonesByFactorAndScreen(string form_factor, double screen_size) {
    bool found = false;
    for (Phone phone : phones) {
        if (phone.form_factor == form_factor && phone.screen_size == screen_size) {
            found = true;
            cout << "Brand: " << phone.brand_name << endl;
            cout << "Model: " << phone.model_name << endl;
            cout << "Form Factor: " << phone.form_factor << endl;
            cout << "Year of Issue: " << phone.year_of_issue << endl;
            cout << "Screen Size: " << phone.screen_size << endl;
            cout << "Price: " << phone.price << endl;
            cout << endl;
        }
    }

    if (!found) {
        cout << "No phones found with form factor '" << form_factor << "' and screen size '" << screen_size << "'." << endl;
    }

}

void ShowBrandWithMaxQuantity() {
    map<string, int> brand_count;
    for (const auto& phone : phones) {
        brand_count[phone.brand_name]++;
    }

    string max_brand;
    int max_count = 0;
    for (const auto& brand : brand_count) {
        if (brand.second > max_count) {
            max_count = brand.second;
            max_brand = brand.first;
        }
    }

    cout << "Brand with the maximum quantity of phones: " << max_brand << endl;
}

void topThreeByScreenSize()
{
    map<double, int> screenSizeCount;
    for (const auto& phone : phones) {
        screenSizeCount[phone.screen_size]++;
    }

    vector<std::pair<double, int>> screenSizes;
    for (const auto& kv : screenSizeCount) {
        screenSizes.push_back(kv);
    }

    sort(screenSizes.begin(), screenSizes.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    cout << "Top-3 screen sizes:\n";
    for (int i = 0; i < 3 && i < screenSizes.size(); i++) {
        cout << screenSizes[i].first << ": " << screenSizes[i].second << " phones"<<endl<<endl;
    }
}

int main() {
    int option;
    string formFactor;
    double screenSize;
  
    do
    {
        cout << "--- Phone Shop ---" << endl;
        cout << "1. Add a phone" << endl;
        cout << "2. Delete a phone" << endl;
        cout << "3. Show report" << endl;
        cout << "4. Show all phones by brand" << endl;
        cout << "5. Show all phones by factor and screen" << endl;
        cout << "6. Show brand with max quantity" << endl;
        cout << "7. Show Top-3 screen sizes" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            AddPhone();
            break;
        case 2:
            DeletePhone();
            break;
        case 3:
            ShowReport();
            break;
        case 4:
            ShowPhonesByBrand();
            break;
        case 5:
            cout << "Enter the form factor: ";
            cin >> formFactor;
            cout << "Enter the screen size: ";
            cin >> screenSize;
            ShowPhonesByFactorAndScreen(formFactor, screenSize);
            break;
        case 6:
            ShowBrandWithMaxQuantity();
            break;
        case 7:
            topThreeByScreenSize();
            break;
        case 8:
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (option != 8);
    return 0;
}

