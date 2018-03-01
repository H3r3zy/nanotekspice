/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#ifndef CPP_NANOTEKSPICE_FACTORY_HPP
#define CPP_NANOTEKSPICE_FACTORY_HPP

#include <iostream>
#include <map>

template<typename Object, typename Key=std::string>
class Factory {
public:
	Factory() = default;
	~Factory();
	// Other
	void add(Key key, Object *obj);
	void rm(Key key);
	Object *create(const Key &key);
protected:

private:
	std::map<Key, Object *> _constructor;
};

#endif //CPP_NANOTEKSPICE_FACTORY_HPP
