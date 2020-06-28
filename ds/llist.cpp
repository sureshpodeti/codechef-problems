#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int);
};


Node::Node(int num){
    data = num;
}
Node *insert(Node *root, int num){
    if(root==nullptr){
        //create the node
        root = new Node(num);
        root->next = nullptr;
    }else
        root->next = insert(root->next, num);

    return root;

}


void display(Node *root){
    Node *t;
    t = root;

    while(t!=nullptr){
            cout << t->data << " ";
            t = t->next;
    }
    cout << endl;


}

void reverseDisplay(Node *t){

    if(t==nullptr) return;
    reverseDisplay(t->next);
    cout << t->data << endl;
}
int main(){
    Node *root = nullptr;
    int a;
    for(int i=0;i<6;++i){
        cin >> a;
        root = insert(root, a);
    }

    Node *t = root;
    reverseDisplay(t);

    display(root);


    return 0;
}
