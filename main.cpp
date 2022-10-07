#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int Lines(std::string path){
    std::ifstream fin;
    fin.open(path);
    std::string line;
    int r=0;
    while (!fin.eof()){
        getline(fin,line);
        ++r;
    }
    return r;
}
int Bytes(std::string path){
    int k;
    k = std::filesystem::file_size(path);
    return k;
}
int Words(std::string path){
    std::string line;
    std::ifstream finn;
    finn.open(path);
    int r = 0;
    while (!finn.eof()){
        getline(finn,line);
        for (int x=0;x<line.length();++x){
            if ((line[x+1]==' ' or line[x+1]=='\0' or line[x+1]=='\n' or line[x+1]=='\t') and
                not (line[x]==' ' or line[x]=='\0' or line[x]=='\n' or line[x]=='\t')){
                ++r;
            }
        }
    }
    return r;
}
int Chars(std::string path){
    std::ifstream fin;
    fin.open(path);
    std::string line;
    int r=0;
    while (!fin.eof()){
        getline(fin,line);
        for (char x : line){
            if (!(x == '\t' or x == '\n' or x == '\0' or x == ' ')){
                ++r;
            }
        }
    }
    return r;
}
int main(int argc, char* argv[])
{
    std::string line,ak,kk;
    std::string mass[1000];
    int mask[4] = {0,0,0,0};
    int y=0,z=0;
    for(int i=1;i<argc;++i){
        ak=argv[i];
        if (ak[0]=='-'){
            if (ak[1]=='-'){
                if (ak=="--lines"){
                    mask[0]=1;
                }
                if (ak=="--bytes"){
                    mask[1]=1;
                }
                if (ak=="--words"){
                    mask[2]=1;
                }
                if (ak=="--chars"){
                    mask[3]=1;
                }
            } else {
                for (int x=1;x<ak.length();++x){
                    if(ak[x]=='l') {
                        mask[0] = 1;
                        ++z;
                    }
                    if(ak[x]=='c') {
                        mask[1] = 1;
                        ++z;
                    }
                    if(ak[x]=='w') {
                        mask[2] = 1;
                        ++z;
                    }
                    if(ak[x]=='m') {
                        mask[3] = 1;
                        ++z;
                    }
                }
            }
        } else {
            mass[y] = ak;
            ++y;
        }
    }
    if (z>0) {
        for (int t = 0; t < y; ++t) {
            if (mask[0] == 1) {
                std::cout << Lines(mass[t]) << " ";
            }
            if (mask[2] == 1) {
                std::cout << Words(mass[t]) << " ";
            }
            if (mask[1] == 1) {
                std::cout << Bytes(mass[t]) << " ";
            }
            if (mask[3] == 1) {
                std::cout << Chars(mass[t]) << " ";
            }
            std::cout<< mass[t] <<"\n";
        }

    }else{
        for (int t = 0; t < y; ++t) {
            std::cout << Lines(mass[t]) << " ";
            std::cout << Words(mass[t]) << " ";
            std::cout << Bytes(mass[t]) << " ";
            std::cout << Chars(mass[t]) << " ";
            std::cout<<mass[t]<<"\n";
        }
    }

    return 0;
}