
#include <malloc.h>
#include <iostream>
#include "list.h"


using namespace std;
using namespace lt;

int lt::random(int start, int end)
{
    return start + (end - start)*rand() / RAND_MAX;
}

int lt::TestList()
{
    cout << "...begin test CList..." <<endl;

    CList *slist = new CSlist();

    cout << "the list size is: " << slist->count() << endl;
    cout << "begin build the list, give a num: ";
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        slist->push_back(random(1, count * 100));
    }
    cout << "the list size is: " << slist->count() << endl;
    slist->output();

    cout << "insert element...put in the pos and value:";
    int pos = 0;
    int val = 0;
    cin >> pos >> val;

    slist->insert(pos, val);
    cout << "the list size is: " << slist->count() << endl;
    slist->output();

    cout << "push back element...put in the value:";
    cin >> val;
    slist->push_back(val);
    cout << "the list size is: " << slist->count() << endl;
    slist->output();

    cout << "push front element...put in the value:";
    cin >> val;
    slist->push_front(val);
    cout << "the list size is: " << slist->count() << endl;
    slist->output();

    cout << "remove element...put in the pos:";
    cin >> pos;
    slist->remove(pos);
    cout << "the list size is: " << slist->count() << endl;
    slist->output();


    delete slist;
    return 0;
}



void CSlist::initialize()
{
	if (NULL == m_pHeader)
	{
		m_pHeader = (TSlist *)malloc(sizeof(TSlist));
	}
	
	if (NULL != m_pHeader)
	{
		m_pHeader->next = NULL;
	}
}

int CSlist::count()
{
	int cnt = 0;
	TSlist *cur = m_pHeader->next;
	while (NULL != cur)
	{
		cnt++;
		cur = cur->next;
	}
	return cnt;
}

void CSlist::output()
{
	TSlist *cur = m_pHeader->next;

	while (NULL != cur)
	{
		cout << cur->data<<" ";
		cur = cur->next;
	}

	cout << endl;
}

void CSlist::push_back(ElmType val)
{
	TSlist *next = m_pHeader->next;
	TSlist *cur = m_pHeader;

	while (NULL != next)
	{
		next = next->next;
		cur = cur->next;
	}

	TSlist *list = (TSlist *)malloc(sizeof(TSlist));
	if (NULL == list)
	{
		return;
	}

	cur->next = list;
	list->data = val;
	list->next = NULL;
}

void CSlist::push_front(ElmType val)
{
	TSlist *list = (TSlist *)malloc(sizeof(TSlist));
	if (NULL == list)
	{
		return;
	}

	list->data = val;
	list->next = m_pHeader->next;
	m_pHeader->next = list;
}

void CSlist::insert(int pos, ElmType val)
{
	if ((pos <=0 ) || (pos > count()))
	{
		return;
	}
    TSlist *cur = m_pHeader;
	while ((NULL != cur) && (--pos != 0))
	{
		cur = cur->next;
	}

	TSlist *list = (TSlist *)malloc(sizeof(TSlist));
	if (NULL == list)
	{
		return;
	}

	list->data = val;
	list->next = cur->next;
	cur->next = list;
}

void CSlist::remove(int pos)
{
    if ((pos <=0 ) || (pos > count()))
    {
        return;
    }
    TSlist *pre = m_pHeader;
    TSlist *cur = m_pHeader->next;
    while((NULL != cur) && (--pos != 0))
    {
        cur = cur->next;
        pre = pre->next;
    }
    pre->next = cur->next;
    delete cur;
}











