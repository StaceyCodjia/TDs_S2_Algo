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