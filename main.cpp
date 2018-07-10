#include <iostream>
#include <vector>
#include <string>
std::string bigint_multiply(const std::string& left_number,const std::string& right_number)
{
    if(left_number=="0"  || right_number =="0"){
        return "0";
    }
    std::vector<std::string> up_result;
    std::vector<std::string> down_result;
    std::string up_number;
    std::string down_number;
    int all_size = left_number.size()* right_number.size()+1;
    if(left_number.size()>=right_number.size())
    {
        up_number = left_number;
        down_number = right_number;
    }else{
        up_number = right_number;
        down_number = left_number;
    }
    std::vector<std::vector<std::string>> candidate_result;
    for(int down_index = down_number.size()-1;down_index>=0;down_index--)
    {
        char down_tmp_buff[2] = {down_number[down_index],'\0'};
        int down_math_number = atoi(down_tmp_buff);
//        std::cout<<down_number[down_index]<<"========="<<down_math_number<<std::endl;
        int down_digit = down_number.size()-down_index;
        std::vector<std::string> part_result;
        part_result.resize(all_size);
        for(int up_index =up_number.size()-1;up_index>=0;up_index--)
        {
            int up_digit = up_number.size() - up_index;
            char tmp_buff[2] = {up_number[up_index],'\0'};
            int up_math_number = atoi(tmp_buff);
            int temp_result = down_math_number* up_math_number;
            //std::cout<<down_math_number<<"****"<<up_math_number<<"==="<<temp_result<<std::endl;
            int k = up_digit+down_digit-2;
            part_result[k] = std::to_string(temp_result);
        }
        candidate_result.push_back(std::move(part_result));
    }

//    for(int i = 0;i<candidate_result.size();i++)
//    {
//        auto& part_result = candidate_result[i];
//        for(int j = 0;j<part_result.size();j++)
//        {
//            std::cout<<part_result[j]<<std::endl;
//        }
//    }

    int digit_index = 0;
    std::vector<std::string> result;
    result.resize(all_size+1);
    while(digit_index<all_size)
    {
        int number = atoi(result[digit_index].c_str());
        for(int index = 0;index<candidate_result.size();index++)
        {
            auto& part_result = candidate_result[index];
            std::string fix_str = part_result[digit_index]==""?"0":part_result[digit_index];
//            std::cout<<"record==="<<fix_str<<std::endl;
            number+= atoi(fix_str.c_str());
        }
//         std::cout<<"number==="<<number%10<<std::endl;
         int to_ex_add = (number- number%10)/10;
         result[digit_index] = std::to_string(number%10);
         result[digit_index+1] = std::to_string(to_ex_add);
         digit_index++;
    }

    std::string right_result ;
    bool is_zero_str = true;
    for(int index = result.size()-1;index>=0;index--)
    {
        if(is_zero_str && result[index]=="0")
        {

        }else{
            is_zero_str = false;
            right_result.append(result[index]);
        }
    }
    return right_result;
}
int main()
{
    std::cout<<bigint_multiply("92233720368547758070","2")<<std::endl;
    return 0;
}