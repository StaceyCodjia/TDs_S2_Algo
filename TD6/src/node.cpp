#include "node.hpp"


//Exo 1

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

void Node::insert(int value){
    if (value < this -> value) {
        // Insérer à gauche si la valeur est inférieure
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else {
        // Insérer à droite sinon
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

int Node::height() const {
    if (is_leaf()) {
        return 1;
    } else {
        int left_height = (left != nullptr) ? left->height() : 0;
        int right_height = (right != nullptr) ? right->height() : 0;
        return 1 + std::max(left_height, right_height);
    }
}

void Node::delete_children(){
    if (left != nullptr) {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix() const{
    if (left != nullptr) {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right != nullptr) {
        right->display_infix();
    }
}

std::vector<Node const*> Node::prefix() const{
    std::vector<Node const*> result;

    result.push_back(this);

    if (left != nullptr) {
        std::vector<Node const*> left_prefix = left->prefix();
        result.insert(result.end(), left_prefix.begin(), left_prefix.end());
    }

    if (right != nullptr) {
        std::vector<Node const*> right_prefix = right->prefix();
        result.insert(result.end(), right_prefix.begin(), right_prefix.end());
    }

    return result;
}

std::vector<Node const*> Node::postfix() const {
    std::vector<Node const*> result;

    if (left != nullptr) {
        std::vector<Node const*> left_postfix = left->postfix();
        result.insert(result.end(), left_postfix.begin(), left_postfix.end());
    }

    if (right != nullptr) {
        std::vector<Node const*> right_postfix = right->postfix();
        result.insert(result.end(), right_postfix.begin(), right_postfix.end());
    }

    result.push_back(this);

    return result;
}

Node*& Node::most_left(Node*& node) {
    if (node->left) {
        return most_left(node->left);
    } else {
        return node;
    }
}

bool remove(Node*& node, int value){
        if (node == nullptr) {
            return false;
        }
        if (value < node->value) {

            return remove(node->left, value);

        } else if (value > node->value) {

            return remove(node->right, value);

        } else {
            // Cas où le nœud est une feuille
            if (node->is_leaf()) {
                delete node;
                node = nullptr;
            } 
            // Cas où le nœud a uniquement un sous-arbre
            else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
            // Cas où le nœud a deux sous-arbres
                Node*& successor = node->most_left(node->right);
                node->value = successor->value;
                remove(successor, successor->value);
            }
            return true;
        }
    }

void delete_tree(Node* node){
    if (node == nullptr) {
        return;
    }
    
    delete_tree(node->left);
    delete_tree(node->right);
            
    delete node;
    node = nullptr;
}
int Node::min() const {
    if (left == nullptr) {
        return value;
    }
    return left->min();
}
int Node::max() const {
    if (right == nullptr) {
        return value;
    }
    return right->max();
}