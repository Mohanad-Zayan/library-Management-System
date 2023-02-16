//
// Created by 20121 on 2/10/2023.
//

#include "Book.h"
int Book::count = 0 ;
Book::Book(){
    title = "" ;
    isbn = "" ;
    category = "" ;
    count++ ;
    id = count ;
    averageRating = 0.0 ;
    sumRates = 0 ;
    numRates  = 0 ;
    hasAuthor = false ;
}
Book::Book(string title , string isbn , string category ){
    this->title = title   ;
    this->isbn = isbn  ;
    this->category = category  ;
    count++ ;
    averageRating = 0.0 ;
    id = count ;
    sumRates = 0 ;
    numRates  = 0 ;
    hasAuthor = false ;
}
Book::Book(const Book& book){
    this->title = book.title   ;
    this->isbn = book.isbn  ;
    this->category = book.category  ;
    this->id = book.id ;
    this->author = book.author ;
    this->averageRating = book.averageRating ;
    this->sumRates = book.sumRates ;
    this->numRates = book.numRates ;
    if(book.hasAuthor){
        setAuthor(book.author) ;
    }

}

string Book::getTitle() const{
    return  this-> title;
}
string Book::getIsbn() const{
    return  this-> isbn;
}
int Book::getId() const{
    return  this-> id;
}
User Book::getAuthor() const {
    return  author ;
}
double Book::getAverageRating () const{
    return  averageRating ;
}
//////////////////////////////////////////
string Book::getCategory() const{
    return  this-> category;
}
////////////////////////////////////
void Book::setTitle(string  title){
    this->title = title ;
}
void Book::setIsbn(string  isbn){
    this->isbn = isbn ;
}
//////////////////////////////////////////
void Book::setId(int id){
    this->id = id ;
}
//////////////////////////////////////////
void Book::setCategory(string  category){
    this->category = category ;
}
//////////////////////////////////////////
void Book::setAuthor(const User & user ){
    hasAuthor = true ;
    author = user;

}
//////////////////////////////////////////
void Book::rateBook(double rateing ){

    sumRates += rateing ;
    numRates++ ;
    this->averageRating = sumRates/numRates  ;
}
//////////////////////////////////////////
ostream &operator<<(ostream & output, const Book & book){
    output << "==============================" << endl ;
    output << "name = " << book.title ;
    output << "| isbn = " << book.isbn;
    output << "| category = " << book.category  ;
    output << "| Average Rating = " << book.averageRating << endl;
    output << "==============================" << endl ;
    if(book.hasAuthor){
        output << (book.author) ;
    }
    return  output ;
}

//////////////////////////////////////////
istream &operator>>( istream & input , Book & book){
    cout << "Enter the info of the Book " << endl ;
    cout << "title "<< "isbn " << "category "  << endl ;
    cout << "space seprated" << endl ;
    input >> book.title >> book.isbn >> book.category  ;
    return  input;
}


bool Book::operator==(const Book & book){
    return (this->title == book.title && this->isbn == book.isbn && this->category == book.category && this->averageRating == book.averageRating && this->author == book.author)
    ;
}

/////////////////////////////////////////////////
