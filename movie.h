#ifndef MOVIE_H //what r these two for??
#define MOVIE_H
#include "product.h"

class Movie : public Product
{
	public:
	//does this have to be different from isbn and author variable name
	Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);

	std::set<std::string> keywords() const;

	std::string displayString() const;

	void dump(std::ostream& os) const;

	bool isMatch(std::vector<std::string>& searchTerms) const;

//what to name these
	private:
	std::string genre_;
	std::string rating_;
};
#endif