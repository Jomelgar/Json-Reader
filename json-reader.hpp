/*
    Lector de JSON en C++ a mano. En si este contiene funciones de lexer y el parser, ademas de atributos
    contienen los elementos
*/
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "Node.hpp"

enum class TokenType{
    LBRACE, RBRACE, LBRACKET, RBRACKET,
    COLON, COMMA,
    STRING, NUMBER, BOOLEAN, NUL,
    END, UNKNOWN
};

struct Token 
{
    TokenType type;
    std::string value;
};

class ReaderJson
{
private:
    Node * root;
    std::vector<Token> Lexer(std::string &);
     void Parser(std::vector<Token> &);
public:
    void readFile(std::string &);
};

void ReaderJson::readFile(std::string & fileName)
{
    std::ifstream file("data.json");
    std::string content((std::istreambuf_iterator<char>(file)),
                    (std::istreambuf_iterator<char>()));
    std::vector<Token> tokens = Lexer(content);

};

std::vector<Token> ReaderJson::Lexer(std::string & body)
{
    std::vector<Token> result;
    size_t i = 0;

    while (i < body.size())
    {
        char c = body[i];

        if (isspace(c)) { i++; continue; }

        switch (c)
        {
        case '{': result.push_back({TokenType::LBRACE,"{"}); i++; break;
        case '}': result.push_back({TokenType::RBRACE,"}"}); i++; break;
        case '[': result.push_back({TokenType::LBRACKET,"["}); i++; break;
        case ']': result.push_back({TokenType::RBRACKET,"]"}); i++; break;
        case ':': result.push_back({TokenType::COLON,":"}); i++; break;
        case ',': result.push_back({TokenType::COMMA,","}); i++; break;

        case '"': {
            std::string value;
            i++;
            while (i < body.size() && body[i] != '"') {
                if (body[i] == '\\' && i + 1 < body.size()) i++;
                value += body[i++];
            }
            i++;
            result.push_back({TokenType::STRING, value});
            break;
        }

        default:
            if (isdigit(c) || c == '-') {
                std::string number;
                while (i < body.size() && (isdigit(body[i]) || body[i]=='.' || body[i]=='-'))
                    number += body[i++];
                result.push_back({TokenType::NUMBER, number});
            }
            else if (isalpha(c)) {
                std::string word;
                while (i < body.size() && isalpha(body[i]))
                    word += body[i++];
                if (word=="true" || word=="false")
                    result.push_back({TokenType::BOOLEAN, word});
                else if (word=="null")
                    result.push_back({TokenType::NUL, word});
                else
                    result.push_back({TokenType::UNKNOWN, word});
            }
            else {
                result.push_back({TokenType::UNKNOWN, std::string(1,c)});
                i++;
            }
        }
    }

    result.push_back({TokenType::END, ""});
    return result;
};

void Parser(std::vector<Token> & tokens){
    size_t i = 0;

    Token actual = tokens.at(i);
    //Aqui se hara un switch basicamente para los LBRACE, LBRACKET y por ultimo STRING
    switch (actual.type)
    {
    case TokenType::LBRACE:
        
        /* code */
    break;
    case TokenType::LBRACKET:
        
        /* code */
    break;
    case TokenType::STRING:
        /* code */
    break;
    default:
        throw "The JSON file is not valid.";
    }
    
    if(tokens.at(i).type != TokenType::END)
    {
        throw "The JSON file is not valid";
    }
};