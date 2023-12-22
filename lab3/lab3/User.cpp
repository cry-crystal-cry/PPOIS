#include "User.h"

User::User() = default;

User::User(const Name& name_, const Gender& gender_, const int& age_, const string& country_, const string& familyStatus_)
	:Person(name_, gender_, age_, country_, familyStatus_) {}

User::~User() = default;

void User::followUser(User* user_)
{
	followingUsers.push_back(user_);
}

void User::createPost(const string& text_, const Date& date_, const Time& time_)
{
	posts.push_back(Post(text_, date_, time_, this));
}

void User::addDialog(const Dialog& dialog_)
{
	dialogs.push_back(dialog_);
}

void User::createDialog(User* companion_)
{
	Dialog dialog_(companion_, this);
	addDialog(dialog_);
	companion_->addDialog(dialog_);
}

void User::addChat(const Chat& chat_)
{
	chats.push_back(chat_);
}

void User::addToChat(Chat* chat_, User* companion_)
{
	companion_->addChat(*chat_);
	chat_->addCompanion(companion_);
}

void User::createChat(const string& chatName_)
{
	addChat(Chat(chatName_,this));
}

vector<User*> User::getFollowingUsers() const
{
	return followingUsers;
}

vector<Post> User::getPosts() const
{
	return posts;
}

vector<Dialog> User::getDialogs() const
{
	return dialogs;
}

vector<Chat> User::getChats() const
{
	return chats;
}

void User::operator=(const User& other)
{
	Person::operator=(other);
	followingUsers = other.getFollowingUsers();
	posts = other.getPosts();
	dialogs = other.getDialogs();
	chats = other.getChats();
}

bool User::operator==(const User& other) const
{
	return Person::operator==(other) && (followingUsers == other.getFollowingUsers()) && (posts == other.getPosts()) && 
		(dialogs == other.getDialogs()) && (chats == other.getChats());
}
