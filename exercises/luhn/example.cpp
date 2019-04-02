#include "luhn.h"

using namespace std;

namespace luhn{

    bool valid(std::string const& input_str)
    {

        string reversed;
        reversed.assign(input_str.rbegin(),input_str.rend());
        reversed.erase(0,reversed.find_first_not_of(" "));
        reversed.erase(reversed.find_last_not_of(" ") + 1);

        if(reversed.size()<=1){
            return false;
        }

        int result = 0;
        int counter=0;
        for(auto c:reversed)
        {
            if(c==' ')
            {
                continue;
            } else if(isdigit(c)) {
                int digit = (int)c-48;

                if(counter%2==1){
                    result=digit*2>9?result+digit*2-9:result+digit*2;
                }else{
                    result=result+digit;
                }
                counter++;
            } else {
                return false;
            }
        }
        return result % 10 == 0;

    }


} // namespace luhn
