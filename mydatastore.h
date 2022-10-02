#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "datastore.h"
#include <map>
#include "util.h"
using namespace std;

class MyDataStore : public DataStore
{
	public:

	MyDataStore();

	~MyDataStore();

	void addProduct(Product* p);

	void addUser(User* u);

	void addToCart(std::string username, Product* p);
	
	void viewCart(std::string username);
	
	void buyCart(std::string username);

	void clear();

	std::vector<Product*> search(std::vector<std::string>& terms, int type);

  void dump(std::ostream& ofile);

	private:
	std::set<Product*> allProducts;
	map<std::string, User*> users;
	map<std::string, std::vector<Product*>> cart;
	map<std::string, std::set<Product*>> dStore;
	//map<users, std::set<Product*>>
};