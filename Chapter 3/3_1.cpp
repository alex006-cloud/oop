#include <iostream>
#include <vector>
#include <string>

// Класс Book
class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string &title, const std::string &author)
        : title(title), author(author) {}

    virtual void displayInfo() const {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};

// Класс Textbook, наследующий от Book
class Textbook : public Book {
public:
    std::string subject;

    Textbook(const std::string &title, const std::string &author, const std::string &subject)
        : Book(title, author), subject(subject) {}

    void displayInfo() const override {
        std::cout << "Textbook: " << title << " by " << author << ", Subject: " << subject << std::endl;
    }
};

// Класс Library
class Library {
private:
    std::vector<Book*> books;

public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const auto &book : books) {
            book->displayInfo();
        }
    }

    ~Library() {
        for (auto &book : books) {
            delete book;
        }
    }
};

int main() {
    Library library;

    Book* book1 = new Book("1984", "George Orwell");
    Textbook* textbook1 = new Textbook("Calculus", "James Stewart", "Mathematics");

    library.addBook(book1);
    library.addBook(textbook1);

    library.displayBooks();

    return 0;
}
