//
// Created by 20121 on 2/12/2023.
//

#include "UserList.h"

UserList::UserList(){
    usersCount = capacity = 0 ;
}

UserList::UserList(int capacity ){
    this->capacity = capacity  ;
    usersCount = 0 ;
    users = new User[capacity] ;
}
void UserList::addUser(const User & user){
  if(usersCount < capacity){
      users[usersCount] = user ;
      users[usersCount].setId(usersCount+1)  ;
      usersCount++ ;
  }else{
      cout << "You've exceeded the maximum number of users" << endl ;
  }
}
User* UserList::searchUser(string name){
    for(int i = 0 ; i < usersCount ; i++){
        if(users[i].getName() == name ) return &users[i] ;
    }
    return nullptr ;
}
User* UserList::searchUser(int id){
    for(int i = 0 ; i < usersCount ; i++){
        if(users[i].getId() == id ) return &users[i] ;
    }
    return nullptr ;
}
void UserList::deleteUser(int id){
    User *newUsers = new User[capacity];
    for (int i = 0; i < usersCount ; ++i) {
        if(users[i].getId() == id ) { usersCount--; continue;  }
        newUsers[i] = users[i] ;
    }
    users =newUsers ;
    newUsers = nullptr ;
}
UserList::~UserList(){
    delete [] users ;
}
ostream &operator<<( ostream& output ,const UserList& ul){
    for (int i = 0; i < ul.usersCount ; ++i) {
        output << ul.users[i] ;
    }
    return output ;
}
