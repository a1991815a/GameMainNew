#ifndef __PRORITY_LIST__
#define __PRORITY_LIST__
#include <list>

template<
	typename _Ty,
	typename _Pr = std::less<_Ty>,
	typename _Ax = std::allocator<_Ty>
>
class Prority_List{
public:
	typedef std::list<_Ty, _Ax> _Myt;
	typedef typename _Myt::_Mybase _Mybase;
	typedef typename _Myt::_Alloc _Alloc;
	typedef typename _Myt::_Node _Node;
	typedef typename _Myt::_Nodeptr _Nodeptr;

	typedef typename _Myt::allocator_type allocator_type;
	typedef typename _Alloc::size_type size_type;
	typedef typename _Alloc::difference_type difference_type;
	typedef typename _Alloc::pointer pointer;
	typedef typename _Alloc::const_pointer const_pointer;
	typedef typename _Alloc::reference reference;
	typedef typename _Alloc::const_reference const_reference;
	typedef typename _Alloc::value_type value_type;

	typedef typename _Myt::const_iterator const_iterator;
	typedef typename _Myt::iterator iterator;

	typedef typename _Myt::reverse_iterator reverse_iterator;
	typedef typename _Myt::const_reverse_iterator const_reverse_iterator;

public:
	Prority_List()
		:comp()
	{};
	Prority_List(const Prority_List& _list)
		:m_list(_list.m_list), comp(_list.comp)
	{};
	Prority_List(Prority_List&& _list)
		:m_list(std::move(_list.m_list)), comp(_list.comp)
	{};

	iterator insert(const _Ty& val){
		auto itor = m_list.begin();
		for (; itor != m_list.end(); ++itor)
		{
			if(comp(val, *itor)){
				return m_list.insert(itor, val);
			}
		}
		m_list.push_back(val);
		itor = m_list.end();
		return --itor;
	};

	iterator erase(const_iterator itor){
		return m_list.erase(itor);
	};

	iterator erase(const _Ty& val){
		auto itor = m_list.begin();
		while (itor != m_list.end())
		{
			if(*itor == val)
			{
				itor = m_list.erase(itor);
				break;
			}
			++itor;
		}
		return itor;
	}

	template<typename _Ty1,typename COMP>
	iterator erase_if(const _Ty1& val, COMP& comp, bool multiple = false) {
		auto itor = m_list.begin();
		while (itor != m_list.end())
		{
			if (comp(val, *itor))
			{
				itor = m_list.erase(itor);
				if(multiple)
					continue;
				else
					break;
			}
			++itor;
		}
		return itor;
	}

	void eraseAll(const _Ty& val){
		auto itor = m_list.begin();
		while (itor != m_list.end())
		{
			if(*itor == val)
			{
				itor = m_list.erase(itor);
				continue;
			}
			++itor;
		}
	}

	iterator find(const _Ty& val){
		auto itor = m_list.begin();
		for (; itor != m_list.end(); ++itor)
			if(*itor == val)
				return itor;
		return itor;
	};
	const_iterator find(const _Ty& val) const{
		auto itor = m_list.begin();
		for (; itor != m_list.end(); ++itor)

			if(*itor == val)
				return itor;
		return itor;
	};
	
	_Ty& front(){
		return m_list.front();
	};
	const _Ty& front() const{
		return m_list.front();
	};
	_Ty& back(){
		return m_list.back();
	};
	const _Ty& back() const{
		return m_list.back();
	};

	void push_front(_Ty& val){
		m_list.push_front(val);
	};

	void push_back(_Ty& val){
		m_list.push_back(val);
	};

	void pop_front(){
		m_list.pop_front();
	};

	void pop_back(){
		m_list.pop_back();
	};
	

	iterator begin(){
		return m_list.begin();
	};
	const_iterator begin() const{
		return m_list.begin();	
	};
	iterator end(){
		return m_list.end();
	};
	const_iterator end() const{
		return m_list.end();
	};

	reverse_iterator rbegin(){
		return m_list.rbegin();
	};

	const_reverse_iterator rbegin() const{
		return m_list.rbegin();	
	};
	reverse_iterator rend(){
		return m_list.rend();
	};
	const_reverse_iterator rend() const{
		return m_list.rend();
	};

	size_t size() const{
		return m_list.size();
	}

	bool empty() const{
		return m_list.empty();
	}



private:
	std::list<_Ty, _Ax> m_list;
	_Pr comp;
};
#endif