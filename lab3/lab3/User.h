#pragma once
#include "Person.h"
#include "Post.h"
#include "Dialog.h"
#include "Chat.h"
#include <vector>

class User :
    public Person
{
protected:
    vector<User*> followingUsers;
    vector<Post> posts;
    vector<Dialog> dialogs;
    vector<Chat> chats;
public:
    User();
    User(const Name& name_, const  Gender& gender_, const int& age_, const string& country_, const string& familyStatus_);
    ~User();
    void followUser(User*);
    void createPost(const string& text_, const Date& date_, const Time& time_);
    void addDialog(const Dialog&);
    void createDialog(User*);
    void addChat(const Chat&);
    void addToChat(Chat*, User*);
    void createChat(const string& chatName_);
    vector<User*> getFollowingUsers() const;
    vector<Post> getPosts() const;
    vector<Dialog> getDialogs() const;
    vector<Chat> getChats() const;
    void operator=(const User& other);
    bool operator==(const User& other) const;
};

