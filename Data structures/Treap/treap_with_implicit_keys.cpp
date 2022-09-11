#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));

struct node
{
    node *left, *right;
    int x, y, size;
    node(int val) {
        x = val;
        y = rnd();
        left = right = nullptr;
        size = 1;
    }
};
 
int get_sz(node* root) {
    if (root == nullptr) return 0;
    return root->size;
}
 
void recalc(node* &root) {
    if (root != nullptr)root->size = get_sz(root->left) + get_sz(root->right) + 1;
}
 
node *merge(node *l, node *r){
    if(l == nullptr){
        return r;
    }
    if(r == nullptr){
        return l;
    }
    if(l->y > r->y){
        l->right = merge(l->right, r);
        recalc(l);
        return l;
    }
    r->left = merge(l, r->left);
    recalc(r);
    return r;
}
 
pair<node*, node*> split(node *root, int k){
    if(root == nullptr){
        return {nullptr, nullptr};
    }
    int key = get_sz(root->left);
    if (key >= k) {
        auto e = split(root->left, k);
        root->left = e.second;
        recalc(root);
        return {e.first, root};
    }
    auto e = split(root->right, k - key - 1);
    root->right = e.first;
    recalc(root);
    return {root, e.second};
}
 
void print(node* root) {
    if (root == nullptr) return;
    print(root->left);
    cout << root->x << ' ';
    print(root->right);
}


int main() {
    return 0;
}