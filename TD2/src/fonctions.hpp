#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <cmath>

// Exo 1
std::vector<std::string> split_string(std::string const& s);
bool is_floating(std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);

// Exo 2
enum class Operator { ADD, SUB, MUL, DIV, POW };
enum class TokenType { NUMBER, OPERATOR };
struct Token {
  TokenType type;
  float value;
  Operator op;
};
Token make_token(float value);
Token make_token(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);
float npi_evaluate(std::vector<Token> const& tokens);