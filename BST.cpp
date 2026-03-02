#include <iostream>


template<typename Key,typename Value>
class BST {
    private:
    struct Node {
        Key key;
        Value val;
        Node* left;
        Node* right;
        int n;
        Node(Key k,Val v) : key(k),val(v),left(nullptr),right(nullptr) {}
    };
    Node* root;
    public:
    void put(Key key,Value val) {
        put(root,key,val);
    }
    Node* put(Node* temp, Key k, Value v) {
        if(!temp) {
            temp = new Node(k,v);
            return;
        }
        if(temp->left->k > k) {
            temp->left = put(temp->left,k,v);
        }
        else if(temp->right < k) {
            temp->right = put(temp->right,k,v);
        }
        else if(temp->key == k) {
            temp.val = v;
        }
        return x;
    }
    Value& get(const Key& key) {
        Node* temp = root;
        while(temp) {
            if(key > temp->key) temp = temp->right;
            else if(key < temp->key) temp = temp->left;
            else return x->val;
        }
        throw std::runtime_error("Value not found");
    }
    Value& operator[](Key key) {
        if(!root) {
            root = new Node(key)
        }
    }
};

int main() {
    std::cout << "pepeLaugh";
    return 0;
}