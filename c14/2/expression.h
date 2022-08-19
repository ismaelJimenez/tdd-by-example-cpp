#ifndef Expression_H
#define Expression_H

class Money;
class Bank;

class Expression
{
public:
    virtual std::unique_ptr<Money> reduce(const Bank& bank, const std::string &to) const = 0;
};

#endif