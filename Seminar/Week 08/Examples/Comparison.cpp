#include <string>
#include <tuple>

struct Record
{
    std::string name;
    unsigned int floor;
    double weight;
    friend bool operator<(const Record &l, const Record &r)
    {
        // tie provides lexicographical comparison
        return std::tie(l.name, l.floor, l.weight) < std::tie(r.name, r.floor, r.weight); // keep the same order
    }
};