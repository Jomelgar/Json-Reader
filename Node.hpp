/*
Objetos de JSON, en teoría debe ser Object el abstracto y los hijos que, o son variables o 
son arreglos con variaables dentro o solo valores
*/
#include <vector>

class Node
{
public:
    enum class NodeType {VALUE,VARIABLE, ARRAY, OBJECT};
    
    virtual ~Node() = default;
    NodeType getNodeType() {return this->t;}

    Node(NodeType NodeType) : t(NodeType) {};
private:
    NodeType t;
};
