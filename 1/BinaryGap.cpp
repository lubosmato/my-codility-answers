#include <algorithm>

int solution(int input) {
  int biggestGap = 0;
  int gaps = 0;
  bool gapStarted = false;
  while (input != 0) {
    if ((input & 1) == 1) {
      biggestGap = std::max(biggestGap, gaps);
      gaps = 0;
      gapStarted = true;
    } else {
      if (gapStarted) {
        gaps++;
      }
    }
    input >>= 1;
  }
  return biggestGap;
}
