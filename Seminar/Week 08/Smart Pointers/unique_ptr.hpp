#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

typedef decltype(nullptr) nullptr_t;

class UniquePtr{

public:
    UniquePtr() noexcept = default;
    UniquePtr(nullptr_t) noexcept;
    explicit UniquePtr(int *ptr) noexcept;
    ~UniquePtr() noexcept;

    int &operator *() const noexcept;
    int *operator ->() const noexcept;
    int *Get() const noexcept;
    explicit operator bool() const noexcept;

    int *Release() noexcept;
    void Reset(int *ptr = nullptr);
    void Swap(UniquePtr &other) noexcept;

    UniquePtr(UniquePtr const &) = delete;
    UniquePtr &operator =(UniquePtr const &) = delete;

private:
    int *m_Ptr;

};

inline bool operator ==(UniquePtr const &lhs, UniquePtr const &rhs) noexcept;
inline bool operator ==(UniquePtr const &lhs, nullptr_t) noexcept;
inline bool operator ==(nullptr_t, UniquePtr const &rhs) noexcept;

inline bool operator !=(UniquePtr const &lhs, UniquePtr const &rhs) noexcept;
inline bool operator !=(UniquePtr const &lhs, nullptr_t) noexcept;
inline bool operator !=(nullptr_t, UniquePtr const &rhs) noexcept;

#endif