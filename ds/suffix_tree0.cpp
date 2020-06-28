#include<iostream>

using namespace std;
const int ALPHABETS_COUNT = 26;

struct TrieNode{
  struct TrieNode *childrens[ALPHABETS_COUNT];
  bool is_endof_word;
};


struct TrieNode *GetNode(){
  struct TrieNode *tmp_node = new TrieNode;
  for(int i=0;i<ALPHABETS_COUNT;++i)
    tmp_node->childrens[i] = NULL;
  tmp_node->is_endof_word = false;

  return tmp_node;
}


void InsertKey(struct TrieNode *root, string key){
  struct TrieNode *tmp_node = root;
  for(int i=0;i<key.length();++i){
    int index = key[i] - 'a';
    if(tmp_node->childrens[index]==NULL){
      tmp_node->childrens[index] = GetNode();
    }

    tmp_node = tmp_node->childrens[index];
  }

  tmp_node->is_endof_word = true;
}


bool SearchKey(struct TrieNode *root, string key){
  struct TrieNode *tmp_node = root;

  for(int i=0;i<key.length();++i){
    int index = key[i] - 'a';
    if(tmp_node->childrens[index] == NULL)
      return false;
    tmp_node = tmp_node->childrens[index];
  }

  return (tmp_node!=NULL && tmp_node->is_endof_word);
}
int main(){
  string keys[] = {"banana", "anana", "nana", "ana", "na", "a"};

  int n = sizeof(keys)/sizeof(keys[0]);

  struct TrieNode *root = GetNode();

  for(int i=0;i<n;++i){
    InsertKey(root, keys[i]);
  }

  cout << SearchKey(root, "banana") << endl;
  

  return 0;
}
