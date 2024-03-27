#include <string>

// If you can avoid defining default operations, do

class rule_of_zero
{
    std::string cppstring;

public:
    rule_of_zero(const std::string &arg) : cppstring(arg) {}
};

class base_of_five_defaults
{
public:
    base_of_five_defaults(const base_of_five_defaults &) = default;
    base_of_five_defaults(base_of_five_defaults &&) = default;
    base_of_five_defaults &operator=(const base_of_five_defaults &) = default;
    base_of_five_defaults &operator=(base_of_five_defaults &&) = default;
    virtual ~base_of_five_defaults() = default;
};