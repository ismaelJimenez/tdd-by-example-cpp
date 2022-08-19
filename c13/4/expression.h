#ifndef Expression_H
#define Expression_H

class Money;

class Expression {
 public:
  virtual std::unique_ptr<Money> reduce(const std::string &to) const = 0;
};

#endif