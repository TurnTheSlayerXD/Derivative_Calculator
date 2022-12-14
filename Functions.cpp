//
// Created by Professional on 07.12.2022.
//
//
// Created by Professional on 27.11.2022.
//
#include "Functions.h"
using namespace std;
int Derivative::find_plusORminus(const string& str, int l, int r) {
    vector<char> BKT;
    int x = -1;
    for (int i = l; i <= r; i++) {
        if (str[i] == '(') {
            BKT.push_back(str[i]);
        }
        else if (str[i] == ')') {
            BKT.pop_back();
        }
        else if (str[i] == '+' || str[i] == '-') {
            if (BKT.empty() == false) {
                continue;
            }
            else {
                x = i;
            }
        }
    }
    return x;
}

int Derivative:: find_multiplyORdivide(const string& str, int l, int r) {
    vector<char> BKT;
    int x = -1;

    for (int i = l; i <= r; i++) {
        if (str[i] == '(') {
            BKT.push_back(str[i]);
        }
        else if (str[i] == ')') {
            BKT.pop_back();
        }
        else if (str[i] == '*' || str[i] == '/') {
            if (BKT.empty() == false) {
                continue;
            }
            else {
                x = i;
            }
        }
    }
    return x;
}

int Derivative::find_involution(const string& str, int l, int r) {
    vector<char> BKT;

    int x = -1;
    for (int i = l; i <= r; i++) {
        if (str[i] == '(') {
            BKT.push_back(str[i]);
        }
        else if (str[i] == ')') {
            BKT.pop_back();
        }
        else if (str[i] == '^') {
            if (BKT.empty() == false) {
                continue;
            }
            else {
                x = i;
            }
        }
    }

    return x;
}

bool Derivative::check_brackets(const string& str, int l, int r) {
    vector<char> BKT;
    for (int i = l + 1; i <= r - 1; i++) {
        if (str[i] == '(') {
            BKT.push_back('(');
        }
        if (str[i] == ')' && BKT.empty() == false) {
            BKT.pop_back();
        }
    }
    if (BKT.empty() == true) {
        return false;
    }
    else {
        return true;
    }
}

int Derivative::find_X(const string& str, int l, int r) {
    for (int i = l; i <= r; i++) {
        if (str[i] == 'x') {
            return i;
        }
    }
    return -1;
}


string Derivative::find_function(const string& str, int l, int r) {
    int i = l;
    bool exists = false;
    for (i; i <= r; i++) {
        if (check_if_letter(str[i]) == true) {
            exists = true;
            break;
        }
    }
    if (exists == false) {
        return "!";
    }
    else if (str.substr(i, 3) == "sin") {
        return "cos";
    }
    else if (str.substr(i, 3) == "cos") {
        return "-sin";
    }
    else if (str.substr(i, 3) == "log") {
        return "log";
    }
    else if (str.substr(i, 2) == "ln") {
        return "1/";
    }
    else if (str.substr(i, 2) == "tg") {
        return "1/cos^2";
    }
    else if (str.substr(i, 3) == "ctg") {
        return "-1/cos^2";
    }
    else if (str.substr(i, 4) == "acos") {
        return "-1/sqrt";
    }
    else if (str.substr(i, 4) == "asin") {
        return "1/sqrt";
    }
    else if (str.substr(i, 3) == "atg") {
        return "1/(1+";
    }
    else if (str.substr(i, 4) == "actg") {
        return "-1/(1+";
    }
    else {
        return "!";
    }
}

bool Derivative::check_if_num(char x) {
    if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5'
        || x == '6' || x == '7' || x == '8' || x == '9' || x == '.') {
        return true;
    }
    return false;
}

bool Derivative::check_if_letter(char x) {
    for (int i = 0; i <= 25; i++) {
        if (x == 'a' + i) {
            return true;
        }
    }
    if(x == '[' || x == ']'){
        return true;
    }
    return false;
}

string Derivative::construct_num(const string& str, int l, int r) {
    int size = 0;
    for (int i = l; i <= r; i++) {
        if (check_if_num(str[i])) {
            size++;
        }
        else {
            break;
        }
    }
    if (size == 0) {
        return "!";
    }
    return str.substr(l, size);
}

string Derivative::construct_word(const string& str, int l){
    int size = 0;
    if(str[l] == '['){
        int r = l;
        for(r; str[r] != ']'; r++);
        return str.substr(l, r - l + 1);
    }
    for(int i = l; i <= str.length() - 1; i++){
        if(check_if_letter(str[i]) == true || check_if_num(str[i]) == true){
            size++;
        }
        else{
            break;
        }
    }
    return str.substr(l, size);
}

