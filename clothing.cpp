#include "clothing.h"
#include"util.h"
#include "product.h"
#include <string>
using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) : Product(category, name, price, qty)
{
	size_ = size;
	brand_ = brand;
}

std::set<std::string> Clothing::keywords() const
{
	std::set<std::string> temp;
	std::set<std::string> temp2;
	std::set<std::string> res;
	temp = parseStringToWords(name_);
	temp2 = parseStringToWords(brand_);
	res = setUnion(temp, temp2);
	return res;
}

std::string Clothing::displayString() const
{
	std::string temp = name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n$" + (std::to_string(price_)).substr(0,5) + " " + std::to_string(qty_) + " left.";
	return temp;
}

void Clothing::dump(std::ostream& os) const
{
	Product::dump(os);
	os << brand_ << "\n" << size_;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
	return false;
}



