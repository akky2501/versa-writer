#include <type_traits>

#include<iostream>
#include<typeinfo>
/*
// T�^��hoge�Ƃ��������o�ϐ��������Ă��邩�ǂ����𔻕ʂ��郁�^�֐�
template < typename T >
struct has_mem_hoge
{
private:

	template < typename U >
	[] check() -> decltype(reinterpret_cast<U *>(nullptr)->hoge, std::true_type){};
	template < typename U >
	std::false_type check(){};

public:
	static const bool value = std::is_same< check<T>(), std::true_type >::value;
};


class A{
public:
	int hoge;
};
*/
int main(void){
	//std:type_info const & t = typeid(A);

	//std::cout << t.name() << std::endl;

	char v = -120;
	unsigned char x = v;

	std::cout << (int)x << std::endl;

	return 0;
}
