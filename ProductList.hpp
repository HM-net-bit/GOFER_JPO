#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using std::string, std::cin, std::cout, std::vector, std::endl, std::ifstream, std::ofstream;
using std::find;

namespace HM {
class ProductList {
private:
    vector<string> m_names;
    vector<int> m_quantities;

public:
    // Funkcja dodająca nowy produkt lub edytująca istniejący
    void addOrUpdateProduct(const string& name, int quantity) {
    if (name.empty()) {
        cout << "Error: Product name cannot be empty." << endl;
        return;
    }

    /*  
        Pętla odpowiadająca aktualizowaniu liości produktu
        Sprawdza czy istnieje produkt o takiej nazwie jeśli istnieje to aktualizuje wartość
    */
    for (int i = 0; i < m_names.size(); ++i) {
        if (m_names[i] == name) {
            
            //Sprawdzamy czy ilość nie jest mniejsza lub równa 0
            if (m_quantities[i] + quantity < 0) {
                cout << "Error: Quantity cannot be less than 0." << endl;
                return;
            }

            m_quantities[i] += quantity;

            //Jeśli produkt będzie miał ilość 0 to zostanie usunięty
            if (m_quantities[i] == 0) { 
                m_names.erase(m_names.begin() + i);
                m_quantities.erase(m_quantities.begin() + i);
                cout << "Product '" << name << "' removed from the list as its quantity reached 0." << endl;
            } else {
                cout << "Updated product list:" << endl;
            }
            
            // wyświetlamy listę po aktualizacji 
            displayProducts(); 
            return;
        }
    }

    // Dodanie nowego produktu, jeśli nie istnieje
    if (quantity > 0) {

        //Dodanie nazwy do wektora nazw
        m_names.push_back(name);
        //Dodanie ilości do wektora ilości
        m_quantities.push_back(quantity);
        cout << "Updated product list:" << endl;
        displayProducts();
    } else {
        cout << "Error: Cannot add a new product with zero or negative quantity." << endl;
    }
}



    // Funkcja gdzie usuwamy produkt
    void removeProduct(const string& name) {
    for (size_t i = 0; i < m_names.size(); ++i) {
        if (m_names[i] == name) {
            
            //Usuwamy nazwę i ilość na tych samych indeksach w wektorach nazw i ilości
            m_names.erase(m_names.begin() + i);
            m_quantities.erase(m_quantities.begin() + i);
            cout << "Product removed: " << name << endl;
            cout << "Updated product list:" << endl;
            displayProducts(); // wyświetlamy listę po aktualizacji
            return;
        }
    }
    cout << "Error: Product not found." << endl;
}


    // Funkcja ładująca listę z pliku
    void loadFromFile(const string& filename) {
    
    //Sprawdzamy czy nazwa pliku nie jest pusta
    if (filename.empty()) {
        cout << "Error: Filename cannot be empty." << endl;
        return;
    }
    
    //Sprawdzamy czy plik został poprawnie utworzony
    ifstream file(filename);
    if (!file) {
        cout << "Error: File " << filename << " does not exist or cannot be opened." << endl;
        return;
    }


    string line;
    
    //Pętla wczytająca plik linia po lini
    while (getline(file, line)) {

        //szukanie przecinka w danej linii
        size_t commaPos = line.find(',');
        
        //Sprawdzanie warunku czy nie ma przecinka w linii
        //Jeśli nie ma to pomijamy linie ponieważ linia może być przekłamana
        if (commaPos != string::npos) {
            //wczytywanie nazwy produktu od 0 do pozycji przecinka
            string name = line.substr(0, commaPos);

            //wczytywanie ilości od przecinka do końca
            int quantity = std::stoi(line.substr(commaPos + 1));
            
            // Zamiast nadpisywać, dodajemy lub aktualizujemy produkt
            addOrUpdateProduct(name, quantity);
        }
    }
    cout << "Data loaded from " << filename << endl;
    displayProducts();
}


    //Zapisywanie podanych danych do pliku
    void saveToFile(const string& filename) const {
        if (filename.empty()) {
            cout << "Error: Filename cannot be empty." << endl;
            return;
        }

        //Tworzymy plik za pomocą ofstream
        ofstream file(filename);
        
        //Sprawdzamy czy plik został poprawnie utworzony
        if (!file) {
            cout << "Error opening file." << endl;
            return;
        }

        for (size_t i = 0; i < m_names.size(); ++i) {
            file << m_names[i] << "," << m_quantities[i] << endl;
        }

        //Potwierdzamy zapis
        cout << "Data saved to " << filename << endl;
    }

    // Wyświetlanie listy produktów
    void displayProducts() const {
        //Sprawdzamy czy lista zakupów nie jest pusta
        if (m_names.empty()) {
            cout << "The product list is empty." << endl;
            return;
        }
        
        //Wyświetlanie podanej listy zakupów
        cout << "Product List:" << endl;
        for (size_t i = 0; i < m_names.size(); ++i) {
            cout << "Product: " << m_names[i] << ", Quantity: " << m_quantities[i] << endl;
        }
    }
};
}
