#include <iostream>
#include <chrono>

#pragma pack(1)
struct SampleStructPack1
{
    bool flag;
    unsigned int timeout;
};
#pragma pack(0)

#pragma pack(2)
struct SampleStructPack2
{
    bool flag;
    unsigned int timeout;
};
#pragma pack(0)

#pragma pack(4)
struct SampleStructPack4
{
    bool flag;
    unsigned int timeout;
};
#pragma pack(0)

struct SampleStruct
{
    bool flag;
    unsigned int timeout;
};

static void print(size_t sz, size_t sz_flag, size_t sz_timeout)
{
    std::cout << "\tflag: " << sz_flag << " Bytes" << std::endl;
    std::cout << "\t+" << std::endl;
    std::cout << "\ttimeout: " << sz_timeout << " Bytes" << std::endl;
    std::cout << "\t=" << std::endl;
    std::cout << "\t" << sz_timeout + sz_flag << " Bytes" << std::endl;
    std::cout << "sizeof struct:  " << sz << " Bytes" << std::endl;
}

/*
SampleStructPack1 #pragma pack (1): It allocates 1 byte memory block, so our sample struct fits perfectly, in this case it is true that 4 + 1 = 5.
SampleStructPack2 #pragma pack (2): Minimum block size is 2 bytes. Integer attribute fits because it just needs 2 blocks of 2 Bytes. Boolean attribute needs just 1 Byte, but minimum block size is 2 Bytes, that’s why total allocated memory is 6 bytes, 4 + 2 = 6.
SampleStructPack4 #pragma pack (4): It is like previous one, but in this case we are wasting more memory for boolean attribute, it needs 1 Byte, but we are allocating 4 Bytes.
SampleStruct (default compiler alignment): As you can see it behaves exactly like #pragma pack (4), so we can deduct it is the default compiler alignment.
*/

/*
Why don’t we always use smallest memory alignment (#pragma pack (1)) so we can save more memory?
Because of performance loss.
*/

static const long MAX_ELEMENTS = 100000;
using namespace std::chrono;

void allocate1()
{
    SampleStructPack1 elements[MAX_ELEMENTS];
    std::cout << "SampleStructPack1: " << sizeof(elements) << " bytes allocated";
}

void allocate2()
{
    SampleStructPack2 elements[MAX_ELEMENTS];
    std::cout << "SampleStructPack2: " << sizeof(elements) << " bytes allocated";
}

void allocate4()
{
    SampleStructPack4 elements[MAX_ELEMENTS];
    std::cout << "SampleStructPack4: " << sizeof(elements) << " bytes allocated";
}

void chrono1()
{
    auto begin = high_resolution_clock::now();
    allocate1();
    std::cout << " in " << duration_cast<nanoseconds>(high_resolution_clock::now() - begin).count() << " nanoseconds" << std::endl;
}

void chrono2()
{
    auto begin = high_resolution_clock::now();
    allocate2();
    std::cout << " in " << duration_cast<nanoseconds>(high_resolution_clock::now() - begin).count() << " nanoseconds" << std::endl;
}

void chrono4()
{
    auto begin = high_resolution_clock::now();
    allocate4();
    std::cout << " in " << duration_cast<nanoseconds>(high_resolution_clock::now() - begin).count() << " nanoseconds" << std::endl;
}

void performanceTest()
{
    chrono1();
    chrono2();
    chrono4();
}

int main()
{

    std::cout << "SampleStructPack1" << std::endl;
    print(sizeof(SampleStructPack1), sizeof(SampleStructPack1::flag), sizeof(SampleStructPack1::timeout));
    std::cout << " -- " << std::endl;

    std::cout << "SampleStructPack2" << std::endl;
    print(sizeof(SampleStructPack2), sizeof(SampleStructPack2::flag), sizeof(SampleStructPack2::timeout));

    std::cout << "SampleStructPack4" << std::endl;
    print(sizeof(SampleStructPack4), sizeof(SampleStructPack4::flag), sizeof(SampleStructPack4::timeout));

    std::cout << "SampleStruct" << std::endl;
    print(sizeof(SampleStruct), sizeof(SampleStruct::flag), sizeof(SampleStruct::timeout));
    /*
    SampleStruct
    flag: 1 Bytes
    +
    timeout: 4 Bytes
    =
    5 Bytes
    sizeof struct:  8 Bytes
    --
    */
    std::cout << " -- " << std::endl;

    performanceTest();
}