#include "shared_ptr.hpp"
#include <stdexcept>

SharedPtr::SharedPtr(nullptr_t) noexcept{}

explicit SharedPtr::SharedPtr(int *ptr): m_Ptr(ptr){

    try{
        m_RC = new size_t(1);
    }
    catch(std::bad_alloc const &ex){
        delete m_Ptr;
        throw ex;
    }

}

SharedPtr::SharedPtr(SharedPtr const &other) noexcept{

    m_Ptr = other.m_Ptr;
    m_RC = other.m_RC;
    if(m_Ptr) ++(*m_RC);

}

SharedPtr::~SharedPtr() noexcept{

    if(m_Ptr && --(*m_RC) == 0){

        delete m_Ptr;
        delete m_RC;

    }

}

SharedPtr &SharedPtr::operator =(SharedPtr const &other) noexcept{

    SharedPtr temp(other);
    temp.Swap(*this);
    return *this;

}

int &SharedPtr::operator *() const noexcept{
    return *m_Ptr;
}

int *SharedPtr::operator ->() const noexcept{
    return m_Ptr;
}

int *SharedPtr::Get() const noexcept{
    return m_Ptr;
}

explicit SharedPtr::operator bool() const noexcept{
    return m_Ptr ? true : false;
}

size_t SharedPtr::UseCount() const noexcept{

    if(m_Ptr) return *m_RC;
    return 0;

}
bool SharedPtr::Unique() const noexcept{
    return UseCount() == 1;
}

void SharedPtr::Reset(){

    SharedPtr temp;
    temp.Swap(*this);

}

void SharedPtr::Reset(int *ptr){

    SharedPtr temp(ptr);
    temp.Swap(*this);

}

void SharedPtr::Swap(SharedPtr &other) noexcept{

    std::swap(m_Ptr, other.m_Ptr);
    std::swap(m_RC, other.m_RC);

}

inline bool operator ==(SharedPtr const &lhs, SharedPtr const &rhs) noexcept{
    return lhs.Get() == rhs.Get();
}

inline bool operator ==(SharedPtr const &lhs, nullptr_t) noexcept{
    return !lhs;
}

inline bool operator ==(nullptr_t, SharedPtr const &rhs) noexcept{
    return !rhs;
}

inline bool operator !=(SharedPtr const &lhs, SharedPtr const &rhs) noexcept{
    return !(lhs == rhs);
}

inline bool operator !=(SharedPtr const &lhs, nullptr_t) noexcept{
    return bool(lhs);
}

inline bool operator !=(nullptr_t, SharedPtr const &rhs) noexcept{
    return bool(rhs);
}