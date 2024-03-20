#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Book {
    std::string title;
    std::string author;
};

std::vector<Book> books;

void addBook(std::string title, std::string author) {
    books.push_back({title, author});
    std::cout << "Book added successfully.\n";
}

void removeBook(std::string title) {
    auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) {
        return book.title == title;
    });

    if (it != books.end()) {
        books.erase(it);
        std::cout << "Book removed successfully.\n";
    } else {
        std::cout << "Book not found.\n";
    }
}

void listBooks() {
    for (const auto& book : books) {
        std::cout << "Title: " << book.title << ", Author: " << book.author << '\n';
    }
}

int main() {
    std::string command;
    while (true) {
        std::cout << "Enter command (add, remove, list, quit): ";
        std::cin >> command;
        if (command == "add") {
            std::string title, author;
            std::cout << "Enter title: ";
            std::cin >> title;
            std::cout << "Enter author: ";
            std::cin >> author;
            addBook(title, author);
        } else if (command == "remove") {
            std::string title;
            std::cout << "Enter title: ";
            std::cin >> title;
            removeBook(title);
        } else if (command == "list") {
            listBooks();
        } else if (command == "quit") {
            break;
        } else {
            std::cout << "Invalid command.\n";
        }
    }
    return 0;
}
