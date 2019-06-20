#ifndef INTEGRALMATH_POINTERLOGIC_HPP
#define INTEGRALMATH_POINTERLOGIC_HPP

#include <memory>

namespace IntegralMath
{


class PointerLogic
{
public:
	// C++14 Patch: std::make_unique<>()
	template<typename T, typename... Args>
	static inline std::unique_ptr<T> makeUnique(Args&&... args)
	{
		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}

	// C++14 Patch: std::make_shared<>()
	template<typename T, typename... Args>
	static inline std::shared_ptr<T> makeShared(Args&&... args)
	{
		return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
	}
};


} // namespace IntegralMath



#endif // INTEGRALMATH_POINTERLOGIC_HPP