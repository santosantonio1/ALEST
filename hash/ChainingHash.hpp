#ifndef _CHAINING_HASH_
#define _CHAINING_HASH_

#include<vector>
#include<forward_list>
#include<functional>

// É aquela coisa... O único capaz de ler e entender esse
// código é o proprio Deus e o próprio
// Bjarne Stroustopdsaop, pai do C++

template<typename Key, typename Value> 
    class ChainingHash
    {
        public:
            // Construtor (default = 4)
            ChainingHash(std::size_t m = 4)
            {
                M = m;
                t.resize(M);
                N = 0;
            }
            // O(n)
            // Médio: 3~5 operações
            void push(Key key, Value val)
            {
                std::size_t i = hash(key);
                // pair<key, val>
                for(auto &node : t[i])
                {
                    if(key == node.first)
                    {
                        // Atualiza o valor da chave.
                        node.second = val;
                        return;
                    }
                }
                // Caso não exista a chave na lista, adicione-a!
                t[i].push_front(std::pair<Key, Value>(key, val));
                N++;
                if(N/M >= 8) resize(2*M);
            }
            // O(n)
            // Médio: 3~5 operações
            void remove(Key key)
            {
                Value v = get(key);
                if(v>=0)
                {
                    std::size_t i = hash(key);
                    t[i].remove(std::pair<Key, Value>(key, v));
                    N--;
                    if(M > 4 && N/M <= 2) resize(M/2);
                }
            }
            // O(n)
            // Médio: 3~5 operações
            Value get(Key key)
            {
                std::size_t i = hash(key);
                for(auto &node : t[i])
                {
                    if(key == node.first)
                        return (Value) node.second;
                }
                // Caso a chave não tenha sido encontrada...
                return -1;
            }
            // O(n)
            // Médio: 3~5 operações
            bool contains(Key key)
            {
                return get(key) != -1;
            }
            // print(key, value)
            void print()
            {
                for(auto &l : t)
                {
                    if(!l.empty())
                    {
                        for(auto &a : l)
                            std::cout << "(" << a.first << ", " << hash(a.first) << ") ";

                        std::cout << std::endl;
                    }
                }
            }
        private:
            // M: Número de linhas
            // N: Número de pares<chave, valor>
            std::size_t M, N;
            // Testar vector x linked-list ... Reza a lenda que o vector é O(1)
            // Tabela hash
            std::vector<std::forward_list<std::pair<Key, Value>>> t;

            // ------------------------------            
            // Geração de hash
            std::hash<Key> hash_code;

            std::size_t hash(Key key)
            {
                return (hash_code(key) & 0x7fffffff) % M;
            }
            // ------------------------------            

            void resize(std::size_t size)
            {
                std::vector<std::pair<Key, Value>> nodes;
                std::size_t i=0;
                for(auto &l : t)
                {
                    for(auto &node : l)
                        nodes.push_back(node);

                    l.clear();
                }
                N = 0;
                M = size;
                t.resize(size);
                for(auto &node : nodes)
                    push(node.first, node.second);
            }
    };

#endif