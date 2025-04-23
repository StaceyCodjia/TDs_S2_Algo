#include "node.hpp"

int main(){
    Node* root = create_node(10);

    root->insert(5);
    root->insert(17);
    root->insert(1);
    root->insert(9);
    root->insert(15);

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


    root->delete_children();
    delete root;
    return 0;
}