/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Created by sahel.lucas-saoudi@epitech.eu,
*/

#include <IComponent.hpp>
#include "Factory.hpp"

template <typename Object, typename Key>
Factory<Object, Key>::~Factory()
{
	for (auto &it: _constructor) {
		delete (it).second;
	}
}

template <typename Object, typename Key>
void Factory<Object, Key>::add(Key key,
	Object *obj)
{
	_constructor[key] = obj;
};

template <typename Object, typename Key>
void Factory<Object, Key>::rm(Key key)
{
	delete _constructor[key];
	_constructor.erase(key);
};

template <typename Object, typename Key>
Object *Factory<Object, Key>::create(
	const Key &key
)
{
	Object *tmp = nullptr;
	auto it = _constructor.find(key);

	if (it != _constructor.end())
		tmp=((*it).second)->copy();

	return tmp;
}

template class Factory<nts::IComponent>;