#pragma once
#include <string>
#include <vector>

const int MAX_CHAR = 128;
const char DATA_DELIMITER = ',';

struct trieNode {
  std::string data;
  int routerNumber;
  trieNode* children[MAX_CHAR];
  bool isEndOfString;
};

typedef struct trieNode TrieNode;

class PrefixMatcher {
private:
  TrieNode* head;
  void doTraverse(TrieNode* pRoot, std::vector<std::string>& trieData);
  bool isLastNode(TrieNode* pNode);
  void doGetSuggestions(TrieNode* pRoot, std::string particalString, std::vector<std::string>& trieData);
  void doGetSuggestions(TrieNode* pRoot, std::string particalString, std::vector<std::string>& trieData, bool includingMatchingPrefix);
  TrieNode* createNode(std::string data);
  bool isEmpty();
  bool insertString(std::string stringValue);
  bool insertString(std::string stringValue, int routerNumber);
  bool search(std::string stringValue);
  std::vector<std::string> traverse(void);
  std::vector<std::string> getMatchingStrings(std::string partialString);
  std::vector<std::string> getMatchingStrings(std::string partialString, bool includingMatchingPrefix);

public:
  PrefixMatcher();
  ~PrefixMatcher();

  void insert(std::string address, int routerNumber);
  int selectRouter(std::string networkAddress);
  std::vector<std::string> getRouters(std::string networkAddress);
};

