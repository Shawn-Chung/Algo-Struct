#include <ctime>

namespace lt{

int random(int start, int end);

int TestList();



typedef int ElmType;
// ��������ṹ
struct TSlist{
	ElmType data;
	TSlist *next;
};
//˫������ṹ
struct TDlist
{
	ElmType data;
	TDlist *rlink;
	TDlist *llink;
};
//������������
class CList
{
public:
	virtual void initialize() = 0; //��ʼ��������ͷ
	virtual bool isEmpty() = 0; //�Ƿ�Ϊ��
	virtual int count() = 0; //�ڵ���
	virtual void output() = 0; //������нڵ�����
	virtual void push_back(ElmType val) = 0; //β������
	virtual void push_front(ElmType val) = 0; //ͷ������
    virtual void insert(int pos, ElmType val) = 0; //����pos��
	virtual void remove(int pos) = 0; //ɾ��pos���Ľڵ�
};


//������
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
//����ѭ������
class CCSlist : public CList
{
	virtual void initialize();
	TSlist *m_pHeader;
};
//˫������
class CDlist : public CList
{

};
//˫��ѭ������
class CCDlist : public CList
{

};









}


