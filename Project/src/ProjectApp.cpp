#include <Easy.h>

class Project : public Easy::Application
{
public:
	Project()
	{

	}

	~Project()
	{

	}
};

Easy::Application* Easy::CreateApplication()
{
	return new Project();
}