
#ifndef SMART_PTR_SHARED_MUT_H
#define SMART_PTR_SHARED_MUT_H

#include "smart_obj.h"
#include "unique_immut.h"

namespace ptr {
class shared_mut : public smart_obj {
private:
    mgr* _mgr;
    void increase();
public:
    shared_mut();
    explicit shared_mut(Object* obj);
    ~shared_mut();
    shared_mut(const shared_mut& ref);

    Object* get() const;
    void release();
    int count();

    shared_mut operator+(const shared_mut &shared);
    shared_mut operator-(const shared_mut &shared);
    shared_mut operator*(const shared_mut &shared);
    shared_mut operator/(const shared_mut &shared);
    Object* operator->();

//    shared_mut operator+(unique_immut &unique);
//    shared_mut operator-(unique_immut &unique);
//    shared_mut operator*(unique_immut &unique);
//    shared_mut operator/(unique_immut &unique);
//    shared_mut&operator=(unique_immut &r);
    shared_mut&operator=(const shared_mut &r);
}; // end of class shared_mut
} // end of namespace ptr

#endif //SMART_PTR_SHARED_MUT_H
