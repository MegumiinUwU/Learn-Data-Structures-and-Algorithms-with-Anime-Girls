
#ifndef _NODETYPE_H
#define _NODETYPE_H

// Node structure for Single Linked List
template <typename T>
struct node {
    T info;
    node* link = nullptr;
    node() = default;

    node(T data) : info(info), link(nullptr) {}
};

// Node structure for Double Linked List
template <typename T>
struct dNode {
    T data;
    dNode* prev = nullptr;
    dNode* next = nullptr;

    dNode() = default;

    dNode(T data) : data(data), prev(nullptr), next(nullptr) {}
};

// Node structure for Circular Linked List
template <typename T>
struct circularNode {
    T data;
    circularNode* next = nullptr;

    circularNode(T data) : data(data), next(nullptr) {}
};










#endif // _NODETYPE_H
