
#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

void unique_immut::release() {
	if (_mgr != nullptr) {
		(_mgr->count)--;
		delete _mgr;
		_mgr = nullptr;
	}
}

Object* unique_immut::get() const {
	if (_mgr != nullptr)
		return _mgr->ptr;
	else
		return nullptr;
}

unique_immut unique_immut::operator+(unique_immut &unique) {
	
	int result = (_mgr->ptr->get() + unique.get()->get());

	release();
	unique.release();


	Object* o = new Object(result);
	
	unique_immut new_unique(o);
	return new_unique;
}

unique_immut unique_immut::operator-(unique_immut &unique) {
	
	int result = (_mgr->ptr->get() - unique.get()->get());
	
	release();
	unique.release();


	Object* o = new Object(result);
	
	unique_immut new_unique(o);
	return new_unique;
}

unique_immut unique_immut::operator*(unique_immut &unique) {
	
	int result = (_mgr->ptr->get() * unique.get()->get());
	
	release();
	unique.release();


	Object* o = new Object(result);
	
	unique_immut new_unique(o);
	return new_unique;
}

unique_immut unique_immut::operator/(unique_immut &unique) {
	
	int result = (_mgr->ptr->get() / unique.get()->get());
	
	release();
	unique.release();
	
	Object* o = new Object(result);

	unique_immut new_unique(o);
	return new_unique;
}

Object* unique_immut::operator->() {
	return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut &r) {
	if (r._mgr != _mgr) {
		release();
		return r;
	}
	else {
		return *this;
	}
}
} // end of namespace ptr
