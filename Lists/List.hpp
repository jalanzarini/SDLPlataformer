#include <iostream>
using namespace std;

namespace Lists
{
    template <class TL>
    class List
    {
    public:
        template <class TE>
        class Element
        {
        private:
            Element<TE> *next;
            TE data;

        public:
            Element(TE info) : data(info), next(nullptr) {}
            ~Element()
            {
                next = nullptr;
            }

            Element<TE> *getNext() { return next; }
            void setNext(Element<TE> *el) { next = el; }

            TE getData() { return data; }
        };

    private:
        Element<TL> *first;
        Element<TL> *last;

    public:
        List() : first(nullptr), last(nullptr) {}
        ~List() {}

        Element<TL> *begin() { return first; }
        Element<TL> *getlast() { return last; }

        void clean()
        {
            Element<TL> *aux = nullptr;
            Element<TL> *aux2 = nullptr;
            aux = first;
            while (aux != nullptr)
            {
                aux2 = aux->getNext();
                if (aux->getData()->getDeletable())
                {
                    delete (aux->getData());
                }
                delete aux;
                aux = aux2;
            }

            first = nullptr;
            last = nullptr;
        }

        void insert(TL element)
        {
            Element<TL> *el = nullptr;
            el = new Element<TL>(element);
            if (first == nullptr)
            {
                first = el;
                last = el;
            }
            else
            {
                last->setNext(el);
                last = el;
            }
        }

        class iterator //Inspired by https://cs.calvin.edu/activities/books/c++/intro/3e/WebItems/Ch14-Web/STL-List-14.4.pdf
        {
        private:
            Element<TL> *iter;

        public:
            iterator operator++()
            {
                iter = iter->getNext();
                return *this;
            }

            TL operator*()
            {
                return iter->getData();
            }

            void operator=(Element<TL> *el)
            {
                iter = el;
            }

            bool operator!=(Element<TL> *el)
            {
                return iter != el;
            }
        };
    };
}