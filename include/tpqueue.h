// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
struct SYM {
  char ch;
  int prior;
};
class TPQueue {
 private:
    int c;
    int begin, end;
    SYM* arr;

 public:
    TPQueue() : cnt(0), begin(0), end(0), data(new T[size]) {}

    T pop() {
        if (cnt == 0) {
            throw std::string("Empty");
        } else {
            count--;
            return data[begin++ % size];
        }
    }
    void push(const T &item) {
        if (cnt >= size)
            throw std::string("Full");
      cnt++;
      int Index = end;
      for (int i = begin; i < end; i++) {
          if (data[i].prior < item.prior) {
              Index = i;
              break;
          }
      }
      for (int i = end; i > Index; i--)
          data[i % size] = data[(i - 1) % size];
              data[Index % size] = item;
        end++;
    }
};


#endif  // INCLUDE_TPQUEUE_H_
