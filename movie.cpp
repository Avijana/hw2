#include "movie.h"
#include"util.h"
#include "product.h"




Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) : Product(category, name, price, qty)
{
	genre_ = genre;
	genre_ = genre;
}

std::set<std::string> Movie::keywords() const
{
	std::set<std::string> temp;
	std::set<std::string> temp2;
	std::set<std::string> res;
	temp = parseStringToWords(name_);
	res.insert(genre_);
	return res;
}

std::string Movie::displayString() const
{
	std::string temp = name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
	return temp;
}

void Movie::dump(std::ostream& os) const
{
	Product::dump(os);
	os << genre_ << "\n" << rating_;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
	return false;
}



