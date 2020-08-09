#include "Controller.h"

int main()
{
	//try - catch exceptions
	try
	{
		Controller controller;
		controller.run();
	}
	catch (const std::ios_base::failure & e)
	{
		e.what();
		std::cin.get();
	}
	catch (const std::out_of_range & e)
	{
		e.what();
		std::cin.get();
	}
	catch (const std::range_error & e)
	{
		e.what();
		std::cin.get();
	}
	catch (const std::exception & e)
	{
		e.what();
		std::cin.get();
	}
	catch (...)
	{
		std::cerr << "Sorry.. something wrong. Bye.";
		std::cin.get();
	}

	return 0;
}