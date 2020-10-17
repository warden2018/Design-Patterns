#include <iostream>
#include <string>

using namespace std;

/*
* Each distinct product of a product family should have 
* a base interface. All the inheritable class should implement
* this interface. This class represents a series product,such as
* chair, or a cup. Different kinds of chair can be the concrete 
* implementation out of it.
*/
class AbstractProductA {
public:
	virtual ~AbstractProductA(){}
	virtual string UsefulFunctionA() const = 0;
};

/*
* Concrete products are created by corresponding concrete factory.
*/
class ConcreteProductA1 : public AbstractProductA {
public:
	string UsefulFunctionA() const override {
		return "The result of the Concrete ProductA1";
	}
};

class ConcreteProductA2 : public AbstractProductA {
public:
	string UsefulFunctionA() const override {
		return "The result of the Concrete ProductA2";
	}
};

/*
* Here is the base interface of another product. All products can interact with
* each other, but proper interaction is possible only between products
* of the same concrete functions.
*/
class AbstractProductB {
public:
	virtual ~AbstractProductB(){}
	virtual string UsefulFunctionB() const  = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
	string UsefulFunctionB() const override {
		return "The result of the Concrete ProductB1";
	}
};

class ConcreteProductB2 : public AbstractProductB {
public:
	string UsefulFunctionB() const override {
		return "The result of the Concrete ProductB2";
	}
};


class AbstractFactory {
public:
	virtual AbstractProductA* CreateProductA() const = 0;
	virtual AbstractProductB* CreateProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
	AbstractProductA* CreateProductA() const override {
		return new ConcreteProductA1();
	}
	AbstractProductB* CreateProductB() const override {
		return new ConcreteProductB1();
	}
};

class ConcreteFactory2 : public AbstractFactory {
public:
	AbstractProductA* CreateProductA() const override {
		return new ConcreteProductA2();
	}
	AbstractProductB* CreateProductB() const override {
		return new ConcreteProductB2();
	}
};

void ClientCode(const AbstractFactory &absFactory) {
	const AbstractProductA* product_A = absFactory.CreateProductA();
	const AbstractProductB* product_B = absFactory.CreateProductB();
	cout << product_A->UsefulFunctionA() << endl;
	cout << product_B->UsefulFunctionB() << endl;
	delete product_A;
	delete product_B;
}
int main() {
	cout << "The app is launched." << endl;
	cout << "Client: Testing client code with the first factory type: " << endl;
	ConcreteFactory1* factory1 = new ConcreteFactory1();
	ClientCode(*factory1);
	delete factory1;

	cout << "Client: Testing client code with the first factory type: " << endl;
	ConcreteFactory2* factory2 = new ConcreteFactory2();
	ClientCode(*factory2);
	delete factory2;

	system("pause");
	return 0;
}