string Derivative::create_expr(string expr) {
    int l = 0, r = expr.length() - 1;
    for (l,r ; expr[l] == '(' && expr[r] == ')' && check_brackets(expr, l, r) == false; l++, r--);

    int pos;
    if(find_X(expr, l, r) == -1 && find_key_word(expr) == "const"){
        return "0";
    }

    else if ((pos = find_plusORminus(expr, l, r)) != -1) {
        string str1 = expr.substr(l, pos - l );
        string str2 = expr.substr( pos + 1 , r - pos);
        string action;
        if (expr[pos] == '+') {
            action = "+";
        }
        if (expr[pos] == '-') {
            action = "-";
        }
        return create_expr(str1) + action + create_expr(str2);
    }

    else if ((pos = find_multiplyORdivide(expr, l, r)) != -1) {
        if (expr[pos] == '*') {
            string str1 = expr.substr(l, pos - l);
            string str2 = expr.substr(pos + 1, r - pos);
            return "(" + create_expr(str1) + ")*" + str2 + "+("
                   + create_expr(str2) + ")*" + str1 ;
        }
        else {
            string str1 = expr.substr(l, pos - l);
            string str2 = expr.substr(pos + 1, r - pos);
            return "((" + create_expr(str1) + ")*" + str2 + "-("
                   + create_expr(str2) + ")*" + str1 + ")/(" + str2 + ")^2";
        }
    }

    else if ((pos = find_involution(expr, l, r)) != -1) {
        string num;
        if ((num = construct_num(expr, pos + 1, r)) != "!") {
            float pow_int = stof(num);
            pow_int--;
            string power = to_string(pow_int);
            if (expr[pos - 1] == 'x') {
                return num + 'x' + '^' + power;
            }
            if (expr[pos - 1] == ')') {
                string str =  expr.substr(l, pos - l);
                return num + expr.substr(l, pos - l) + "^" + power + "*"
                       + "(" + create_expr( str) + ")";
            }
        }
        else {
            string str1 = expr.substr(l, r + 1);
            string str2 = "ln(" + expr.substr(l, pos - l) +
                          ")*(" + expr.substr(pos + 1, r - pos) + ")";
            return str1 + "*(" + create_expr(str2) + ")";
        }
    }

    else if (check_if_letter(expr[l]) == true && expr[l] != 'x') {
        string function;
        if((function = find_function(expr, l, r)) == "!"){
            if(find_key_word(expr) == "fuu"){
                return expr;
            }
            else if(find_key_word(function) == "const"){
                return "0";
            }
        }
        int it;
        for (it = l + 2; it <= r; it++) {
            if (expr[it] == '(') {
                break;
            }
        }

        if(function == "log"){
            it++;
            int mid = it;
            for(mid; expr[mid] != ','; mid++);
            string str1 = "ln(" + expr.substr(it,mid - it) + ")";
            string str2 =  "ln(" + expr.substr(mid + 1,r - mid - 1) + ")";
            return create_expr(str2 + "/" + str1);
        }
        else if(function == "1/"){
            return function + expr.substr(it, r - it + 1)
                   + "*(" + create_expr(expr.substr(it, r - it + 1)) + ")";
        }
        else if (function == "1/sqrt") {
            return  function + "(1-" + expr.substr(it, r - it + 1) + "^2)"
                    + "*(" + create_expr(expr.substr(it, r - it + 1)) + ")";
        }
        else if (function == "-1/sqrt") {
            return "(" + function + "(1-" + expr.substr(it, r - it + 1) + "^2))"
                   + "*(" + create_expr(expr.substr(it, r - it + 1)) + ")";
        }
        else if(function == "1/(1+"){
            return function + expr.substr(it, r - it + 1) + "^2)" + "*("
                   + create_expr(expr.substr(it, r - it + 1)) + ")";
        }
        else if(function == "-1/(1+"){
            return "(" + function + expr.substr(it, r - it + 1) + "^2))"
                   + "*(" + create_expr(expr.substr(it, r - it + 1)) + ")";
        }
        return function + expr.substr(it, r - it + 1)
               + "*(" + create_expr(expr.substr(it, r - it + 1)) + ")";
    }

    else{
        return "1";
    }
    return "0";
}
string Derivative:: find_key_word(const string& str){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i][str.length() - 1] == ']' || arr[i][0] == '['){
            return "fuu";
        }
        else{
            return "const";
        }
    }
    return "const";
}
Derivative::Derivative(string expr) {
    string function;
    for (int i = 0; i < expr.length(); i++) {
        if (check_if_letter(expr[i]) == true && expr[i] != 'x')
        {
            if ((function = find_function(expr, i, expr.length() - 1)) == "!") {
                function = construct_word(expr, i);
                arr.push_back(function);
                i = i + construct_word(expr, i).length();
            } else {
                i = i + find_function(expr, i, expr.length() - 1).length();
            }
        }
    }
    result = create_expr(expr);
    if(result.length() > 3) {
        for (int i = 1; i <= result.length() - 2; i++) {
            if (result[i - 1] == '(' && result[i + 1] == ')' && 'x' != result[i]) {
                result.erase(i + 1, 1);
                result.erase(i - 1, 1);
            }
        }
    }
}
string Derivative::get_result() {
    return result;
}
