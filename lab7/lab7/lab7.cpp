#include <iostream>
#include "Tree.h"
bool comparaValori(int a, int b) {
    return a == b;
}
bool sortareDescrescatoare(int a, int b) {
    return a > b;
}

int main() {
    Tree<int>* radacina = Tree<int>::addnode(nullptr, 100);
    Tree<int>::addnode(radacina, 20);
    Tree<int>::addnode(radacina, 80);
    Tree<int>::addnode(radacina, 50);
    std::cout << "Radacina are valoarea: " << radacina->get_value() << "\n";
    std::cout << "Numar copii " << radacina->count() << "\n";
    Tree<int>::insert(radacina, 1, 99);
    std::cout << "Noul numar copii " << radacina->count() << "\n";
    Tree<int>* gasit = Tree<int>::find(radacina, 80, comparaValori);
    if (gasit != nullptr) {
        std::cout << "succes " << gasit->get_value() << "\n";
        Tree<int>::addnode(gasit, 81);
        std::cout << " " << radacina->count() << "\n";
    }
    else
        std::cout << "Fail"<<"\n";
    radacina->sort(sortareDescrescatoare);
    radacina->sort(nullptr);
    Tree<int>::delete_node(radacina);
    return 0;
}