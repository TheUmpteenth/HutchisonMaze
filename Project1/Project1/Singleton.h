#pragma once
#ifndef _SINGLETON_H
#define _SINGLETON_H

// This boilerplate code was taken from
// https://gist.github.com/daniebker/2299755
// for use in my maze game

template<typename T>
class Singleton
{
public:
	static T* GetInstance();
	static void Destroy();

private:

	Singleton(Singleton const&) {};
	Singleton& operator=(Singleton const&) {};

protected:
	static T* m_instance;

	Singleton() { m_instance = static_cast <T*> (this); };
	~Singleton() {  };
};

template<typename T>
typename T* Singleton<T>::m_instance = 0;

template<typename T>
T* Singleton<T>::GetInstance()
{
	if (!m_instance)
	{
		Singleton<T>::m_instance = new T();
	}

	return m_instance;
}

template<typename T>
void Singleton<T>::Destroy()
{
	delete Singleton<T>::m_instance;
	Singleton<T>::m_instance = 0;
}

#endif