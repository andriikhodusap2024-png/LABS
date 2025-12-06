#pragma once

#include <memory>
#include "transformer.h"

class ListNode : public std::enable_shared_from_this<ListNode> {
private:
    Transformer transformer_;

public:
    std::shared_ptr<ListNode> next;
    std::weak_ptr<ListNode> prev;

    explicit ListNode(const Transformer& t);
    ~ListNode();

    Transformer& getTransformer();
    const Transformer& getTransformer() const;
};
