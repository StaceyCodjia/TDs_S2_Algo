#include "node.hpp"

int main(){
    Node* root = create_node(10);

    root->insert(5);
    root->insert(20);
    root->insert(1);
    root->insert(6);

    std::cout << "Arbre Binaire :" << std::endl;
    pretty_print_left_right(*root);

    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;

    std::cout << "Parcours infixe : ";
    root->display_infix();
    std::cout << std::endl;
    
    std::vector<Node const*> prefix_nodes = root->prefix();

    std::cout << "Parcours prefixe : ";
    for (Node const* node : prefix_nodes) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;

    std::vector<Node const*> postfix_nodes = root->postfix();

    std::cout << "Parcours postfixe : ";
    for (Node const* node : postfix_nodes) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Valeur minimale : " << root->min() << std::endl;
    std::cout << "Valeur maximale : " << root->max() << std::endl;

    delete_tree(root);
    return 0;
}