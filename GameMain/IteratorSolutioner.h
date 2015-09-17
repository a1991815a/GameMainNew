#ifndef __ITERATORSOLUTIONER__
#define __ITERATORSOLUTIONER__

template<typename _Container>
class IteratorSolutioner{
public:
	typedef typename _Container::iterator iterator;
	typedef typename _Container::const_iterator const_iterator;
	IteratorSolutioner(_Container& container)
		:container(&container)
	{}

	inline iterator nextItor() {
		if (isUpdate)
		{
			isUpdate = false;
			return itor;
		}
		return ++itor;
	};

	inline void updateItor(iterator& itor) {
		isUpdate = true;
		this->itor = itor;
	};

	inline iterator begin() {
		itor = container->begin();
		return itor;
	}

	inline iterator end() {
		return container->end();
	}

	inline const_iterator begin() const{
		itor = container->begin();
		return itor;
	}

	inline const_iterator end() const {
		return container->end();
	}
private:
	iterator itor;
	bool isUpdate;
	_Container* container;
};

template<typename _Container>
class ConstIteratorSolutioner {
public:
	typedef typename _Container::const_iterator const_iterator;

	ConstIteratorSolutioner(const _Container& container)
		:container(&container)
	{}

	inline const_iterator nextItor() {
		if (isUpdate)
		{
			isUpdate = false;
			return itor;
		}
		return ++itor;
	};

	inline void updateItor(const_iterator& itor) {
		isUpdate = true;
		this->itor = itor;
	};

	inline const_iterator begin() {
		itor = container->begin();
		return itor;
	}

	inline const_iterator end() {
		return container->end();
	}
private:
	const_iterator itor;
	bool isUpdate;
	const _Container* container;
};

#endif