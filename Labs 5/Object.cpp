#include "Object.h"
#include <iostream>

Object::~Object()
{
	std::cout << "Âûçâàí äåñòðóêòîð îáúåêòà áàçîâîãî êëàññà Object" << std::endl;
}

Object::Object()
{
	std::cout << "Âûçâàí êîíñòðóêòîð îáúåêòà áàçîâîãî êëàññà Object" << std::endl;
}