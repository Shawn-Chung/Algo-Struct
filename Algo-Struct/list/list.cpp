
#include <malloc.h>
#include <iostream>
#include "gloabl.h"
#include "list.h"
#include "easylogging++.h"

using namespace std;
using namespace lt;



int lt::TestList()
{
    LOG(INFO) << "...begin test CList...";

    CList *slist = new CSlist();

    LOG(INFO) << "the list size is: " << slist->count() ;
    LOG(INFO) << "begin build the list, give the size of list: ";
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        slist->push_back(random(1, count * 100));
    }
    LOG(INFO) << "the list size is: " << slist->count() ;
    slist->output();

    LOG(INFO) << "insert element...put in the pos and value:";
    int pos = 0;
    int val = 0;
    cin >> pos >> val;

    slist->insert(pos, val);
    LOG(INFO) << "the list size is: " << slist->count();
    slist->output();

    LOG(INFO) << "push back element...put in the value:";
    cin >> val;
    slist->push_back(val);
    LOG(INFO) << "the list size is: " << slist->count() ;
    slist->output();

    LOG(INFO) << "push front element...put in the value:";
    cin >> val;
    slist->push_front(val);
    LOG(INFO) << "the list size is: " << slist->count() ;
    slist->output();

    LOG(INFO) << "remove element...put in the pos:";
    cin >> pos;
    slist->remove(pos);
    LOG(INFO) << "the list size is: " << slist->count() ;
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
    QVector<ElmType> data;

	while (NULL != cur)
	{
        data.append(cur->data);
		cur = cur->next;
	}
    LOG(INFO) << data;
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











