#include "smartNode.hpp"


int main(){
    std::unique_ptr<SmartNode> root = create_smart_node(10);

    root->insert(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    std::cout << "Arbre Binaire :" << std::endl;
    pretty_print_left_right(*root);

    std::cout << "Valeur minimale : " << root->min() << std::endl;
    std::cout << "Valeur maximale : " << root->max() << std::endl;

    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;
}