#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <map>
#include <utility>

//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//std::mt19937 gen(1);

template <size_t Size>
size_t random_index()
{
    static std::uniform_int_distribution<size_t> dist(0, Size-1);
    return dist(gen);
}

using Data = std::vector<size_t>;

template <size_t Size>
Data trial()
{
    //P := [1, 2, ..., N]
    //for i in 1..N do
    //    j := rand(1, N)
    //    swap(P[i], P[j])

    // [1, 2, .... N]
    Data values(Size);
    for (size_t i = 0; i < Size; i++)
    {
        values[i] = i + 1;
    }
    
    for (size_t i = 0; i < Size; i++)
    {
        size_t j = random_index<Size>();
        std::swap(values[i], values[j]);
    }
    
    return values;
}

int main()
{
    constexpr size_t N = 6;
    Data values(N);
    for (size_t i = 0; i < N; i++)
    {
        values[i] = i + 1;
    }
   
    // Initialize map
    std::map<Data, size_t> map;   
    do {
        map[values] = 0;
    } while (std::next_permutation(values.begin(), values.end()));
    
    std::cout << "N: " << N << "\n";
    std::cout << "size of map: " << map.size() << "\n";

    // fill map with trial data
    for (int i = 0; i < 2'000'000; i++)
    {
        Data data = trial<N>();
        map[data]++;  
    }

    std::cout << "Printing...\n";
    
    // max element of map
    using pair_type = decltype(map)::value_type;
    auto max_pair = std::max_element
    (
        std::begin(map), std::end(map),
        [] (const pair_type & p1, const pair_type & p2) {
            return p1.second < p2.second;
        }
    );
    size_t max_value = max_pair->second;
        
    // Reset for print
    for (size_t i = 0; i < N; i++)
    {
        values[i] = i + 1;
    }
    do {
        size_t value = (map[values] / static_cast<double>(max_value) * 160.0);
        std::cout << std::string(value, '#') << '\n';
    } while (std::next_permutation(values.begin(), values.end()));    
}
