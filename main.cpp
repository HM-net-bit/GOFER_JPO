/**
 * @file main.cpp
 * @brief Entry point for the product management application.
 * 
 * This program allows the user to add product names to a list and displays the list.
 */

#include <iostream>
#include <vector>
#include <string>
#include "ProductList.hpp"
using std::cout, std::endl, std::vector,std::string;

/**
 * @brief Main function of the program.
 * 
 * This function provides a console interface for adding product names to a list and
 * displaying them when the user finishes.
 * 
 * @return Returns 0 on successful execution.
 */

int main() {
    HM::ProductList productList; // Create an instance of ProductList
    std::string input;

    cout << "Input name of product OR input 'stop' to end a program:" <<endl;


    while (true) {
        cout << "Input name of produkct: ";
        getline(std::cin, input);

        if (input == "stop") {
            break;
        }

        productList.addProduct(input); // Add the product to the list
    }

    productList.displayProducts(); // Display the list of products

    return 0;
}
