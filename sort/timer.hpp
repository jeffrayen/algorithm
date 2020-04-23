#include <cassert>
#include <chrono>

class Timer{
 private:
  bool has_tock;
  std::chrono::high_resolution_clock::time_point tick, tock;
 public:
  Timer(): has_tock(false){
    tick = std::chrono::high_resolution_clock::now();
  }
  void set_tock(void){
    tock = std::chrono::high_resolution_clock::now();
    has_tock = true;
  }
  void reset(void){
    tick = std::chrono::high_resolution_clock::now();
    has_tock = false;
  }
  double get_ms(void){
    assert(has_tock);
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(tock-tick).count();
    return (double)duration*1e-6;
  }
};
