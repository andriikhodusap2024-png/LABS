#include "listnode.h"

ListNode::ListNode(const Transformer& t)
    : transformer_(t)
{
    std::cout << u8"[КОНСТРУКТОР] Вузол списку створено\n";
}

ListNode::~ListNode()
{
    std::cout << u8"[ДЕСТРУКТОР] Вузол списку знищено\n";
}

Transformer& ListNode::getTransformer() { return transformer_; }

const Transformer& ListNode::getTransformer() const { return transformer_; }
