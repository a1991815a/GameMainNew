#ifndef __SET__
#define __SET__
#include <unordered_set>


template<typename _Kty,
	typename _Hasher = std::hash<_Kty>,
	typename _Keyeq = std::equal_to<_Kty>,
	typename _Alloc = std::allocator<_Kty> >
class Set{
public:
	typedef std::unordered_set<_Kty, _Hasher, _Keyeq, _Alloc> _Myt;
	typedef typename _Myt::_Mytraits _Mytraits;
	typedef typename _Myt::_Mybase _Mybase;
	typedef _Hasher hasher;
	typedef _Kty key_type;
	typedef _Keyeq key_equal;
	typedef _Mytraits key_compare;	// extra

	typedef typename _Mybase::_Pairib _Pairib;
	//	typedef typename _Mybase::value_compare value_compare;
	typedef typename _Mybase::allocator_type allocator_type;
	typedef typename _Mybase::size_type size_type;
	typedef typename _Mybase::difference_type difference_type;
	typedef typename _Mybase::pointer pointer;
	typedef typename _Mybase::const_pointer const_pointer;
	typedef typename _Mybase::reference reference;
	typedef typename _Mybase::const_reference const_reference;
	typedef typename _Mybase::iterator iterator;
	typedef typename _Mybase::const_iterator const_iterator;
	typedef typename _Mybase::value_type value_type;

	typedef typename _Mybase::iterator local_iterator;
	typedef typename _Mybase::const_iterator const_local_iterator;

public:
	Set() {

	};
	Set(const Set& _set) {
		this->m_set = _set.m_set;
		auto itor = m_set.begin();
		for (; itor != m_set.end(); ++itor)
			(*itor)->retain();
	};
	Set(Set&& _set) {
		swap(_set);
	};
	~Set() {
		clear();
	};

	void insert(_Kty& val) {
		m_set.insert(value_type(val));
		val->retain();
	};

	iterator erase(_Kty& val) {
		iterator itor = find(val);
		(*itor)->release();
		return m_set.erase(itor);
	};

	iterator erase(iterator itor) {
		(*itor)->release();
		return m_set.erase(itor);
	}

	iterator begin() {
		return m_set.begin();
	};
	const_iterator begin() const {
		return m_set.begin();
	};
	iterator end() {
		return m_set.end();
	};
	const_iterator end() const {
		return m_set.end();
	};

	iterator find(const _Kty& key) {
		return m_set.find(key);
	};

	const_iterator find(const _Kty& key) const {
		return m_set.find(key);
	};

	void clear() {
		auto itor = begin();
		for (; itor != end(); ++itor)
			(*itor)->release();
		m_set.clear();
	};

	void swap(Set& _set) {
		m_set.swap(_set.m_set);
	};

	bool empty() const {
		return m_set.empty();
	};

	size_type size() const {
		return m_set.size();
	};

	typename size_type max_size() const {
		return m_set.max_size();
	};

	void reserve(size_t _size) {
		m_set.reserve(_size);
	};


private:
	std::unordered_set<_Kty, _Hasher, _Keyeq, _Alloc> m_set;
};
#endif