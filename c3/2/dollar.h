#ifndef Dollar_H
#define Dollar_h

class Dollar
{
public:
  Dollar(unsigned int amount) : amount{amount} {}

  Dollar times(unsigned int multiplier)
  {
    return {amount * multiplier};
  }

  unsigned int amount;
};

constexpr bool operator==(const Dollar& lhs, const Dollar& rhs)
{
    return lhs.amount == rhs.amount;
}

#endif