#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::string,std::cin,std::cout,std::vector,std::endl,std::ofstream;

namespace HM {
class ProductList {
private:
    vector<string> m_names;
    vector<int> m_quantities;

public:
    // Funkcja dodająca nowy produkt lub edytująca istniejący
    void addOrUpdateProduct(const string& name, int quantity) {
        
        //Sprawdzamy czy nazwa nie jest pusta
        if (name.empty()) {
            cout << "Error: Product name cannot be empty." << endl;
            return;
        }

        //Sprawdzamy czy ilość nie jest mniejsza lub równa 0
        if (quantity <= 0) {
            cout << "Error: Quantity cannot be less or equal 0." << endl;
            return;
        }

        /*  Pętla odpowiadająca aktualizowaniu liości produktu
            Sprawdza czy istnieje produkt o takiej nazwie jeśli istnieje to aktualizuje wartość
        */
        for (int i = 0; i < m_names.size(); ++i) {
            if (m_names[i] == name) {
                m_quantities[i] += quantity;
                return;
            }
        }
        //Dodanie nazwy do wektora nazw
        m_names.push_back(name);
        //Dodanie ilości do wektora ilości
        m_quantities.push_back(quantity);
    }

    // Funkcja zapisywania produktów do pliku
    void saveToFile(const string& filename) const {
        
        //Sprawdzamy czy nazwa pliku nie jest pusta
        if (filename.empty()) {
            cout << "Error: Filename cannot be empty." << endl;
            return;
        }

        //Tworzymy plik za pomocą ofstream
        ofstream file(filename + ".txt");
        
        //Sprawdzamy czy plik został poprawnie utworzony
        if (!file) {
            cout << "Error opening file." << endl;
            return;
        }

        //Zapisywanie podanych danych do pliku
        for (int i = 0; i < m_names.size(); ++i) {
            file << "Product: "<<m_names[i] << ", Quantity: " << m_quantities[i] << endl;
        }
        
        //Potwierdzamy zapis
        cout << "Data saved to " << filename << ".txt" << endl;
    }

    //Funkcja do wyświetlania produktów
    void displayProducts() const {
        
        //Sprawdzamy czy lista zakupów nie jest pusta
        if (m_names.empty()) {
            cout << "The product list is empty." << endl;
            return;
        }

        //Wyświetlanie podanej listy zakupów
        cout << "Product List:" << endl;
        for (int i = 0; i < m_names.size(); ++i) {
            cout << "Product: "<<m_names[i] << ", Quantity: " << m_quantities[i] << endl;
        }
    }
};
}
