
// BugHunt2017BDoc.h : CBugHunt2017BDoc ��Ľӿ�
//


#pragma once

#include <vector>
#include "Bug.h"
#include "Frog.h"

class CBugHunt2017BDoc : public CDocument
{
	friend class CBugHunt2017BView;


protected: // �������л�����
	CBugHunt2017BDoc();
	DECLARE_DYNCREATE(CBugHunt2017BDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CBugHunt2017BDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:		// DID
	CImage m_bmpBackgrang;
	std::vector<Bug*> m_listBug;		
	std::vector<Frog*> m_listFrog;
	// std::vector<Frog*> m_listMFrog;

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
