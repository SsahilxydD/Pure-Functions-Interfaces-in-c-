#include <iostream>
using namespace std;

// Base class with a pure virtual function
class printable
{
public:
	// Pure virtual function, meaning it must be implemented by derived classes
	virtual string GetClassName() = 0;
};

// Derived class Entity inheriting from printable
class Entity : public printable
{
public:
	// Implementation of GetName function returning a default value "Entity"
	virtual string GetName() { return "Entity"; }
	
	// Implementation of GetClassName function returning "Entity"
	string GetClassName() override { return "Entity"; }
};

// Derived class Player inheriting from Entity
class Player :public Entity
{
private:
	string m_Name;
public:
	// Constructor accepting a name and initializing m_Name
	Player(const string& name) :m_Name(name) {}

	// Implementation of GetName returning the stored name
	string GetName() override { return m_Name; }
	
	// Implementation of GetClassName returning the stored name
	string GetClassName() override { return m_Name; }
};

// Function to print the name of an entity
void Print(Entity* entity)
{
	cout << entity->GetName() << '\n';
}

// Function to print the class name of a printable object
void print(printable* obj)
{
	cout << obj->GetClassName() << '\n';
}

int main()
{
	// Creating an Entity object and printing its name and class name
	Entity* e = new Entity{};
	Print(e);
	print(e);

	// Creating a Player object and printing its name and class name
	Player* p = new Player{"sahilxyd"};
	Print(p);
	print(p);

	// Cleaning up dynamically allocated memory
	delete e;
	delete p;
}
