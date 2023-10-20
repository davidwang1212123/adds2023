#include <string>
#include "DocumentManager.h"
using namespace std;

DocumentManager::DocumentManager() {
  m_patronSet.clear();
  m_documentSearchMap.clear();
  m_documentInfoMap.clear();
}

DocumentManager::~DocumentManager() {}

void DocumentManager::addDocument(string name, int id, int license_limit) {
  // validate parameters
  if (license_limit <= 0)
    return;

  string nameLC;
  nameLC.clear();

  for (int i = 0; i < name.size(); i++) {
    nameLC.push_back(tolower(name.at(i)));
  }

  map<string, int>::iterator itr1 = m_documentSearchMap.end();
  map<int, DocumentInfoT>::iterator itr2 = m_documentInfoMap.end();

  itr1 = m_documentSearchMap.find(nameLC);
  itr2 = m_documentInfoMap.find(id);

  // either the document name or id already exists
  if ((itr1 != m_documentSearchMap.end()) || (itr2 != m_documentInfoMap.end()))
    return;

  m_documentSearchMap.insert(pair<string, int>(nameLC, id));
  
  DocumentInfoT documentInfo;
  documentInfo.license_limit = license_limit;
  documentInfo.loan_count = 0;

  m_documentInfoMap.insert(pair<int, DocumentInfoT>(id, documentInfo));
}

void DocumentManager::addPatron(int patronID) {
  if (patronID > 0)
    m_patronSet.insert(patronID);
}

int DocumentManager::search(string name) {
  string nameLC;
  nameLC.clear();

  for (int i = 0; i < name.size(); i++) {
    nameLC.push_back(tolower(name.at(i)));
  }

  map<string, int>::iterator itr = m_documentSearchMap.find(nameLC);
  if (itr == m_documentSearchMap.end())
    return 0;
  else
    return itr->second;
}

bool DocumentManager::borrowDocument(int docID, int patronID) {
  map<int, DocumentInfoT>::iterator itrDocumentInfo = m_documentInfoMap.find(docID);
  if (itrDocumentInfo == m_documentInfoMap.end())
    return false;

  set<int>::iterator itrPatron = m_patronSet.find(patronID);
  if (itrPatron == m_patronSet.end())
    return false;

  if (itrDocumentInfo->second.loan_count == itrDocumentInfo->second.license_limit)
    return false;
  else
  {
    itrDocumentInfo->second.loan_count++;
    return true;
  }
}

void DocumentManager::returnDocument(int docID, int patronID) {
  map<int, DocumentInfoT>::iterator itrDocumentInfo = m_documentInfoMap.find(docID);
  if (itrDocumentInfo == m_documentInfoMap.end())
    return;

  set<int>::iterator itrPatron = m_patronSet.find(patronID);
  if (itrPatron == m_patronSet.end())
    return;

  if (itrDocumentInfo->second.loan_count <= 0)
    return;
  else
    itrDocumentInfo->second.loan_count--;
}
