#include<iostream>

using namespace std;

class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        this -> title = nullptr;
        this -> authors = nullptr;
        this -> publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this -> title = new char[strlen(title) + 1];
        strcpy(this -> title, title);
        this -> authors = new char[strlen(authors) + 1];
        strcpy(this -> authors, authors);
        this -> publishingYear = publishingYear;
        // strlen cho độ dài chuỗi không chứa kí tự kết thúc nên phải cộng thêm 1 để chứa đủ kí tự kết thúc
        // strcpy cho phép copy chuỗi chứa luôn cả kí tự kết thúc nên không cần cộng 1
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        this -> title = new char[strlen(book.title) + 1];
        strcpy(title, book.title);
        this -> authors = new char[strlen(book.authors) + 1];
        strcpy(authors, book.authors);
        publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
        this -> title = new char[strlen(title) + 1];
        strcpy(this -> title, title);
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
        this -> authors = new char[strlen(authors) + 1];
        strcpy(this -> authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */ 
        this -> publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return this -> title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return this -> authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return this -> publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] title;
        delete[] authors;
        this -> publishingYear = 0;
    }

    void printBook(){
        printf("%s\n%s\n%d", this -> title, this -> authors, this -> publishingYear);
    }
};  



// index hợp lệ hay ko quan tâm đến count, ko qt capacity