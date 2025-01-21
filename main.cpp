/**
 * @file main.cpp
 * @brief Main program to manage a product list.
 */

#include <iostream>
#include "ProductList.hpp"
using std::string, std::cin, std::cout, std::endl;

/**
 * @brief Main function to manage product list operations.
 * 
 * Provides a menu-driven interface to add, update, remove, save,
 * and display products using the ProductList class.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    HM::ProductList p1; ///< Object to manage product list.
    string name, filename; ///< Variables to store product name and filename.
    int quantity; ///< Variable to store product quantity.
    char choice; ///< Variable to store user choice.

    /**
     * @brief Prompt user to load product list from file.
     */
    cout << "Do you want to load the product list from a file? (y/n): ";
    cin >> choice;
    cin.ignore(); // Ignore newline character

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter filename: ";
        getline(cin, filename);
        p1.loadFromFile(filename);
    }

    /**
     * @brief Main menu loop for product list operations.
     */
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
        case '1': ///< Add or update product
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter quantity (use negative number to decrease): ";
            cin >> quantity;
            cin.ignore();
            p1.addOrUpdateProduct(name, quantity);
            break;

        case '2': ///< Remove product
            cout << "Enter product name to remove: ";
            getline(cin, name);
            p1.removeProduct(name);
            break;

        case '3': ///< Save product list to file
            cout << "Enter filename: ";
            getline(cin, filename);
            p1.saveToFile(filename);
            break;

        case '4': ///< Display product list
            p1.displayProducts();
            break;

        case '5': ///< Exit program
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
