#include <iostream>
#include <locale>
#include <memory>
#include "TQueue.h"

void Menu()
{
	std::cout << "1. Create queue\n";
	std::cout << "2. Add item\n";
	std::cout << "	3. Add trapeze\n";
	std::cout << "	4. Add rhombus\n";
	std::cout << "	5. Add pentagon\n";
	std::cout << "6. Delete item\n";
	std::cout << "7. Print queue\n";
	std::cout << "8. Menu\n";
	std::cout << "0. Exit\n";
	std::cout << "\n";
}

int main() {
	std::shared_ptr<TQueue<Figure>> q = nullptr;
	int action;
	Menu();
	std::cin >> action;

	while (action != 0)
	{
		if (action == 1 && q == nullptr){
			q = std::shared_ptr<TQueue<Figure>> (new TQueue<Figure>);
			std::cout << "Queue created\n";
		}
		//std::cout << q << " " << action << std::endl;
		if (action == 2 && q != nullptr) {
			int cnt;
			std::cin >> cnt;
			if (cnt == 3) {
				q->Push(std::shared_ptr<Figure> (new Trapeze(std::cin)));
			}
			else if (cnt == 4) {
				q->Push(std::shared_ptr<Figure> (new Rhombus(std::cin)));
			}
			else if (cnt == 5) {
				q->Push(std::shared_ptr<Figure> (new Pentagon(std::cin)));
			}
		}
		if (action == 6 && q != nullptr){
			if (!q->Empty()){
				auto r = q->Pop();
				std::cout << r << "\n";
			}
			else
				std::cout << "Queue is empty\n";
		}
		if (action == 7 && q != nullptr)
			//std::cout << *q;
			for (auto i: *q) {
				i->Print();
			}
		/*if (action == 5 && q != nullptr){
			delete q;
			std::cout << "Queue deleted\n";
			q = nullptr;
		}*/
		if (action == 8)
			Menu();
		std::cin >> action;
	}
	//int* a;
	//a = new int;
	/*int b = 1;
	std::shared_ptr<int> a(new int);
	int *c = a.get();
	*c = b;
	std::cout << *a << std::endl;*/
	/*std::shared_ptr<Figure> f(new Trapeze(std::cin));
	f->Print();*/
	/*TQueue q;
	q.Push(std::shared_ptr<Figure> (new Trapeze(std::cin)));
	q.Push(std::shared_ptr<Figure> (new Rhombus(std::cin)));
	q.Push(std::shared_ptr<Figure> (new Pentagon(std::cin)));
	std::cout << q;*/
}