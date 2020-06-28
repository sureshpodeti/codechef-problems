#include<iostream>
using namespace std;

void InsertKey(struct TrieNode*, string);
int GetIndex(char);
bool SearchKey(struct TrieNode*, string);


const int ALPHABETS_COUNT = 26; 

struct TrieNode{
  struct TrieNode *childrens[ALPHABETS_COUNT];
  bool isEndOfWord;
};


struct TrieNode *GetNode(){
  struct TrieNode *tmp_node = new TrieNode;
  for(int i=0;i<ALPHABETS_COUNT;++i)
    tmp_node->childrens[i] = NULL;
  tmp_node->isEndOfWord = false;

  return tmp_node;
}


void InsertKey(struct TrieNode *root, string key){
  struct TrieNode *tmp_node = root;

  for(int i=0;i<key.length();++i){
    int index = GetIndex(key[i]);

    if(tmp_node->childrens[index] == NULL){
      tmp_node->childrens[index] = GetNode();
    }
    tmp_node = tmp_node->childrens[index];
  }

  // put the endofword status
  tmp_node->isEndOfWord = true;

  
}

int GetIndex(char c){
  return c-'a';
}

bool SearchKey(struct TrieNode *root, string key){
  struct TrieNode *tmp_node = root;

  for(int i=0;i<key.length();++i){
    int index = GetIndex(key[i]);

    if(tmp_node->childrens[index] == NULL)
      return false;

	tmp_node = tmp_node->childrens[index];

  }
  

  return (tmp_node!=NULL && tmp_node->isEndOfWord);

}


void RemoveKey(struct TrieNode *root, string key){




}

int main(){
  
  string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  struct TrieNode *root = GetNode();
  int n = sizeof(keys)/sizeof(string);
  for(int i=0;i<n;++i){
    InsertKey(root, keys[i]);
  }
  
  cout << SearchKey(root, "Answer") << endl;
  cout << SearchKey(root, "answer") << endl;
  

  return 0;
}
