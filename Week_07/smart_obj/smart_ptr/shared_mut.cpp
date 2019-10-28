//201602011 서성덕

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();
}

shared_mut::shared_mut(const shared_mut& ref) {
	_mgr = ref._mgr;
	increase();
}

Object* shared_mut::operator->() {
    return _mgr->ptr;
}

void shared_mut::release() {
	if (_mgr == nullptr)
		return;
	(_mgr->count)--;
	if (_mgr->count == 0) {
		delete _mgr;
	}
	_mgr = new mgr();
	return;
}

Object* shared_mut::get() const {
	if (_mgr != nullptr)
		return _mgr->ptr;
	else
		return nullptr;
}

void shared_mut::increase() {
	_mgr->count += 1;
}

int shared_mut::count() {
	return _mgr->count;
}

shared_mut shared_mut::operator+(const shared_mut &shared) {
	int result = ( (_mgr->ptr->get()) + (shared.get()->get()) );
	Object* o = new Object(result);
	shared_mut new_shared(o);
	return new_shared;
}

shared_mut shared_mut::operator-(const shared_mut &shared) {
	int result = ( (_mgr->ptr->get()) - (shared.get()->get()) );
	Object* o = new Object(result);
	shared_mut new_shared(o);
	return new_shared;
}

shared_mut shared_mut::operator*(const shared_mut &shared) {
	int result = ( (_mgr->ptr->get()) * (shared.get()->get()) );
	Object* o = new Object(result);
	shared_mut new_shared(o);
	return new_shared;
}

shared_mut shared_mut::operator/(const shared_mut &shared) {
	int result = ( (_mgr->ptr->get()) / (shared.get()->get()) );
	Object* o = new Object(result);
	shared_mut new_shared(o);
	return new_shared;
}

shared_mut& shared_mut::operator=(const shared_mut &r) {
	release();
	_mgr = r._mgr;
	increase();
	return *this;
}
} // end of namespace ptr
