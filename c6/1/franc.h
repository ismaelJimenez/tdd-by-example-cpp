#ifndef Franc_H
#define Franc_H

class Franc {
 public:
  Franc(unsigned int amount) : amount{amount} {}

  Franc times(unsigned int multiplier) { return {amount * multiplier}; }

 private:
  unsigned int amount;

  friend constexpr bool operator==(const Franc &lhs, const Franc &rhs);
};

constexpr bool operator==(const Franc &lhs, const Franc &rhs) {
  return lhs.amount == rhs.amount;
}

#endif