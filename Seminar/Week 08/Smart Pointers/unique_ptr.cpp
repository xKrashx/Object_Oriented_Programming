#include "unique_ptr.hpp"

UniquePtr::UniquePtr(nullptr_t) noexcept{}

explicit UniquePtr::UniquePtr(int *ptr) noexcept: m_Ptr(ptr){}

UniquePtr::~UniquePtr(){ if(m_Ptr) delete m_Ptr; }

int &UniquePtr::operator *() const noexcept{ return *m_Ptr; }
int *UniquePtr::operator ->() const noexcept{ return m_Ptr; }
int *UniquePtr::Get() const noexcept{ return m_Ptr; }
explicit UniquePtr::operator bool() const noexcept{ return m_Ptr ? true : false; }

int *UniquePtr::Release() noexcept{

    int *old = m_Ptr;
    m_Ptr = nullptr;
    return old;

}

void UniquePtr::Reset(int *ptr){

    UniquePtr temp(ptr);
    temp.Swap(*this);

}

void swap(int *&lhs, int *&rhs){

    int *temp = lhs;
    lhs = rhs;
    rhs = temp;

}

void UniquePtr::Swap(UniquePtr &other) noexcept{
    swap(m_Ptr, other.m_Ptr);
}

inline bool operator ==(UniquePtr const &lhs, UniquePtr const &rhs) noexcept{
    return lhs.Get() == rhs.Get();
}

inline bool operator ==(UniquePtr const &lhs, nullptr_t) noexcept{
    return !lhs;
}

inline bool operator ==(nullptr_t, UniquePtr const &rhs) noexcept{
    return !rhs;
}

inline bool operator !=(UniquePtr const &lhs, UniquePtr const &rhs) noexcept{
    return !(lhs == rhs);
}

inline bool operator !=(UniquePtr const &lhs, nullptr_t) noexcept{
    return bool(lhs);
}

inline bool operator !=(nullptr_t, UniquePtr const &rhs) noexcept{
    return bool(rhs);
}