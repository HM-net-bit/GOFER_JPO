#include <iostream>
#include "ProductList.hpp"
using std::string,std::cin,std::cout,std::endl;

int main() {
    HM::ProductList productList;
    string name, filename;
    int quantity;

    cout << "Enter product name (or 'exit' to stop):\n";
    while (true) {
        cout << "Product name: ";
        getline(cin, name);

        if (name == "exit") break;

        cout << "Quantity: ";
        cin >> quantity;
        
        //usuwa znak nowej lini żebyśmy mogli dodać kolejny produkt albo wyjść
        /*
            Gdy nie ma cin.ignore():

            Enter product name (or 'exit' to stop):
            Product name: Mleko
            Quantity: 10
            Product name: Quantity: 
        */
        cin.ignore(); 

        // Wywołanie metody dodania lub aktualizowania ilości produktu
        productList.addOrUpdateProduct(name, quantity);
    }

    cout << "Enter filename to save: ";
    getline(cin, filename);

    // Wywołanie metody zapisu do pliku
    productList.saveToFile(filename);

    return 0;
}
