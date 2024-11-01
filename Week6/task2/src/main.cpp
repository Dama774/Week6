#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include "order.h"
#include "product.h"
#include "customer.h"

// Функция для создания временной метки
time_t createTime(int year, int month, int day) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900; // Год с 1900
    timeinfo.tm_mon = month - 1;     // Месяц (0-индексированный)
    timeinfo.tm_mday = day;           // День месяца
    return mktime(&timeinfo);
}

// Функция для расчета общей суммы всех заказов в феврале 2020 года
double calculateTotalForFebruary2020(const std::vector<Order>& orders) {
    double total = 0.0;

    struct tm start = {0};
    start.tm_year = 2020 - 1900; // Год с 1900
    start.tm_mon = 1;            // Февраль (0-индексированный)

    struct tm end = {0};
    end.tm_year = 2020 - 1900;   // Год с 1900
    end.tm_mon = 2;              // Март (0-индексированный)

    time_t startTime = mktime(&start);
    time_t endTime = mktime(&end);

    for (const auto& order : orders) {
        if (order.getOrderDate() >= startTime && order.getOrderDate() < endTime) {
            for (const auto& product : order.getProducts()) {
                total += product.getPrice();
            }
        }
    }

    return total;
}

int main() {
    std::vector<Order> orders;

    // Создаем несколько продуктов
    Product product1(1, "Laptop", "Electronics", 999.99);
    Product product2(2, "Mouse", "Electronics", 25.50);
        Product product3(3, "Keyboard", "Electronics", 45.00);

    Customer customer1(1);
    customer1.setName("Alice");
    
    Customer customer2(2);
    customer2.setName("Bob");

    // Создание заказов
    std::set<Product> productsOrder1 = {product1, product2};
    Order order1(1, createTime(2020, 2, 10), createTime(2020, 2, 15), "Delivered", customer1, productsOrder1);

    std::set<Product> productsOrder2 = {product3};
    Order order2(2, createTime(2020, 2, 20), createTime(2020, 2, 25), "Delivered", customer2, productsOrder2);

    // Заказ вне февраля
    std::set<Product> productsOrder3 = {product1};
    Order order3(3, createTime(2020, 3, 5), createTime(2020, 3, 10), "Pending", customer1, productsOrder3);

    orders.push_back(order1);
    orders.push_back(order2);
    orders.push_back(order3);

    double total = calculateTotalForFebruary2020(orders);

    std::cout << "Общая сумма по всем заказам в феврале 2020: " << total << std::endl;

    return 0;
}

