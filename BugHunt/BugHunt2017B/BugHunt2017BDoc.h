
// BugHunt2017BDoc.h : CBugHunt2017BDoc 类的接口
//


#pragma once

#include <vector>
#include "Bug.h"
#include "Frog.h"

class CBugHunt2017BDoc : public CDocument
{
	friend class CBugHunt2017BView;


protected: // 仅从序列化创建
	CBugHunt2017BDoc();
	DECLARE_DYNCREATE(CBugHunt2017BDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
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

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
