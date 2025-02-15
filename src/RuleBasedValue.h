#pragma once
#include <map>
#include <optional>
#include <numeric>

// ========================================================
// ルール: 最優先の値を取得する
// ========================================================
template<typename KeyType, typename T>
struct HighestPriorityRule {
    static std::optional<T> GetValue(const std::map<KeyType, T>& values) {
        if (!values.empty()) {
            return values.begin()->second;
        }
        return std::nullopt;
    }
};

// ========================================================
// ルール: 全ての値を合算する（T が数値型の場合）
// ========================================================
template<typename KeyType, typename T>
struct SumRule {
    static std::optional<T> GetValue(const std::map<KeyType, T>& values) {
        if (values.empty()) return std::nullopt;

        T sum = std::accumulate(values.begin(), values.end(), T(0),
            [](T acc, const auto& pair) { return acc + pair.second; });

        return sum;
    }
};

// ========================================================
// 汎用的な PriorityValue クラス
// ========================================================
template<typename KeyType, typename T, template<typename, typename> class Rule = HighestPriorityRule>
class RuleBasedValue {
private:
    using RuleType = Rule<KeyType, T>;

    std::map<KeyType, T> priorityMap; // 優先度ごとの値管理

public:
    // 値を設定
    void SetValue(KeyType priority, const T& value) {
        priorityMap[priority] = value;
    }

    // 特定の優先度の値を削除
    void RemoveValue(KeyType priority) {
        priorityMap.erase(priority);
    }

    // ルールに基づいた値を取得
    std::optional<T> GetValue() const {
        return RuleType<KeyType, T>::GetValue(priorityMap);
    }
};

template<typename T>
using PriorityValue = RuleBasedValue<int, T, HighestPriorityRule>;

template<typename T>
using SumValue = RuleBasedValue<int, T, SumRule>;
