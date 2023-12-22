#include "Post.h"

Post::Post() = default;

Post::Post(const string& text_, const Date& date_, const Time& time_, Person* personFrom_)
	:Note(text_, date_, time_)
{
	setPersonFrom(personFrom_);
}

Post::~Post() = default;

void Post::setPersonFrom(Person* personFrom_)
{
	personFrom = personFrom_;
}

void Post::addReaction(const Reaction& reaction_)
{
	reactions.push_back(reaction_);
}

void Post::addComment(const Comment& comment_)
{
	comments.push_back(comment_);
}

Person* Post::getPersonFrom() const
{
	return personFrom;
}

vector<Reaction> Post::getReactions() const
{
	return reactions;
}

vector<Comment> Post::getComments() const
{
	return comments;
}

void Post::operator=(const Post& other)
{
	Note::operator=(other);
	setPersonFrom(other.getPersonFrom());
	reactions = other.getReactions();
	comments = other.getComments();
}

bool Post::operator==(const Post& other) const
{
	return Note::operator==(other) && (personFrom == other.getPersonFrom()) && (reactions == other.getReactions()) && 
		(comments == other.getComments());
}

