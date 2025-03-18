#include "fonctions.hpp"

//Exo 1
std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), 
    std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s){
    for (char c : s){
        if (!std::isdigit(c) && c != '.'){
            return false;
        }
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens){

    std::stack<float> stack;
    for (int i = 0; i < tokens.size(); i++){
        std::string token = tokens[i];
        if (is_floating(token)){
            stack.push(std::stof(token));
        } else {
            float operand2 = stack.top();
            stack.pop();
            float operand1 = stack.top();
            stack.pop();
            if (token == "+"){
                stack.push(operand1 + operand2);
            } else if (token == "-"){
                stack.push(operand1 - operand2);
            } else if (token == "*"){
                stack.push(operand1 * operand2);
            } else if (token == "/"){
                stack.push(operand1 / operand2);
            }else if (token == "^"){
                stack.push(std::pow(operand1, operand2));
        }
    }
}
return stack.top();
return 0.f;
}

//Exo 2
Token make_token(float value){
    return {TokenType::NUMBER, value};
}
Token make_token(Operator op){
    return {TokenType::OPERATOR, 0.f, op};
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens;
    for (int i = 0; i < words.size(); i++){
        std::string word = words[i];
        if (is_floating(word)){
            tokens.push_back(make_token(std::stof(word)));
        } else {
            if (word == "+"){
                tokens.push_back(make_token(Operator::ADD));
            } else if (word == "-"){
                tokens.push_back(make_token(Operator::SUB));
            } else if (word == "*"){
                tokens.push_back(make_token(Operator::MUL));
            } else if (word == "/"){
                tokens.push_back(make_token(Operator::DIV));
            } else {
                throw std::runtime_error("Operateur inconnu : " + word);
            }
        }
    }
    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;
    for (int i = 0; i < tokens.size(); i++){
        Token token = tokens[i];
        if (token.type == TokenType::NUMBER){
            stack.push(token.value);
        } else {
            float operand2 = stack.top();
            stack.pop();
            float operand1 = stack.top();
            stack.pop();
            if (token.op == Operator::ADD){
                stack.push(operand1 + operand2);
            } else if (token.op == Operator::SUB){
                stack.push(operand1 - operand2);
            } else if (token.op == Operator::MUL){
                stack.push(operand1 * operand2);
            } else if (token.op == Operator::DIV){
                stack.push(operand1 / operand2);
            } else if (token.op == Operator::POW){
                stack.push(std::pow(operand1, operand2));
            }
        }
    }
    return stack.top();
    return 0.f;
}