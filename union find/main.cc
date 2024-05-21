#include "ufds.hpp"
#include "wufds.hpp"
using namespace std;

int main()
{
    int n;
    cin >> n;

    // UF uf(n);
    WQUF uf(n);

    int p, q;
    while(cin >> p >> q)
    {
        if(uf.connected(p,q)) continue;
        // uf.u(p,q);
        // uf.quick_u(p,q);
        uf.u(p,q);
        cout << p << " " << q;
    }

    cout << uf.size() << " components" << endl;

    return 0;
}