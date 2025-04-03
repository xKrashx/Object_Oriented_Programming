#include <iostream>
#include <math.h>


const char * hex = {
    "0123456789ABCDEF"
};

size_t sizeofChar(const char* input){
    size_t counter = 0;
    while (input[counter]!='\0')
    {
        counter++;
    }
    return counter-1;
    
}

void reverseChar(char* str)
{
    for(size_t i =0;i<sizeof(str)/2;i++)
    {
        char temp=str[i];
        str[i]=str[sizeof(str)-i-1];
        str[sizeof(str)-i-1]=temp;
    }
}

void LongToHexPrint(unsigned long ip){
    std::cout<<"0x";
    char result[9];
    size_t counter = 0;
    while(ip > 0){
        result[counter] = hex[ip%16];
        counter++;
        ip/=16;
    }
    result[counter] = '\0';
    reverseChar(result);
    std::cout << result;
    size_t i =0;
    while(result[i] !='\0'){
        std::cout<<result[i];i++;
    }

}


unsigned long IpToLong(const char * ipAddress){
    unsigned long result = 0;
    size_t pow = 0;
    int temp =0;
    for(size_t i=0;i<sizeofChar(ipAddress)+1;i++){
        if(ipAddress[i] == '.' ){
            result += temp * std::pow(256,pow);
            pow+=1;
            temp = 0;
        }
        else{
            temp *=10;
            temp += (ipAddress[i] - '0');
        }


    }
    result += temp * std::pow(256,pow);
    return result;
}

int main(){
    const char * ip = "127.0.0.1";
    LongToHexPrint(IpToLong(ip));
    return 0;
}