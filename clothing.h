#ifndef CLOTHING_H //what r these two for??
#define CLOTHING_H
#include "product.h"

class Clothing : public Product
{
	public:
	//does this have to be different from isbn and author variable name
	Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);

	std::set<std::string> keywords() const;

	std::string displayString() const;

	void dump(std::ostream& os) const;

	bool isMatch(std::vector<std::string>& searchTerms) const;

//what to name these
	private:
	std::string size_;
	std::string brand_;
};
#endif