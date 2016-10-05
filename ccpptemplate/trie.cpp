/*edit by tfans 2016-10-05*/
#include<cstdio>
#include<iostream>
using namespace std;

struct TrieNode{
	int val;
	TrieNode* next[26];
	TrieNode() : val(0){
		for(int i=0; i<26; i++) next[i]=NULL;
	}
};

class Trie{
private:
	TrieNode* root;

public:
	Trie(){ root=new TrieNode();}
	
	void insert(string word){
		if(search(word)) return ;
		TrieNode* now=root;
		for(int i=0; i<word.size(); i++){
			int c=word[i]-'a';
			if(now->next[c] == NULL) {
				now->next[c]=new TrieNode();
			}
			now=now->next[c];
		}
		now->val=true;
	}
	
	//return if the word exists in the trie.
	bool search(string word){
		TrieNode* now=root;
		for(int i=0; i<word.size(); i++){
			int c=word[i]-'a';
			if(now->next[c] == NULL) {
				return false;			
			}
			now=now->next[c];
		}
		return now->val;
	}

	// Returns if there is any word in the trie
    // that starts with the given prefix.
	bool startsWith(string prefix){
		TrieNode* now=root;
		for(int i=0; i<prefix.size(); i++){
			int c=prefix[i]-'a';
			if(now->next[c] == NULL) {
				return false;			
			}
			now=now->next[c];
		}
		return true;
	}
};

int main()
{
	Trie trie;
	trie.insert("something");
	cout<<trie.search("some")<<endl;
	cout<<trie.search("something")<<endl;
	cout<<trie.startsWith("some")<<endl;
	cout<<trie.startsWith("someh")<<endl;
	
	return 0;
}

