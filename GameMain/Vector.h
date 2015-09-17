#ifndef __VECTOR__
#define __VECTOR__
#include <vector>

template<
	typename _Ty,
	typename _Alloc = std::allocator<_Ty> >
class Vector{
public:
	typedef std::vector<_Ty, _Alloc> _Myt;
	typedef typename _Myt::_Mybase _Mybase;
	typedef typename _Myt::allocator_type allocator_type;

	typedef typename _Myt::value_type value_type;
	typedef typename _Myt::size_type size_type;
	typedef typename _Myt::difference_type difference_type;
	typedef typename _Myt::pointer pointer;
	typedef typename _Myt::const_pointer const_pointer;
	typedef typename _Myt::reference reference;
	typedef typename _Myt::const_reference const_reference;

	typedef typename _Myt::iterator iterator;
	typedef typename _Myt::const_iterator const_iterator;

	typedef _STD reverse_iterator<iterator> reverse_iterator;
	typedef _STD reverse_iterator<const_iterator> const_reverse_iterator;

public:
	Vector() {};
	Vector(const Vector& vec) {
		m_vector = vec.m_vector;
		auto itor = m_vector.begin();
		for (; itor != m_vector.end(); ++itor)
			(*itor)->retain();
	};
	Vector(Vector&& vec) {
		m_vector.swap(vec.m_vector);
	};
	~Vector()
	{
		clear();
	}

	void insert(size_t index, _Ty& val) {
		m_vector.insert(m_vector.begin() + index, val);
		val->retain();
	};
	void insert(const_iterator itor, _Ty& val) {
		m_vector.insert(itor, val);
		val->retain();
	};
	void erase(size_t index) {
		m_vector.at(index)->release();
		m_vector.erase(m_vector.begin() + index);
	};
	iterator erase(iterator itor) {
		(*itor)->release();
		return m_vector.erase(itor);
	};
	iterator erase(const _Ty& val) {
		auto itor = m_vector.begin();
		for (; itor != m_vector.end(); ++itor)
		{
			if (*itor == val) 
				{
					(*itor)->release();
					return erase(itor);
				}
		}
		assert(false);
		return m_vector.end();
	};


	_Ty& at(size_t index) {
		return m_vector.at(index);
	};
	const _Ty& at(size_t index) const {
		return m_vector.at(index);
	}

	void clear() {
		auto itor = m_vector.begin();
		for (; itor != m_vector.end(); ++itor)
			(*itor)->release();
		m_vector.clear();
	};
	size_t size() const {
		return m_vector.size();
	};
	bool empty() const {
		return m_vector.empty();
	};

	_Ty& front() {
		return m_vector.front();
	};
	const _Ty& front() const {
		return m_vector.front();
	};
	_Ty& back() {
		return m_vector.back();
	};
	const _Ty& back() const {
		return m_vector.back();
	};

	void push_back(_Ty& val) {
		val->retain();
		m_vector.push_back(val);
	};
	void push_front(_Ty& val) {
		val->retain();
		m_vector.push_front(val);
	};
	void pop_back() {
		m_vector.back()->release();
		m_vector.pop_back();
	};
	void pop_front() {
		m_vector.front()->release();
		m_vector.pop_front();
	};

	void swap(Vector& vec) {
		m_vector.swap(vec.m_vector);
	};

	iterator begin() {
		return m_vector.begin();
	};
	const_iterator begin() const {
		return m_vector.begin();
	};
	iterator end() {
		return m_vector.end();
	};
	const_iterator end() const {
		return m_vector.end();
	};

	reverse_iterator rbegin() {
		return m_vector.rbegin();
	};
	const_reverse_iterator rbegin() const {
		return m_vector.rbegin();
	};
	reverse_iterator rend() {
		return m_vector.rend();
	};
	const_reverse_iterator rend() const {
		return m_vector.rend();
	};

	void reserve(size_t _size) {
		m_vector.reserve(_size);
	};

private:
	std::vector<_Ty> m_vector;
};
#endif