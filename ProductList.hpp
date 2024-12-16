/**
 * @file ProductList.hpp
 * @brief Defines the ProductList class for managing a list of products.
 * 
 * This file contains the declaration of the ProductList class, which provides
 * methods for adding, displaying, and managing a list of products.
 */

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl, std::vector,std::string;

namespace HM{

/**
 * @class ProductList
 * @brief A class to manage a list of products.
 * 
 * The ProductList class provides methods to add products to a list and display the list.
 */

class ProductList {
private:
/**
 * @brief A container to store the names of products.
 */
    vector<string> m_products; 

public:
/** 
 * @brief parameter constructor and default constructor
*/
    ProductList(vector<string> products):m_products(products){}
    ProductList(){}

/**
 * @brief Adds a product to the list.
 * @param product The name of the product to add.
*/
    void addProduct(string product) {
        if (product.empty()) {
            cout << "ERROR: Name of product can't be empty" <<endl;
            return;
        }
        m_products.push_back(product);
    }

/**
* @brief Displays all products in the list.
* This function iterates over the list of products and prints each one to the standard output.
*/
    void displayProducts() const {
        cout << "\nList of products:" <<endl;
        for (string product : m_products) {
            cout << "- " << product <<endl;
        }
    }
};
}
