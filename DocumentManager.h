#pragma once

#include <string>
#include <set>
#include <map>

typedef struct {
  int license_limit;
  int loan_count;
} DocumentInfoT;

class DocumentManager {
private:
  std::set<int> m_patronSet;
  std::map<std::string, int> m_documentSearchMap;
  std::map<int, DocumentInfoT> m_documentInfoMap;

public:
  DocumentManager();
  ~DocumentManager();

  void addDocument(std::string name, int id, int license_limit);
  void addPatron(int patronID);
  int search(std::string name);
  bool borrowDocument(int docid, int patronID);
  void returnDocument(int docid, int patronID);
};

