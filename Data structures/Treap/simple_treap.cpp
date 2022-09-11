#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
mt19937 rnd(time(0));
#define second second
// in split: left < k, right >= k
struct node{
    int x, y;
    node *left, *right;
 
    node(int val){
        x = val;
        y = rnd();
        left = right = nullptr;
    }
};
 
node *merge(node *l, node *r){
    if(l == nullptr){
        return r;
    }
    if(r == nullptr){
        return l;
    }
    if(l->y > r->y){
        l->right = merge(l->right, r);
        return l;
    }
    r->left = merge(l, r->left);
    return r;
}
 
pair<node*, node*> split(node *root, int x){
    if(root == nullptr){
        return {nullptr, nullptr};
    }
    if(root->x >= x){
        auto res = split(root->left, x);
        root->left = res.second;
        return {res.first, root};
    }
    auto res = split(root->right, x);
    root->right = res.first;
    return {root, res.second};
}
 
bool exists(node* a, int k) {
    if (a == nullptr) return false;
    if (a->x == k) return true;
    if (a->x < k) return exists(a->right, k);
    return exists(a->left, k);
}
 
node *insert(node *root, int x){
    if (exists(root,x)) return root;
    auto trees = split(root, x);
    node *nw = new node(x);
    return merge(trees.first, merge(nw, trees.second));
}
 
node *erase(node *root, int x){
    auto trees = split(root, x);
    trees.second = split(trees.second, x + 1).second;
    return merge(trees.first, trees.second);
}
 
int get_min(node* a) {
    if (a == nullptr) return inf;
    if (a->left == nullptr) return a->x;
    return get_min(a->left);
}
 
int get_max(node *a){
    if(a == nullptr)return -inf;
    if(a->right == nullptr)return a->x;
    return get_max(a->right);
}
 
int next(node *root, int x){
    auto trees = split(root, x + 1);
    int res = get_min(trees.second);
    merge(trees.first, trees.second);
    return res;
}
 
int prev(node *root, int x){
    auto trees = split(root, x);
    int res = get_max(trees.first);
    merge(trees.first, trees.second);
    return res;
}

signed main()
{
    node* root = new node(0);
    return 0;  
}