#include <algorithm>
#include <vector>
#include <limits>

int solution(int finalPosition, std::vector<int>& leafTimes) {
  std::vector<int> path;

  const std::size_t pathSize = leafTimes.size();
  path.resize(pathSize);

  constexpr int maxPosition = std::numeric_limits<int>::max();
  std::fill(path.begin(), path.end(), maxPosition);

  for (std::size_t i = 0; i < pathSize; i++) {
    const std::size_t pathIndex = leafTimes[i] - 1;
    path[pathIndex] = std::min(int(i), path[pathIndex]);
  }

  const auto obstacle = std::find(path.cbegin(), std::next(path.cbegin(), finalPosition), maxPosition);
  const std::size_t obstacleIndex = std::distance(path.cbegin(), obstacle);

  const bool isWithoutPath = obstacleIndex < finalPosition;
  if (isWithoutPath)
    return -1;

  const int timeNeeded = *std::max_element(path.cbegin(), obstacle);
  return timeNeeded;
}
