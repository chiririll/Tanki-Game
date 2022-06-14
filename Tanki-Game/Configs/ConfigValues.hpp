#pragma once

namespace cfg 
{
	template <typename T>
	class ConfigValue {
	protected:
		T m_value;

	public:
		ConfigValue() = default;
		ConfigValue(const T& value): m_value(value) {};
		virtual ~ConfigValue() = default;

		virtual T Get() const { return  m_value; }
		virtual void Set(const T& value) { m_value = value; };
	};

	template <typename T>
	class BoundedValue: public ConfigValue<T>
	{
	private:
		T m_min;
		T m_max;

	public:
		BoundedValue(T value, T min, T max);
		virtual ~BoundedValue() = default;

		void Set(const T& value) override;
	};
}

namespace cfg
{
	template<typename T>
	inline BoundedValue<T>::BoundedValue(T value, T min, T max) :
		m_min(min), m_max(max), ConfigValue<T>()
	{
		Set(value);
	}

	template<typename T>
	inline void BoundedValue<T>::Set(const T& value)
	{
		// Clamp
		this->m_value = value < m_min ? m_min : (value > m_max ? m_max : value);
	}
}
