#include "book.h"
#include"util.h"
#include "product.h"




Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author) : Product(category, name, price, qty)
{
	isbn_ = isbn;
	author_ = author;
}

std::set<std::string> Book::keywords() const
{
	std::set<std::string> temp;
	std::set<std::string> temp2;
	std::set<std::string> res;
	temp = parseStringToWords(name_);
	temp2 = parseStringToWords(author_);
	res = setUnion(temp, temp2);
	res.insert(isbn_);
	return res;
}

std::string Book::displayString() const
{
	std::string temp = name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
	return temp;
}

void Book::dump(std::ostream& os) const
{
	Product::dump(os);
	os << isbn_ << "\n" << author_;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
	return false;
}



