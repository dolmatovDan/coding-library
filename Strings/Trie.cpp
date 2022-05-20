#include <bits/stdc++.h>
using namespace std;
const int k = 26;

struct node {
    node* to[k];
    bool terminal = 0;
};

void add(node* root, string &s) {
    auto v = root;
    for (char c : s) {
        int c1 = c - 'a';
        if (v->to[c1] == nullptr) {
            v->to[c1] = new node();
        }
        v = v->to[c1];
    }
    v->terminal = true;
}
bool find(node* root, string &s) {
    auto v = root;
    for (char c : s) {
        int c1 = c - 'a';
        if (v->to[c1] == nullptr) {
            return false;
        }
        v = v->to[c1];
    }
    return v->terminal;
}
void erase(node* root, string &s) {
    auto v = root;
    for (char c : s) {
        v = v->to[c - 'a'];
    }
    v->terminal = false;
}
int main() {
    node *root = new node();
    return 0;
}