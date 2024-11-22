#include <iostream>
#include <string>
#include <vector>


class Book
{
protected:
    std::string name;
    std::string autor;
    int age;
public:
    Book(std::string name, std::string autor, int age) : 
        name(name), autor(autor), age(age) {};
    
    void DisplayInfo() const {
        std::cout << "Название: " << name << " Год выпуска: " << age << " Автор: " << autor << std::endl;
    }

    int GetAge() const {
        return age;
    }
};

void Sort(std::vector<Book>& books){
    int n = books.size();
    for( int i = 0; i < n-1; i++){
        for( int j = 0; j < n-1; j++){
            if(books[j].GetAge() > books[j+1].GetAge()){
                std::swap(books[j], books[j + 1]);
            }
        }
    }
}

void display_books(const std::vector<Book>& books) {
    for(const auto& book : books){
        book.DisplayInfo();
    }
}

int main() {
    std::vector<Book> books = {
        Book("Book1", "Auror1", 2000),
        Book("Book2", "Auror2", 1990),
        Book("Book3", "Auror3", 2010),
        Book("Book4", "Auror4", 2010),
        Book("Book5", "Auror5", 1975),
        Book("Book6", "Auror6", 2110),
    };

    Sort(books);
    display_books(books);
}