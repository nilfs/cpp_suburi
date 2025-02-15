#include <iostream>
#include "RuleBasedValue.h"

// std::optionalを std::cout で出力できるようにするオーバーロード
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
    if (opt) {
        os << *opt;  // 値がある場合は中身を出力
    } else {
        os << "nullopt";  // 値がない場合は "nullopt" を出力
    }
    return os;
}

int main(int, char**){
    PriorityValue<int> value1;

    value1.SetValue( 0, 100 );
    value1.SetValue( 2, 50 );

    std::cout << "Hello, from suburi!\n";

    std::cout << "Priority " << value1.GetValue() << std::endl;

    value1.RemoveValue(0);

    std::cout << "Priority " << value1.GetValue() << std::endl;
}
