#include <iostream>
#include <string>
#include <memory>

class test_virtual
{
public:
	virtual void print() = 0;
};

class test_a : public test_virtual
{
public:
	virtual void print() { std::cout << "this is test_a.\n"; }
};

class test_b : public test_a
{
public:
	virtual void print() { std::cout << "this is test_b.\n"; }
};


class base{
public:
     base(){std::cout << "base" << std::endl;}
     ~base(){std::cout << "~base" << std::endl;}
     virtual void print(){std::cout << "base::print" << std::endl;}
};
 
class derived:public base{
 public:
     derived(){std::cout << "derived" << std::endl;}
     ~derived(){std::cout << "~derived" << std::endl;}
     virtual void print(){std::cout << "derived::print" << std::endl;}
};

int main()
{
	std::shared_ptr<test_virtual> ptr_virtual = std::make_shared<test_b>();
	ptr_virtual->print();
	std::shared_ptr<test_a> ptr_a = std::make_shared<test_b>();
	ptr_a->print();
	std::cout << std::endl;
        std::shared_ptr<base> b_ptr = std::make_shared<derived>();
        b_ptr->print();
    	auto d_ptr = std::dynamic_pointer_cast<derived>(b_ptr);
        d_ptr->print();
	return 0;
}
