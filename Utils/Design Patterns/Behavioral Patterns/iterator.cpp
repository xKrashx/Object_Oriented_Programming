#include <iostream>
#include <cstdint>
#include <vector>

template <typename T>
class List{
public:
	void Append(T &&x){ m_Data.emplace_back(std::forward<T>(x)); }

	size_t Size(){ return m_Data.size(); }

	T &operator[](size_t n){ return m_Data[n]; }
	T const operator[](size_t n) const{ return m_Data[n]; }

private:
	class Iterator{
    public:
        T &operator *(){
            return *pointer;
        }

        T const &operator *() const{
            return *pointer;
        }

        T *operator ->(){
            return pointer;
        }

        T const *operator ->() const{
            return pointer;
        }

        Iterator &operator ++(){
            ++pointer;
            return *this;
        }

        Iterator operator ++(int){
            Iterator old = *this;
            ++(*this);
            return old;
        }

        Iterator &operator --(){
            --pointer;
            return *this;
        }

        Iterator operator --(int){
            Iterator old = *this;
            --(*this);
            return old;
        }

        bool operator ==(const Iterator& other) const{
			return pointer == other.pointer;
		}

		bool operator !=(const Iterator& other) const{
			return !(*this == other);
		}

    private:
        friend class List;
        T *pointer;

        Iterator(T *pointer): pointer(pointer){}
    };

public:
    Iterator begin(){
        return Iterator(m_Data.data());
    }

    Iterator end(){
        return Iterator(m_Data.data() + Size());
    }

private:
	std::vector<T> m_Data;
};

int main(){
	List<int32_t> list;
	list.Append(2);
	list.Append(3);
	list.Append(1);

	for (auto it = list.begin(); it != list.end(); ++it) {
		std::cout << *it;  // 231
	}

	for(auto it : list){
		std::cout << it << '\n';
	}

	return 0;
}
