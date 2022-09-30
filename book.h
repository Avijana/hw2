#include "product.h"
#ifndef BOOK_H 
#define BOOK_H


class Book : public Product
{
	public:
	//does this have to be different from isbn and author variable name
	Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);

	std::set<std::string> keywords() const;

	std::string displayString() const;

	void dump(std::ostream& os) const;

	bool isMatch(std::vector<std::string>& searchTerms) const;

//what to name these
	private:
	std::string isbn_;
	std::string author_;
};
#endif