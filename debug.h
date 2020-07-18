//made by Rohan Kumar

#include <iostream>
#include <vector>
#include <set>
#include <map>

// print 1d vector
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

// print 2d vector
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1)
            os << "\n"; 
    }
    os << "]";
    return os;
}

// print set
template <typename T> 
std::ostream& operator<<(std::ostream& os, const std::set<T>& v) { 
    os << "{"; 
    for (auto it : v) { 
        os << it; 
        if (it != *v.rbegin()) 
            os << ", "; 
    } 
    os << "}"; 
    return os; 
}

// print map
template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::map<T, S>& v) {
    for (auto it : v)  
        os << it.first << " : " 
           << it.second << "\n"; 
      
    return os; 
}

// print pair
template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::pair<T, S>& v) { 
    os << "(";
    os << v.first << ", "
       << v.second << ")";
    return os;
}