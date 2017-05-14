// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;
// Prototypes - helper functions ------------------------------------------------------------------

extern void dump_treap(Node *node, std::ostream &os, DumpFlag flag);
Node *search_treap(Node *node, const std::string &key);
Node *insert_treap(Node *node, const std::string &key, const std::string &value);
Node *RotateRight(Node *node);
Node *RotateLeft(Node *node);
void traversal(Node *node);
int max_height(Node *node);
int min_height(Node *node);
int get_random();

// Methods ---------------------------------------------------------------------

void            TreapMap::insert(const std::string &key, const std::string &value) {
     root = insert_treap(root, key, value);
}

const Entry     TreapMap::search(const std::string &key) {
    auto result = search_treap(root, key);
    return (result == nullptr ? NONE : result->entry);
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_treap(root, os, flag);
}

int             TreapMap::getMaxTreeHeight(){
    int max = max_height(root); 
    return max;
}


int             TreapMap::getMinTreeHeight(){
    int min = min_height(root);
    return min; 
}

void            TreapMap::preOrderTraversal(){
    traversal(root);
    cout << endl;   
}


void dump_treap(Node *node, std::ostream &os, DumpFlag flag) {
    if (node == nullptr) {
        return;
    }

    dump_treap(node->right, os, flag);
    switch (flag) {
        case DUMP_KEY:          os << node->entry.first  << std::endl; break;
        case DUMP_VALUE:        os << node->entry.second << std::endl; break;
        case DUMP_KEY_VALUE:    os << node->entry.first  << "\t" << node->entry.second << std::endl; break;
        case DUMP_VALUE_KEY:    os << node->entry.second << "\t" << node->entry.first  << std::endl; break;
    }
    dump_treap(node->left, os, flag);
}


Node *search_treap(Node *node, const std::string &key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->entry.first == key) {
        return node;
    }

    if (node->entry.first > key) {
        return search_treap(node->left, key);
    } else {
        return search_treap(node->right, key);
    }
}

Node *insert_treap(Node *node, const std::string &key, const std::string &value) {
    if (node == nullptr) {
        return new Node{Entry(key, value), get_random(), nullptr, nullptr};
    }

    if (node->entry.first > key) {
        node->left = insert_treap(node->left, key, value);
        if ((node->left)->priority > node->priority) {
            node = RotateRight(node);
        }
    } 
    if (node->entry.first < key) {
        node->right = insert_treap(node->right, key, value);
        if ((node->right)->priority > node->priority) {
            node = RotateLeft(node);
        }
    }
    if (node->entry.first == key) {
        node->entry.second = value;
    }

    return node;
}

Node *RotateRight(Node *node) {
    Node *n2 = node->left;
    Node *n3 = n2->right;
    n2->right = node;
    node->left = n3;
    return n2;
}

Node *RotateLeft(Node *node) {
    Node *n2 = node->right;
    Node *n3 = n2->left;
    n2->left = node;
    node->right = n3;
    return n2;
}

void traversal(Node *node) {
    if (node == nullptr) {
        return;
    }
    cout << node->entry.second << " ";
    traversal(node->left);
    traversal(node->right);
}

int max_height(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    int left_height = max_height(node->left);
    int right_height = max_height(node->right);
    return (max(left_height, right_height) + 1);
}

int min_height(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    int left_height = min_height(node->left);
    int right_height = min_height(node->right);
    return (min(left_height, right_height) + 1);
}

int get_random() {
    static std::random_device               rd;
    static std::default_random_engine   g(rd());
    static std::uniform_int_distribution<>  d(1, INT_MAX);
    return d(g);
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
