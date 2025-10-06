
#include <variant>
#include <optional>
#include <string>
#include "Node.hpp"

class Value : public Node
{
public:
    enum class valueType{INT, STRING,DOUBLE,BOOL,EMPTY};
    using Variant = std::variant<std::nullptr_t,int,std::string,bool,double>;  
    
    Value() : Node(NodeType::VALUE),value(nullptr),type(valueType::EMPTY){};
    Value(int v) : Node(NodeType::VALUE),value(v),type(valueType::INT){}
    Value(double v) : Node(NodeType::VALUE),value(v),type(valueType::DOUBLE){}
    Value(bool v) : Node(NodeType::VALUE),value(v),type(valueType::BOOL){}

    valueType getNodeType(){return type;}
    template<typename T>
    std::optional<T> getValue() const {
        if (auto ptr = std::get_if<T>(&value))
            return *ptr;
        return std::nullopt;
    }
private:
    Variant value;
    valueType type;
};