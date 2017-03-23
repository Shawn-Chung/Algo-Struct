#include <ctime>

namespace lt{

int random(int start, int end);

int TestList();



typedef int ElmType;
// 单向链表结构
struct TSlist{
	ElmType data;
	TSlist *next;
};
//双向链表结构
struct TDlist
{
	ElmType data;
	TDlist *rlink;
	TDlist *llink;
};
//链表操作虚基类
class CList
{
public:
	virtual void initialize() = 0; //初始化，创建头
	virtual bool isEmpty() = 0; //是否为空
	virtual int count() = 0; //节点数
	virtual void output() = 0; //输出所有节点数据
	virtual void push_back(ElmType val) = 0; //尾部插入
	virtual void push_front(ElmType val) = 0; //头部插入
    virtual void insert(int pos, ElmType val) = 0; //插入pos处
	virtual void remove(int pos) = 0; //删除pos处的节点
};


//单链表
class CSlist : public CList
{
public:
	CSlist() :m_pHeader(NULL){ initialize(); }

	virtual void initialize();
	virtual int count();
	virtual bool isEmpty(){ return (NULL == m_pHeader->next); }
	virtual void output();
	virtual void push_back(ElmType val);
	virtual void push_front(ElmType val);
	virtual void insert(int pos, ElmType val);
    virtual void remove(int pos);

private:
	TSlist *m_pHeader;
};
//单向循环链表
class CCSlist : public CList
{
	virtual void initialize();
	TSlist *m_pHeader;
};
//双向链表
class CDlist : public CList
{

};
//双向循环链表
class CCDlist : public CList
{

};









}


