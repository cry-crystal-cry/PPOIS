#pragma once
#include "Note.h"
#include "Comment.h"
#include "Reaction.h"

class Post :
    public Note
{
protected:
    Person* personFrom;
    vector<Reaction> reactions;
    vector<Comment> comments;
    //int picture[10][10];
public:
    Post();
    Post(const string& text_, const Date& date_, const Time& time_, Person* personFrom_);
    ~Post();
    void setPersonFrom(Person*);
    void addReaction(const Reaction&);
    void addComment(const Comment&);
    //void setPicture(const int*);
    Person* getPersonFrom() const;
    vector<Reaction> getReactions() const;
    vector<Comment> getComments() const;
    //int* getPicture() const;
    void operator=(const Post& other);
    bool operator==(const Post& other) const;
};

