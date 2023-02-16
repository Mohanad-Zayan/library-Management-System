//
// Created by 20121 on 2/12/2023.
//

#ifndef LMS_USERLIST_H
#define LMS_USERLIST_H
#include <iostream>
#include "User.h"
class UserList
        {
        private:
            User* users; // dynamically  allocated
            int capacity;
            int usersCount;
        public:
            UserList();
            UserList(int );
            void addUser(const User &);
            User* searchUser(string );
            User* searchUser(int );
            void deleteUser(int );
            friend ostream &operator<<( ostream& ,const UserList&);
            ~UserList();
        };
#endif //LMS_USERLIST_H
