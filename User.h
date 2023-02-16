//
// Created by 20121 on 2/10/2023.
//

#ifndef LMS_USER_H
#define LMS_USER_H
#include <iostream>
using namespace std;
class User{
private:
    string name;
    string password;
    string email;
    int age;
    int id;

public:
    static int count;
    User();
    User(string  , int  , string  , string  );
    User(const User& );
    bool operator==(const User&  );
    void setName(string );
    string getName() const;
    void setPassword(string );
    string getPassword()const;
    void setEmail(string );
    string getEmail()const ;
    void setAge(int );
    int getAge();
    void setId(int );
    int getId();
    void Display ();
    friend ostream &operator<<(ostream &, const User &);
    friend istream &operator>>( istream & , User &);
    void operator=(const User &) ;
};

#endif //LMS_USER_H
