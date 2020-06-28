
#include<iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};


struct TrieNode *getNode(){
    struct TrieNode *trieNode = new TrieNode;
    trieNode->isEndOfWord = false;
    for(int i=0;i<ALPHABET_SIZE;++i)
        trieNode->children[i] = nullptr;

    return trieNode;

}

void insertKey(struct TrieNode *root, string key){
    TrieNode *tempRoot = root;

    for(int i=0;i<key.length();++i){
        int index = key[i] - 'a';
        if(!tempRoot->children[index]){
            tempRoot->children[index] = getNode();
        }
        tempRoot = tempRoot->children[index];
    }
    tempRoot->isEndOfWord = true;
}

bool searchKey(struct TrieNode *root, string key){
    struct TrieNode *tempRoot = root;
    for(int i=0;i<key.length();++i){
        int index = key[i] - 'a';
        if(!tempRoot->children[index]){
            return false;
        }

        tempRoot = tempRoot->children[index];
    }

    return (tempRoot!=nullptr && tempRoot->isEndOfWord);

}

int main(){
    string keys[] = {"the", "a", "three", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(string);

    struct TrieNode *root = getNode();
    for(int i=0;i<n;++i){
            insertKey(root, keys[i]);
    }


    cout << searchKey(root, "answer") << endl;



    return 0;
}
