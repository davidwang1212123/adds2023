//#include <iostream>
#include "PrefixMatcher.h"
using namespace std;

PrefixMatcher::PrefixMatcher()
{
  head = createNode("");
}

PrefixMatcher::~PrefixMatcher()
{
}

void PrefixMatcher::insert(string address, int routerNumber)
{
  insertString(address, routerNumber);
}

int PrefixMatcher::selectRouter(string networkAddress)
{
  vector<string> routerList = getRouters(networkAddress);
  
  if (routerList.size() <= 0)
    return -1;

  int index;
  string currNetworkAddress;
  int currNetworkAddressLen;
  int currRouterNumber;

  
  int selectedNetworkAddressLen = 0;
  int selectedRouterNumber = -1;
  string selectedNetworkAddress;

  char ch = DATA_DELIMITER;

  for (int i = 0; i < routerList.size(); i++)
  {
    index = routerList.at(i).find(ch);
    currNetworkAddress = routerList.at(i).substr(0, index);
    currRouterNumber = stoi(routerList.at(i).substr(index + 1, routerList.at(i).length() - index - 1));

    //cout << currNetworkAddress << ": " << currRouterNumber << endl;

    currNetworkAddressLen = currNetworkAddress.length();
    if (currNetworkAddressLen == networkAddress.length())
    {
      //cout << "selectedRounterNumber: " << currRouterNumber << ", " << currNetworkAddress << endl;
      return currRouterNumber;
    }
    
    if (currNetworkAddressLen > selectedNetworkAddressLen)
    {
      selectedNetworkAddressLen = currNetworkAddress.length();
      selectedRouterNumber = currRouterNumber;
      selectedNetworkAddress = currNetworkAddress;
    }
  }

  //cout << "selectedRounterNumber: " << selectedRouterNumber << ", " << selectedNetworkAddress << endl;

  return selectedRouterNumber;
}

vector<string> PrefixMatcher::getRouters(string networkAddress)
{
  vector<string> routerList = getMatchingStrings(networkAddress, true);
  return routerList;
}

TrieNode* PrefixMatcher::createNode(string data)
{
  TrieNode* pTrieNode = new TrieNode;
  pTrieNode->data = data;
  pTrieNode->routerNumber = -1;
  pTrieNode->isEndOfString = false;

  for (int i = 0; i < MAX_CHAR; i++)
    pTrieNode->children[i] = nullptr;

  return pTrieNode;
}

bool PrefixMatcher::isEmpty()
{
  if (head == nullptr)
    return true;

  for (int i = 0; i < MAX_CHAR; i++)
    if (head->children[i] != nullptr)
      return false;

  return true;
}

bool PrefixMatcher::insertString(string stringValue)
{
  return insertString(stringValue, -1);
}

bool PrefixMatcher::insertString(string stringValue, int routerNumber)
{
  TrieNode* pCurrNode = head;
  int index = 0;

  for (int i = 0; i < stringValue.length(); i++)
  {
    index = stringValue[i];

    if (pCurrNode->children[index] == nullptr)
      pCurrNode->children[index] = createNode(stringValue.substr(0, i + 1));

    pCurrNode = pCurrNode->children[index];
  }

  pCurrNode->isEndOfString = true; // indicate this is the end of string
  pCurrNode->routerNumber = routerNumber; // record the routerNumber on the leaf node

  return true;
}

bool PrefixMatcher::search(string stringValue)
{
  TrieNode* pCurrNode = head;
  int index = 0;

  for (int i = 0; i < stringValue.length(); i++)
  {
    index = stringValue[i];

    if (pCurrNode->children[index] == nullptr)
      return false;

    pCurrNode = pCurrNode->children[index];
  }

  return ((pCurrNode != nullptr) && pCurrNode->isEndOfString);
}

vector<string> PrefixMatcher::traverse(void)
{
  vector<string> result;

  doTraverse(head, result);

  return result;
}

void PrefixMatcher::doTraverse(TrieNode* pRoot, vector<string>& trieData)
{
  if (pRoot == nullptr)
    return;

  TrieNode* pCurr = pRoot;
  trieData.push_back(pCurr->data);
  if (pCurr->isEndOfString)
    trieData.push_back("isEndOfString: true; routerNumber: " + to_string(pCurr->routerNumber));
  else
    trieData.push_back("isEndOfString: false; routerNumber: " + to_string(pCurr->routerNumber));

  for (int i = 0; i < MAX_CHAR; i++)
  {
    doTraverse(pCurr->children[i], trieData);
  }
}

bool PrefixMatcher::isLastNode(TrieNode* pNode)
{
  for (int i = 0; i < MAX_CHAR; i++)
    if (pNode->children[i] != nullptr)
      return false;

  return true;
}

vector<string> PrefixMatcher::getMatchingStrings(string partialString)
{
  return getMatchingStrings(partialString, false);
}

vector<string> PrefixMatcher::getMatchingStrings(string partialString, bool includingMatchingPrefix)
{
  vector<string> suggestions;
  TrieNode* pCurrNode = head;
  int index;

  for (char ch : partialString)
  {
    index = ch;

    // no word has this prefix
    if (pCurrNode->children[index] == nullptr)
      return suggestions;

    pCurrNode = pCurrNode->children[index];

    if ((pCurrNode->isEndOfString) && includingMatchingPrefix)
      suggestions.push_back(pCurrNode->data + DATA_DELIMITER + to_string(pCurrNode->routerNumber));
  }

  // If partialWord is present as a word, and there is
  // no children
  if (isLastNode(pCurrNode))
  {
    if (!includingMatchingPrefix)
      suggestions.push_back(partialString);

    return suggestions;
  }

  doGetSuggestions(pCurrNode, partialString, suggestions, includingMatchingPrefix);

  return suggestions;
}

void PrefixMatcher::doGetSuggestions(TrieNode* pRoot, string partialString, vector<string>& suggestions)
{
  doGetSuggestions(pRoot, partialString, suggestions, false);
}

void PrefixMatcher::doGetSuggestions(TrieNode* pRoot, string partialString, vector<string>& suggestions, bool includingMatchingPrefix)
{
  string s;

  if (pRoot->isEndOfString)
  {
    if (!includingMatchingPrefix)
      suggestions.push_back(partialString);
    else
    {
      s = partialString + DATA_DELIMITER + to_string(pRoot->routerNumber);
      if (find(suggestions.begin(), suggestions.end(), s) == suggestions.end())
        suggestions.push_back(s);
    }
  }

  for (int i = 0; i < MAX_CHAR; i++)
    if (pRoot->children[i] != nullptr)
    {
      // child node character value
      //char child = 'a' + i;
      char child = i;

      doGetSuggestions(pRoot->children[i], partialString + child, suggestions, includingMatchingPrefix);
    }
}
