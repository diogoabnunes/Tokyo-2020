#include "utils.h"

string ltrim(string totrim) {
    totrim = totrim.substr(totrim.find_first_not_of(" "));
    return totrim;
}
string rtrim(string totrim) {
    totrim.erase(totrim.find_last_not_of(" ") + 1);
    return totrim;
}
string trim(string totrim) {
    totrim = ltrim(totrim);
    totrim = rtrim(totrim);
    return totrim;
}

vector <string> string_to_vector(string s) {
    vector<string> v;
    string elem;
    int num = count(s.begin(), s.end(), ',');
    if (num == 0) {
        elem = trim(s);
        v.push_back(elem);
        return v;
    }
    do {
        elem = trim(s.substr(0, s.find_first_of(",")));
        s.erase(0, s.find_first_of(",")+1);
        v.push_back(elem);
    } while (s.find(",") != string::npos);
    elem = trim(s);
    s.erase();
    v.push_back(elem);

    return v;
}
string comp_vec_to_str(vector <string> v) {
    string total;
    int n = v.size();
    if (n == 0) return "";
    else if (n == 1) return v[0];
    else if (n == 2) return v[0] + ", " + v[1];
    else {
        for (int i = 0; i < n - 1; i++) {
            total += v[i] + ", ";
        }
        total += v[n - 1];
    }
    return total;
}

void clearInput(){
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}