#include "movie.h"
#include"util.h"
#include "product.h"
using namespace std;



Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) : Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}

std::set<std::string> Movie::keywords() const
{
	std::set<std::string> temp;
	std::set<std::string> temp2;
	std::set<std::string> res;
	temp = parseStringToWords(name_);
	temp2 = parseStringToWords(genre_);
	res = setUnion(temp, temp2);
	return res;
}

std::string Movie::displayString() const
{
	std::string temp = name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + (std::to_string(price_)).substr(0,5) + " " + std::to_string(qty_) + " left.";
	return temp;
}

void Movie::dump(std::ostream& os) const
{
	Product::dump(os);
	os << genre_ << "\n" << rating_ << "\n";
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
	return false;
}



