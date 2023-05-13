#include <windows.h>
#include <sstream>
#include <filesystem>
#include "sequence.cpp"
#include "number.cpp"

std::vector<Number> stringToArray(std::string str);
Sequence* getSequence(std::vector<Number> arr,HINSTANCE &dll);
typedef Sequence* (*createSequence)();
int main() {
    std::string seriesStr;
    std::cout<<"Enter Series:";
    std::cin>>seriesStr;
    std::vector<Number> arr = stringToArray(seriesStr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;

    HINSTANCE dll;
    Sequence *s= getSequence(arr,dll);
    
    long long int term;
    std::cout<<"Term:";
    std::cin>>term;
    std::cout<<"t"<<term<<":"<<s->term(term)<<std::endl;

    // Clean up
    delete s;
    FreeLibrary(dll);

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
Sequence* getSequence(std::vector<Number> arr,HINSTANCE &dll){
    std::vector<std::string> dlls;
    for (const auto& entry : std::filesystem::directory_iterator("sequences")) {
        if (entry.is_regular_file() && entry.path().extension() == ".dll") {
            dlls.push_back(entry.path().string());
        }
    }
    for(const std::string& dllPath : dlls){
        dll = LoadLibrary(TEXT(dllPath.c_str()));
        if (dll == NULL) {
            DWORD error = GetLastError();
            LPSTR messageBuffer = nullptr;
            size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                nullptr, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, nullptr);
            std::string message(messageBuffer, size);
            LocalFree(messageBuffer);
            std::cerr << "Failed to load DLL '" << dllPath << "': " << message << std::endl;
            continue;
        }
        // Get a pointer to the CreateArthSequence function
        createSequence create = (createSequence)GetProcAddress(dll, "create");
        if (create == NULL) {
            FreeLibrary(dll);
            continue;
        }

        // Create an ArthSequence object using the DLL function
        Sequence* s = create();
        if (s->detect(arr)){
            return s;
        }
    }
    return new Sequence();
}