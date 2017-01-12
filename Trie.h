#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
#include <vector>

class TNode {
  std::string value;
  bool isCompleteWord;
  std::unordered_map<char, TNode *> children;
public:
  TNode() : value(""), isCompleteWord(false) { }
  TNode(std::vector<char> aSet, std::string val, bool isComplete) 
    : value(val), isCompleteWord(isComplete) {
    for(int i = 0; i < aSet.size(); i++) {
      children[aSet[i]] = NULL;
    }
  }
  void setValue(std::string vv)                         { value = vv; }
  void setIsComplete(bool isComplete)              { isCompleteWord = isComplete; }
  void setChild(char index, TNode *val)            { children[index] = val; }
  void setChildren(std::unordered_map<char, TNode *> newChildren) { children = newChildren; }
  TNode *getChild(char index)                      { return children[index]; }
  std::string getValue()                                { return value; }
  bool isWord() const                          { return isCompleteWord; }
};

class Trie {
  TNode *root;
  std::vector<char> alphabetSet;
  int count;
public:
  Trie() {
    // Default character set 
    for(char i = 'a'; i <= 'z'; i++)
      alphabetSet.push_back(i);
    root = new TNode(alphabetSet, std::string(""), false);
  }
  Trie(std::vector<char> aSet) {
    alphabetSet = aSet;
    root = new TNode(alphabetSet, std::string(""), false);
  }
  void add(std::string item) {
    TNode *curNode = root;

    for(int i = 0; i < item.length(); i++) {
      if(!curNode->getChild(item[i])) {
        TNode *newNode = new TNode(alphabetSet, item.substr(0, i+1), i == item.length()-1);
        curNode->setChild(item[i], newNode);
      }
      curNode = curNode->getChild(item[i]);
    }
  }
  bool checkIfExists(std::string item) {
    TNode *curNode = root;

    for(int i = 0; i < item.length(); i++) {
      if(!curNode->getChild(item[i]))
        return false;
      curNode = curNode->getChild(item[i]);
    }
    return true;
  }
  int findPartially(std::string item) {
    TNode *curNode = root;

    // Get to the last Node
    for(int i = 0; i< item.length()-1; i++) {
      if(!curNode->getChild(item[i]))
        return 0;
      curNode = curNode->getChild(item[i]);
    }
    return getPossibleWords(curNode);
  }
  int getPossibleWords(TNode *curNode) {
    if(!curNode)
      return 0;
    int totalWords = 0;
    for(int i = 0; i < alphabetSet.size(); i++) {
      if(curNode->getChild(alphabetSet[i])) {
        totalWords += getPossibleWords(curNode->getChild(alphabetSet[i]));
      }
    }

    if(curNode->isWord())
      totalWords++;
    return totalWords;
  }
};

#endif
