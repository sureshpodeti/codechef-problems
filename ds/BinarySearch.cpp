
#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        Node(int);
};

Node::Node(int num){
    data = num;
}

Node *insert(Node *root, int num){
    if(root==nullptr){
        //create the node
        root = new Node(num);
        root->left = nullptr;
        root->right = nullptr;
    }else if(root->data > num){
        // insert left side
        root->left = insert(root->left, num);
    }else{
        root->right = insert(root->right, num);
    }
    return root;

}


void preorderTraversal(Node *t){
    if(t==nullptr) return;
    cout << t->data << " ";
    //traverse left
    preorderTraversal(t->left);
    //traverse right
    preorderTraversal(t->right);

}


void inorderTraversal(Node *t){
    if(t==nullptr) return;

    //traverse left
    inorderTraversal(t->left);
    cout << t->data << " ";
    //traverse right
    inorderTraversal(t->right);

}

void postorderTraversal(Node *t){
    if(t==nullptr) return;

    //traverse left
    postorderTraversal(t->left);
    //traverse right
    postorderTraversal(t->right);
    cout << t->data << " ";


}

int main(){
    int n, a;
    cin >> n;

    Node *root = nullptr;

    while(n--){
        cin >> a;
        root = insert(root, a);
    }

    Node *t = root;

    preorderTraversal(t);
    cout << endl;

    inorderTraversal(t);
    cout << endl;


    postorderTraversal(t);
    cout << endl;



    return 0;
}
