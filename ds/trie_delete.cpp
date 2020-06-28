#include<iostream>

using namespace std;


struct TrieNode *GetNode();
void InsertKey(struct TrieNode*, string);
bool SearchKey(struct TrieNode*, string);
bool IsEmpty(struct TrieNode*);

struct TrieNode *RemoveKey(struct TrieNode*, string, int);

const int ALPHABETS_COUNT = 26;
struct TrieNode{
  struct TrieNode *childrens[ ALPHABETS_COUNT];
  bool is_end_of_word;

};


struct TrieNode *GetNode(){
  struct TrieNode *root = new TrieNode;

  for(int i=0;i<ALPHABETS_COUNT;++i)
    root->childrens[i] = NULL;

  root->is_end_of_word = false;

  return root;

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
  tmp_node->is_end_of_word = true;
}


bool SearchKey(struct TrieNode *root, string key){
  struct TrieNode *tmp_node = root;
  for(int i=0;i<key.length();++i){
    int index = key[i] - 'a';
    if(tmp_node->childrens[index] == NULL)
      return false;
    tmp_node = tmp_node->childrens[index];
  }
  return (tmp_node != NULL && tmp_node->is_end_of_word);
}

bool IsEmpty(struct TrieNode *root){
  for(int i=0;i<ALPHABETS_COUNT;++i){
    if(root->childrens[i]!=NULL){
      return false;
    }
  }

  return true;

}
struct TrieNode *RemoveKey(struct TrieNode *root, string key, int i=0){
  // base cases
  if(root==NULL)
    return root;


  if(i==key.length()){

    if(root->is_end_of_word){
      root->is_end_of_word = false;
    }

    if(IsEmpty(root)){
      delete(root);
      root = NULL;
    }

    return root;

  }


  int index = key[i] - 'a';

  root->childrens[index] = RemoveKey(root->childrens[index], key, i+1);


  if(IsEmpty(root) && root->is_end_of_word==false){
    delete(root);
    root = NULL;
  }

  return root;
    
}

int main(){

  string keys[] = { "the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane" }; 
    int n = sizeof(keys) / sizeof(keys[0]);
  
  struct TrieNode *root = GetNode();

  for(int i=0;i<n;++i)
    InsertKey(root, keys[i]);


  // Search for different keys 
    SearchKey(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    SearchKey(root, "these") ? cout << "Yes\n" : cout << "No\n"; 
  
    RemoveKey(root, "heroplane", 0); 
    SearchKey(root, "hero") ? cout << "Yes\n" : cout << "No\n";
    SearchKey(root, "heroplane") ? cout << "Yes\n" : cout << "No\n"; 
    

  

  return 0;
}
