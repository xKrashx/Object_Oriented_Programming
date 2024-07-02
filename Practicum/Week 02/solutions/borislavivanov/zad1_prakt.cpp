#include<iostream>
#include<fstream>

int main(){
    const char deviders[] = {"0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM-"};
    std::cout<<sizeof(deviders)<<std::endl;
    std::ifstream file("zad1.txt");
    if(!file.is_open()){ std::cout<<"Couldnt open file :C";return -1;}
    size_t counter = 0;
    bool inWord = true;
    while(!file.eof()){
        char c = file.get();
        bool check = false;
        for(size_t i =0 ;i<64;i++){
            if(c == deviders[i]){
                check = true;
                inWord = true;
            }
        }
        if(check == false&&inWord == true){
            inWord = false;
            counter++;
        }
    }
    file.close();
    std::cout<<counter;
    return 0;
    
}