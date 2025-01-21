#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using std::string, std::cin, std::cout, std::vector, std::endl, std::ifstream, std::ofstream;
using std::find;

namespace HM {
/**
 * @class ProductList
 * @brief A class to manage a list of products with their quantities.
 */
class ProductList {
private:
    vector<string> m_names; ///< Vector storing product names.
    vector<int> m_quantities; ///< Vector storing product quantities.

public:

    /**
     * @brief Default constructor.
     */
    
    ProductList()=default;
    /**
     * @brief Parameterized constructor.
     * @param names Vector of product names.
     * @param quantities Vector of product quantities.
     */
    ProductList(const vector<string>& names, const vector<int>& quantities) : m_names(names), m_quantities(quantities) {}
    
    /**
     * @brief Adds a new product or updates an existing one.
     * @param name The name of the product.
     * @param quantity The quantity to add or update.
     */
    void addOrUpdateProduct(const string& name, int quantity) {
        if (name.empty()) {
            cout << "Error: Product name cannot be empty." << endl;
            return;
        }

        // Loop to check and update product quantity
        for (int i = 0; i < m_names.size(); ++i) {
            if (m_names[i] == name) {
                if (m_quantities[i] + quantity < 0) {
                    cout << "Error: Quantity cannot be less than 0." << endl;
                    return;
                }

                m_quantities[i] += quantity;

                if (m_quantities[i] == 0) {
                    m_names.erase(m_names.begin() + i);
                    m_quantities.erase(m_quantities.begin() + i);
                    cout << "Product '" << name << "' removed from the list as its quantity reached 0." << endl;
                } else {
                    cout << "Updated product list:" << endl;
                }

                displayProducts();
                return;
            }
        }

        if (quantity > 0) {
            m_names.push_back(name);
            m_quantities.push_back(quantity);
            cout << "Updated product list:" << endl;
            displayProducts();
        } else {
            cout << "Error: Cannot add a new product with zero or negative quantity." << endl;
        }
    }

    /**
     * @brief Removes a product from the list.
     * @param name The name of the product to remove.
     */
    void removeProduct(const string& name) {
        for (size_t i = 0; i < m_names.size(); ++i) {
            if (m_names[i] == name) {
                m_names.erase(m_names.begin() + i);
                m_quantities.erase(m_quantities.begin() + i);
                cout << "Product removed: " << name << endl;
                cout << "Updated product list:" << endl;
                displayProducts();
                return;
            }
        }
        cout << "Error: Product not found." << endl;
    }

    /**
     * @brief Loads products from a file.
     * @param filename The name of the file to read from.
     */
    void loadFromFile(const string& filename) {
        if (filename.empty()) {
            cout << "Error: Filename cannot be empty." << endl;
            return;
        }

        ifstream file(filename);
        if (!file) {
            cout << "Error: File " << filename << " does not exist or cannot be opened." << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string name = line.substr(0, commaPos);
                int quantity = std::stoi(line.substr(commaPos + 1));
                addOrUpdateProduct(name, quantity);
            }
        }
        cout << "Data loaded from " << filename << endl;
        displayProducts();
    }

    /**
     * @brief Saves the product list to a file.
     * @param filename The name of the file to save to.
     */
    void saveToFile(const string& filename) const {
        if (filename.empty()) {
            cout << "Error: Filename cannot be empty." << endl;
            return;
        }

        ofstream file(filename);
        if (!file) {
            cout << "Error opening file." << endl;
            return;
        }

        for (size_t i = 0; i < m_names.size(); ++i) {
            file << m_names[i] << "," << m_quantities[i] << endl;
        }

        cout << "Data saved to " << filename << endl;
    }

    /**
     * @brief Displays the list of products.
     */
    void displayProducts() const {
        if (m_names.empty()) {
            cout << "The product list is empty." << endl;
            return;
        }

        cout << "Product List:" << endl;
        for (size_t i = 0; i < m_names.size(); ++i) {
            cout << "Product: " << m_names[i] << ", Quantity: " << m_quantities[i] << endl;
        }
    }
};
}
