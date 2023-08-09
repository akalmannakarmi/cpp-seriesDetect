#include <windows.h>
#include <sstream>
#include <filesystem>
#include "sampleSequence.h"
// #include "setup/number.cpp"
// #include "setup/sequence.cpp"

typedef Sequence* (*createSequence)();
std::vector<Number> stringToArray(std::string str);
Sequence* getSequence(std::vector<Number> arr,std::vector<createSequence> &sequences);
std::vector<createSequence> loadSequences(std::vector<HINSTANCE> &dlls);
int main() {
    std::vector<HINSTANCE> dlls;
    std::vector<createSequence> sequences = loadSequences(dlls);

    std::string seriesStr;
    std::cout<<"Enter Series:";
    std::cin>>seriesStr;
    std::vector<Number> arr = stringToArray(seriesStr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;

    Sequence *s;
    if(!s->findSequence(s,sequences,arr)){
        std::cout<<"didnt find"<<std::endl;
        return -1;
    }
    // Sequence *s= getSequence(arr,sequences);
    std::cout<<"Type:"<<s->type<<std::endl;
    
    long long int term;
    std::cout<<"Term:";
    std::cin>>term;
    std::cout<<"t"<<term<<":"<<s->term(term)<<std::endl;

    // Clean up
    delete s;
    for(int i=0;i<dlls.size();i++){
        FreeLibrary(dlls[i]);
    }
    std::cout<<"Closing Safely"<<std::endl;
    return 0;
}


std::vector<Number> stringToArray(std::string str) {
    std::vector<Number> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, ',')) {
        size_t pos = token.find('/');
        if (pos != std::string::npos) {
            std::string token1 = token.substr(0, pos);
            std::string token2 = token.substr(pos + 1);
            Number n1(std::stoi(token1),std::stoi(token2));
            result.push_back(n1);
        } else {
            Number n(std::stoi(token));
            result.push_back(n);
        }
    }
    return result;
}
std::vector<createSequence> loadSequences(std::vector<HINSTANCE> &dlls){
    std::vector<createSequence> sequences;
    for (const auto& entry : std::filesystem::directory_iterator("sequences")) {
        if (entry.is_regular_file() && entry.path().extension() == ".dll") {
            HINSTANCE dll = LoadLibrary(TEXT(entry.path().string().c_str()));
            if (dll == NULL) {
                std::cout << "Failed to load DLL: " << entry.path().string() << std::endl;
                FreeLibrary(dll);
                continue;
            }
            // Get a pointer to the CreateArthSequence function
            createSequence create = (createSequence)GetProcAddress(dll, "create");
            if (create == NULL) {
                std::cout << "Failed to get function create() from DLL: " << entry.path().string() << std::endl;
                FreeLibrary(dll);
                continue;
            }
            sequences.push_back(create);
            dlls.push_back(dll);
        }
    }
    return sequences;
}
Sequence* getSequence(std::vector<Number> arr,std::vector<createSequence> &sequences){
    for(int i=0;i<sequences.size();i++){
        Sequence* s = sequences[i]();
        if (s->detect(arr,sequences))
            return s;
        delete s;
    }
    return new Sequence();
}