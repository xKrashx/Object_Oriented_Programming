#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP

typedef decltype(nullptr) nullptr_t;
typedef unsigned long long size_t;

class SharedPtr{

public:
    SharedPtr() = default;
    SharedPtr(nullptr_t) noexcept;
    explicit SharedPtr(int *ptr);
    SharedPtr(SharedPtr const &other) noexcept;
    ~SharedPtr() noexcept;

    SharedPtr &operator =(SharedPtr const &other) noexcept;

    int &operator *() const noexcept;
    int *operator ->() const noexcept;
    int *Get() const noexcept;
    explicit operator bool() const noexcept;

    size_t UseCount() const noexcept;
    bool Unique() const noexcept;

    void Reset();
    void Reset(int *ptr);
    void Swap(SharedPtr &other) noexcept;

private:
    int *m_Ptr = nullptr;
    size_t *m_RC = nullptr;

};

inline bool operator ==(SharedPtr const &lhs, SharedPtr const &rhs) noexcept;
inline bool operator ==(SharedPtr const &lhs, nullptr_t) noexcept;
inline bool operator ==(nullptr_t, SharedPtr const &rhs) noexcept;

inline bool operator !=(SharedPtr const &lhs, SharedPtr const &rhs) noexcept;
inline bool operator !=(SharedPtr const &lhs, nullptr_t) noexcept;
inline bool operator !=(nullptr_t, SharedPtr const &rhs) noexcept;

#endif