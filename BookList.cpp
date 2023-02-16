//
// Created by 20121 on 2/12/2023.
//

#include "BookList.h"
#include "Book.h"

BookList::BookList() {
    booksCount = capacity = 0 ;
}
BookList::BookList(int capacity) {
    this->capacity = capacity ;
    booksCount = 0 ;
    books = new Book[capacity] ;
}

void BookList::addBook(const Book & book) {
    if(booksCount < capacity){
        books[booksCount] = book ;
        books[booksCount].setId(booksCount+1) ;
        booksCount++ ;
    }else{
        cout << "You've exceeded the maximum number of Books" << endl ;
    }
}
Book* BookList::searchBook(int id) {
    for(int i = 0 ; i < booksCount ; i++){
        if(books[i].getId() == id ) return &books[i] ;
    }
    return nullptr ;
}

Book* BookList::searchBook(string name) {
    for(int i = 0 ; i < booksCount ; i++){
        if(books[i].getTitle() == name ) return &books[i] ;
    }
    return nullptr ;
}

void BookList::deleteBook(int id) {
    Book *newBooks = new Book[capacity];
    for (int i = 0; i < booksCount ; ++i) {
        if(books[i].getId() == id ) { booksCount--; continue;  }
        newBooks[i] = books[i] ;
    }
    books = newBooks ;
    newBooks = nullptr ;
}

Book BookList::getTheHighestRatedBook() {
    double highestRated = INT_MIN ;int index = -1 ;
    for (int i = 0; i < booksCount ; ++i) {
        if(books[i].getAverageRating() > highestRated ){
            highestRated = books[i].getAverageRating() ;
            index = i ;
        }
    }
    return books[index] ;
}

void BookList::getBooksForUser(const User & user) {
    bool found = false  ;
    for (int i = 0; i < booksCount; ++i) {
        if(books[i].getAuthor().getName() == user.getName()) {
            cout << books[i];
            found = true ;
        }
    }
    if(found == false ) cout << "No book Found for this Author \n" ;
}
Book& BookList::operator[] (int index ){
    if(index < 0 || index >= booksCount){
        exit(1) ;
    }
    return books[index] ;
}

ostream&operator<<(ostream & output ,const BookList & bl ){
    for(int i = 0 ; i < bl.booksCount ; i++){
        output << bl.books[i] ;
    }
    return  output ;
}

BookList::~BookList() {
    delete [] books ;
}