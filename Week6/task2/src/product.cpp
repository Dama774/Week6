#include "product.h"
#include <utility>

Product::Product(long id) : id(id) {}

Product::Product(long id, std::string name, std::string category, double price) : 
        id(id), name(std::move(name)), category(std::move(category)), price(price) {}

long Product::getId() const {
    return id;
}

void Product::setId(long id) {
    Product::id = id;
}

const std::string &Product::getName() const {
    return name;
}

void Product::setName(const std::string &name) {
    Product::name = name;
}

const std::string &Product::getCategory() const {
    return category;
}

void Product::setCategory(const std::string &category) {
    Product::category = category;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double price) {
    Product::price = price;
}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << "id: " << product.id << " name: " << product.name 
       << " category: " << product.category << " price: " << product.price;
    return os;
}

