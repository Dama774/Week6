#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    long id;
    std::string name;
    std::string category;
    double price;

public:
    Product(long id);
    Product(long id, std::string name, std::string category, double price);
    
    long getId() const;
    void setId(long id);
    
    const std::string &getName() const;
    void setName(const std::string &name);
    
    const std::string &getCategory() const;
    void setCategory(const std::string &category);
    
    double getPrice() const;
    void setPrice(double price);
    
    // Оператор сравнения
    bool operator<(const Product& other) const {
        return id < other.id; // Сравниваем по id
    }

    friend std::ostream &operator<<(std::ostream &os, const Product &product);
};

#endif // PRODUCT_H

