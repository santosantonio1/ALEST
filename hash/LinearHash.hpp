#ifndef _LINEAR_HASH_
#define _LINEAR_HASH_

#include<vector>
#include<forward_list>
#include<functional>

template<typename Key, typename Value>
    class LinearHash
    {
        public:
            LinearHash(size_t m = 4)
            {
                M = m;
                N = 0;
                v.resize(M);
            }
            Value get(Key key)
            {
                std::size_t i = hash(key);
                return (v[i].first == key) ? v[i].second : NULL;
            }
            void put(Key key, Value val)
            {
                std::size_t i;
                for(i = hash(key); v[i] != NULL; i++);
                v[i] = std::pair<Key, Value>(key, val);
                N++;
                // Resize...
                if(N == M/2 - 1) resize(2*M);
            }
            void remove(Key key)
            {   
                
                if(N == M/8 - 1) resize(M/2);
            }
        private:
            // Capacidade, número de pares<chave, valor>
            size_t M, N;
            
            std::vector<std::pair<Key, Value>> v;

            // ----------------------------------
            // Geração de hash
            std::hash<Key> hash_function;
            
            size_t hash(Key key)
            {
                return (hash_function(key) & 0x7fffffff) % M;
            }
            // ----------------------------------
            void resize(std::size_t size)
            {
                std::vector<std::pair<Key, Value>> temp = v;
                v.clear();
                M = size;
                N = 0;
                v.resize(size);
                for(auto &p : temp)
                    push(p.first, p.second);
            }
    };

#endif