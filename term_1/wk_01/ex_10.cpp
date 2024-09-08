#include <iostream>
#include <sstream>
#include <vector>

class HarmSeq{
public:
    HarmSeq(int start, size_t counter_lim): start(start), counter_lim(counter_lim), number(start){}
    // one bit of an ugly class XD
    int get_value(){
        return 1/number;
    }

    int get_value_fix(){
        return 1.0/number;
    }

    double get_value_fix_FIX_XD(){
        return 1.0/number;
    }
    int next(){
        number++;
        return get_value();
    }
    double next_fix_FIX_XD(){
        number++;
        return get_value_fix_FIX_XD();
    }
private:
    int start;
    size_t counter_lim;
    int number;
};

int main(int argc, char** argv){
    // process cmd args (NAIVE):
    size_t n;
    if (argc != 2){
        std::cerr << "Warning: wrong number of arguments. Exactly 1 argument is required." << std::endl;
        std::cout << "Setting n value to 10" << std::endl;
        n = 10;
    }
    else{
        std::istringstream ss(argv[1]);
        if (!(ss >> n)) {
            std::cerr << "Invalid number: " << argv[1] << '\n';
        } else if (!ss.eof()) {
            std::cerr << "Trailing characters after number: " << argv[1] << std::endl;
        }
    }

    std::cout<< "n = " << n << std::endl;
    // print sequence to stdout
    auto sequence = HarmSeq(1, n);
    std::vector<double> my_vector;
    my_vector.reserve(n);

    std::cout << "my_array values prior initialization:" << std::endl;
    for (std::vector<double>::iterator i = my_vector.begin(); i != my_vector.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
//    for (auto& el: my_vector){
//        std::cout << el << std::endl;
//    }

    for (size_t i=0; i<n; i++){
        my_vector.push_back(sequence.next());
    }

    std::cout << "print out with for loop:\n";
    std::cout.precision(16);
    std::cout<< std::scientific;
    for (auto& el: my_vector){
        std::cout << el << " ";
    }
    std::cout << std::endl;

    std::cout << "Hmmm... Still not working! So how do I fix this??? XD" << std::endl;

    std::cout << "By the way try running this program with n==20 and n==200" << 200 << std::endl;

    return 0;
}
