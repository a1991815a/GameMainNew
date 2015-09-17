#ifndef __MAP__
#define __MAP__
#include <unordered_map>


template<typename _Kty, 
	typename _Ty, 
	typename _Hasher = std::hash<_Kty>,
	typename _Keyeq = std::equal_to<_Kty>,
	typename _Alloc = std::allocator<pair<const _Kty, _Ty> > >
class Map
{
public:
	typedef std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc> _Myt;
	typedef typename _Myt::_Mytraits _Mytraits;
	typedef typename _Myt::_Mybase _Mybase;
	typedef _Hasher hasher;
	typedef _Kty key_type;
	typedef _Ty mapped_type;
	typedef _Keyeq key_equal;
	typedef _Mytraits key_compare;	// extra

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
	Map() {

	};
	Map(const Map& _map) {
		this->m_map = _map.m_map;
		auto itor = m_map.begin();
		for (; itor != m_map.end(); ++itor)
			itor->second->retain();
	};
	Map(Map&& _map) {
		m_map.swap(_map);
	};
	~Map();

	void insert(const _Kty& key, _Ty& val) {
		m_map.insert(value_type(key, val));
		val->retain();
	};

	iterator erase(const _Kty& key) {
		iterator itor = find(key);
		itor->second->release();
		return m_map.erase(itor);
	};

	iterator erase(iterator itor) {
		itor->second->release();
		return m_map.erase(itor);
	}

	_Ty& at(const _Kty& key) {
		return m_map.at(key);
	};
	const _Ty& at(const _Kty& key) const {
		return m_map.at(key);
	};

	iterator begin() {
		return m_map.begin();
	};
	const_iterator begin() const {
		return m_map.begin();
	};
	iterator end() {
		return m_map.end();
	};
	const_iterator end() const {
		return m_map.end();
	};

	iterator find(const _Kty& key) {
		return m_map.find(key);
	};

	const_iterator find(const _Kty& key) const {
		return m_map.find(key);
	};

	void clear() {
		auto itor = begin();
		for (; itor != end(); ++itor)
			itor->second->release();
		m_map.clear();
	};

	void swap(Map& _map) {
		m_map.swap(_map.m_map);
	};

	bool empty() const {
		return m_map.empty();
	};

	size_type size() const {
		return m_map.size();
	};

	typename size_type max_size() const {
		return m_map.max_size();
	};

	void reserve(size_t _size) {
		m_map.reserve(_size);
	};

private:
	std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc> m_map;
};

#endif