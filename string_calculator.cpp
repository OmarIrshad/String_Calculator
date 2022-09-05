#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    if (isdigit(digit) == true){
        int b = digit - 48;
        return b;
    }
    else{
        throw std::invalid_argument("");
    }
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    char b;
    if (decimal <= 9){
        b = decimal + '0';

    return b;
    }
    else{
        throw std::invalid_argument("");
    }
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    int i = 0;
    string exception = "-0"; 

     while (num.at(i) == '0' || num.at(i) == '-') {
        if (num.at(i) == '-'){
            i++;
        }
        if (num.at(i) == '0'){
            num = num.replace(i,1,"");
        } 
        if (num == "" || num == "-"){
            break;
        }

     }
     if (num == ""){
        num = "0";
     }
     if (num == "-"){
        num = "0";
     }
      return num;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
// Establish variables
int left;
int right;
int sum;
int remainder = 0;
string solution = ""; 
int double_negative = 0;
    if(lhs.at(0) == '-' && rhs.at(0) != '-'){
        lhs = lhs.replace(0,1,"");
        swap(lhs,rhs);
        solution = subtract(lhs,rhs);
        return solution;
    }
    if(lhs.at(0) != '-' && rhs.at(0) == '-'){
        rhs = rhs.replace(0,1,"");
        solution = subtract(lhs,rhs);
        return solution;
    }
    
    //Code for two negative numbers 
    if ((lhs.at(0) == '-') && (rhs.at(0) == '-' || rhs.at(0) == '0')){
        lhs = lhs.replace(0,1,"");
        rhs = rhs.replace(0,1,"");
        double_negative = double_negative + 2;
    }
    
    // Code for making the two equal length
    if (lhs.length() < rhs.length()){
        int difference = rhs.length() - lhs.length();
        for(int k = 0; k < difference; k++){
            lhs = "0" + lhs; // add "0" to the left of lhs until equal length

        }
    }
    else if (lhs.length() > rhs.length()){
        int difference_2 = lhs.length() - rhs.length();
        for(int k = 0; k < difference_2; k++){
            rhs = "0" + rhs;
        }
    }

//Actual code for adding
    if (lhs.length() == rhs.length()){
        for(int i = lhs.length() - 1; i >= 0; i--){ 
            sum = 0;
            left = digit_to_decimal(lhs.at(i));
            right = digit_to_decimal(rhs.at(i));
            sum = left + right + remainder;
            if(sum > 9){
                sum = sum - 10;
                remainder = 1;
            }
            else{
                remainder = 0;
            }
            solution = decimal_to_digit(sum) + solution;
        }
        if (remainder > 0) {
            solution = decimal_to_digit(remainder) + solution;
        }
        if(double_negative > 0){
            solution = "-" + solution;
        }
        return solution;
    }

return solution;
}

string subtract(string lhs, string rhs) {
    // TODO(student): implement
    string second_negative;
    //////////////////F
    if((lhs.at(0)) == '-' && rhs.at(0) == '-' ){
        rhs = rhs.replace(0,1,"");
        second_negative = add(lhs,rhs);
        return second_negative;
    }
    if((lhs.at(0) != '-') && (rhs.at(0) == '-')){
        rhs = rhs.replace(0,1,"");
        second_negative = add(lhs,rhs);
        return second_negative;
    }
    if((rhs.at(0) != '-') && (lhs.at(0) == '-')){
        rhs = "-" + rhs;
        second_negative = add(lhs,rhs);
        return second_negative;
    }

    //////////////////////////////////////////// This box makes the two variables of equal length
    if (lhs.length() < rhs.length()){
        int difference = rhs.length() - lhs.length();
        for(int k = 0; k < difference; k++){
            lhs = "0" + lhs; // add "0" to the left of lhs until equal length

        }
    }
    else if (lhs.length() > rhs.length()){
        int difference_2 = lhs.length() - rhs.length();
        for(int k = 0; k < difference_2; k++){
            rhs = "0" + rhs;
        }
    }
    //////////////////////////////////////////////
    
    int flipper = 0;
    /////////////////////// Ths box checks to see which input is bigger than th other
    if( lhs.length() == rhs.length()){
        for(unsigned int i = 0; i < lhs.length(); i++){
            if (digit_to_decimal(lhs.at(i)) > digit_to_decimal(rhs.at(i))){
                break;
            }
            if(digit_to_decimal(lhs.at(i)) < digit_to_decimal(rhs.at(i))){
                swap(lhs,rhs);
                flipper = flipper + 1;
                break;
            }

        }
    }
    ////////////////////////// This block does the actual subtraction
    string solution = "";
    int add_1 = 0;
    if(lhs.length() == rhs.length()){
        for(int b = lhs.length()-1; b >= 0; b--){
            int subtract = 0;
            int top = digit_to_decimal(lhs.at(b));
                if(add_1 > 0){
                    top = top - 1;
                    add_1 = 0;
                }
            int bot = digit_to_decimal(rhs.at(b));
            if( (top - bot) < 0){
                subtract = (top + 10) - bot;
                add_1 = add_1 + 1;
            }
            else{
                subtract = top - bot;
            }

         solution = decimal_to_digit(subtract) + solution;
        }
    }
    ////////////////////////////////////


    ////////////////////////// If items were flipped, add a negative sign:
    if( flipper > 0){
        solution = "-" + solution;
    }
    solution = trim_leading_zeros(solution);



    return solution;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement



int negativeoutput = 0;

if(lhs.at(0) == '-' && rhs.at(0) == '-'){
    lhs = lhs.replace(0,1,"");
    rhs = rhs.replace(0,1,"");
}
if(lhs.at(0) == '-'){  \
    lhs = lhs.replace(0,1,"");
    negativeoutput = 1;

}
if(rhs.at(0) == '-'){
    rhs = rhs.replace(0,1,"");
    negativeoutput = 1;
}

if(lhs.length() > rhs.length()){
    swap (lhs,rhs);
}

    int product;
    string main = "";
    string actual_main = "0";
    string alt = " ";
    int counter = 0; 
    int jumper = 0;
    string final_main = "0";
    for (int i = lhs.length() - 1 ; i >= 0 ; i--){nv 
        int top = digit_to_decimal(lhs.at(i));
        // Loops top 
        for(int b = rhs.length() - 1; b >= 0 ; b--){
            // 
            int bot = digit_to_decimal(rhs.at(b));
            product = top * bot; 
            ////
            if (product > 9){
                main = decimal_to_digit(product%10);
                alt = decimal_to_digit(product/10);
                main = alt + main;
            }
            else{
                main = decimal_to_digit(product);
            }
            counter = (lhs.length() - 1 - i) + (rhs.length()-1-b); // Add
            if (counter> 0){
                for(int k=0; k < (counter+jumper); k++){
                    main = main + '0';
                }
            }
            actual_main = add(main,actual_main);
        }
        final_main = add(actual_main,final_main);
        actual_main = "0";
    }
if(negativeoutput > 0){
    final_main = "-" + final_main;
    
}

    return final_main;


}