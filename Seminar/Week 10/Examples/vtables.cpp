#include<iostream>

class Base{

    public:
        virtual void fun(){
            std::cout<<"\nInside Base::fun()\n";       // function address 1000
        }
        virtual void gun(){
            std::cout<<"\nInside Base::gun()\n";       // function address 2000
        }
        virtual void sun(){
            std::cout<<"\nInside Base::sun()\n";       // function address 3000
        }

};

class Derived:public Base{

    public:
        void fun(){
            std::cout<<"\nInside Derived::fun()\n";    // function address 4000
        }
        void gun(){
            std::cout<<"\nInside Derived::gun()\n";    // function address 5000
        }
};

int main(){

    std::cout << "Base class size: " << sizeof(Base) << '\n';

    Base *bptr = new Base;          // pointer of Base class pointing to object of Base class
    std::cout << "Base pointer " << bptr << '\n';

    int64_t *ptr=(int64_t *)bptr;   // integer pointer which gets the address of vptr which is in first four bytes of Base class object
    std::cout << "Int pointer to base " << ptr << ' ' << std::hex << *ptr << '\n';

    int64_t *vptr=(int64_t *)*ptr;  // integer pointer which points to memory allocated to the array of virtual function addresses i.e. VTABLE
    std::cout << "Vtable pointer " << vptr << ' ' << std::hex << *vptr << '\n';

    void (*fp)();                   // function pointer which will points to the function having prototype void function_name()

    fp=(void(*)())(*vptr);          // function pointer currently holds the address of first function in VTABLE i.e. Base::fun()
    fp();    //1000                 // call to the Base::fun()
    std::cout << (void *)fp << '\n';// Base::fun() address in memory

    fp=(void(*)())(*(vptr+1));      // function pointer currently holds the address of first function in VTABLE i.e. Base::gun()
    fp();    //2000                 // call to the Base::gun()
    std::cout << (void *)fp << '\n';// Base::gun() address in memory

    fp=(void(*)())(*(vptr+2));      // function pointer currently holds the address of first function in VTABLE i.e. Base::sun()
    fp();    //3000                 // call to the Base::sun()
    std::cout << (void *)fp << '\n';// Base::sun() address in memory

    delete bptr;                    // Freeing memory
    bptr=new Derived;               // Base class pointer points to Derived class object i.e. Up casting hence overriding will take place
                                    // After overriding in VTABLE  at 0 th index which was holding the address of Base::fun() will get replaced with address of Derived::fun()
                                    // After overriding in VTABLE  at 1 st index which was holding the address of Base::gun() will get replaced with address of Derived::gun()
                                    // After overriding in VTABLE  at 2 nd index which was holding the address of Base::sun() will will not override because of there no definition of gun() in Derived class

    ptr=(int64_t *)bptr;                // integer pointer which gets the address of vptr which is in first four bytes of Derived class object
    vptr=(int64_t *)*ptr;               // integer pointer which points to memory allocated to the array of  virtual function addresses which were overred previously.e. VTABLE after overriding

    fp=(void(*)())(*vptr);           // function pointer currently holds the address of first function in VTABLE i.e. Derived::fun()(overriding)
    fp();     //4000                 // call to the Derived::fun()
    std::cout << (void *)fp << '\n'; // Derived::fun() address in memory

    fp=(void(*)())(*(vptr+1));       // function pointer currently holds the address of first function in VTABLE i.e. Derived::gun()(overriding)
    fp();     //5000                 // call to the Derived::gun()
    std::cout << (void *)fp << '\n'; // Derived::gun() address in memory

    fp=(void(*)())(*(vptr+2));       // function pointer currently holds the address of first function in VTABLE i.e. Derived::sun()
    fp();     //3000                 // call to the Base::sun()
    std::cout << (void *)fp << '\n'; // Base::sun() address in memory

    delete bptr;                     // Freeing memory

    return 0;

}