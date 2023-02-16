//
// Created by 20121 on 2/10/2023.
//

#ifndef LMS_BOOK_H
#define LMS_BOOK_H
#include <iostream>
#include "User.h"
using namespace std ;
class Book{
        private:
            string title;
            string isbn;
            int id;
            string category;
            double averageRating;
            User author;
            bool hasAuthor ;
            double sumRates ;
            int numRates ;
        public:
            static int count;
            Book();
            Book(string , string , string );
            Book(const Book& );
            void setTitle(string );
            string getTitle() const ;
            void setIsbn(string );
            string getIsbn() const;
            void setId(int);
            int getId() const;
            void setCategory(string );
            string getCategory()const;
            void setAuthor(const User & );
            User getAuthor() const;
            void rateBook(double );
            double getAverageRating () const;
            bool operator==(const Book&);
            friend ostream &operator<<(ostream &, const Book &);
            friend istream &operator>>( istream &, Book &);

        };
#endif //LMS_BOOK_H
