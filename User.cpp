//
// Created by 20121 on 2/10/2023.
//

#include "User.h"

int User::count = 0 ;

User::User() {
    name = "" ;
    age = 0 ;
    password = "" ;
    email = "" ;
    count++;
    id = count ;
}
//////////////////////////
User::User(string name  , int age  , string email  , string password) {
    this->name = name ;
    this->age = age ;
    this->email = email ;
    this->password = password ;
    count++;
    id = count ;
}
//////////copy constructor/////////////////
User::User(const User &user) {
    this->name = user.name ;
    this->age = user.age ;
    this->email = user.email ;
    this->password = user.password ;
    this->id = user.id ;

}
////////////////////////////
string User::getName() const {
    return this-> name ;
}
int User::getAge()  {
    return this-> age ;
}
string User::getEmail() const {
    return this-> email ;
}
string User::getPassword() const {
    return this-> password ;
}
int User::getId()  {
    return this-> id ;
}
////////////////////
void User::setName(string name){
    this->name = name ;
}
void User::setAge(int age){
    this->age = age ;
}
void User::setEmail(string email){
    this->email = email ;
}
void User::setPassword(string password){
    this->password = password ;
}
void User::setId(int id){
    this->id = id ;
}
////////////////////////////////////
bool User::operator==(const User &user) {
    return (this->name == user.name && this->age == user.age && this->email == user.email && this->id == user.id );
}

//////////////////////////////////////
void User::Display() {
    cout << "*************************"<<endl ;
    cout << "name = " << name <<endl;
    cout << "email = " << email <<endl;
    cout << "id = " << id << endl ;
    cout << "age = " << age <<endl;
    cout << "*************************"<<endl ;
}
//////////////////////////////////////
istream &operator>>( istream & input , User & user){
    cout << "Enter the info of the use " << endl ;
    cout << "name "<< "age " << "email " << "passowrd " << endl ;
    cout << "space seprated" << endl ;
    input >> user.name >> user.age >> user.email >>user.password ;
    return  input;
}
ostream &operator<<( ostream & output , const User & user){
    output << "==============================" << endl ;
    output << "name = " << user.name ;
    output << "| email = " << user.email;
    output << "| id = " << user.id  ;
    output << "| age = " << user.age << endl;
    output << "==============================" << endl ;
    return  output ;
}
/////////////////////////////////////////////
void User::operator=(const User & user){
    this->name = user.name ;
    this->password = user.password ;
    this->email = user.email ;
    this->age = user.age ;
}