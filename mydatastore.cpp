#include <set>
#include <vector>
#include "mydatastore.h"
using namespace std;

MyDataStore::MyDataStore()
{

}
MyDataStore::~MyDataStore()
{
	
}

// void MyDataStore::clear()
// {
// 	allProducts.clear();
// 	users.clear();
// 	cart.clear();
// 	dStore.clear();
// }

void MyDataStore::addProduct(Product* p)
{
	set<string> x = p->keywords();

	for(set<string>::iterator it = x.begin(); it != x.end(); it++)
	{
		if(dStore.find(*it) == dStore.end()) //pairs together keywords with sets of products
		{
			set<Product*> temp;
			dStore.insert(make_pair(*it, temp));
			dStore[*it].insert(p);
			//dStore[*it].insert(p);
		}
		else
		{
			dStore[*it].insert(p);
		}
	}
	allProducts.insert(p);
}

void MyDataStore::addUser(User* u)
{
	std::string temp = convToLower(u->getName());
	users.insert(make_pair(temp, u)); //pairs string username with a user
	if(cart.find(temp)==cart.end()) //makes user a cart
	{
		std::vector<Product*> items;
		cart.insert(make_pair(temp,items));
	}
}

void MyDataStore::addToCart(std::string username, Product* p)
{
	if(users.find(username) == users.end())
	{
		cout << "invalid request: user does not exist" << endl;
		return;
	}
	cart[username].push_back(p);
	//cart[username].insert(p);
}

void MyDataStore::viewCart(std::string username)
{
	//string outputCart;
	if(users.find(username) == users.end())
	{
		//return "invalid request: user does not exist";
		cout << "invalid request: user DNE" << endl;
		
	}
	int prodNum = 1;
	for(std::vector<Product*>::iterator it = cart[username].begin(); it != cart[username].end(); it++) //prints products in users cart
	{
		cout<< "Item " << prodNum << ": " << "\n" << (*it)->displayString() << "\n";
		prodNum++;
	}
	//return outputCart;
}

void MyDataStore::buyCart(std::string username)
{
	//username = convToLower(username);
	if(users.find(username) == users.end()) //make lower case when creating user
	{
		cout << "invalid request: user does not exist" << endl;
		return;
	}
	
	for(std::vector<Product*>::iterator it = cart[username].begin(); it < cart[username].end();) //goes through each item in cart
	{
		 if(((users[username])->getBalance() > (*it)->getPrice()) && ((*it)->getQty() > 0))// checks if user passes reqs to buy
			 {
				 //cout << "NOO" << endl;
			 	(users[username])->deductAmount((*it)->getPrice());
				(*it)->subtractQty(1);
				(cart[username]).erase(it);
			 }
			else //if user buys the item it does not increment but if they dont it does (prevents seg fault)
		 {
			 it++;
		 }
		 }
	}
	



std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	//for each term create a set of products that match the term
	set<Product*> result = dStore[terms[0]]; //makes sure we dont have empty set when performing intersect
	for(std::vector<string>::iterator it = terms.begin(); it != terms.end(); it++)
	{
		if(dStore.find(*it) != dStore.end())
		{
			
			if(type==0)
			{
				result = setIntersection(result, dStore[*it]);
			}
			else if(type==1)
			{
				result = setUnion(result, dStore[*it]);
			}
		}
	//change set to vector and return vector
	}	
	vector<Product*> final(result.begin(), result.end());
	return final;
}


void MyDataStore::dump(std::ostream& ofile)
{
    ofile << "<products>" << endl;
    set<Product*>::iterator it;

    for (it = allProducts.begin(); it != allProducts.end(); it++)
		{
        (*it)->dump(ofile); 
    } 

    ofile << "</products>" << endl;
    
    ofile << "<users>" << endl;
    map<string, User*>::iterator it2; 

    for (it2 = users.begin(); it2 != users.end(); it2++)
		{
        (*it2).second->dump(ofile); 
    }

    ofile << "</users>" << endl;
}

	
