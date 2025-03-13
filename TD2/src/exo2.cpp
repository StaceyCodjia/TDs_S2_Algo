#include "fonctions.hpp"

enum class Operator { ADD, SUB, MUL, DIV};
enum class TokenType { NUMBER, OPERATOR };
struct Token {
  TokenType type;
  float value;
  Operator op;
};
Token make_token(float value) {
    return Token{TokenType::NUMBER, value, Operator{}};
}
Token make_token(Operator op) {
    return Token{TokenType::OPERATOR, 0.0f, op};
}


int main(){

}