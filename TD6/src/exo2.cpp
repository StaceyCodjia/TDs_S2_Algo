#include "node.hpp"

int main(){
    Node* root = create_node(10);

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

    std::cout << "Parcours infixe : ";
    root->display_infix();
    std::cout << std::endl;

    std::cout << "Valeur minimale : " << root->min() << std::endl;
    std::cout << "Valeur maximale : " << root->max() << std::endl;

    auto prefix_nodes = root->prefix();
    int sum = 0;
    for (const auto& node : prefix_nodes) {
        sum += node->value;
    }
    std::cout << "La somme est egale a :"<< sum << std::endl;

    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;
}