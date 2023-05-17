#include <vector>
#include <windows.h>
#include "number.h"
#include "sequence.h"

bool Sequence::detect(std::vector<Number> &nums,std::vector<createSequence> &sequences){
    return false;
}

Number Sequence::term(long long int n){
    return Number();
}

bool Sequence::findSequence(Sequence *s,std::vector<createSequence> &sequences,std::vector<Number> &arr){
    for(int i=0;i<sequences.size();i++){
        s = sequences[i]();
        if (s->detect(arr,sequences))
            return true;
    }return false;
}