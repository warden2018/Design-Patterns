#include <string>
#include <iostream>

/*[Factory Method]
* A creation design pattern which solves the problem of creating
* product objects without specifying their concrete classes.
*/




/*
* The product interface declares the operations that all concrete products must 
* implement.
*/
class Product{
public:
	virtual ~Product(){};
	virtual std::string Operation() const = 0;

};

/*
* Concrete products provide various implementations of the product interface.
*/
class ConcreteProduct1 : public Product {
public:
	std::string Operation() const override{
		return "{Result of the ConcreateProduct1}";
	}
};

class ConcreteProduct2 : public Product {
public:
	std::string Operation() const override{
		return "{Result of the ConcreateProduct2}";
	}
};

/*
* The Creator class declares the factory method that is supposed to return an
* object of a Product class. The Creator's implementation is usually provided by
* subclasses of the Creator.
*/
class Creator{
	/*
	* Note that the Creator class may also provide default implementation of 
	* the factory method.
	*/
public:
	virtual ~Creator(){}
	/*
	* Note that, despite the name, the Creator's primary task is not creating the 
	* product objects. Usually, it contains some core business logic that relies on 
	* product objects, returned by the factory method, in this example the factory 
	* method is FactoryMethod. The real creating job is done by the subclass of 
	* Creator by overriding FactoryMethod function and returning different types 
	* of product.
	*/
	virtual Product* FactoryMethod() const = 0;

	std::string SomeOperation() const {
		Product* product = this->FactoryMethod();
		//Now use the product
		std::string result = "Creator: The same creator's code has just worked with: " + product->Operation();
		delete product;
		return result;
	}
};

/*
* Real product object creator class. Usually client add the new subclass 
* of Creator for their own business use cases.
*/
class ConcreteCreator1 : public Creator {
public:
	/*
	* Note the signature of the method still uses the abstract product type,
	* even though the concrete product is actually returned from the method.
	* This way the Creator can stay independent from the concrete creators.
	*/
	Product* FactoryMethod() const override{
		return new ConcreteProduct1();
	}
};

class ConcreteCreator2 : public Creator {
public:
	Product* FactoryMethod() const override{
		return new ConcreteProduct2();
	}
};

//client code 

void ClientCode(const Creator& creator){
	//...
	std::cout << "I am not aware of the creator's class, but I can still work correctly with it! \n"
				<< creator.SomeOperation() << std::endl;
}


int main(){
	std::cout << "App Launched with the ConcreteCreator1. \n";
	Creator* creator = new ConcreteCreator1();
	ClientCode(*creator);
	std::cout << std::endl;

	std::cout << "App Launched with the ConcreteCreator2. \n";
	Creator* creator2 = new ConcreteCreator2();
	ClientCode(*creator2);
	std::cout << std::endl;


	delete creator;
	delete creator2;

	system("pause");
	return 0;
}



 