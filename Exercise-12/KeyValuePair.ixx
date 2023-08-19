export module KeyValuePair;
import <concepts>;

export namespace Hatsushigure
{
template <std::integral KeyType, std::floating_point ValType>
class KeyValuePair
{
private:
	KeyType m_key;
	ValType m_value;
public:
	KeyValuePair(const KeyType& key, const ValType& value) : m_key {key}, m_value {value} {}
public:
	const auto& key() const { return m_key; }
	void setKey(const KeyType& key) { m_key = key; }
	const auto& value() const { return m_value; }
	void setValue(const ValType& value) { m_value = value; }
};
}