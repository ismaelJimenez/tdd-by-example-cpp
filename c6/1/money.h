#ifndef Money_H
#define Money_H

class Money {
 public:
  Money(unsigned int amount) : amount{amount} {}

 protected:
  unsigned int amount;
};

#endif