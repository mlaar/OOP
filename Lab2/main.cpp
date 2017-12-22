#include <iostream>
#include <locale>
#include "TQueue.h"

void Menu()
{
	std::cout << "1. Create queue\n";
	std::cout << "2. Add item\n";
	std::cout << "3. Delete item\n";
	std::cout << "4. Print queue\n";
	std::cout << "5. Delete queue\n";
	std::cout << "6. Menu\n";
	std::cout << "0. Exit\n";
	std::cout << "\n";
}

int main() {
	TQueue *q = nullptr;
	int action;
	Menu();
	std::cin >> action;

	while (action != 0)
	{
		if (action == 1 && q == nullptr){
			q = new TQueue;
			std::cout << "Queue created\n";
		}
		//std::cout << q << " " << action << std::endl;
		if (action == 2 && q != nullptr)
			q->Push(Trapeze(std::cin));
		if (action == 3 && q != nullptr){
			if (!q->Empty()){
				Trapeze r = q->Pop();
				std::cout << r << "\n";
			}
			else
				std::cout << "Queue is empty\n";
		}
		if (action == 4 && q != nullptr)
			std::cout << *q;
		if (action == 5 && q != nullptr){
			delete q;
			std::cout << "Queue deleted\n";
			q = nullptr;
		}
		if (action == 6)
			Menu();
		std::cin >> action;
	}
}