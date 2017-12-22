#include <iostream>
#include <locale>
#include <memory>
#include "TQueue.h"
#include "Tree.h"
#include <string>

void Menu()
{
    std::cout << "1. Create queue\n";
    std::cout << "2. Add item\n";
    std::cout << "  3. Add trapeze\n";
    std::cout << "  4. Add rhombus\n";
    std::cout << "  5. Add pentagon\n";
    std::cout << "6. Delete item\n";
    std::cout << "7. Print queue\n";
    std::cout << "8. Menu\n";
    std::cout << "9. Create Tree\n";
    std::cout << "10. Add Tree\n";
    std::cout << "0. Exit\n";
    std::cout << "\n";
}

int main() {
    std::shared_ptr<TQueue<Tree<std::shared_ptr<Figure> > > > queue = nullptr;
    std::shared_ptr<Tree<std::shared_ptr<Figure> > > t = nullptr;
    int action;
    Menu();

    while (std::cin >> action && action != 0) {
        std::cin.clear();
        std::cin.sync();
        if (action == 1 && queue == nullptr){
            queue = std::shared_ptr<TQueue<Tree<std::shared_ptr<Figure> > > > (new TQueue<Tree<std::shared_ptr<Figure> > >);
            std::cout << "Queue created" << std::endl;
        }
        else if (action == 2 && t != nullptr) {
            int cnt;
            std::cin >> cnt;
            if (cnt == 3) {
                std::string path = "\0";
                std::cout << "Enter path: " << std::endl;
                std::cin >> path;
                if (path[0] != 'S' && path[0] != 'B') {
                    path = "\0";
                }
                t->Insert(std::shared_ptr<Figure> (new Trapeze(std::cin)), path);
            }
            else if (cnt == 4) {
                std::string path = "\0";
                std::cout << "Enter path: " << std::endl;
                std::cin >> path;
                if (path[0] != 'S' && path[0] != 'B') {
                    path = "\0";
                }
                t->Insert(std::shared_ptr<Figure> (new Rhombus(std::cin)), path);
            }
            else if (cnt == 5) {
                std::string path = "\0";
                std::cout << "Enter path: " << std::endl;
                std::cin >> path;
                if (path[0] != 'S' && path[0] != 'B') {
                    path = "\0";
                }
                t->Insert(std::shared_ptr<Figure> (new Pentagon(std::cin)), path);
            }
        }
        else if (action == 6 && queue != nullptr){
            if (!queue->Empty()){
                auto r = queue->Pop();
                r->Print();
            }
            else {
                std::cout << "Queue is empty\n";
            }
        }
        else if (action == 7 && queue != nullptr) {
            for (auto i: *queue) {
                i->Print();
            }
        }
        else if (action == 8) {
            Menu();
        }
        else if (action == 9) {
            std::cout << "  1 Trapeze\n  2 Rhombus\n  3 Pentagon" << std::endl;
            int cnt;
            std::cin >> cnt;
            std::shared_ptr<Figure> f;
            if (cnt == 1) {
                f = std::shared_ptr<Figure>(new Trapeze(std::cin));
            }
            else if (cnt == 2) {
                f = std::shared_ptr<Figure>(new Rhombus(std::cin));
            } 
            else if (cnt == 3) {
                f = std::shared_ptr<Figure>(new Pentagon(std::cin));
            } else {
                continue;
            }

            t = std::shared_ptr<Tree<std::shared_ptr<Figure> > > (new Tree<std::shared_ptr<Figure> > (f, 4) );
            std::cout << "Tree created" << std::endl;
        }
        else if (action == 10 && queue != nullptr && t != nullptr) {
            queue->Push(std::shared_ptr<Tree<std::shared_ptr<Figure> > > (t));
        }
    }
}