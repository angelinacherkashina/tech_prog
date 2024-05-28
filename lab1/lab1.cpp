
#include <iostream>
#include <string>
#include <memory>
#include <string>

// Определение структуры
struct Node {
    std::string name;
    int id;
    double value;
    std::shared_ptr<Node> next;
};

// Функции для работы со списком

// Функция добавления элемента в начало списка
void addElementToFront(std::shared_ptr<Node>& head, const std::string& name, int id, double value) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    newNode->name = name;
    newNode->id = id;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

// Функция добавления элемента в конец списка
void addElementToEnd(std::shared_ptr<Node>& head, const std::string& name, int id, double value) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    newNode->name = name;
    newNode->id = id;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    }
    else {
        std::shared_ptr<Node> current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функция добавления элемента после заданного элемента
void addElementAfter(std::shared_ptr<Node>& head, const std::string& targetName, const std::string& name, int id, double value) {
    std::shared_ptr<Node> current = head;
    while (current && current->name != targetName) {
        current = current->next;
    }

    if (current) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->name = name;
        newNode->id = id;
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Функция добавления элемента перед заданным элементом
void addElementBefore(std::shared_ptr<Node>& head, const std::string& targetName, const std::string& name, int id, double value) {
    if (!head) return;

    if (head->name == targetName) {
        addElementToFront(head, name, id, value);
        return;
    }

    std::shared_ptr<Node> current = head;
    while (current->next && current->next->name != targetName) {
        current = current->next;
    }

    if (current->next) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->name = name;
        newNode->id = id;
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Функция удаления элемента по имени
void deleteElementByName(std::shared_ptr<Node>& head, const std::string& name) {
    if (!head) return;

    if (head->name == name) {
        head = head->next;
        return;
    }

    std::shared_ptr<Node> current = head;
    while (current->next && current->next->name != name) {
        current = current->next;
    }

    if (current->next) {
        current->next = current->next->next;
    }
}

// Функция вывода содержания списка на экран
void printList(const std::shared_ptr<Node>& head) {
    std::shared_ptr<Node> current = head;
    while (current) {
        std::cout << "Name: " << current->name << ", ID: " << current->id << ", Value: " << current->value << std::endl;
        current = current->next;
    }
}

// Функция main
int main() {
    std::shared_ptr<Node> head = nullptr;

    addElementToEnd(head, "First", 1, 1.1);
    addElementToEnd(head, "Second", 2, 2.2);
    addElementToFront(head, "Zeroth", 0, 0.0);
    addElementAfter(head, "First", "Between", 1, 1.5);
    addElementBefore(head, "Second", "BeforeSecond", 1, 1.75);

    std::cout << "List after additions:" << std::endl;
    printList(head);

    deleteElementByName(head, "Between");
    std::cout << "List after deletion:" << std::endl;
    printList(head);

    return 0;
}