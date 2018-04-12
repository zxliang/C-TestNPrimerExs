#ifndef MYTRIE_H
#define MYTRIE_H

using namespace std;

class TrieNode {
public:
  TrieNode* next[26];
  bool isEnd;

  TrieNode(bool mark = false) {
	isEnd = mark;
	memset(next, 0, sizeof(next));
  }
};

class Trie {
private:

  TrieNode* root;
  void clear(TrieNode* root) {
	for (int i = 0; i < 26; i++) {
	  if (root->next[i] != nullptr)
		clear(root->next[i]);
	}
	delete(root);
  }

  TrieNode* findString(string word) {
	TrieNode* temp = root;
	for (int i = 0; i < word.size(); i++) {
	  if (temp->next[word[i] - 'a'] != nullptr)
		temp = temp->next[word[i] - 'a'];
	  else {
		temp = nullptr;
		break;
	  }
	}
	return temp;
  }

public:
  Trie() {
	root = new TrieNode();
  }

  ~Trie() {
	clear(root);
  }

  void insert(string word) {
	TrieNode* temp = root;
	for (int i = 0; i < word.size(); i++) {
	  if (temp->next[word[i] - 'a'] == nullptr)
		temp->next[word[i] - 'a'] = new TrieNode();
	  temp = temp->next[word[i] - 'a'];
	}
	temp->isEnd = true;
  }

  bool search(string word) {
	TrieNode* temp = findString(word);
	if (temp != nullptr && temp->isEnd == true)
	  return true;
	return false;
  }

  bool startWith(string prefix) {
	TrieNode* temp = findString(prefix);
	if (temp != nullptr)
	  return true;
	return false;
  }
};


#endif //!MYTRIE_H