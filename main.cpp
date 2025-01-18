#include <iostream>
#include "ProductList.hpp"
using std::string, std::cin, std::cout, std::endl;

int main() {
    HM::ProductList productList;
    string name, filename;
    int quantity;
    char choice;

    // Wczytywanie listy z pliku na starcie programu
    cout << "Do you want to load the product list from a file? (y/n): ";
    cin >> choice;
    // Ignorowanie znaku nowej linii
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter filename: ";
        getline(cin, filename);
        productList.loadFromFile(filename);
    }

    // Menu główne
    while (true) {
        cout << "\nMenu:\n"
             << "1. Add or update product\n"
             << "2. Remove product\n"
             << "3. Save product list to file\n"
             << "4. Display product list\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1': // Dodajemy/aktualizujemy produkt
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter quantity (use negative number to decrease): ";
            cin >> quantity;
            cin.ignore();
            productList.addOrUpdateProduct(name, quantity);
            break;

        case '2': // Usuwamy produkt
            cout << "Enter product name to remove: ";
            getline(cin, name);
            productList.removeProduct(name);
            break;

        case '3': // Zapiujemy do pliku
            cout << "Enter filename: ";
            getline(cin, filename);
            productList.saveToFile(filename);
            break;

        case '4': // Wyświetlamy produkty
            productList.displayProducts();
            break;

        case '5': // Wyjście
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
