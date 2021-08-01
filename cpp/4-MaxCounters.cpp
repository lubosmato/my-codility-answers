#include <algorithm>
#include <vector>

std::vector<int> solution(int countersCount, std::vector<int>& operations) {
    std::vector<int> counters;
    counters.resize(countersCount);
    
    int previousMax = 0;
    int maxCounterValue = 0;
    const int maxCounterOperation = countersCount + 1;
    const std::size_t operationsSize = operations.size();
    for (std::size_t i = 0; i < operationsSize; i++) {
        const int operation = operations[i];
        const std::size_t counterIndex = operations[i] - 1;

        if (operation == maxCounterOperation) {
            previousMax = maxCounterValue;
        } else {
            counters[counterIndex] = std::max(counters[counterIndex], previousMax);
            counters[counterIndex]++;
            maxCounterValue = std::max(maxCounterValue, counters[counterIndex]);
        }
    }
    
    for (int& counterValue : counters) {
        counterValue = std::max(counterValue, previousMax);
    }
    
    return counters;
}
