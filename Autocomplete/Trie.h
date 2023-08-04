#pragma once

#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 256;

// ��������� ����� ������ 
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, ���� ���� �������� ������ �����
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
vector<string> finisher(struct TrieNode* root, string key);
void finder(struct TrieNode* node, string& buffer, vector<string>& result, int& depth);
