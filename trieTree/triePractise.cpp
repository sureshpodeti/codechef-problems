#include<iostream>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};


struct TrieNode *getNode(){
    //factory to create the TrieNode with initial values
    struct TrieNode *node = new struct TrieNode;
    node->isEndOfWord = false;


    for(int i=0;i<ALPHABET_SIZE;++i)
        node->children[i] = NULL;

    return node;

};

void insertKey(struct TrieNode *root, string key){
    struct TrieNode *tempNode = root;

    for(int i=0;i<key.length(); ++i){
        int index = key[i] - 'a';
        if(tempNode->children[index]==NULL)
            tempNode->children[index] = getNode();
        // showing pointing to next node is presence of a character
        tempNode = tempNode->children[index];

    }
    //finally mark the leaf node as end of the word
    tempNode->isEndOfWord = true;
}


bool searchKey(struct TrieNode *root, string key){
    struct TrieNode *tempNode = root;

    for(int i=0;i<key.length();++i){
        int index = key[i] - 'a';
        if(tempNode->children[index]==NULL)
            return false;
        tempNode = tempNode->children[index];
    }

    return (tempNode!=NULL && tempNode->isEndOfWord);
}



int main(){

    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = getNode();

    for(int i=0;i<n;++i)
        insertKey(root, keys[i]);

    if(searchKey(root, "the"))
        cout << "found" << endl;
    else cout << "not found" << endl;

    if(searchKey(root, "these"))
        cout << "found" << endl;
    else cout << "not found" << endl;



    return 0;
}
